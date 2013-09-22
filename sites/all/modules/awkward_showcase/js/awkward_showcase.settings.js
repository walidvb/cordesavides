(function($)
{
    $(document).ready(function() {
        $("#showcase").awShowcase(
        {
            content_width:			Drupal.settings.awkward_showcase.content_width,
            content_height:			Drupal.settings.awkward_showcase.content_height,
            fit_to_parent:			Drupal.settings.awkward_showcase.fit_to_parent,
            auto:					Drupal.settings.awkward_showcase.auto,
            interval:				Drupal.settings.awkward_showcase.interval,
            continuous:				Drupal.settings.awkward_showcase.continuous,
            loading:				Drupal.settings.awkward_showcase.loading,
            tooltip_width:			Drupal.settings.awkward_showcase.tooltip_width,
            tooltip_icon_width:		Drupal.settings.awkward_showcase.tooltip_icon_width,
            tooltip_icon_height:	Drupal.settings.awkward_showcase.tooltip_icon_height,
            tooltip_offsetx:		Drupal.settings.awkward_showcase.tooltip_offsetx,
            tooltip_offsety:		Drupal.settings.awkward_showcase.tooltip_offsety,
            arrows:					Drupal.settings.awkward_showcase.arrows,
            buttons:				Drupal.settings.awkward_showcase.buttons,
            btn_numbers:			Drupal.settings.awkward_showcase.btn_numbers,
            keybord_keys:			Drupal.settings.awkward_showcase.keybord_keys,
            mousetrace:				Drupal.settings.awkward_showcase.mousetrace, /* Trace x and y coordinates for the mouse */
            pauseonover:			Drupal.settings.awkward_showcase.pauseonover,
            stoponclick:			Drupal.settings.awkward_showcase.stoponclick,
            transition:				Drupal.settings.awkward_showcase.transition, /* hslide/vslide/fade */
            transition_delay:		Drupal.settings.awkward_showcase.transition_delay,
            transition_speed:		Drupal.settings.awkward_showcase.transition_speed,
            show_caption:			Drupal.settings.awkward_showcase.show_caption, /* onload/onhover/show */
            thumbnails:				Drupal.settings.awkward_showcase.thumbnails,
            thumbnails_position:	Drupal.settings.awkward_showcase.thumbnails_position, /* outside-last/outside-first/inside-last/inside-first */
            thumbnails_direction:	Drupal.settings.awkward_showcase.thumbnails_direction, /* vertical/horizontal */
            thumbnails_slidex:		Drupal.settings.awkward_showcase.thumbnails_slidex, /* 0 = auto / 1 = slide one thumbnail / 2 = slide two thumbnails / etc. */
            dynamic_height:			Drupal.settings.awkward_showcase.dynamic_height, /* For dynamic height to work in webkit you need to set the width and height of images in the source. Usually works to only set the dimension of the first slide in the showcase. */
            speed_change:			Drupal.settings.awkward_showcase.speed_change, /* Set to true to prevent users from swithing more then one slide at once. */
            viewline:				Drupal.settings.awkward_showcase.viewline, /* If set to true content_width, thumbnails, transition and dynamic_height will be disabled. As for dynamic height you need to set the width and height of images in the source. */
            custom_function:		null /* Define a custom function that runs on content change */
        });
    });
})(jQuery);