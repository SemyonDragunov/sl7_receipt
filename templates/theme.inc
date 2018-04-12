<?php

/**
 * @author Semyon Dragunov <sam.dragunov@gmail.com>
 * https://github.com/SemyonDragunov
 */

/**
 * Preprocess for sl7-receipt.tpl.php
 */
function template_preprocess_sl7_receipt(&$variables) {
  $variables['company_name'] = variable_get('sl7_receipt_company_name', NULL);
  $variables['company_tel'] = variable_get('sl7_receipt_company_tel', NULL);
  $variables['company_inn'] = variable_get('sl7_receipt_company_inn', NULL);
  $variables['company_kpp'] = variable_get('sl7_receipt_company_kpp', NULL);
  $variables['bank_name'] = variable_get('sl7_receipt_bank_name', NULL);
  $variables['bank_bik'] = variable_get('sl7_receipt_bank_bik', NULL);
  $variables['bank_rs'] = variable_get('sl7_receipt_bank_rs', NULL);
  $variables['bank_ks'] = variable_get('sl7_receipt_bank_ks', NULL);
  $variables['order'] = is_object($variables['order']) ? $variables['order'] : sl7_order_load($variables['order']);
}