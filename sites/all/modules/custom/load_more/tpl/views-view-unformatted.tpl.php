<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
dpm('tpl was used');	
?>
hello
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?> 
    <?php if ($attributes_array[$id]) { print ' ' . $attributes_array[$id]['#name'] . '="' . $attributes_array[$id]['#value'] .'"';  } ?>
>
    <?php print $row; ?>
  </div>
<?php endforeach; ?>