(function($){
	Drupal.behaviors.owl = {
		attach: function(context, settings) {
			$('body').once('carousel', function(){
				var wrapperSelector = '.calendar-view .view-content';
				var itemSelector = '.calendar-row';

				var owlSettings =
				{
					items: 6,
					navigation: true,
					itemsDesktop : [1199,8],
				    itemsDesktopSmall : [980,6],
				    itemsTablet: [768,4],
				    itemsMobile : [479,2],
				};
				var owl = $(wrapperSelector).owlCarousel(owlSettings).data('owlCarousel');
				var currentIndex = settings.shared.mapping.indexOf(settings.shared.nid);

				owl.goTo(currentIndex);
				var className = 'calendar-item-active';
				$('.owl-item:nth-child(' + currentIndex+1 + ')').addClass(className);
				$('.owl-item').addClass('col-md-2');

				$('body').bind('item-loaded', function(event, triggerIndex)
				{
					console.log($('.owl-item:nth-child(' + triggerIndex+1 + ')'), triggerIndex);
					$('.'+className).removeClass(className);
					$('.owl-item:nth-child(' + triggerIndex+1 + ')').addClass(className);
					owl.goTo(triggerIndex);
				});
			});

		}
	};

}(jQuery))