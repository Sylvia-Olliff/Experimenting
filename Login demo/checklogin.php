<?php
	
	include 'connection.php';
	//Create connection variables and hold all output until this portion of the script finishes.
	ob_start(); 

	$con = new connect("test","members");
	/*
	$host="localhost"; // Host name 
	$username="root"; // Mysql username 
	$password=""; // Mysql password 
	$db_name="test"; // Database name 
	$tbl_name="members"; // Table name 
	*/

	//check if the user selected to register as a new user and redirect
	if($_POST['New'] === 'New User') {
		header("location:register_new_form.php");
	}

	// Connect to server and select database.
	$db = mysqli_init();
	$db->real_connect($con->getHost(), $con->getUsername(), $con->getPassword(), $con->getDb_name());
	if ($db->connect_errno) {
    	echo "Failed to connect to MySQL: (" . $db->connect_errno . ") " . $db->connect_error;
	}

	// Define $myusername and $mypassword 
	$myusername=$_POST['myusername']; 
	$mypassword=$_POST['mypassword']; 

	// To protect MySQL injection
	$myusername = stripslashes($myusername);
	$mypassword = stripslashes($mypassword);	

	$tbl_name = $con->getTbl_name();
	//retrieve the hashed password from the database
	$sql="SELECT password FROM $tbl_name WHERE username='$myusername'";
	$result = $db->query($sql);

	$row = $result->fetch_row();

	//check if what the user entered matched what is stored in the database
	if(password_verify($mypassword, $row[0])) {
		// Register $myusername and redirect to file "login_success.php"
		session_start();
		$_SESSION['user'] = $myusername;
		header("location:login_success.php");
	}
	else {
		echo "Wrong Username or Password";
	}
	
	ob_end_flush(); //Let the data flow
?>