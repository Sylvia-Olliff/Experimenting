<?php
	session_start();
	$test = $_SESSION['user'];
	if(is_null($test)){
		header("location:main_login.php");
	}
	header("location:main_menu.php");
?>