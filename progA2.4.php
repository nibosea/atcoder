<?php
//エラーを表示してくれる
ini_set('display_errors', true);
error_reporting(E_ALL);
?>
<!DOCTYPE html>
<html lang="ja">
<head>
<title>実装Ａの結果</title>
</head>
<body>
<?php
$start = time();
$INDEX_ID = 0;
$INDEX_TIME = 1;
$INDEX_IDO = 2;
$INDEX_KEIDO = 3;
$INDEX_URL = 4;
$tag = isset($_REQUEST["tag"]) ? $_REQUEST["tag"] : "false";

//実装Ａをこのファイルに実装してください。
$filename = "tag.csv";
$file=fopen($filename,"r");
//$file2=fopen($filename2,"r");
ini_set('max_execution_time',300);// <- 秒数300マックスつってんのに余裕で1200秒実行する．なんだこいつ


$A = array(); // tagが検索結果と一致したとき，画像IDをAに入れる
$hit = 0;
while(!feof($file)){
  $csv = fgets($file); // tag.csv
  $str = explode(",", $csv);
  if(count($str) == 1) continue; // 最終行の事故を防ぐ
  $now = substr($str[1],0,-1); // 現在行のtag名をnowに格納
  if($now != $tag) continue; //検索結果tagと一致しているか
  $hit = $hit + 1;
  array_push($A, $str[0]);
  // tagが検索結果にヒットした時だけ配列に格納する
  unset($str);
}
fclose($file);
// 何個マッチしたか見てみる
print_r($A);
print_r($hit);
$end = time();
print_r('処理時間 = '.($end - $start).'秒<br />');

$filename2 = "geotag.csv";
$file2=fopen($filename2,"r");
$index = 0; // A[index]まで見た
$get = 0;
$B = array();
while(!feof($file2)){
  $csv = fgets($file2); // geotag.csv
  $str = explode(",", $csv);
  if(count($str) == 1) continue; // 最終行の事故を防ぐ
  $now = $str[$INDEX_ID];
  if($now != $A[$index]) {
    continue;
  }
  //print_r($now.':<br />');
  $index = $index+1;
  if($hit <= $index) break;
  // HIT!!! nowの画像出力せい！
    $ps = array($str[$INDEX_TIME], $str[$INDEX_ID], $str[$INDEX_IDO], $str[$INDEX_KEIDO], $str[$INDEX_URL]);
  array_push($B, $ps);
  $get++;
  unset($str);
}
fclose($file2);
$end = time();
print_r('2つのファイル全部見るのにかかった処理時間 = '.($end - $start).'秒<br />');
$INDEX_TIME = 0;
$INDEX_ID = 1;
function date_sort($a, $b) {
    return strtotime($b) - strtotime($a);
}
// ソートしたい要素の値を配列に入れる
foreach ($B as $photo => $Detail) {
  $ArrDate[] = $Detail[$INDEX_TIME];
}

// ソートする
array_multisort($ArrDate, SORT_ASC, SORT_NUMERIC,
$B);

//var_dump($B);
//usort($B, "date_sort");
//arsort($B);
$end = time();
print_r('SORT処理時間 = '.($end - $start).'秒<br />');
//echo "bunbun";
//print_r($B);
$get--;
// これだと，$getが100以上の時，Worst古い100の中で新しい順に表示されてしまう．
$cnt=0;
for($i = $get; $i >= 0; $i--){
  $url = $B[$i][$INDEX_URL];
  $img = file_get_contents($url);
  $enc_img = base64_encode($img);
  $imginfo = getimagesize('data:application/octet-stream;base64,' . $enc_img);
  echo '<img src="data:' . $imginfo['mime'] . ';base64,'.$enc_img.'">';
  echo "<br />";
  print("(緯度,経度) = (".$B[$i][$INDEX_IDO].",".$B[$i][$INDEX_KEIDO].")");
  print(",撮影時刻:".$B[$i][$INDEX_TIME]."<br />");
  if($i % 10 == 0) print("今は".($get - $i +1)."枚目の出力やで" ."<br />");
  $cnt++;
  if($cnt >= 100) break;
}
$end = time();
print_r('終わるまでの処理 = '.($end - $start).'秒<br />');
//以下はダミーコードです。
if(isset($_REQUEST["tag"])){
  //echo "[Program A] Input tag = [".$_REQUEST["tag"]."]";
}else{
  echo "[Program A] Please input a tag.";
}
?>
</body>
</html>
