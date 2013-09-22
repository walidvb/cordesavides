<?php
/*
 * Implements hook_views_plugins().
 *
 * This function creates the style plugin for Awkward Showcase views.
 */
function awkward_showcase_views_plugins() {
  return array(
    'module' => 'awkward_showcase', // This just tells our themes are elsewhere.
    'style' => array(
      // Style plugin for the navigation.
      'awkward_showcase' => array(
        'path' => drupal_get_path('module', 'awkward_showcase') . '/plugins',
        'title' => t('Awkward Showcase'),
        'help' => t('Display the results as an Awkward Showcase image gallery.'),
        'handler' => 'views_plugin_style_aw_showcase',
        'theme' => 'views_view_awkward_showcase',
        'theme file' => 'theme.inc',
        'theme path' => drupal_get_path('module', 'awkward_showcase') . '/theme',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'normal',
        'even empty' => FALSE,
      ),
    ),
  );
}
