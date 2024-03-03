<?php
?>

<!DOCTYPE html>
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

        .image{
            
            margin-left: 80px;
            text-align: center;
            
            box-shadow: 15px 15px rgba(135, 0, 0, 1);
           
        }

        .banner{
            
            margin-bottom: 50px;
            text-align: center;
           
        }

        .button-container {
            display: flex;
            flex-direction: row;
            
        }

    </style>

    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>Trash Taste Recipes</title>
        <link rel="icon" type="image/x-icon" href="image/logo.ico">
    </head>

    <body>
        <div class="banner">
            <img src="image/banner.jpg" alt="Description of the image" width="1550" height="170">
        </div>

        <div class="w3-center text button-container">
           
            <form action="loading.php" method="POST">
                <input type="hidden"  name="option" value="3"/>
                <input type="image" src="image/appetizer.jpg" class="w3-round image" alt="Option 1" width="400" height="500">
            </form>
            <form action="loading.php" method="POST">
                <input type="hidden"  name="option" value="2"/>
                <input type="image" src="image/entree.jpg" class="w3-round image" alt="Option 2" width="400" height="500">
            </form>
            <form action="loading.php" method="POST">
                <input type="hidden"  name="option" value="1"/>
                <input type="image" src="image/dessert.jpg" class="w3-round image" alt="Option 3" width="400" height="500">
            </form>
        </div>  
    </body>

    <?php
        $year =  date('Y');
    ?>

    <br>
    <footer class="w3-panel w3-center w3-text-gray w3-small">
        &copy; <?php echo $year; ?> Syntax Samurai
    </footer>
</html>