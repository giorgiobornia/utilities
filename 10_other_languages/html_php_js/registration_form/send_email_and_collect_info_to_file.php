<html>

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title> Registration handler</title>
</head>

<body>



<?php

////////////// SQL ////////////
//require_once("./database_connect.php");  
//this is if you wanted to create a table in a SQL database
//For now, we just do a log file to collect the data
//////////////////////////

// Configurable parameters:
 $file_to_store_regs="./registration.log"; //this doesn't seem to be working, maybe they don't allow to write files

	$toaddress  = "nome.cognome@site";
	$mailsubject = "Registration";
	$referringpage = "Registration Form";
	$referringURL = "https://my.website";
// End of configurable parameters

 
// collect info ---------------------
        $return_html_c = "<br> \n";
	$displaymsg = "";  //print_r($_POST,true)
        $displaymsg = $displaymsg .
                      "<p> This information was received from IP: " .
                      @$_SERVER['REMOTE_ADDR'] .
                      $return_html_c;


	foreach ($_POST as $key => $value) {
		$displaymsg = $displaymsg . "$key: $value" . $return_html_c; 
		};
//---------------------


//---------------------
//print to file (past)
	$myfile      = fopen ($file_to_store_regs, "a");
	               fwrite($myfile, $displaymsg);  //fputcsv was another option 
//print to a database table (future)
//---------------------


//---------------------
//send email
        $mail_status = mail($toaddress, $mailsubject, $displaymsg);
	
	if( $mail_status ) {
            echo $displaymsg;
            echo "<p> Contact $toaddress if this is incorrect <br>";
	} 
        else {
		echo "<p> Something is wrong. Your information could not be sent. <br>";
                echo "<p> Contact $toaddress <br>";
	};


//	if( strlen($toaddress)>0 ) {
//	    mail($toaddress, $mailsubject, $mailmsg);
//	};
//---------------------

		
echo "<p> Return to <a href=\"$referringURL\"> $referringpage </a>";

?>



</body>

</html>
