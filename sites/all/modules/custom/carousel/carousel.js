(function($){
	Drupal.behaviors.owl = {
		attach: function(context, settings) {
			$('body').once('carousel', function(){
				var wrapperSelector = '.calendar-view .view-content';
				var itemSelector = '.calendar-item';

				var settings =
				{
					items: 6,
					navigation: true,					
				};
				var owl = $(wrapperSelector).owlCarousel(settings).data('owlCarousel');

				$('body').bind('item-loaded', function(event, triggerIndex)
				{
					owl.goTo(triggerIndex);
				});
			});

		}
	};

}(jQuery))