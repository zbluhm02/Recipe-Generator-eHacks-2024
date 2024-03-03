<?php
//If you touch this is will literally break everything.
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    echo $_POST["value"];
    if (isset($_POST['option'])) {
        $selectedOption = $_POST['option'];
    }}

setcookie('option', $selectedOption, time() + 3600, '/');
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
            
        </div>
    </body>

    <?php
        $year =  date('Y');
    ?>
    <br>

    <footer class="w3-panel w3-center w3-text-gray w3-small">
        
    </footer>
</html>

<?php
function displayCenteredProgressBarAndRedirect($delay, $url) {
    echo "<div style='text-align: center;'>
            <img src='image/loadingScreen.gif' alt='Loading...' width='400' height='400' style='margin-bottom: 20px;'><br>
            <progress id='progress-bar' value='0' max='100' style='width: 50%;'></progress>
          </div>";
    echo "<meta http-equiv='refresh' content='$delay;url=$url'>";
    echo "<script>
            var progressBar = document.getElementById('progress-bar');
            var interval = setInterval(function() {
                if (progressBar.value >= 100) {
                    clearInterval(interval);
                    window.location.href = '$url';
                } else {
                    progressBar.value++;
                }
            }, ".($delay * 1000 / 100)."); // Divide by 100 for 100 steps
          </script>";
}


$delay = 10; // 10 seconds delay
$url = "recipe.php";
displayCenteredProgressBarAndRedirect($delay, $url);

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
            <p> A delicious recipe is being created right now. </p>
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


