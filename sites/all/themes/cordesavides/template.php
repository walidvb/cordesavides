<?php

/**
 * @file template.php
 */
function cordesavides_preprocess_html(&$variables) {
  drupal_add_css('//cdnjs.cloudflare.com/ajax/libs/animate.css/2.0/animate.min.css', array('type' => 'external'));
}
/**
 * Bootstrap theme wrapper function for the primary menu links
 */
function cordesavides_menu_tree__primary(&$variables) {
  return '<ul class="main-menu menu nav navbar-nav  col-md-3 col-lg-2 col-sm-6">' . $variables['tree'] . '</ul>';
}

//set youtube frame width to 100%
function cordesavides_video_filter_iframe(&$variables) {
  $video = $variables['video'];
  $video['width'] = '100%';
  $video['height'] = '350';
  $classes = video_filter_get_classes($video);
  $output = '<iframe src="' . $video['source'] . '" width="' . $video['width'] . '" height="' . $video['height'] . '" class="video-filter ' . implode(' ', $classes) . '" frameborder="0"></iframe>';
  return $output;
}

function cordesavides_preprocess_node(&$vars) {
  if($vars['type'] == 'event')
  {
    //dpm($vars);
    drupal_add_js(drupal_get_path('theme', 'cordesavides') . '/myJS.js', 'file');
    drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/masonry/3.1.1/masonry.pkgd.js', 'external');
    drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/mousetrap/1.2.2/mousetrap.min.js', 'external');
  }
}


