<?php

/**
 * @file template.php
 */

/**
 * Bootstrap theme wrapper function for the primary menu links
 */
function cordesavides_menu_tree__primary(&$variables) {
  return '<ul class="main-menu menu nav navbar-nav col-md-2">' . $variables['tree'] . '</ul>';
}

function cordesavides_video_filter_iframe(&$variables) {
  $video = $variables['video'];
  $video['width'] = '100%';
  $video['height'] = '350';
  $classes = video_filter_get_classes($video);
  $output = '<iframe src="' . $video['source'] . '" width="' . $video['width'] . '" height="' . $video['height'] . '" class="video-filter ' . implode(' ', $classes) . '" frameborder="0"></iframe>';
  return $output;
}
