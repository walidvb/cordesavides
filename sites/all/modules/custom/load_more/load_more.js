var first = true;
(function ($) {
	var pushState = false;
	var current = 0;
	Drupal.behaviors.load_more = {
		attach: function(context, settings){
			var $settings = settings.load_more;
			var $mapping = $settings.mapping;

			var $view = $('.'+$settings.view_name);
			var $trigger = $('.'+$settings.item_name);
			var $targetContainerSelector = '.pane-node-content';
			var $facebookCommentsBoxSelector = '.pane-facebook-comments-box';
		//---------------------ajax calls
		var loadFrom = function (nid, triggerIndex){
			console.log('loadFrom run from ' + nid);
			
			if(current != nid)
			{
				var targetContainer = $($targetContainerSelector).addClass('load-more-loading');
				var ajaxSettings = 
				{
					url: settings.basePath + 'load_more/' + nid,
					success: function(response)
					{

						var content = $(response.node_content);
						$('.node', targetContainer).replaceWith(content);
						var script = content.script;
						$('head').append(script);
						$('body').trigger('item-loaded', triggerIndex, response);
						var title = window.document.title = response.node_title + ' | ' + settings.load_more.site_name;
						$('h1').html(response.node_title);
					//Attach included scripts
					Drupal.attachBehaviors(content);
					current = nid;
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
		$(this).bind('load-from', function(e, data){
			loadFrom(data.nid, data.index);
		});

		History.Adapter.bind(window,'statechange',function(){
			//console.log('first is ' , first);
			if(!first)
			{
				//console.log('will change');
				var State = History.getState();
				pushState = false;
				loadFrom(State.data.nid, State.data.triggerIndex);
				//console.log("State", State);
			}
			first = false;

		});
		//console.log(settings.load_more.nid)
		History.replaceState({'nid': settings.load_more.nid, 'triggerIndex': settings.load_more.mapping.indexOf(settings.load_more.nid)}, document.title, window.location.href);
	});
}
}
}(jQuery))