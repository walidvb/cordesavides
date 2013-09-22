(function($){
	Drupal.behaviors.owl = {
		attach: function(context, settings) {
			$('body').once('carousel', function(){
				var wrapperSelector = '.calendar-view .view-content';
				var itemSelector = '.calendar-item';

				var owlSettings =
				{
					items: 6,
					navigation: true,					
				};
				var owl = $(wrapperSelector).owlCarousel(owlSettings).data('owlCarousel');
				console.log(settings);
				var currentIndex = settings.shared.mapping.indexOf(settings.shared.nid);
				owl.goTo(currentIndex);
				$('body').bind('item-loaded', function(event, triggerIndex)
				{
					owl.goTo(triggerIndex);
				});
			});

		}
	};

}(jQuery))