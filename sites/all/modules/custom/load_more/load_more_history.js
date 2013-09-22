/**
 * @file
 * Defines an load_more plugin for the statehandler.
 */

(function ($) {
  Drupal.behaviors.load_more_history = {
    attach: function (context, settings) {

      // add the plugin to the stateHandler js object, aliasing it to "plugin" for simplicity here...
      var plugin = Drupal.settings.stateHandler.plugins['load_more'] = new StateHandlerPlugin();
      
      // Plugin weight controls the order that plugins are executed.
      plugin.weight = 10;
      
      /**
       * plugin.buildState will extend a State object from a URL. Other plugins 
       * may (will) access State before it is passed to History. Order of
       * operations is dictated by plugin weight.
       *  @param url: a url to derive a State object from.
       *  @param state: A State object that has been extended by other plugins.
       *  @return State: a modified State object containing plugin-specific data
       */
      plugin.buildState = function(State, url) {
        // Important: initialize the state Object if one doesn't already exist
        var State = State || {};

        // Set up the namespace for this plugin
        State.load_more = {};

        // Tack on what you need to, and return the State when you're done.
        State.load_more.url = url;
        State.load_more.title = document.title;

        // Pass off the extended/modified state object to other plugins for processing.
        return State;
      }
      
      /**
       * plugin.buildTitle builds (optionally overrides) a title from a state.
       * This will be used to update the page title in the browser.
       * For our load_more we return the randomData we set in buildState.
       * Order of operations is dictated by plugin weight.
       * Return null if your plugin shouldn't modify the title, alternatively,
       * use the default implementation of the Class by deleting this method assignment.
       *  @param State: a State object
       *  @return Title: a string to be appended to the title for the state
       */
      plugin.buildTitle = function(State) {

        return document.title;
      }
      
      /**
       * plugin.processState will be the guts of your plugin.
       * This will define what to do with the state data that is sent to it.
       * This will be invoked on back + forward and direct access/refresh.
       *  @param State: a fully built state object for your application to use
       *  @param url: the path of the current state, useful for deciding if your
       *    plugin should do something for this state or not.
       *    (automatically populated by Statehandler and History.js).
       */
      plugin.processState = function(State, url) {
        // Initial page loads will not contain State data, so dont do anything.
        if(JSON.stringify(State) == "{}") {
          return;
        }

        /**
         * You'll probably want to do some ajax stuff in here, and render it in 
         * a specific/classy manner, but we'll just stringify it for now and 
         * display it in main content as an load_more.
         */
      };



      /**
       * BEGIN jQuery EVENTS
       * Application State Triggers:
       * Set up your click handlers here... you may be interested in jQuery.on().
       * For our load_more, we will trigger state changes by links in the header
       */
 
      $("body").bind('item-loaded',function(event, trigger, response) {
        var url = 'test';
        // var url = $(this).attr('href'),
        
        title = $(this).attr('title');

        // Fire off the url and title to the StateHandler.
        //settings.stateHandler.pushState(url, title);
       
        // Return false to let plugins handle updating the page.
        return false;
      });

      /**
       * END jQuery EVENTS
       */
    }
  };
}(jQuery));
