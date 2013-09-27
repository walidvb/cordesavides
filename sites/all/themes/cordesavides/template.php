<?php

/**
 * @file template.php
 */

/**
 * Implements hook_preprocess_HOOK().
 */
function cordesavides_menu_tree__main_menu(&$variables){
	dpm($variables);
	dpm('hello');
}

/**
 * Implements hook_preprocess_page().
 */
function cordesavides_preprocess_node(&$variables) {
}

function cordesavides_video_filter_iframe(&$variables) {
  $video = $variables['video'];
  $video['width'] = '100%';
  $video['height'] = '350';
  $classes = video_filter_get_classes($video);

  $output = '<iframe src="' . $video['source'] . '" width="' . $video['width'] . '" height="' . $video['height'] . '" class="video-filter ' . implode(' ', $classes) . '" frameborder="0"></iframe>';

  return $output;
}

