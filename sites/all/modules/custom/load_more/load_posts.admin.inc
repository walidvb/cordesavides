<?php

/**
 * @file
 * Administrative page callbacks for the colorbox module.
 */

/**
 * General configuration form for controlling the colorbox behaviour.
 */
function load_more_admin_settings() {

  $form['load_more_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Appearence'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE
  );
  
  $form['load_more_settings']['load_more_speed'] = array(
    '#type' => 'textfield',
    '#title' => t('Opening and closing speed'),
    '#default_value' => $colorbox_path,
    '#description' => t('The speed at which posts should open and close(in ms)'),
  );
    return system_settings_form($form);
}

/**
 * Checks if the directory in $form_element exists and contains a file named
 * 'jquery.colorbox.js'. If validation fails, the form element is flagged
 * with an error from within the file_check_directory function.
 *
 * @param $form_element
 *   The form element containing the name of the directory to check.
 */
function _colorbox_admin_settings_check_plugin_path($form_element) {
  $library_path = $form_element['#value'];
  if (!is_dir($library_path) || !(file_exists($library_path . '/colorbox/jquery.colorbox.js') && file_exists($library_path . '/colorbox/jquery.colorbox-min.js'))) {
    form_set_error($form_element['#parents'][0], t('You need to download the !colorbox and extract the entire contents of the archive into the %path folder of your server.', array('!colorbox' => l(t('Colorbox plugin'), 'http://colorpowered.com/colorbox/'), '%path' => $library_path)));
  }

  return $form_element;
}

/**
 * Enable the Colorbox load feature of the login links are set to open in a Colorbox.
 */
function _colorbox_admin_settings_login_links_load($form_element) {
  $login_links = $form_element['#value'];
  if ($login_links == 2) {
    variable_set('colorbox_load', 1);
  }

  return $form_element;
}
