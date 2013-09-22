<?php

/**
 * Template preprocess handler for 'awkward_showcase_container' theme.
 */
function template_preprocess_awkward_showcase_container(&$vars) {
  // Attach the Awkward Showcase css
  if (!isset($cache['css'])) {
    $css = awkward_showcase_get_library_file('awkward_showcase_css_file');
    if ($css === FALSE) {
      drupal_set_message(t('The Awkward Showcase CSS file was not found in its path. Please refer to README.txt for installation instructions.'), 'error');
      return;
    }
    $cache['css'] = $css;
  }
  drupal_add_css($cache['css'],'theme');

  // Attach Awkward Showcase JavaScript
  $settings = $vars['settings'];
  awkward_showcase_add_js($settings);
  $items = $vars['items'];
}

/**
 * Theme 'views_view_awkward_showcase'.
 */
function theme_views_view_awkward_showcase($vars) {
  $items = array();
  foreach ($vars['rows'] as $row) {
    $items[] = $row;
  }

  return theme('awkward_showcase_container', array(
    'items' => $items,
    'settings' => $vars['options'],
  ));
}