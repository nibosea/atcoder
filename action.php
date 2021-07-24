<html>
    <head> <title>検索結果</title>
    </head>
<h1> 検索結果（PHP action.php)</h1>
やあ！<br>
<?php echo htmlspecialchars($_POST['search']);?>を探しているみたいだね！！

<?php

/*$_POST['serach']が住所か郵便番号かを判定する*/
$zip = 1;
$addr = 2;
function get_type($var) {
  $length = strlen($var);
  // printf("var = %s </br>", $var);
  // printf("var string = %d </br>",$length);
  // 1 -> 郵便 || 2-> 住所
  if($length !== 7){
    /*7文字以外は住所判定*/
    return 2;
  } else {
    for($i = 0; $i < 7; $i++){
      if('0' <= $var[$i] or $var[$i] <= '9'){
        // ok
      } else {
        return 2;
      }
    }
    return 1;
  }
}

/*TODO PWの設定が必要*/
$link = mysqli_connect('localhost', 'shizutaro', '***********', 'CSexp1DB');
if ($link -> connect_errno){
/*database接続エラーの検出*/
    throw new RuntimeException('mysqli connection error: ' . $link->connect_error);
} else {
    //echo 'connect success';
    printf("<br/>");
}

/*入力された文字列が住所か郵便番号かの結果をjudgeに格納*/
$judge = get_type($_POST['search']);

/*形式に合わせてSQLを作成する*/
$sql = "";
if($judge == $zip){
  echo '郵便番号だよ</br>';
  $sql = "select * from zipShizuoka where zip = '".$_POST['search']."'";
} else {
  echo '住所だなあ';
  $sql = "select * from zipShizuoka where CONCAT(addr1,addr2,addr3) like '%".$_POST['search']."%'";
}

// print($sql); 完成したSQL文
print("<br/>"); /*改行はこれでも動く*/
if ($result = $link->query($sql)) {
    $row_cnt = $result -> num_rows;
    printf ("result set has %d rows</br>", $row_cnt);
    while ($row = $result->fetch_assoc()) {
        $name = $row["addr1"].$row["addr2"].$row["addr3"];
        echo $row["zip"].": ";
        echo $name."<br>";
    }
}


/*disconnect*/
$result->close();
$link->close();
?>
