(function ($) {

	Drupal.behaviors.cordesavides = {
		attach: function(context, settings){

			//-------------Keyboard Event
			var keyTimer;
			var switchSlide = function(prevNext){
					clearTimeout(keyTimer);
					var origin = $('.owl-item.calendar-item-active');
					var target = origin.removeClass('calendar-item-active')[prevNext]().addClass('calendar-item-active');
					console.log(origin)
					if(!target.length)
					{
						origin.addClass('calendar-item-active');
					}
					else
					{
						if(!target.hasClass('active'))
						{
							$('body').trigger('owl-goto', target.index());
						}
						keyTimer = setTimeout(function(){target.trigger('click');}, 600);
					}
			};

			$('body').once('mousetrap', function(){
				Mousetrap.bind('left', function(){
					switchSlide('prev');
				});
				Mousetrap.bind('right', function(){
					switchSlide('next');
				});
			})
			//-------------Content
			//masonry the facebook albums
			$('.facebook-album-image img').once('cordesavides', function(){
				$(this).wrapAll('<div class="facebook-album-wrapper"/>');
				$(this).hide().load(function(){
					var m = new Masonry('.facebook-album-wrapper', { itemSelector: '.facebook-album-image'});
					$(this).fadeIn();
				})
			});
			//Add Comments title as trigger for the box
			var $blockTitle = $('.h2', context);
			$blockTitle.once('myJS', function(){
				$(this).addClass('clickable')
				.bind('click', function()
				{
					var title = $(this);
					var block = title.next()

					block.slideToggle( function()
					{
						if(!title.toggleClass('closed').hasClass('closed'))
						{
							$('html, body').animate(
							{
								scrollTop: block.offset().top,
							});
						};
					});
				})
			});

			//Collapse all on small screens
			if($(window).width() < 770)
			{
				$blockTitle.trigger('click');
			}
			else
			{
				console.log('clicked on fb');
				$('.fcb-title', context).trigger('click');
			}
			//$(window).once('myJS', function(){
				$(window).resize(function(){
					if($(window).width() >= 768)
					{
						var concernedBlocks = $blockTitle.not('.fcb-title');
						var block = concernedBlocks.next();
						block.slideDown( function()
						{
							concernedBlocks.removeClass('closed');
						});
					}
					else
					{
						$blockTitle.addClass('clickable');
						var block = $blockTitle.next();
						block.slideUp( function()
						{
							$blockTitle.addClass('closed');
						});
					}
				});
			//});
		}
	}
}(jQuery))