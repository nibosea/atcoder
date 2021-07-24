<!DOCTYPE html>
<html lang="ja">
    <meta charset="UTF-8">
    <head>
        <title>実装Ｃの結果</title>
    </head>
    <body>
<?php
//実装Ｃをこのファイルに実装してください。
$servername = "localhost";
$username = "haru";
$password = "V2vQaQYf";
$dbname = "CSexp1DB";

$conn = new mysqli($servername, $username, $password, $dbname);

if($conn->connect_error){
    die("Connection failed: " . $conn->connect_error);
}

if(isset($_REQUEST["tag"])){
    $sql = "SELECT * FROM tag 
            INNER JOIN geotag on tag.id = geotag.id
            WHERE tag like '" .$_REQUEST["tag"] . "'
            ORDER BY geotag.time desc LIMIT 100";
}

if($result = $conn->query($sql)){
    echo "撮影時刻"." ". "緯度"." "."経度"." "."写真"."<br>";
    while($row = $result->fetch_assoc()){
        $url = $row["url"];
        $img = file_get_contents($url);
        $enc_img = base64_encode($img);
        $imginfo = getimagesize('data:application/octet-stream;base64,' . $enc_img);

		echo '<img src="data:' . $imginfo['mime'] . ';base64,'.$enc_img.'">';

    }
    $result->close();
}else{
    echo $conn->error;
}

?>
    </body>
</html>
