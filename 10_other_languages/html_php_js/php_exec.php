<?php
// Put this file in the Document Root of the PHP server
//how to run a php file in the browser from outside the Document Root
//I think the alternative is to set some Virtual Host for the PHP server
//Do
//http://localhost/php_exec.php?f={your_file_name}

$file = $_GET['f']; // After checking if it is set etc.
include $file;
?>
