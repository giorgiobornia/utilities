<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>

  <head>
  
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  
  <title> University - Department</title>
  
  
  <meta http-equiv="Description" name="Description" content="University - Department" />

  
  <meta http-equiv="Keywords" name="Keywords" content="University - Department" />
  
  <style type="text/css">
  
            .style1 {
                color: #FFFFFF;
            }
            
            .style2 {
                color: #FFFFFF;
                font-weight: bold;
            }
            
            .style3 {
                color: #000000;
            }
            
.auto-style1 {
   font-family: sans-serif;
 }
.auto-style2 {
	font-family: sans-serif;
	font-weight: normal;
}
.auto-style3 {
	font-style: normal;
	color: #000000;
}
.auto-style4 {
	font-weight: normal;
}
.auto-style5 {
	color: #FFFFFF;
	font-family: sans-serif;
}
.auto-style6 {
	font-family: sans-serif;
	margin-right: 0px;
}
  </style>
		
</head>




<body style="text-align: center; color: #000000;">

<div>
  <h1 class="auto-style2"> Event Title </h1>
  <h2><span class="auto-style2"> Event Date </span> <span class="auto-style2"><br /></span></h2>
</div>

<p>
 <span class="auto-style1" style="font-size: 12pt;">&nbsp;&nbsp;<br /> </span> 
 <span class="auto-style1"> Online Registration Form </span>
</p>

<form action="./send_email_and_collect_info_to_file.php" method="post" name="Event Registration">

<input class="auto-style1" type="hidden" value="Event" name="Form" />

<table style="width: 650;">

<tbody>
<tr>
<td>
<h4 class="auto-style2"> Please provide the following contact information: </h4>


<table style="width: 600;">
<tbody>
<tr>
<td class="auto-style5" align="right"><em class="auto-style3">First Name</em></td>
<td>
<input class="auto-style1" type="text" size="35" name="Contact_FirstName" />
</td>
<td class="auto-style5" align="right"><em class="auto-style3">Last Name</em></td>
<td width="253">
<input class="auto-style1" type="text" size="28" name="Contact_LastName" />
</td>
</tr>
<tr>
<td class="auto-style5" align="right"><em class="auto-style3">Institution</em></td>
<td><input class="auto-style1" type="text" size="35" name="Contact_Institution" /></td>
<td class="auto-style1" align="right">&nbsp;</td>
<td class="auto-style1" width="253">&nbsp;</td>
</tr>
<tr>
<td class="auto-style5" align="right"><em class="auto-style3">Email Address</em></td>
<td><input class="auto-style1" type="text" size="35" name="Contact_EmailAddress" /></td>
<td class="auto-style1" align="right">&nbsp;</td>
<td class="auto-style1" width="253">&nbsp;</td>
</tr>
</tbody>
</table>


<table style="width: 600;" border="0">
<tbody>
<tr>
<td class="auto-style1">Attendee Status</td>
<td><input class="auto-style1" type="radio" value="Undergraduate Student" name="Attendee_Status" /><span class="auto-style1">Undergraduate Student&nbsp;&nbsp;&nbsp;&nbsp; </span></td>
<td style="width: 110px;"><input class="auto-style1" type="radio" value="Graduate Student" name="Attendee_Status" /><span class="auto-style1">Graduate Student</span></td>
<td style="width: 90px;"><input class="auto-style1" type="radio" value="Post-Doc" name="Attendee_Status" /><span class="auto-style1">Post-Doc</span></td>
<td style="width: 90px;"><input class="auto-style1" type="radio" value="Professor" name="Attendee_Status" /><span class="auto-style1">Professor</span></td>
<td style="width: 90px;"><input class="auto-style1" type="radio" value="Other" name="Attendee_Status" /><span class="auto-style1">Other</span></td>
</tr>
</tbody>
</table>


</td>
</tr>
</tbody>

</table>

<p>
  <input class="auto-style1" type="submit" value="Submit Form" />
  <span class="auto-style1">&nbsp; &nbsp;&nbsp; &nbsp; &nbsp; &nbsp; </span> 
  <input class="auto-style1" type="reset" value="Reset" />
</p>

</form>

<p>&nbsp;</p>

</body>

</html>
