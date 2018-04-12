<html>
<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <title></title>
</head>
<body>

<table cellpadding="0" cellspacing="0" bordercolor="#000000" border="1" width="100%">
  <tr>
    <td width="30%">
      <B>ИЗВЕЩЕНИЕ</B>
      <BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR>
      Кассир
      <BR><BR>
    </td>
    <td width="70%">
      <b><?php print $variables['company_name']; ?></b><br>
      ИНН <?php print $variables['company_inn']; ?> / КПП <?php print $variables['company_kpp']; ?><br>
      Р/с <?php print $variables['bank_rs']; ?><br>
      К/с <?php print $variables['bank_ks']; ?><br>
      БИК <?php print $variables['bank_bik']; ?><br>
      в <?php print $variables['bank_name']; ?><br>
      <?php print $variables['company_tel']; ?><BR>
      <b>Плательщик</b><br>
      Ф.И.О. ______________________________________________________________<br>
      Адрес: ______________________________________________________________<br>
      <BR>
      <table celpadding="0" cellspacing="0" border="1" width="100%">
        <tr>
          <td>№ счета</td>
          <td>Сумма</td>
        </tr>
        <tr>
          <td><?php print $variables['order']->oid; ?></td>
          <td><?php print number_format($variables['sum'], 2); ?> руб.</td>
        </tr>
      </table>
      <BR>
      (<?php print $variables['sum_str']; ?>)
      <BR><BR>
      ________________ "____" ______________ 20__г.<BR><BR>
    </td>
  </tr>
  <tr>
    <td width="30%">
      <B>КВИТАНЦИЯ</B>
      <BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR><BR>
      Кассир
      <BR><BR>
    </td>
    <td width="70%">
      <b><?php print $variables['company_name']; ?></b><br>
      ИНН <?php print $variables['company_inn']; ?> / КПП <?php print $variables['company_kpp']; ?><br>
      Р/с <?php print $variables['bank_rs']; ?><br>
      К/с <?php print $variables['bank_ks']; ?><br>
      БИК <?php print $variables['bank_bik']; ?><br>
      в <?php print $variables['bank_name']; ?><br>
      <?php print $variables['company_tel']; ?><BR>
      <b>Плательщик</b><br>
      Ф.И.О. ______________________________________________________________<br>
      Адрес: ______________________________________________________________<br>
      <BR>
      <table celpadding="0" cellspacing="0" border="1" width="100%">
        <tr>
          <td>№ счета</td>
          <td>Сумма</td>
        </tr>
        <tr>
          <td><?php print $variables['order']->oid; ?></td>
          <td><?php print number_format($variables['sum'], 2); ?> руб.</td>
        </tr>
      </table>
      <BR>
      (<?php print $variables['sum_str']; ?>)
      <BR><BR>
      ________________ "____" ______________ 20__г.<BR><BR>
    </td>
  </tr>
</table>

</body>
</html>