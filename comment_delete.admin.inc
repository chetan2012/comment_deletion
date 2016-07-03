<?php
/**
 * @file
 * Provide structure for the administrative interface to select content type.
 */

/**
 * Implements comment_delete_settings_form() .
 */
function comment_delete_settings_form($form, &$form_state) {
  $comment_delete_form = array();
  $comment_delete_form['comment_delete_types'] = array(
    '#type' => 'select',
    '#multiple' => TRUE,
    '#title' => t('Currently enabled content types'),
    '#description' => t('Set types of nodes for which comments needs to be deleted. <strong>Note</strong> that comments may stay open for the content type.'),
    '#options' => node_type_get_names(),
    '#default_value' => variable_get('comment_delete_types', ''),
    '#empty_option' => '-None-',
    '#weight' => -20,
  );
  if (variable_get('comment_delete_types', '')) {
    $comment_delete_form['batch_link'] = array(
      '#type' => 'link',
      '#title' => t('Start Batch'),
      '#prefix' => t('<strong>Note:</strong> Click&nbsp;'),
      '#suffix' => t('&nbsp;link after save configuration for execution of delete comment.'),
      '#href' => 'admin/comment_delete_batch',
      '#weight' => 10,
    );
  }
  $comment_delete_form['actions']['#weight'] = -10;
  return system_settings_form($comment_delete_form);
}
