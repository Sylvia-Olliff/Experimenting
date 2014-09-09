<?php
	session_start();
	//Verify that a user has logged in by verifying that the session variable user is not null  
	$test = $_SESSION['user'];
	if(is_null($test)){
		header("location:main_login.php");
	}

	//establish connection variables
	$host="localhost"; // Host name 
	$username="root"; // Mysql username 
	$password=""; // Mysql password 
	$db_name="test"; // Database name 
	$tbl_name="posts"; // Table name 


	//connect to database
	$db = mysqli_init();
	$db->real_connect($host, $username, $password, $db_name);

	if ($db->connect_errno) {
    	echo "Failed to connect to MySQL: (" . $db->connect_errno . ") " . $db->connect_error;
	}

	//Retrieve from members database the associated user id
	$myusername = $test;
	$sql="SELECT id FROM members WHERE username='$myusername'";	
	$result = $db->query($sql);

	$row = $result->fetch_row();
	
	//Clear variables for safe reuse
	unset($sql);
	

	//Check posts database for all posts associated with the user
	$sql="SELECT content FROM $tbl_name WHERE userID='$row[0]'";
	unset($result);
	unset($row);
	$result = $db->query($sql);

	$row = $result->fetch_row();

	//Establish all posts in an array
	for ($i=0; $i < count($row); $i++) { 
		$messages[$i] = $row[$i];
	}

	$_SESSION["messages"] = $messages;

	var_dump($_SESSION);

	//session_destroy();
?>