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
		drupal_add_js(drupal_get_path('theme', 'cordesavides') . '/myJS.js', 'file');
    drupal_add_js('//cdnjs.cloudflare.com/ajax/libs/masonry/3.1.1/masonry.pkgd.js', 'external');
	}
  //dpm($vars);
}