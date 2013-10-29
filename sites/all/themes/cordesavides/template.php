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

function cordesavides_form_element_label($variables) {
  $element = $variables['element'];
  // This is also used in the installer, pre-database setup.
  $t = get_t();
 
  // If title and required marker are both empty, output no label.
  if ((!isset($element['#title']) || $element['#title'] === '') && empty($element['#required'])) {
    return '';
  }
 
  // If the element is required, a required marker is appended to the label.
  $required = !empty($element['#required']) ? theme('form_required_marker', array('element' => $element)) : '';
 
  $title = filter_xss_admin($element['#title']);
 
  $attributes = array();
  // Style the label as class option to display inline with the element.
  if ($element['#title_display'] == 'after') {
    $attributes['class'] = 'option';
  }
  // Show label only to screen readers to avoid disruption in visual flows.
  elseif ($element['#title_display'] == 'invisible') {
    $attributes['class'] = 'element-invisible';
  }
 
  if (!empty($element['#id'])) {
    $attributes['for'] = $element['#id'];
  }
 
  // Bootstrap wants us to add a class to the label as well.
  if ($element['#type'] == 'checkbox') {
    $attributes['class'] = 'checkbox';
  }
 
  // The leading whitespace helps visually separate fields from inline labels.
  if (!empty($variables['rendered_element'])) {
    return ' <label' . drupal_attributes($attributes) . '>' . $variables['rendered_element'] . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
  }
  else {
    return ' <label' . drupal_attributes($attributes) . '>' . $t('!title !required', array('!title' => $title, '!required' => $required)) . "</label>\n";
  }
}

/*
function cordesavides_form_alter(&$vars){

  unset($vars['field_email']['und']['#prefix']);
  unset($vars['field_email']['und']['#suffix']);
  dpm($vars);

  return $vars;
}

function cordesavides_field_widget_form_alter(&$element, &$form_state, $context){
  dpm($element);
  dpm($context);
}
function cordesavides_button($variables){
  $element = $variables['element'];
  $element['#attributes']['type'] = 'submit';
  element_set_attributes($element, array('id', 'name', 'value'));

  $element['#attributes']['class'][] = 'form-' . $element['#button_type'];
  if (!empty($element['#attributes']['disabled'])) {
    $element['#attributes']['class'][] = 'form-button-disabled';
  }
  $element['#attributes']['class'][] = 'btn-default';
  return '<span class="input-group-btn"><input' . drupal_attributes($element['#attributes']) . ' /></span>';
}

function cordesavides_form_label($variables){
  dpm($variables);
}
function cordesavides_form_element($variables){
    $element = &$variables['element'];

  // This function is invoked as theme wrapper, but the rendered form element
  // may not necessarily have been processed by form_builder().
  $element += array(
    '#title_display' => 'before',
  );

  // Add element #id for #type 'item'.
  if (isset($element['#markup']) && !empty($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }
  // Add element's #type and #name as class to aid with JS/CSS selectors.
  $attributes['class'] = array('form-item');
  if (!empty($element['#type'])) {
    $attributes['class'][] = 'form-type-' . strtr($element['#type'], '_', '-');
  }
  if (!empty($element['#name'])) {
    $attributes['class'][] = 'form-item-' . strtr($element['#name'], array(' ' => '-', '_' => '-', '[' => '-', ']' => ''));
  }
  // Add a class for disabled elements to facilitate cross-browser styling.
  if (!empty($element['#attributes']['disabled'])) {
    $attributes['class'][] = 'form-disabled';
  }
  $output = '';//<div' . drupal_attributes($attributes) . '>' . "\n";

  // If #title is not set, we don't display any label or required marker.
  if (!isset($element['#title'])) {
    $element['#title_display'] = 'none';
  }
  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? ' <span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  switch ($element['#title_display']) {
    case 'before':
    case 'invisible':
      $output .= ' ' . theme('form_element_label', $variables);
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;

    case 'after':
      $output .= ' ' . $prefix . $element['#children'] . $suffix;
      $output .= ' ' . theme('form_element_label', $variables) . "\n";
      break;

    case 'none':
    case 'attribute':
      // Output no label and no required marker, only the children.
      $output .= ' ' . $prefix . $element['#children'] . $suffix . "\n";
      break;
  }

  if (!empty($element['#description'])) {
    $output .= '<div class="description">' . $element['#description'] . "</div>\n";
  }

  //$output .= "</div>\n";
  dpm($output);
  dpm($variables); 

  return $output;
}
function cordesavides_form($variables) {
  $element = $variables['element'];
  if (isset($element['#action'])) {
    $element['#attributes']['action'] = drupal_strip_dangerous_protocols($element['#action']);
  }
  element_set_attributes($element, array('method', 'id'));
  if (empty($element['#attributes']['accept-charset'])) {
    $element['#attributes']['accept-charset'] = "UTF-8";
  }
  dpm($element);
  // Anonymous DIV to satisfy XHTML compliance.
  return '<form' . drupal_attributes($element['#attributes']) . '>' . $element['#children'] . '</form>';
}

function bootstrap_form($form) {
  $variables['element'] = $form;
  // render all form elements and/or add custom markup. ** Addition: don't forget to render the hidden inputs form_id and form_build_id, otherwise your form will not work at all
  $output = '<div>'.drupal_render($form['elem1']).'</div>';
  $output .= drupal_render($form['elem2']);
  $output .= drupal_render($form['form_build_id']);
  $output .= drupal_render($form['form_id']);
  // you can also use $output .= drupal_render($form) to print all form elements that have left after manual rendering
  $variables['element']['#children'] = $output;
  return theme_form($variables);
}
*/

