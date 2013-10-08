var owl;
(function($){
	Drupal.behaviors.owl = {
		attach: function(context, settings) {
			$('body').once('carousel', function(){
				var wrapperSelector = '.calendar-view .view-content';
				var itemSelector = '.calendar-row';

				var owlSettings =
				{
					items: 3,
					navigation: true,
					addClassActive: true,
					scrollPerPage: true,
					paginationSpeed: 1200,
					itemsDesktop : [1199,3],
					itemsDesktopSmall : [980,2],
					itemsTablet: [768,2],
					itemsMobile : [479,1],
				};
				owl = $(wrapperSelector).owlCarousel(owlSettings).data('owlCarousel');
				var currentIndex = settings.shared.mapping.indexOf(settings.shared.nid);

				owl.goTo(currentIndex);
				var className = 'calendar-item-active';
				$('.owl-item:nth-child(' + (currentIndex+1) + ')').addClass(className);
				$('.owl-item').addClass('col-md-2');

				$('body').bind('item-loaded', function(event, triggerIndex)
				{
					$('.'+className).removeClass(className);
					$('.owl-item:nth-child(' + (triggerIndex+1) + ')').addClass(className);
					owl.goTo(triggerIndex);
					$(this).trigger('viewChange', true);
				});

				//-------------Body

				var $controls = $('.owl-controls').addClass('col-md-8 col-sm-6');
				var showText = 'Afficher toutes les dates';
				var hideText = 'Retour à la vue normale';
				var $allDates = $('<span class="owl-calendar-trigger col-md-4 col-sm-6 col-xs-12 pull-right"><span  class="visible-xs help">Glisser ou </span><a class="link" href="#"">'+ showText +'</a></span>');
				var $calendar = $('.owl-wrapper');
				$allDates.insertAfter($controls);
				$allDates.bind('click', function(e){
					e.preventDefault();
					var isOpen = $('.owl-carousel').hasClass('open');
					$(this).trigger('viewChange', isOpen);
				});

				$('body').bind('viewChange', function(e, isOpen){
					if(isOpen)
					{
						$('body, html').animate(
						{
							scrollTop: $(this).scrollTop() > $('.owl-wrapper').offset().top ? $('.owl-wrapper').offset().top : $(this).scrollTop(),
						}, 600,
						function()
						{	
							$('.owl-carousel').removeClass('open');
						});
					}
					else
					{
						$('.owl-carousel').addClass('open');
					}
					$('a', $allDates).text(!isOpen ? hideText : showText);
				});
			});
		}
	}
}(jQuery))