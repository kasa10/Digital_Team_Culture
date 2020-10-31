<!DOCTYPE html>
<html>
<head>
    <title>Рекомендательный сервис по контенту и активностям учреждений культуры</title>
    <link rel="stylesheet" type="text/css" href="style.css">
    <meta charset="UTF-8">
    <link href="https://fonts.googleapis.com/css2?family=Jost:wght@300;500;700&display=swap" rel="stylesheet">
</head>
<body>


<div class="top">
    <img class="logo" src="img/logo.png">

    <ul>
        <li><a href="index.php">Главная</a></li>
        <li><a href="afisha.php">Афиша</a></li>
        <li><a href="rek.php">Рекомендации</a></li>
    </ul>


    <a href=""><img style="position: relative; left: 1238px; top: -65px;" src="img/poisk.png"></a>
    <a href=""><img style="position: relative; left: 1301px; top: -67px;" src="img/RU.png"></a>

    <img style="position: inherit; left: 1369px; top: -35px;" src="img/ticket.png">


    <a href="#" class="lk">Личный кабинет</a>

</div>



<div class="rekn">

    <?php
    include "bd.php";



        $sql = mysqli_query($db, "SELECT Avtor,Name FROM rek WHERE ID='232'"); //Тут получать с формы или ввести ID
        while ($result = mysqli_fetch_array($sql)){
            echo ('<p> Автор:   '.$result[0].'</p>');
            echo ('<p> Название книги:   '.$result[1].'</p>');
            echo ('<div style="width: 60px; height: 60px;"> </div>');
        }



    ?>
</div>




</body>
</html>