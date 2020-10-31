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


<img style="position: relative; width: 100%; height: 235px; left: 0px; top: 2px;" src="img/19.png">




<div class="main">

    <a href="" class="filtr">Открыть весь фильтр</a>

    <form>
        <p><input type="checkbox" name="" value=""> Библиотеки</p>
        <p><input type="checkbox" name="" value=""> Театры</p>
        <p><input type="checkbox" name="" value=""> Музеи</p>
        <p><input type="checkbox" name="" value=""> Концерты</p>
        <p><input type="checkbox" name="" value=""> Выставки и экскурсии</p>
        <p><input type="checkbox" name="" value=""> Квесты</p>
        <p><input type="checkbox" name="" value=""> Спорт</p>
        <p><input type="checkbox" name="" value=""> Родителям и детям</p>
        <p><input type="checkbox" name="" value=""> Кино</p>
    </form>



    <a href="" class="callend"><u>Ближайшие мероприятия</u></a>

    <a href="" class="callend" style="left: 458px;">Календарь</a>

    <a href="" class="callend" style="left: 1750px;">На карте</a>


    <?php
    include "bd.php";

    for ($i = 1; $i <= 5; $i++) {

        $sql = mysqli_query($db, "SELECT TEXT FROM news WHERE ID=$i");
        $result = mysqli_fetch_array($sql);


        echo ('<div class="block"><img src="img/news/'.$i.'.jpeg"> 
<p>'.$result[0].'</p>
</div>');
    }

    ?>


</div>



</body>
</html>