<?php

/**
 * @file template.php
 */

/**
 * Bootstrap theme wrapper function for the primary menu links
 */
function cordesavides_menu_tree__primary(&$variables) {
  return '<ul class="menu nav navbar-nav col-md-2">' . $variables['tree'] . '</ul>';
}

function cordesavides_video_filter_iframe(&$variables) {
  $video = $variables['video'];
  $video['width'] = '100%';
  $video['height'] = '350';
  $classes = video_filter_get_classes($video);

  $output = '<iframe src="' . $video['source'] . '" width="' . $video['width'] . '" height="' . $video['height'] . '" class="video-filter ' . implode(' ', $classes) . '" frameborder="0"></iframe>';

  return $output;
}

/**
* Implements hook_date_format_types().
*/
function cordesavides_date_format_types() {
  return array(
    'french'  => t('french'),
  );
}

/**
* Implements hook_date_formats().
*/
function cordesavides_date_formats() {
  $formats = array();

  $formats[] = array(
    'type'    => 'french',
    'format'  => 'd m', // 24|Jun <span>2012</span>
    'locales' => array(fr_FR),
  );


  // save the new date fortmas into variables
  foreach ($formats as $format) {

    variable_set('date_format_' . $format['type'], $format['format']);

  }
  dpm($sormats);
  return $formats;
}