<?php
/**
 * @file
 * Awkward Showcase style plugin for the Views module.
 */

/**
 * Implements a style type plugin for the Views module.
 */
class views_plugin_style_aw_showcase extends views_plugin_style {

  /**
   * Set default options.
   */
  function option_definition() {
    $options = parent::option_definition();

    $this->options['aw_showcase_layout_settings'] = array(
      'Normal' => array(
        'content_width' => 700,
        'content_height' => 470,
        'fit_to_parent' => FALSE,
        'auto' => TRUE,
        'interval' => 3000,
        'continuous' => FALSE,
        'loading' => TRUE,
        'tooltip_width' => 200,
        'tooltip_icon_width' => 32,
        'tooltip_icon_height' => 32,
        'tooltip_offsetx' => 18,
        'tooltip_offsety' => 0,
        'arrows' => TRUE,
        'buttons' => TRUE,
        'btn_numbers' => TRUE,
        'keybord_keys' => TRUE,
        'mousetrace' => FALSE,
        'pauseonover' => TRUE,
        'stoponclick' => FALSE,
        'transition' => 'hslide',
        'transition_speed' => 500,
        'transition_delay' => 0,
        'show_caption' => 'onload',
        'thumbnails' => FALSE,
        'thumbnails_position' => 'outside-last',
        'thumbnails_direction' => 'vertical',
        'thumbnails_slidex' => 1,
        'dynamic_height' => FALSE,
        'speed_change' => TRUE,
        'viewline' => FALSE,
      ),
      'Vertical thumnbails' => array(
        'content_width' => 700,
        'content_height' => 470,
        'fit_to_parent' => FALSE,
        'auto' => FALSE,
        'interval' => 3000,
        'continuous' => FALSE,
        'loading' => TRUE,
        'tooltip_width' => 200,
        'tooltip_icon_width' => 32,
        'tooltip_icon_height' => 32,
        'tooltip_offsetx' => 18,
        'tooltip_offsety' => 0,
        'arrows' => TRUE,
        'buttons' => TRUE,
        'btn_numbers' => TRUE,
        'keybord_keys' => TRUE,
        'mousetrace' => FALSE,
        'pauseonover' => TRUE,
        'stoponclick' => TRUE,
        'transition' => 'vslide',
        'transition_delay' => 300,
        'transition_speed' => 500,
        'show_caption' => 'onhover',
        'thumbnails' => TRUE,
        'thumbnails_position' => 'outside-last',
        'thumbnails_direction' => 'vertical',
        'thumbnails_slidex' => 0,
        'dynamic_height' => FALSE,
        'speed_change' => TRUE,
        'viewline' => FALSE,
      ),
      'Horizontal thumbnails' => array(
        'content_width' => 700,
        'content_height' => 470,
        'fit_to_parent' => FALSE,
        'auto' => FALSE,
        'interval' => 3000,
        'continuous' => FALSE,
        'loading' => TRUE,
        'tooltip_width' => 200,
        'tooltip_icon_width' => 32,
        'tooltip_icon_height' => 32,
        'tooltip_offsetx' => 18,
        'tooltip_offsety' => 0,
        'arrows' => TRUE,
        'buttons' => TRUE,
        'btn_numbers' => TRUE,
        'keybord_keys' => TRUE,
        'mousetrace' => FALSE,
        'pauseonover' => TRUE,
        'stoponclick' => TRUE,
        'transition' => 'hslide',
        'transition_delay' => 300,
        'transition_speed' => 500,
        'show_caption' => 'onhover',
        'thumbnails' => TRUE,
        'thumbnails_position' => 'outside-last',
        'thumbnails_direction' => 'horizontal',
        'thumbnails_slidex' => 0,
        'dynamic_height' => FALSE,
        'speed_change' => FALSE,
        'viewline' => FALSE,
      ),
      'Dynamic height' => array(
        'content_width' => 700,
        'fit_to_parent' => FALSE,
        'auto' => TRUE,
        'interval' => 3000,
        'continuous' => FALSE,
        'loading' => TRUE,
        'tooltip_width' => 200,
        'tooltip_icon_width' => 32,
        'tooltip_icon_height' => 32,
        'tooltip_offsetx' => 18,
        'tooltip_offsety' => 0,
        'arrows' => TRUE,
        'buttons' => TRUE,
        'btn_numbers' => FALSE,
        'keybord_keys' => TRUE,
        'mousetrace' => FALSE,
        'pauseonover' => TRUE,
        'stoponclick' => TRUE,
        'transition' => 'fade',
        'transition_delay' => 300,
        'transition_speed' => 500,
        'show_caption' => 'onhover',
        'thumbnails' => TRUE,
        'thumbnails_position' => 'outside-last',
        'thumbnails_direction' => 'horizontal',
        'thumbnails_slidex' => 0,
        'dynamic_height' => TRUE,
        'speed_change' => FALSE,
        'viewline' => FALSE,
      ),
      'Hundred percent' => array(
        'content_width' => 700,
        'content_height' => 470,
        'fit_to_parent' => TRUE,
        'auto' => FALSE,
        'interval' => 3000,
        'continuous' => FALSE,
        'loading' => TRUE,
        'tooltip_width' => 200,
        'tooltip_icon_width' => 32,
        'tooltip_icon_height' => 32,
        'tooltip_offsetx' => 18,
        'tooltip_offsety' => 0,
        'arrows' => TRUE,
        'buttons' => TRUE,
        'btn_numbers' => TRUE,
        'keybord_keys' => TRUE,
        'mousetrace' => FALSE,
        'pauseonover' => TRUE,
        'stoponclick' => TRUE,
        'transition' => 'hslide',
        'transition_delay' => 300,
        'transition_speed' => 500,
        'show_caption' => 'onhover',
        'thumbnails' => TRUE,
        'thumbnails_position' => 'outside-last',
        'thumbnails_direction' => 'horizontal',
        'thumbnails_slidex' => 0,
        'dynamic_height' => TRUE,
        'speed_change' => FALSE,
        'viewline' => FALSE,
      ),
      'Viewline' => array(
        'content_height' => 470,
        'fit_to_parent' => TRUE,
        'auto' => FALSE,
        'interval' => 3000,
        'continuous' => FALSE,
        'loading' => TRUE,
        'tooltip_width' => 200,
        'tooltip_icon_width' => 32,
        'tooltip_icon_height' => 32,
        'tooltip_offsetx' => 18,
        'tooltip_offsety' => 0,
        'arrows' => TRUE,
        'buttons' => TRUE,
        'btn_numbers' => TRUE,
        'keybord_keys' => TRUE,
        'mousetrace' => FALSE,
        'pauseonover' => TRUE,
        'stoponclick' => TRUE,
        'transition' => 'hslide',
        'transition_delay' => 300,
        'transition_speed' => 500,
        'show_caption' => 'onhover',
        'thumbnails' => TRUE,
        'thumbnails_position' => 'outside-last',
        'thumbnails_direction' => 'horizontal',
        'thumbnails_slidex' => 0,
        'dynamic_height' => FALSE,
        'speed_change' => FALSE,
        'viewline' => TRUE,
      ),
    );

    return $options;
  }

  /**
   * Show a form to edit the style options.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    ctools_include('dependent');
    unset($form['grouping']);

    //set the options correctly based upon the preset that has been selected
    if ($this->options['layout_set'] <> 'Custom') {
      $this->aw_showcase_set_preset_values($this->options['layout_set']);
    }
    else {
      $this->aw_showcase_set_custom_values($this->options);
    }

    $form['aw_showcase'] = array(
      '#type' => 'fieldset',
      '#title' => 'Awkward Showcase',
    );

    $layout_options = array('Normal' => 'Normal',
        'Vertical thumnbails' => 'Vertical thumnbails',
        'Horizontal thumbnails' => 'Horizontal thumbnails',
        'Dynamic height' => 'Dynamic height',
        'Hundred percent' => 'Hundred percent',
        'Viewline' => 'Viewline',
        'Custom' => 'Custom'
    );
    $form['aw_showcase']['layout_set'] = array(
      '#title' => t('Layout Options'),
      '#type' => 'select',
      '#options' => $layout_options,
      '#default_value' => $this->options['layout_set'],
    );

    $field_options = array();
    // Get each field and it's name.
    foreach ($this->view->display_handler->get_handlers('field') as $field => $handler) {
      $field_options[$field] = $handler->ui_name();
    }
    if (count($field_options) > 0) {
      // Add ability to choose which fields to show in the main stage.
      $form['aw_showcase']['main_fields'] = array(
        '#type' => 'radios',
        '#title' => t('Main Content Field'),
        '#options' => $field_options,
        '#default_value' => $this->options['main_fields'],
        '#description' => t("Choose the field that will appear in the main stage."),
        '#process' => array(
          'form_process_radios',
        ),
      );
      // Add ability to chose what field(s) show in the caption
      $form['aw_showcase']['main_caption_fields'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Main Caption Fields'),
        '#options' => $field_options,
        '#default_value' => $this->options['main_caption_fields'],
        '#description' => t("Choose the field(s) that will appear as the caption over the main image."),
        '#process' => array(
          'form_process_checkboxes',
        ),
      );
      // Add ability to choose what field shows in the pager
      $form['aw_showcase']['pager_field'] = array(
        '#type' => 'radios',
        '#title' => t('Pager Field'),
        '#options' => $field_options,
        '#default_value' => $this->options['pager_field'],
        '#description' => t("Choose the field that will appear as the pager image."),
        '#process' => array(
          'form_process_radios',
        ),
      );
      // Add ability to chose what field(s) show in the caption
      $form['aw_showcase']['pager_caption_fields'] = array(
        '#type' => 'checkboxes',
        '#title' => t('Pager Caption Fields'),
        '#options' => $field_options,
        '#default_value' => $this->options['pager_caption_fields'],
        '#description' => t("Choose the field(s) that will appear as the caption on the pager."),
        '#process' => array(
          'form_process_checkboxes',
        ),
      );
    }

    $form['aw_showcase_settings'] = array(
      '#type' => 'fieldset',
      '#title' => 'Awkward Showcase Display Settings',
      '#input' => TRUE,
      '#dependency' => array('edit-style-options-aw-showcase-layout-set' => array('Custom')),
    );
    $form['aw_showcase_settings']['content_width'] = array(
      '#title' => t('Content Width'),
      '#type' => 'textfield',
      '#default_value' => $this->options['content_width'],
      '#size' => 4,
      '#maxlength' => 4,
    );
    $form['aw_showcase_settings']['content_height'] = array(
      '#title' => t('Content Height'),
      '#type' => 'textfield',
      '#default_value' => $this->options['content_height'],
      '#size' => 4,
      '#maxlength' => 4,
    );
    $form['aw_showcase_settings']['fit_to_parent'] = array(
      '#title' => t('Fit to Parent'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['fit_to_parent'],
    );
    $form['aw_showcase_settings']['auto'] = array(
      '#title' => t('Auto Start on Page Load'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['auto'],
    );
    $form['aw_showcase_settings']['interval'] = array(
      '#title' => t('Transition Interval'),
      '#type' => 'textfield',
      '#default_value' => $this->options['interval'],
      '#size' => 6,
      '#maxlength' => 10,
      '#description' => t('Time (in Milliseconds) between transitions.'),
    );
    $form['aw_showcase_settings']['continuous'] = array(
      '#title' => t('Continuous Rotation'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['continuous'],
      '#description' => t('Rotate back to the first image once the last one has been shown.'),
    );
    $form['aw_showcase_settings']['loading'] = array(
      '#title' => t('Loading'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['loading'],
      '#description' => t('Show loading message.'),
    );
    $form['aw_showcase_settings']['tooltip_width'] = array(
      '#title' => t('Tooltip Width'),
      '#type' => 'textfield',
      '#default_value' => $this->options['tooltip_width'],
      '#size' => 5,
      '#maxlength' => 5,
    );
    $form['aw_showcase_settings']['tooltip_icon_width'] = array(
      '#title' => t('Tooltip Icon Width'),
      '#type' => 'textfield',
      '#default_value' => $this->options['tooltip_icon_width'],
      '#size' => 5,
      '#maxlength' => 5,
    );
    $form['aw_showcase_settings']['tooltip_icon_height'] = array(
      '#title' => t('Tooltip Icon Height'),
      '#type' => 'textfield',
      '#default_value' => $this->options['tooltip_icon_height'],
      '#size' => 5,
      '#maxlength' => 5,
    );
    $form['aw_showcase_settings']['tooltip_offsetx'] = array(
      '#title' => t('Tooltip Offset X'),
      '#type' => 'textfield',
      '#default_value' => $this->options['tooltip_offsetx'],
      '#size' => 5,
      '#maxlength' => 5,
    );
    $form['aw_showcase_settings']['tooltip_offsety'] = array(
      '#title' => t('Tooltip Offset Y'),
      '#type' => 'textfield',
      '#default_value' => $this->options['tooltip_offsety'],
      '#size' => 5,
      '#maxlength' => 5,
    );
    $form['aw_showcase_settings']['arrows'] = array(
      '#title' => t('Display left and Right arrows'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['arrows'],
    );
    $form['aw_showcase_settings']['buttons'] = array(
      '#title' => t('Display Buttons'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['buttons'],
    );
    $form['aw_showcase_settings']['btn_numbers'] = array(
      '#title' => t('Display Buttons Numbers'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['btn_numbers'],
    );
    $form['aw_showcase_settings']['keybord_keys'] = array(
      '#title' => t('Enable Keyboard Shortcuts'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['keybord_keys'],
    );
    $form['aw_showcase_settings']['mousetrace'] = array(
      '#title' => t('Mousetrace'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['mousetrace'],
    );
    $form['aw_showcase_settings']['pauseonover'] = array(
      '#title' => t('Pause on Mouseover'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['pauseonover'],
    );
    $form['aw_showcase_settings']['stoponclick'] = array(
      '#title' => t('Stop on Mouse Click'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['stoponclick'],
    );
    $transition_options = array('hslide' => 'Horizontal Slide', 'vslide' => 'Vertical Slide', 'fade' => 'Fade');
    $form['aw_showcase_settings']['transition'] = array(
      '#title' => t('Transition Type'),
      '#type' => 'select',
      '#options' => $transition_options,
      '#default_value' => $this->options['transition'],
    );
    $form['aw_showcase_settings']['transition_speed'] = array(
      '#title' => t('Transition Speed'),
      '#type' => 'textfield',
      '#default_value' => $this->options['transition_speed'],
      '#size' => 5,
      '#maxlength' => 5,
      '#description' => t('How fast the transition happens (In milliseconds)'),
    );
    $form['aw_showcase_settings']['transition_delay'] = array(
      '#title' => t('Transition Delay'),
      '#type' => 'textfield',
      '#default_value' => $this->options['transition_delay'],
      '#size' => 5,
      '#maxlength' => 5,
      '#description' => t('How log to wait to begin the transition (In milliseconds)'),
    );
    $show_caption_options = array('onload' => 'On Load', 'onhover' => 'On Hover', 'show' => 'Show');
    $form['aw_showcase_settings']['show_caption'] = array(
      '#title' => t('Show Caption'),
      '#type' => 'select',
      '#options' => $show_caption_options,
      '#default_value' => $this->options['show_caption'],
      '#description' => t('When does the caption get shown to the user.'),
    );
    $form['aw_showcase_settings']['thumbnails'] = array(
      '#title' => t('Show Thumbnails'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['thumbnails'],
    );
    $thumbnails_position_options = array('outside-last' => 'Outside Last',
      'outside-first' => 'Outside First',
      'inside-last' => 'Inside Last',
      'inside-first' => 'Inside First');
    $form['aw_showcase_settings']['thumbnails_position'] = array(
      '#title' => t('Thumbnail Position'),
      '#type' => 'select',
      '#options' => $thumbnails_position_options,
      '#default_value' => $this->options['thumbnails_position'],
      '#description' => t('Where should the thumbnails be positioned?'),
    );
    $thumbnails_direction_options = array('vertical' => 'Vertical', 'horizontal' => 'Horizontal');
    $form['aw_showcase_settings']['thumbnails_direction'] = array(
      '#title' => t('Thumbnail Direction'),
      '#type' => 'select',
      '#options' => $thumbnails_direction_options,
      '#default_value' => $this->options['thumbnails_direction'],
      '#description' => t('Should the thumbnails be displayed horizontally or vertically?'),
    );
    $thumbnails_slidex_options = array('0' => 'auto', '1' => 'slide one thumbnail', '2' => 'slide two thumbnails');
    $form['aw_showcase_settings']['thumbnails_slidex'] = array(
      '#title' => t('Thumbnail Slidex'),
      '#type' => 'select',
      '#options' => $thumbnails_slidex_options,
      '#default_value' => $this->options['thumbnails_slidex'],
    );
    $form['aw_showcase_settings']['dynamic_height'] = array(
      '#title' => t('Dynamic Height'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['dynamic_height'],
      '#description' => t('In webkit browsers, you need to set the width and height of images in the source. Usually works to only set the dimension of the first slide in the showcase.'),
    );
    $form['aw_showcase_settings']['speed_change'] = array(
      '#title' => t('Speed Change'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['speed_change'],
      '#description' => t('Check this box to prevent users from switching more then one slide at once.'),
    );
    $form['aw_showcase_settings']['viewline'] = array(
      '#title' => t('Viewline'),
      '#type' => 'checkbox',
      '#default_value' => $this->options['viewline'],
      '#description' => t('Check this box and content_width, thumbnails, transition and dynamic_height will be disabled. Just like dynamic height, you need to set the width and height of images in the source.'),
    );



  }

  /**
   * Performs some cleanup tasks on the options array before saving it.
   */
  function options_submit(&$form, &$form_state) {
    $options = &$form_state['values']['style_options'];
    // Pull the fieldset values one level up
    $options += $options['aw_showcase'];
    $options += $options['aw_showcase_settings'];
    unset($options['aw_showcase']);
    unset($options['aw_showcase_settings']);

    // If this is a preset layout get the values and set the options array to the preset values
    if (isset($options['layout_set']) && $options['layout_set'] <> 'Custom') {
      $this->aw_showcase_set_preset_values($options['layout_set']);
    }
    else {
      $this->aw_showcase_set_custom_values($options);
    }

  }

  /**
   * Callback for the select element.
   *
   * This just selects and returns the aw_showcase fieldset.
   */
  function aw_showcase_settings_dynamic_sections_select_callback($form, $form_state) {
    return $form['aw_showcase_settings'];
  }

  /**
   * Sets the options with the layout preset values
   */
  function aw_showcase_set_preset_values($preset_name) {
    $preset_settings = array();
    $preset_settings = $this->options['aw_showcase_layout_settings'][$preset_name];
    foreach($preset_settings as $key => $value) {
      $this->options[$key] = $value;
    }
  }

  /**
   * Sets the options with the custom values
   */
  function aw_showcase_set_custom_values($settings) {
    foreach($settings as $key => $value) {
      $this->options[$key] = $value;
    }
  }

  /**
   * Searches for the image field to use.
   */
  function find_image_field() {
    foreach ($this->view->display_handler->get_handlers('field') as $id => $handler) {
      if (($handler instanceof views_handler_field_field) && ($handler->field_info['type'] == 'image')) {
        return $id;
        break;
      }
    }
    return FALSE;
  }

  /**
   * Render the display in this style.
   */
  function render() {
    // Render each group separately and concatenate.
    $output = '';

    $rendered_fields = $this->render_fields($this->view->result);
    // get the field in the view that should be used to create the pager items
    $pager_view_field = $this->options['pager_field'];

    // get the field in the view that is set for the main image fields
    $main_view_field = $this->options['main_fields'];

    // get the field(s) in the view that are set for the main caption fields
    $main_caption_view_fields = array();
    foreach ($this->options['main_caption_fields'] as $key => $value) {
      if (!empty($value)) {
        $main_caption_view_fields[$key] = $value;
      }
    }

    // get the field(s) in the view that are set for the main caption fields
    $pager_caption_view_fields = array();
    foreach ($this->options['pager_caption_fields'] as $key => $value) {
      if (!empty($value)) {
        $pager_caption_view_fields[$key] = $value;
      }
    }

    //create rows
    $rows = array();
    foreach ($rendered_fields as $fields) {
      //set output of each of the caption fields
      $main_caption = '';
      foreach ($main_caption_view_fields as $main_caption_view_field) {
        $main_caption .= $fields[$main_caption_view_field];
      }
      $pager_caption = '';
      foreach ($pager_caption_view_fields as $pager_caption_view_field) {
        $pager_caption .= $fields[$pager_caption_view_field];
      }
      $rows[] = array(
        'main' => $fields[$main_view_field],
        'pager' => array('image' => $fields[$pager_view_field], 'caption' => $pager_caption),
        'caption' => $main_caption,
      );
    }
    $title = $this->view->human_name;
    $output .= theme($this->theme_functions(),
      array(
        'view' => $this->view,
        'options' => $this->options,
        'rows' => $rows,
        'title' => $title)
    );
    return $output;
  }

}