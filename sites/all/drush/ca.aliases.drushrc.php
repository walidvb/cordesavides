<?php

	$aliases['local'] = array(
	  'root' => '/Users/Gaston/Sites/cordesavides',
	  'uri'  => 'http://localhost/cordesavides',
	 	  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%modules' => 'sites/all/modules',
    '%themes' => 'sites/all/themes',
    '%notfiles' => 'sites/all',
  )
	);

		
	$aliases['remote'] = array (  
	  'uri' => 'http://ca.vbbros.net/',
	  'root' => '/home2/vbbrosne/public_html/cordesavides',
	  'remote-user' => 'vbbrosne',
	  'remote-host' => 'vbbros.net',
	  //'remote-password' => 'Coudrette236',
	  	  'path-aliases' => array(
    '%files' => 'sites/default/files',
    '%modules' => 'sites/all/modules',
    '%themes' => 'sites/all/themes',
    '%notfiles' => 'sites/all',
  )
	);
