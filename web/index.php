<!DOCTYPE html>
<html>
<head>
	<title>Рекомендательный сервис по контенту и активностям учреждений культуры</title>
	<link rel="stylesheet" type="text/css" href="style.css">
	<meta charset="UTF-8">
</head>
<body>


<div class="top">
	
<p>TEST</p>
</div>


<div class="main">

<?php
for ($i = 1; $i <= 4; $i++) {
    echo ('<div class="block"><img src="img/'.$i.'.jpeg"> </div>');
	}
?>


</div>



</body>
</html>