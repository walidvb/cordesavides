(function ($) {
	var pushState = false;
	var idCounter = 0;
	
	Drupal.behaviors.load_more = {
		attach: function(context, settings){
			var $settings = settings.load_more;
			var $mapping = settings.shared.mapping;

			var $view = $('.'+$settings.view_name);
			var $trigger = $('.'+$settings.item_name);
			var $targetContainerSelector = '.pane-node-content';
			var $facebookCommentsBoxSelector = '.pane-facebook-comments-box';
		//---------------------ajax calls
		var loadFrom = function (nid, triggerIndex){
			console.log('loadFrom run from ' + nid);
			var targetContainer = $($targetContainerSelector).addClass('load-more-loading');
			var ajaxSettings = 
			{
				url: settings.basePath + 'load_more/' + nid,
				success: function(response)
				{

					var content = $(response.node_content);
					console.log('ajax-response', response);

					$('.node', targetContainer).replaceWith(content);
					var script = content.script;
					$('head').append(script);
					$('body').trigger('item-loaded', triggerIndex, response);
					var title = window.document.title = response.node_title + ' | ' + settings.load_more.site_name;
					console.log('content before attaching behaviors', content);
					//Attach included scripts
					Drupal.attachBehaviors(content);
					console.log('content after attaching behaviors', content);

					//Fix easy-social
					twttr.widgets.load();
					gapi.plusone.go();
					FB.XFBML.parse()

					if(pushState)
					{
						History.pushState({
							nid: nid,
							triggerIndex: triggerIndex,
						}, title, '/' + settings.basePath + response.node_path);
						pushState = false;
					}
					targetContainer.removeClass('load-more-loading');
				},
				error: function(xhr,status,error)
				{
					console.log(xhr);
					console.log(status);
					console.log(error);
					targetContainer.removeClass('load-more-loading');
				}
			}

			$.ajax(ajaxSettings);
		}



		$trigger.once('load_more', function(){
			var $this = $(this);
			$this.addClass('clickable')
			.bind('click', function(){
				var nid = $mapping[$this.index()];
				pushState = true;
				loadFrom(nid, $this.index());
			});
			$this.find('a').bind('click', function(e){
				e.preventDefault();
			});
		});

		$('body').once('load-more', function(){
			History.Adapter.bind(window,'statechange',function(){
				var State = History.getState();
				pushState = false;
				//loadFrom(State.data.nid, State.data.triggerIndex);
				console.log("loaded from", State);
			});
			History.replaceState({'nid': settings.shared.nid, }, document.title, window.location.href);
		});
	}
}
}(jQuery))