Awkward Showcase Drupal Module
======================

1. How to install Awkward Showcase
2. How to use Awkward Showcase


1. How to install Awkward Showcase
--------------------------

1. Make sure the Libraries module is installed.
   You can download it from it's project page at
   http://drupal.org/project/libraries

2. Download the Awkward Showcase Javascript library from
   http://www.awkwardgroup.com/download/?download=showcase.1.1.1
   and extract the Awkward Showcase folder into your /sites/all/libraries/ directory.
   OR JUST USE DRUSH! drush awshowcase will download, unzip and put the library in the right place!

3. Extract the Awkward Showcase Drupal module into your /sites/all/modules/ directory and
   enable it (module "Awkward Showcase" in category "Other").

4. While not a dependency, you may want to enable the Field Entity module so you can set
   the captions on the pager and main image elements when using the field display formatter.
   This does not apply when using Awkward Showcase with views as you will have a choice of
   using any field, or combination of fields, as captions there.


2. How to use Awkward Showcase
----------------------

There are several approaches of building a Awkward Showcase image gallery:

a) Using Awkward Showcase with an image/media field in a node:
   This is the classic and easiest way of creating a Awkward Showcase gallery.
   You create an image field and upload multiple images to it.

    1. Create a new content type for your gallery pages or alter an existing one.

    2. Add a new or existing field of type "Image" on the "Manage Fields" tab of the content type.

    3. Go to the "Manage Display" page of your content type. Set the "Format" of your image field to "Awkward Showcase".
       To the right of the select box you can now choose from a set of predefined layouts as seen in the Awkward
       Showcase Demos or select Custom and have complete control over all of the settings for the showcase.

    4. Create a new page of your content type, upload some images and view the node.
       The images should now be rendered in a nice Awkward Showcase gallery.

b) Using Awkward Showcase in a view of image fields:
   List any node/gallery with image fields using views. Use any filter you like (e.g. taxonomy) to structure galleries.
   This description contains only the most basic steps.

    1. Create a view of nodes with an image field. On the "Fields" panel in views set the display to "Fields".

    2. On the "Format" Panel choose Awkward Showcase as your views display format.

    3. Click the "Settings" link in the Format panel. In the Awkward Showcase fieldset choose the layout options from
       the presets or choose custom to handle all of the settings yourself and choose which fields should be used for
       the main content, pager, and captions.

    4. Have a look at your view, it should get rendered as a Awkward Showcase now.
