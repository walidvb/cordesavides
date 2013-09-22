<?php
/**
 * @file
 * Default container output for a AW Showcase node.
 */
?>
<div id="showcase" class="showcase">
  <?php foreach($items as $item): ?>
  <!-- Each child div in #showcase represents a slide -->
  <div class="showcase-slide">
    <!-- Put the slide content in a div with the class .showcase-content. -->
    <div class="showcase-content">
      <?php print $item["main"]; ?>
    </div>
    <?php if ($item["pager"]): ?>
    <!-- Put the thumbnail content in a div with the class .showcase-thumbnail -->
    <div class="showcase-thumbnail">
      <?php print $item['pager']['image']; ?>
      <!--<img src="images/01.jpg" alt="01" width="140px" />-->
      <!-- The div below with the class .showcase-thumbnail-caption contains the thumbnail caption. -->
      <div class="showcase-thumbnail-caption"><?php print $item['pager']['caption']; ?></div>
      <!-- The div below with the class .showcase-thumbnail-cover is used for the thumbnails active state. -->
      <div class="showcase-thumbnail-cover"></div>
    </div>
    <?php endif; ?>
    <?php if ($item["caption"]): ?>
    <!-- Put the caption content in a div with the class .showcase-caption -->
    <div class="showcase-caption">
      <?php print $item["caption"]; ?>
    </div>
    <?php endif; ?>
  </div>
  <?php endforeach; ?>
</div>
