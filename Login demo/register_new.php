<?php

	//Create connection variables and hold all output until this portion of the script finishes.
	ob_start();
	$host="localhost"; // Host name 
	$username="root"; // Mysql username 
	$password=""; // Mysql password 
	$db_name="test"; // Database name 
	$tbl_name="members"; // Table name 

	// Connect to server and select database. Uses object method instead of real_connect
	$mysqli = new mysqli($host, $username, $password, $db_name);
	if ($mysqli->connect_errno) {
    	echo "Failed to connect to MySQL: (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
	}

	//define variables for the creation of a new user
	$newuser = $_POST['newusername'];
	$newpass = $_POST['newpassword'];
	$verifyPass = $_POST['verifypassword'];

	//make sure that both passwords match before sending
	if ($newpass !== $verifyPass) {
		echo "Passwords did not match";
		header("location:register_new_form.php");
	}

	//Helps prevent MSQL injection
	$newuser = stripslashes($newuser);
	$newpass = stripslashes($newpass);

	//encrypt the password by hashing before adding to the database
	$newpass = password_hash($newpass, PASSWORD_DEFAULT);

	//add new user to the database
	$sql = "INSERT INTO `test`.`members` (`username`, `password`) VALUES ('$newuser', '$newpass')";
	$result = $mysqli->query($sql);
	ob_end_flush(); //Let the data flow

	header("location:main_login.php"); //Redirect back to the main login for the new user to log in

?>