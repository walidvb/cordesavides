(function ($) {
	Drupal.behaviors.cordesavides = {
		attach: function(context, settings){

			//masonry the facebook albums
			$('.facebook-album-image img').once('cordesavides', function(){
				$(this).hide().load(function(){
					var m = new Masonry('.facebook-album', { itemSelector: '.facebook-album-image'});
					$(this).fadeIn();
				})
			});
			//Add Comments title as trigger for the box
			var $commentTitle = $('.pane-facebook-comments-box .pane-title', context);
			$commentTitle.addClass('clickable closed')
			.bind('click', function()
			{
				var $this = $(this);
				$this.next().slideToggle( function()
				{
					var $comments = $(this);
					if(!$this.toggleClass('closed').hasClass('closed'))
					{
						$('html, body').animate(
						{
							scrollTop: $comments.offset().top,
						});
					};
				});
			})
			.next().slideToggle(function()
			{
				$commentTitle.addClass('clickable closed')
			});
		}
	}
}(jQuery))