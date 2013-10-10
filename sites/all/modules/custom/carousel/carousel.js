(function($){
	Drupal.behaviors.owl = {
		attach: function(context, settings) {
			$('body').once('carousel', function(){
				var wrapperSelector = '.calendar-view .view-content';
				var itemSelector = '.calendar-row';

				var timer;
				var owlSettings =
				{
					items: 3,
					navigation: true,
					addClassActive: true,
					scrollPerPage: true,
					paginationSpeed: 1200,
					itemsDesktop : [1199,3],
					itemsDesktopSmall : [980,2],
					itemsTablet: [767,2],
					itemsMobile : [479,1],
					afterMove: function(elem, o)
					{
						var activeItem = $('.owl-item.active');
						if( activeItem.size() == 1 )
						{
								clearTimeout(timer);
								timer = setTimeout(function(){
								console.log('click triggered');
								var i = activeItem.index();
								var nid=settings.load_more.mapping[i];
								console.log('carousel', nid, i);
								data = {
									'nid': nid,
									'index': i,
								}
								$('body').trigger('load-from', data);
							}, 800);
						}
					},
				}

				var owl = $(wrapperSelector).owlCarousel(owlSettings).data('owlCarousel');
				var currentIndex = settings.load_more.mapping.indexOf(settings.load_more.nid);

				owl.goTo(currentIndex);

				$('body').bind('owl-goto', function(e, index){
					owl.goTo(index);
				});
				var className = 'calendar-item-active';
				$('.owl-item:nth-child(' + (currentIndex+1) + ')').addClass(className);
				$('.owl-item').addClass('col-md-2');

				$('body').bind('item-loaded', function(event, triggerIndex)
				{
						$('.'+className).removeClass(className);
						$('.owl-item:nth-child(' + (triggerIndex+1) + ')').addClass(className);
						if(owl.currentSlide != triggerIndex)
						{
							owl.goTo(triggerIndex);
						}
						$(this).trigger('viewChange', true);
						$('#allDates, .make-switch').bootstrapSwitch('setState', false);
				});

				//-------------Body

				var $controls = $('.owl-controls');
				var showText = 'Afficher toutes les dates';
				var hideText = 'Retour à la vue normale';

				var $allDates = $('<input id="allDates" type="checkbox"/>')
					.prependTo($('.owl-carousel'))
					.wrap('<div class="pull-right col-md-4 col-sm-6 col-xs-12 owl-calendar-trigger" ><div class="make-switch" data-off="danger" data-on-label="o" data-off-label="a"/></div>');
				$('.owl-controls').addClass('col-md-8 col-sm-6')
					.prependTo($('.owl-carousel'));
					
				var bigWidth = $('.owl-wrapper').width();
					//Bind to the switch moving
					$('body').bind('switch-change', function(e, data){
						if(!data.value)
						{
							$('body, html').animate(
							{
								scrollTop: $(this).scrollTop() > $('.owl-wrapper').offset().top ? $('.owl-wrapper').offset().top : $(this).scrollTop(),
							}, 600,
							function()
							{	
								$('.owl-wrapper').animate(
								{
									'width': bigWidth
								},
								function(){setTimeout( function(){$('.owl-carousel').removeClass('open');}, 800);
							});
							});
						}
						else
						{
							$('.owl-wrapper').animate(
							{
								'width': $('.owl-carousel').width()+1
							},
							function(){$('.owl-carousel').addClass('open');
						});
						}
						$('a', $allDates).text(data.value ? hideText : showText);
					});
				});
}
}
}(jQuery))