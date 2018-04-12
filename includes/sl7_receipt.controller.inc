<?php

/**
 * @author Semyon Dragunov <sam.dragunov@gmail.com>
 * https://github.com/SemyonDragunov
 */

class SL7ReceiptPaymentController extends SL7PaymentController {

  protected $nds;
  protected $sum;
  protected $sum_str;

  public function internal($order, $file = '', $format = 'A4', $default_font_size = 0, $default_font = '') {

    $order = is_object($order) ? $order : sl7_order_load($order);
    $this->calculate($order); // Расчеты

    if (!$this->checkup()) exit;

    $check = theme('sl7_receipt', array(
      'order' => $order->oid,
      'sum' => $this->sum,
      'sum_str' => $this->sum_str,
    ));
    $check = mb_convert_encoding($check, 'UTF-8', 'UTF-8');

    sl7_mpdf_include();
    $mpdf = new mPDF('', $format, $default_font_size, $default_font);
    $mpdf->WriteHTML($check);
    $mpdf->Output($file);
    exit;
  }

  /**
   * Переопределяем SL7PaymentController::checkup().
   */
  public function checkup() {
    if (
      !empty($this->payment_type) &&
      !empty($this->sum) &&
      !empty($this->sum_str)
    ) {
      return TRUE;
    }

    return FALSE;
  }

  protected function calculate($order) {
    $this->calc_sum($order);
    $this->calc_sum_str();
  }

  /**
   * Получение общей суммы платежа.
   */
  protected function calc_sum($order) {
    $sum = sl7_order_get_sum($order);
    $this->sum = round($sum, 2);
  }

  protected final function calc_sum_str() {
    if (empty($this->sum)) exit;

    $nul='ноль';
    $ten=array(
      array('','один','два','три','четыре','пять','шесть','семь', 'восемь','девять'),
      array('','одна','две','три','четыре','пять','шесть','семь', 'восемь','девять'),
    );
    $a20=array('десять','одиннадцать','двенадцать','тринадцать','четырнадцать' ,'пятнадцать','шестнадцать','семнадцать','восемнадцать','девятнадцать');
    $tens=array(2=>'двадцать','тридцать','сорок','пятьдесят','шестьдесят','семьдесят' ,'восемьдесят','девяносто');
    $hundred=array('','сто','двести','триста','четыреста','пятьсот','шестьсот', 'семьсот','восемьсот','девятьсот');
    $unit=array(
      array('копейка' ,'копейки' ,'копеек',	 1),
      array('рубль'   ,'рубля'   ,'рублей'    ,0),
      array('тысяча'  ,'тысячи'  ,'тысяч'     ,1),
      array('миллион' ,'миллиона','миллионов' ,0),
      array('миллиард','миллиарда','миллиардов',0),
    );
    list($rub,$kop) = explode('.',sprintf("%015.2f", floatval($this->sum)));
    $out = array();
    if (intval($rub)>0) {
      foreach(str_split($rub,3) as $uk=>$v) {
        if (!intval($v)) continue;
        $uk = sizeof($unit)-$uk-1;
        $gender = $unit[$uk][3];
        list($i1,$i2,$i3) = array_map('intval',str_split($v,1));
        $out[] = $hundred[$i1];
        if ($i2>1) $out[]= $tens[$i2].' '.$ten[$gender][$i3];
        else $out[]= $i2>0 ? $a20[$i3] : $ten[$gender][$i3];
        if ($uk>1) $out[]= $this->morph($v,$unit[$uk][0],$unit[$uk][1],$unit[$uk][2]);
      }
    }
    else $out[] = $nul;
    $out[] = $this->morph(intval($rub), $unit[1][0],$unit[1][1],$unit[1][2]);
    $out[] = $kop.' '.$this->morph($kop,$unit[0][0],$unit[0][1],$unit[0][2]);
    $this->sum_str = trim(preg_replace('/ {2,}/', ' ', join(' ',$out)));
  }

  protected final function morph($n, $f1, $f2, $f5) {
    $n = abs(intval($n)) % 100;
    if ($n>10 && $n<20) return $f5;
    $n = $n % 10;
    if ($n>1 && $n<5) return $f2;
    if ($n==1) return $f1;
    return $f5;
  }
}