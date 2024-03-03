<?php
$test = $_COOKIE['option'];
// Define the base folder path
$baseFolder = 'files/';

// Get the value of the $test variable (assuming it's set elsewhere)


// Depending on the value of $test, select the folder
switch ($test) {
    case 1:
        $folder = 'dessert';
        break;
    case 2:
        $folder = 'entree';
        break;
    case 3:
        $folder = 'appetizer';
        break;
    default:
        echo "Invalid input";
        exit;
}

// Get a list of files in the selected folder
$files = scandir($baseFolder . $folder);

// Remove "." and ".." from the list
$files = array_diff($files, array('.', '..'));

// Select a random file from the list
$randomFile = $files[array_rand($files)];

// Get the content of the selected file
$content = file_get_contents($baseFolder . $folder . '/' . $randomFile);

// Output the content
echo '<div style="text-align: center;">';
echo $content;
echo '</div>';
?>

<html lang="en">
    <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
    <style>
        body {
        background-image: url("image/background.jpg");
        background-size: cover;
        content:"";
	    position:fixed;
	    left:0;
	    top:0;
	    right:0;
	    bottom:0;
	    z-index:-1;
	    display:block;
        background-repeat: no-repeat;
        }

        .image input[type="image"]{
            
            margin-left: 80px;
            text-align: center;
            
            box-shadow: 15px 15px rgba(135, 0, 0, 1);
           
        }

        .banner{
            
            margin-bottom: 50px;
            text-align: center;
           
        }

        .fancy{
            font-family: "Sofia", sans-serif;
            font-size: 40px;
        }

    </style>

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Trash Taste Recipes</title>
        <link rel="icon" type="image/x-icon" href="image/logo.ico">
        <link rel="stylesheet" href="https://fonts.googleapis.com/css?family=Sofia">
    </head>

    <body>
        <div class = "w3-center fancy">
            <a href = "home.php"> <img src = "rth2.png" width="300"></a>
        </div>
    </body>

    <?php
        $year =  date('Y');
    ?>
    <br>

    <footer class="w3-panel w3-center w3-text-gray w3-small">
        
    </footer>
</html>

