(function ($) {
	Drupal.behaviors.cordesavides = {
		attach: function(context, settings){


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
			console.log();
			$blockTitle.addClass('clickable')
			.bind('click', function()
			{
				var title = $(this);
				var block = title.next()
				console.log(title);
				console.log(block);
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
			//Collapse all on small screens
			if($(window).height() >	600 && $(window).width() < 770)
			{
				$blockTitle.trigger('click');
			}
			else
			{
				$('.fcb-title').addClass('clickable').trigger('click');
			}
			$(window).resize(function(){
				if(($(window).height() < 600 && $(window).width() > 770) || $(window).width() > 770)
				{
					var block = $blockTitle.next();
					block.slideDown( function()
					{
						$blockTitle.removeClass('closed');
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
			})
		}
	}
}(jQuery))