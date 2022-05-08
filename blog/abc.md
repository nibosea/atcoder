# AtCoder 解いた問題一覧
## 他記事へのリンク
- [自己紹介のページ](https://iloveconviniboshi.hatenablog.com/entry/2020/03/25/172818);
- [読書備忘録](https://iloveconviniboshi.hatenablog.com/entry/2020/03/23/152828)
- [アルゴリズム,データ構造を学べるサイトまとめ](https://iloveconviniboshi.hatenablog.com/entry/2020/03/04/192631)

## 更新情報
2021/08/08
## 前書き

AtCoderで解いていった問題の解き方（簡易版）をまとめていく
この問題、あの問題みたいにやれば解けそう！！って時にココ見れば分かる。って感じにしたい。

あくまで自分用ですが、アドバイス等は遠慮なくもらえると嬉しいです。

リンク切れ等ございましたらご報告ください！！！
**コードは特に記述のない限りc++14(GCC5.4.1)です**

## 使い方
"Ctrl + f" で検索窓を開いて、「DP」みたいな感じで検索してね。<br>
問題名で検索することも可能です。

## 構成
- 解いた問題のタイトル
	- 一言コメント

## ABC
[ABCのB問題のいくつかを埋めたときの記録](https://iloveconviniboshi.hatenablog.com/entry/2019/11/26/232433)
ここには,
ABC001 / ABC003 / ABC006 / ABC009 / ABC010 / ABC011 / ABC012 / ABC013 / ABC014 / ABC018 / ABC020 / ABC021 / ABC022 / ABC024 / ABC025 / ABC027 / ABC028 / ABC033 / ABC035 / ABC036 / ABC037 / ABC038 / ABC040 /
が入っています。


#### abc042B - 文字列大好きいろはちゃんイージー / Iroha Loves Strings (ABC Edition)
[問題](https://atcoder.jp/contests/abc042/tasks/abc042_b)
[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/25/134405)

vectorに入れてソートする問題

#### abc043B バイナリハックイージー / Unhappy Hacking (ABC Edit)
[問題](https://atcoder.jp/contests/abc043/tasks/abc043_b)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/180807)

string 文字列に対しても、pop_back()という関数を用いることが出来る
ちなみにこれ、空の文字列に対して行ったらどうなるんだろうね！！（気になる）



#### abc047 一次元リバーシ / 1D Reversi
[問題](https://atcoder.jp/contests/abc047/tasks/arc063_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/155542)

同じ文字のまとまりを1つの区画として、何区画あるか数え上げる
特別なことはしていない
#### abc51c Back and forth**
[問題](https://atcoder.jp/contests/abc051/tasks/abc051_c)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/23/203826) 

#### abc056 Go Home
[問題](https://atcoder.jp/contests/abc056/tasks/arc070_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/17/144058?_ga=2.40811042.1658560726.1573923016-792513449.1561374473) 

ちょっとずつ動ける範囲が広くなる
負の方向に跳ねるのは無駄だ
#### abc058 Dubious Document / 怪文書
[問題](https://atcoder.jp/contests/abc058/tasks/arc071_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/17/221359) 

その文字が何回出てきたかを数える
英小文字と数字を対応させる。
mapでも解けそう
#### abc061C Big Array
[問題](https://atcoder.jp/contests/abc061/tasks/abc061_c)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/27/092053)

制約が緩いので配列サイズNで、配列の要素番号と値を対応させて間に合う問題。


#### abc067 Splitting Pile
[問題](https://atcoder.jp/contests/abc067/tasks/arc078_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/17/122319?_ga=2.56621355.1658560726.1573923016-792513449.1561374473) 

整数列が与えられて、前から値を足していったとき、その整数列の総和の半分に値を近づける。
#### abc073C Write and Erase
[問題](https://atcoder.jp/contests/abc073/tasks/abc073_c)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/21/231141) 

出てくる回数が奇数か偶数かを見るだけ
mapを使った

#### abc088C Takahashi`s Information
[問題](https://atcoder.jp/contests/abc088/tasks/abc088_c)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/19/180305) 

数学チックな問題
連立方程式を使うのかな
#### abc110C String Transformation (niboshi time 35m)
[問題](https://atcoder.jp/contests/abc110/tasks/abc110_c)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/23/013914?_ga=2.149242166.1006338473.1574440595-792513449.1561374473) 

難しかった。
サンプルを見て頭を回せ。
全ての出現する文字に対して、対応するものは1個だけじゃないといけない
解説動画で感動するが、これは悩んだものに与えられる特権

#### abc094D Binomial Coefficients
[問題](https://atcoder.jp/contests/abc094/tasks/arc095_b)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/12/01/000201)

直感的にやったらＡＣしてしまった問題。
二項係数に関する問題、証明がなかなか面白い（？）ので公式解説を見るのをお勧めする。

#### abc110D Factorization
[問題](https://atcoder.jp/contests/abc110/tasks/abc110_d)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/30/170343)

解けてうれしくなれた。
良い記事を書いたよ。
数え上げの問題。逆元も使う。（逆元の解説はない）

#### abc116 Grand Garden
[問題](https://atcoder.jp/contests/abc116/tasks/abc116_c)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/011301?_ga=2.52229673.1658560726.1573923016-792513449.1561374473)

操作をする系問題（おおざっぱかよ）
左からどんどん花を完成させていくっていう方針で大体いいと思う。
#### abc128c Switches
[問題](https://atcoder.jp/contests/abc128/tasks/abc128_c)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/29/190435)

bit全探索
bit全探索の初級と言われればそうかもしれないが、bit全探索初心者にとっては結構難しい
僕にとっても難しい。

#### abc131 Megalomania
[問題](https://atcoder.jp/contests/abc131/tasks/abc131_d)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/17/161146) 

Yes,No問題、締め切りが近い順にやっていけばいい
証明は分からないけど直感がそう言ってる
とか言って証明はURL飛べばある（あるよ）
#### abc146
[問題](https://atcoder.jp/contests/abc146/tasks)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/25/020426)
(記事はD問題まで書きました)
二冠
二分探索何もわかってなかった。
ABC回の参加の方針が少し経った気がする

### ARC
#### arc059 いっしょ / Be Together (メンヘラ）
[問題](https://atcoder.jp/contests/arc059/tasks/arc059_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/162826?_ga=2.52296233.1658560726.1573923016-792513449.1561374473) 
全探索（簡単）
#### ARC068C - X: Yet Another Die Game
[問題](https://atcoder.jp/contests/arc068/tasks/arc068_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/19/044606) 
計算量1の問題
記念すべき400AC目
最適な操作方法に気付けるか
#### arc069 Scc Puzzle
[問題](https://atcoder.jp/contests/arc069/tasks/arc069_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/013811) 
#### ARC073c Sento
[問題](https://atcoder.jp/contests/arc073/tasks/arc073_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/21/145134?_ga=2.52794664.1658560726.1573923016-792513449.1561374473) 
押すとT秒水が流れるボタンをたくさんの人が止まってからや止まる前に押したとき、合計で何秒流れるかの問題
・水が流れ始めてから次に押す人が何秒後に押すかに着目
難しい文法はない
#### arc091c Flip,Flip,and Flip
[問題](https://atcoder.jp/contests/arc091/tasks/arc091_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/175114) 

計算量が1の問題
表になるものを数える
もしくは裏になるものを数える
自身を含めて周りにマスが偶数個あれば操作が偶数回で表
奇数個なら裏。
### AGC
#### agc002 Box and Boal
[問題](https://atcoder.jp/contests/agc002/tasks/agc002_b)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/20/010442?_ga=2.13612727.1658560726.1573923016-792513449.1561374473) 

割と面白い問題、AGCだけど古い問題なのでdifficultyほどの難しさはない印象。
実装系だと思う
入力で与えられる添え字-1 が配列で見たいところっていうのに気づかずちょっと手間がかかった。
#### agc006 Prefix and Suffix
[問題](https://atcoder.jp/contests/agc006/tasks/agc006_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/153645?_ga=2.224369307.1658560726.1573923016-792513449.1561374473) 

substrを使うと綺麗かな
二つの文字列 S , Tに対して
Sの後ろ側と Tの前側で一致する文字列の長さの最大値が答えに関連する
#### agc011 Airport Bus
[問題](https://atcoder.jp/contests/agc011/tasks/agc011_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/17/114603?_ga=2.219658777.1658560726.1573923016-792513449.1561374473) 

sortして、到着するのが早い人からどんどん処理をしていく。
難しい構文は使っていない。
#### agc013 Sorted Arrays
[問題](https://atcoder.jp/contests/agc013/tasks/agc013_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/002820) 

実装が難しい問題（？）
数列が与えられて、期待する数列に分けるにはどうしたらいいか？みたいな
#### agc015A A+...+B Problem
[問題](https://atcoder.jp/contests/agc015/tasks/agc015_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/18/171415?_ga=2.111451396.1658560726.1573923016-792513449.1561374473) 

考察の問題
計算量1の問題
和を最大値と最小値まで、任意の値にすることが出来る（できるので）
#### agc015B Evilator
[問題](https://atcoder.jp/contests/agc015/tasks/agc015_b)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/17/234011?_ga=2.45005348.1658560726.1573923016-792513449.1561374473) 
難しいことはしていない
どの階にも1回か2回押せばいける。

#### agc022 Diverse Word
[問題](https://atcoder.jp/contests/agc022/tasks/agc022_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/19/013117?_ga=2.48520742.1658560726.1573923016-792513449.1561374473) 
解説通りには解けていないが嘘解法ではないはず。
辞書順なのでnextpermutationを使った
文字列の長さがアルファベットの数と同じ26であるときの考えが難しい
next_permutationは自分で実装すると案外難しいのでやってみると面白い（らしい）いつかやってみよう
#### agc031A
[問題](https://atcoder.jp/contests/agc031/tasks/agc031_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/19/024534) 
難しい文法は使ってないけど難しい問題
文字列が与えられて考えられる文字列？が何通りあるか数える
abcd ⇒ a , b , c,  d, ab, ac, ad , bc,bd,cdk, abc, abd ,acd, bcd , abcd
で15通り みたいなやつ

#### agc032A Limited Insertion
[問題](https://atcoder.jp/contests/agc032/tasks/agc032_a)

[記事](https://iloveconviniboshi.hatenablog.com/entry/2019/11/29/020411)
vectorの要素の削除を初めて使った。
くそ難しい問題なので、何か新しく理解出来たら追加で何かをかきたい

#### 日ごとのまとめ

##### 12月4日

ABC028c - 数を三つ選ぶマン

ABC136d - Gathering Children

これらは [article,12月4日](https://iloveconviniboshi.hatenablog.com/entry/2019/12/05/000505)
の中にまとめてぶち込んでます

##### 12月5日

技術室億プログラミングコンテスト#4 Day1 a- ヘビがヘビー

技術室億プログラミングコンテスト#4 Day1 B- Long Long Ago

ABC142 E-Get Everything

三つの記事について書いたの記事はこちら～[にぼしの記事](https://iloveconviniboshi.hatenablog.com/entry/2019/12/05/203637)

Get Everything は写経AC。集合を二進数で扱うbitDP、配るDP。どの鍵を使うかで全探索はできないが、
箱が開いているか開いてないかの状況で全探索はできる。
一つ前の状況から、カギを使うことであらわされる二進数表記の状態を考える

面白い問題！！（写経ACだけど）

abc064 D - Insertion 
難しい

文字列操作系の問題（苦手）

どこに挿入するかがポイント？

##### 12月6日

diverta 2019 Programming Contest C- AB substrings

[12月6日の分の記事はこちら](https://iloveconviniboshi.hatenablog.com/entry/2019/12/06/003844)

diverta C-AB substrings
悪くない問題


文字列操作系の問題
簡単か難しいって言われたよくわからないけど
慣れてはや解き出来るようになろうねって感じ

###### 12月8日
- 解いた問題
ABC010C-浮気調査

ARC029 A-高橋くんとお肉

C - Digits in Multiplication

[12月8日の分の記事はこちら](https://iloveconviniboshi.hatenablog.com/entry/2019/12/08/143238)

浮気と調査

距離を求めるときは　doubleを使おうね

高橋くんとお肉 bit 全探索

最近はbit全探索の問題をよく見かけるようになってきた。
やはり同じぐらのでぃフィカルティには同じ位の難易度の問題が集まるのだろうか？


##### 12月9日

- 解いた問題
C - Dubious Document 2

[ABC076C - Dubious Document 2](https://atcoder.jp/contests/abc076/tasks/abc076_c)
[substr,部分文字列、貪欲、辞書順最小]
'?'は'a'にしたほうが辞書順最小になる
最低でもtを一つ部分文字列に含んでいればいいので,tとして考えられる場所が複数ある場合は、
できるだけ後ろのほうが良い。
(前が'a'になっていた方が辞書順で早いので

ABC041C - 背の順

[ABC029 C- Brute-force Attack](https://atcoder.jp/contests/abc029/tasks/abc029_c)
[next_permutation]
next_permutationの手動実装みたいなノリ

ARC016 B- 音楽ゲーム

AGC005 A- STring
難しめ

ABC147 C -HonestOrUnkind2
ビット全探索！！

ABC108 C- Trianglular Relationship
  写経AC

ABC033 C- 数式の書き換え

CODE FESTIVAL 2016 qual C B-K Cakes
ちょっとだけ頭を使う

AGC011 B - Colorful Creatures
楽しい



[12月9日の記事はこちら](https://iloveconviniboshi.hatenablog.com/entry/2019/12/09/040758)


Dubious Document、　substrを使う問題

substrが使えそうって思ったとき、使い慣れてないせいで別解法に逃げがち（WA出した）
おとなしくsubstr使えるようになろうね
##### 12月10日

- 解いた問題一覧
**ABC127 D- Integer Cards**

**ABC085 D- Katana Thrower**
上二問は似ているぞ。

**Tenka1 Programmer Beginner Contest 2019**

**D - Rain Flows into Dams**

**ABC114 C-755**
写経AC

[12月10日の記事はこちら](https://iloveconviniboshi.hatenablog.com/entry/2019/12/10/162320)

##### 12月11日

- 解いた問題
 - ABC069 C- 4- adjacent
 - ARC003 B-さかさま辞書
 - ABC134 D- Preparing Boxes
 多分これが一番おもしろかった
    後ろから球を入れてくのがいい
    [12月11日の記事はこちら](https://iloveconviniboshi.hatenablog.com/entry/2019/12/11/010328)

##### 12月12日
- 解いた問題
 - ABC112 D-Partition 
 [最大公約数,天才考察,]

[12月12日の記事](https://iloveconviniboshi.hatenablog.com/entry/2019/12/14/144331)
全然やってない；；

##### 12月14日
- 解いた問題
 - ARC054 A- 動く歩道
 次の問題に比べればかんたんな条件分岐
 - ARC051 A- 塗り絵
 勘弁してくれ。図形の問題。直線と円
    なんかかっこいい解き方あるのかね

 

 [12月14日の記事](https://iloveconviniboshi.hatenablog.com/entry/2019/12/14/144710)

##### 12月15日
- 解いた問題
 - diverta 2019 Programming Contest 2 B-Picking Up
 マップのキーはペアでもいいよって言う

 [12月15日の記事](https://iloveconviniboshi.hatenablog.com/entry/2019/12/15/211628)

##### 12月16日
- 解いた問題
 - ARC043 A-点数変換

 REが出ないせいでやられた。少数嫌い
 [12月16日の記事](https://iloveconviniboshi.hatenablog.com/entry/2019/12/16/203200)

#####　いつ解いたか分からないやつ
#### ARC007迷子のCDケース
[MAP]
なんかうまく行かない。
n個のCDに対して
n-1個のCDケースと1個のカセット。
CDケースの番号とCDの番号を対応付けて、カセットをCDケース0。
disk0 ~ disk m-1 に対して、以下のような操作を行う

disk[i] = k ,現在流れている曲を p とすると
kが入っているケースにpを入れ,pが入っているケース（つまりカセット）にkを入れる

**ポイントは,kが入っているケースを見つけるために線形探索を行わなければいけないってこと**
cd[i] にはi番目のケースに入っているCDの番号を入れる。(0 <= i <= n)


#### ABC079 D-Wall
[ワーシャルフロイド法]
https://atcoder.jp/contests/abc079/tasks/abc079_d
頂点間を結ぶ最短距離（経路を求める）
書き方は考えるのちょっときついから覚えちゃったほうが良いらしい.
計算量は頂点の数の3乗
rep(k,v){
	rep(i,v){
		rep(j,v){
			dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
		}
	}
}

#### Caddi2018 D- Harlequin
ゲームの必勝法。なるほど面白い。
全部偶数で自分の手番が始まりさえすれば、相手の動きを真似することで、コマが全部なくなるのは自分のターンにできる。
なるほどな

#### 2020/01/27 
1月入ってからずっと書くのサボってました
ぼちぼちやろうね。

##### [ABC153 E-Crested Ibis VS Monster](https://atcoder.jp/contests/abc153/tasks/abc153_e)
[DP Dynamic Proggramming, 動的計画法]
DPっぽいよなあ。って問題。
解説動画によると、二次元DPでも一次元DPでも行けるとのこと。
とりあえず頑張って二次元で書けと言われたので書いた。
[提出コード](https://atcoder.jp/contests/abc153/submissions/9776378)
こーどの　コレがないと　死ぬ　ってやつを忘れるとWAです。
dp[i][j] := i番目までの魔法でjのダメージ（以上）を与えるときの最小のMP消費量。なので
if (j == 0 ) では、0ダメージ以上なので魔法を使わなくて良いんだよ。

**動的計画法,dpはdp[i][j] := hoge って定義考えるとちょっと見通しが良くなる気がする。**
[あと、これのコードの記事も書きました](https://iloveconviniboshi.hatenablog.com/entry/2020/01/28/164925)

##### [ABC152 D - Handstand 2](https://atcoder.jp/contests/abc152/tasks/abc152_d)
[数え上げ, MAP,回文]
数字の上位と下位の数字（100433543　なら上位は１　下位は３）を見て、与えられた範囲内で下位で始まり上位で始まるものが何個あるかを数える問題
(カッコ内の例の場合は 31 ,331, 311…みたいなものの数を数える）
雑に言うと、１回目のループで1からnまでの数字について、それぞれが何で始まり(上位がなにで）何で終わるか(下位が何か）を全部作っていく。
そして、２回目のループで、1からnまでの数字について,aで始まりｂで終わるなら、ｂで始まりaで終わるものの数を数えていく。

[提出こーど ABC 152 D - Handstand2](https://atcoder.jp/contests/abc152/submissions/9798715)

###　2月１日 貪欲消化回〜〜〜
[貪欲,greedy] 
にぼしくん,蟻本をやろうということで、某ちょんさんが蟻本の問題をAtCoderの問題に対応付けてくれているので、それを消化していきます！！
ところで貪欲法って使えることの証明が大事だと思うんですよね。分かる？人間の諸君

##### [ABC083 C-Multiple Gift](https://atcoder.jp/contests/abc083/tasks/arc088_a)
[貪欲]
Xから２倍、その値を２倍ってやっていくのが最適な貪欲ですよね〜〜（証明貪欲)


証明しないとまずいな、ってことで、公式の解説に証明載っていたので写経しました。
画像を直接貼るのめんどくさいのでTwitterのリンクにします
[C-Multiple Gift 証明](https://twitter.com/niboshi_wakai/status/1223405843397279749)

##### [ARC006 C-積み重ね](https://atcoder.jp/contests/arc006/tasks/arc006_3)
[貪欲]
最初これ、入力与えられてきている順番にダンボールを積まないといけないっていうところに気が付きませんでした。

普通に思い順に１山にしたらよくない？って思ってしまいましたね。
これまた証明が思い浮かばない…
そしてまた、感覚でも納得できないですね。

っていうことで解説読んで証明を理解してきましょう。

[積み重ねの証明写経](https://twitter.com/niboshi_wakai/status/1223446358754856961)

まあ、偉そうに写経なんて載せてますけど公式の解説写経です。[これ](https://www.slideshare.net/chokudai/wap-atcoder4)が一番しっくり北

##### [ABC005 C- おいしいたこ焼きの売り方](https://atcoder.jp/contests/abc005/tasks/abc005_3)
[貪欲,二部グラフの最大マッチング]
(↑　タグはつけてますけど、貪欲以外では解いていないです。）
なんとなく、証明以外の部分はちゃんとルールを決めて解こうと考察できたと思う
[考察用紙](https://twitter.com/niboshi_wakai/status/1223645300188839937)貼っておきます。

どんな貪欲か,以下のルールでタコ焼きを売り続けます
1. B[0]から、B[m-1]（m人の客）について、売れるたこ焼きがある時は、可能な限り古いたこ焼きを提供する。

あいも変わらず、証明はできないので、[公式の解説](https://www.slideshare.net/chokudai/abc005)を写経してみる。
[写経してみた](https://twitter.com/niboshi_wakai/status/1223645300188839937)

#### 2020/02/02
[ABC103 D-Islands War](https://atcoder.jp/contests/abc103/tasks/abc103_d)
[区間スケジューリング,貪欲,greedy,] 
難しいですね。
お得に橋を切ることを考えているのですが、言語化ができなくて苦労している問題。
自力で解けたんだけど、なんか上手い解説は浮かばない。
公式の解説を見ようね

#### 2020/02/03
##### [ABC132 D- Blue and Red Balls](https://atcoder.jp/contests/abc132/tasks/abc132_d)
[コンビネーション、組み合わせ数え上げ、mod、nCm,DP,動的計画法、パスカルの三角形]
nCmは普段良くわからない方法で求めてるけど、解説どおりパスカルの三角形で実装してみた。
多分これあらがありまくる。
あらがありすぎて新垣ゆいになりそうなレベル。

#### 2020/02/19
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/02/19/002517)
##### [ABC126 D-Even Relation](https://atcoder.jp/contests/abc126/tasks/abc126_d)
[グラフ、二部グラフ、DFS]

隣の頂点との距離が偶数か奇数か
グラフの問題で易しめのやつ（むずい）
#### 2020/02/20
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/02/19/115743)
#### [ABC150 D- Semi Common Multiple](https://atcoder.jp/contests/abc150/tasks/abc150_d)
[最小公倍数、式変形]

本番通せなくて(c++わい、敗北）、Python勢がオーバーフロー？ｗ知らんけどｗｗｗｗｗｗ
みたい感じになって俺がブチ切れたやつ。

#### 2020/02/21
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/02/22/095435)

#### [ABC067 D- Fennec VS. Snuke](https://atcoder.jp/contests/abc067/tasks/arc078_b)
[ゲーム、幅優先探索,queue,キュー,BFS,グラフ]

最適に動いたときどっちが勝つかってやつ。

####[第７回二本情報オリンピック予選(オンライン)](https://atcoder.jp/contests/joi2008yo/tasks/joi2008yo_f)
[ダイクストラ,クエリが与えられるタイプ,dijkstra,グラフ]

辺を追加するという操作か、二頂点間の最短距離を求めろ。っていうクエリが順次与えられる。
ダイクストラはある１点から他の頂点への距離の最短を求めるアルゴリズム。
#### 2020/02/22
[この日解いた問題の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/02/23/064457)

### [ABC 156 A-Beginner](https://atcoder.jp/contests/abc156/tasks/abc156_a)
[if文,日本語]
Nが10以上の場合はRを出力,
そうでない場合は**内部レーティング**を計算して出力する。

###[ABC 156 B-Digits](https://atcoder.jp/contests/abc156/tasks/abc156_b)
[K進数,whileループ]
10進数で表された整数Nは、K進数だと何桁で表せるか.
ちょっとｳｯってなりましたけど、殴りました。

###[ABC 156 C-Rally](https://atcoder.jp/contests/abc156/tasks/abc156_c)
[全探索]
簡単.
考えるだけ無駄鳴きがする…（難しいのが出てきたらソノトキ考えよう)

###[ABC156 E- Roaming](https://qiita.com/PlanetMeron/items/63ac58898541cbe81ada)
[nCm,操作,組み合わせ、数え上げ、日本語]

本番通せなかった。けど頑張れば解けるような問題。

各部屋にいる人数だけが問題になっていて、中にいる人の違いは考慮しないってことに気が付かなかった。

#### 2020/02/24
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/02/24/115605)

### [ABC104 D-We Love ABC](https://atcoder.jp/contests/abc104/tasks/abc104_d)
[動的計画法、数え上げ,mod]

青パフォで少しむずかしめの問題。ABCが何組あるか。みたいな…。
実質写経ACみたいな感じ。

### [ABC156 D- Bouquet](https://atcoder.jp/contests/abc156/tasks/abc156_d)
[mod,nCm,繰り返し二乗法、数え上げ]

可能な花束の作り方は
 2^n - 1 -  nCa - nCb  です。

### [AGC003 B- Simplified mahjong](https://atcoder.jp/contests/agc003/tasks/agc003_b)
[貪欲法]

簡単

### [ABC054 C- One-Stroke Path](https://atcoder.jp/contests/abc054/tasks/abc054_c)
[グラフ,無向グラフ,簡単グラフ,全順列]

#### 2020/03/04
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/04/205937)

### [ABC157c Guess The Number](https://atcoder.jp/contests/abc157/tasks/abc157_c)
[全探索,if文ゴリ,実装ゲー,しんどい]

### [ABC157d Friend Suggestions](https://atcoder.jp/contests/abc157/tasks/abc157_d)
[UnionFind,ユニオンファインド,グラフ理論]<br>
初めてunionfindをつかう問題だと本番で気づき、さらに通すことが出来た（やったね）

#### 2020/03/11
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/11/162950)
<br>
セグ木をやった日です。
AOJなどをやっていたのでここには載せません
嘘です。載せます

### [AIZU ONLINE JUDGE Range Minimum Query](http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A)
[SegmentTree,セグ木]<br>
典型セグ木みたいな？

### [yosupo judge - Point Add Range Sum](https://judge.yosupo.jp/problem/point_add_range_sum)
[SegmentTree,セグ木]<br>
初のヨスポジャッジからの記事です。
上の典型セグ木のコードを少し変えて頑張って解きました。

#### 2020/03/12
[この日野記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/12/234026)

[yukicoder Range Mindex Query](https://yukicoder.me/problems/no/875)
[Seg-tree,セグ木,RMQ]<br>
RMQのindexを答えてくれという問題です。<br>
この問題を通して得た知見をつらつらと書き連ねていきます。
#### 2020/03/13
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/14/003145)
### [ABC052C - Factors of Factorial](https://atcoder.jp/contests/abc052/tasks/arc067_a)
[全探索,約数の個数]<br>

#### 2020/03/16
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/17/021720)

### [ABC044 C-高橋くんとカード](https://atcoder.jp/contests/abc044/tasks/arc060_a)
[DP,3次元DP,動的計画法,水色パフォーマンス]<br>
自力ACして糞盛り上がりました。

[提出コード](https://atcoder.jp/contests/abc044/submissions/10946539)
#### 2020/03/20
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/21/020813)<br>
### [ABC038 C-単調増加](https://atcoder.jp/contests/abc038/tasks/abc038_c)
[尺取り法]diff試験管900<br>
愚直は通らない。通さない。<br>

### [ABC115 D-Christmas](https://atcoder.jp/contests/abc115/submissions/me)
[再起関数,ムズカシイ]<br>
むずくね？
写経AC
良うわからん

### [ABC075 C-Bridge](https://atcoder.jp/contests/abc075/tasks/abc075_c)
[橋、連結無向グラフ]<br>
橋の問題です。他人の記事からうばってAC
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/22/023247)にちょっとだけ考察というかお気持ちというかが描いてあるかも<br>
#### 2020/03/21 AGC043の日
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/22/023247)

### [ABC075 C-Bridge](https://atcoder.jp/contests/abc075/tasks/abc075_c)
[橋、連結無向グラフ]<br>
#### 2020/03/22
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/23/043611)
### [ARC005 B- P-CASカードと高橋君](https://atcoder.jp/contests/arc005/tasks/arc005_2)
	[天才実装ゲー,方向転換の処理]<br>
### [ABC159 A- The Number of Even](https://atcoder.jp/contests/abc159/tasks/abc159_a)
[偶数奇数,parity]<br>
2つの数を足したら偶数になるような2つの数の選び方は、**偶数+偶数**か**奇数+奇数**ですよ。っていう問題.<br>
### [ABC159 B - String Palindrome](https://atcoder.jp/contests/abc159/tasks/abc159_b)
[Palindrome,回文]<br>
この問題面白くて、実はSが回文で、Sの前半も回文だったら、Sの後半調べなくていいんだよ。すごくね？<br>
### [ABC159 C- Maximum Volume](https://atcoder.jp/contests/abc159/tasks/abc159_c)
 [小数を使えますか,体積の最大化]<br>
 立方体が一番おっきいの！！
### [ABC159 D- Banned K](https://atcoder.jp/contests/abc159/tasks/abc159_d)
 [map,連想配列]<br>
### [ABC159 E- Dividing Chocolate](https://atcoder.jp/contests/abc159/tasks/abc159_e)
[bit全探索,天才実装]<br>
ホワイトチョコレートと普通のチョコレートが混ざった板チョコなんて現実に存在しますか？しません。しません。しないで。

### 2020/03/24
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/24/224206)
###[ABC097 C- K-th Substring](https://atcoder.jp/contests/abc097/tasks/arc097_a)
[部分文字列,substr,連想配列,文字列,辞書順]<br>
辞書順でK番目であるということについての考察。
"abcdef"と言う文字列sがあったとき、その末尾(プレフィックス)を取ったもの"abcde"文字列tは、sよりも辞書順で前か後か。どっちでしょうか。<br>
### [ABC045 C- たくさんの数式](https://atcoder.jp/contests/abc045/tasks/arc061_a)
[bit全探索]<br>
みんな大好きbit全探索の問題です。<br>
### [ABC129 D-Lamp](https://atcoder.jp/contests/abc129/tasks/abc129_d)
[最大化,数え上げ的な]<br>
### [diverta 2019 Programming Contest D- DivRem Number](https://atcoder.jp/contests/diverta2019/tasks/diverta2019_d)
[整数,約数,商と余り]<br>
何か解けちゃいました。

### 2020/03/25
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/26/030422)
[Indeedなう(予選B) B- 高橋くんと文字列操作](https://atcoder.jp/contests/indeednow-qualb/tasks/indeednow_2015_qualb_2)<br>
[文字列,文字列の比較]<br>

### 2020/03/26
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/26/235853)
[ABC124 D-Handstand](https://atcoder.jp/contests/abc124/tasks/abc124_d)<br>
[尺取り法,累積和]<br>
## 2020/03/27
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/28/030508)
[AGC033 A- Darker and Darker](https://atcoder.jp/contests/agc033/tasks/agc033_a)
[複数ヶ所からの幅優先探索]<br>
複数ヶ所からの幅優先探索というのは僕がみたときの印象です。
が、やってることは本当に基本の幅優先探索と一緒で、最初queueに突っ込むのを左上（0,0)だけじゃなくて
'#'のマスを全部queueに突っ込もうね。っていう考えです。

### 2020/03/28
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/29/043857)<br>

[ABC160 A-Coffee](https://atcoder.jp/contests/abc160/tasks/abc160_a)
[文字列,if文]<br>

[ABC160 B-Golden Coins](https://atcoder.jp/contests/abc160/tasks/abc160_b)
[切り捨て,最大化(easy)]<br>
[ABC160 C-Traveling Salesman Around Lake](https://atcoder.jp/contests/abc160/tasks/abc160_c)
[図形(?),最短距離(easy)]<br>
池の周りのセールスマン<br>
[ABC160 D-Line++](https://atcoder.jp/contests/abc160/tasks/abc160_d)
[連想配列(map),無向グラフ(だけど…),最短距離]<br>
無向グラフとか言われて身構えさせられたけど、辺を受け取る処理も書かなくていいので怯えるな！！って感じな気がした問題<br>
[ABC160 E-Red and Green Apples](https://atcoder.jp/contests/abc160/tasks/abc160_e)
[組み合わせ…？,最大化]<br>

### 2020/03/29
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/30/025431)<br>
[ABC121 D- XOR World](https://atcoder.jp/contests/abc121/tasks/abc121_d)
[XOR,周期性,累積和的解法]<br>
実は、kとk+1のXORは1かになる。(ただし、kが偶数のとき）(k = 3とすると3は011,4は100なのでXORは100で4ですね。進数変換は察して)<br>
累積和的解法というのは、BまでのXORからA−1までのXORを引いてあげれば解けるっていうノリです。
僕は、1番目のbitが立っているのが何個あって…っていうのを求めて解きました。くそ汚い解法です.<br>

### 2020/03/30
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/03/31/015551)<br>
### [CODE FESTIVAL 2015 予選 A](https://atcoder.jp/contests/code-festival-2015-quala/tasks/codefestival_2015_qualA_c)<br>
[最適化,最小化]<br>
[公式解説PDF](https://www.slideshare.net/chokudai/codefestival2015quala)<br>
公式のスライド解説って見やすくていいですよね。
- とりあえず全部を写すことにする
### 2020/03/31
**記事に詳しく書いてあるわけじゃないのでこの日のブログのリンクは無し**
### [ABC112 C- Pyramid](https://atcoder.jp/contests/abc112/tasks/abc112_c)<br>
[重実装,全探索]<br>
何か解説動画でウンウン言っていましたが，正直良くわからなかった．<br>
解説PDFをみた感じで，一番わかり易い(それが知れたら解ける）のは，**h[i] != 0 となるiが存在すること**．これがわかれば解けた．<br>
## 2020/04/01
[この日野記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/02/033642)<br>
### [ABC090 D- Remainder Reminder](https://atcoder.jp/contests/abc090/tasks/arc091_b)<br>
[固定,数え上げ]<br>
余りを求める問題は，余りに周期性があることを意識しよう。<br>
つまり，0,1,2,...nをkで割った余りは0,1,...k-1, 0,1,...,k-1, ..., r<br>というふうに循環し，このときのrはn%kですね（そりゃそう)
## 2020/04/02
[この日のk爺](https://iloveconviniboshi.hatenablog.com/entry/2020/04/02/230553)<br>
### [ABC080 C-Shopping Street](https://atcoder.jp/contests/abc080/tasks/abc080_c)
[bit全探索,条件,最大値]<br>
最大値は負にもなりうるので，ans = 0;で初期化するのはダメだよ.<br>
## 2020/04/03
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/03/172549)<br>
### [ABC81 D- Coloring Dominoes](https://atcoder.jp/contests/abc071/tasks/arc081_b)
[数え上げ,mod,解説AC]<br>
横ドミノが並んでるときに3倍じゃなくて2倍になると思ってた…<br>
パターンを全通り考えよう！

## 2020/04/04
[この日野記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/05/011718)<br>
### [ABC161 A- ABC Swap](https://atcoder.jp/contests/abc161/tasks/abc161_a)
[特になし]<br>
中身を入れ替えるという操作は2回しかしていないので単純にz,x,yの順に出力するだけですね<br>

### [ABC161 B- Popular Vote](https://atcoder.jp/contests/abc161/tasks/abc161_b)
[割り算]<br>
1WA出しちゃいました（ﾃﾍﾍﾟﾛ）<br>
楽な実装方針ですと，a[i] * 4 * mが総得票数を上回っているか見たほうが楽そうですね。<br>
総得票数 * (1/4m)とすると，切り上げれば良いのか切り捨てれば良いのか頭がﾎﾟｱになってしまうので，a[i] * 4 * m >= 総得票数をチェックしたほうが良いとおもいます。<br>
もちろん大きい順に（降順）ソートしている前提ですよ。<br>

### [ABC161 C- Replacing Integer](https://atcoder.jp/contests/abc161/tasks/abc161_c)<br>
[数学,パターン]<br>
何かよく分からない雑な考察とif文3つで通してしまいました。解説を読む必要があります。<br>

なるほど，N,Kの大小で考察をすると楽だったのですね。<br>

### [ABC161 D-Lunlun Number](https://atcoder.jp/contests/abc161/tasks/abc161_d)<br>
[BFS]<br>
既にlunlun数だとわかっている物を10倍して（追加できるなら）それ-1, +0, +1 をlunlun数に追加する。
解けた。楽しい。

## 2020/04/05

### [ABC105 C- Base -2 Number](https://atcoder.jp/contests/abc105/tasks/abc105_c)<br>
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/05/080651)<br>
[数学,-2進数,進数変換]<br>
解けたけどよく分かってない。<br>
ただ，なんとな〜くだけど，大事な（他の進数のときも意識したほうが良さそうな）ことは，k進数にするときは，kで割った余りがある条件になっていたらk進数のそこのフラグが立つ。で，その次のフラグを見るためには元の数をkで割って見る。って感じにするのが大事なんだと思う。<br>
### [ABC109 D- Make Them Even](https://atcoder.jp/contests/abc109/tasks/abc109_d)<br>
[操作，偶奇,最大化,貪欲法]<br>
偶数と奇数しか見なくていいので，なんとなく右下に寄せていくイメージで行けば良さそう。<br>
どのマスも必ず1回以下の操作をすれば偶数にすることが出来る。<br>
だから，もしも奇数個のコインがあるのであれば右（右にマスがなければ下）に移動サせる。<br>
**右下のときだけどこにも移動させれないので偶数にならない可能性がある**

## 2020/04/06

[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/07/010647)<br>
### [ABC138 D- Ki](https://atcoder.jp/contests/abc138/tasks/abc138_d)
[木，Tree,累積,深さ優先探索]<br>
はい，出ましたAfter Contestのテストケースを乗り越えられなかった問題。<br>
ポイントは**木の持ち方**,**DFSのやり方**(ってすぬけさんが言ってた）<br>

## 2020/04/07
[この日野記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/07/225804)<br>

### [CODE FESTIVAL 2017 QUAL A C- Palindromic Matrix](https://atcoder.jp/contests/code-festival-2017-quala/tasks/code_festival_2017_quala_c)
[回文,文字列,手を動かせ]<br>
手を動かしてみるとなんとなく見えてくることがあります。

### 2020/04/16
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/13/013601)<br>
ABC162の回です

### [ABC162 A- Lucky7](https://atcoder.jp/contests/abc162/tasks/abc162_a)<br>
[桁の値]<br>
### [ABC 162 B- FizzBuzz Sum](https://atcoder.jp/contests/abc162/tasks/abc162_b)<br>
[全探索,FizzBuzz]<br>
Nの値が10^6までなので，全部見ればいいっすね。

### [ABC162 C- Sum of gcd of Tuples(EasY)](https://atcoder.jp/contests/abc162/tasks/abc162_c)

[全探索，最大公約数]<br>

### [ABC162 D- RGB Triplets](https://atcoder.jp/contests/abc162/tasks/abc162_d)
[数え上げ,組み合わせ(?),条件]<br>
中々面白い問題ですね。これが速く解けるか解くのに時間がかかるかで蒼perf ~ 緑perfまで変動するみたいです。にゃーん<br>
とりあえず，RGBそれぞれの数を数えてあげましょう。<br>

### 2020/04/22
[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/23/235947)<br>
ABC163の回です
### [ABC163 D- Sum of Large Numbers](https://atcoder.jp/contests/abc163/tasks/abc163_d)
[数え上げ]<br>
unrated回なので考えずに終わってしまいました。N+1個の数は10^100 + i と言う数で表されていて，
ある数h個取った時とg個(h!=g)取った時の値は絶対に一緒にならないので，取る数が何個かを全部見てやればよさそうです。<br>

### 2020/04/27

[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/04/27/235602)<br>
### [ABC148 E- Double Factorial](https://atcoder.jp/contests/abc148/tasks/abc148_e)
[約数の個数,10進数]<br>

N!!が10を約数に何個持つかっていう問題。<br>
まずはNの階乗の中に何個2や5があるかっていうのを数えてみる。
1,2,3,...N(N個)の中に何個5の倍数があるか，それはN/5個だね。
これら5の倍数のものを全て5で割ると,<br>
1,2,3,...N/5(N/5個)ってなっていく，これらを繰り返すことで，N!が5で何回割れるかっていうのが
求まる。<br>
で，多分それが答え。<br>
ちなみにNが奇数のときは，1,3,5,...,NがN!!で2が含まれることがないので答えは0

### [ABC148 F- Playing Tag on Tree](https://atcoder.jp/contests/abc148/tasks/abc148_f)
[木,鬼ごっこ]<br>
高橋くんの初期位置からの距離(T)と，青木くんの初期位置からの距離(S)のうち，T < S となるようなSのうち最大のもの-1が答え（のはず)<br>
二人の距離が偶数奇数によらず追いかけっ子が終わる場所が同じっていうのが面白いね<br>

### [ABC158 E- Divisible Substring](https://atcoder.jp/contests/abc158/tasks/abc158_e)
[累積和,文字列中の整数,部分文字列,10進数]<br>
15943 = 3 + 40 + 900 + 5000 + 10000 的なノリを10進数は大事にすると良い。<br>
ってかこの問題すげえっすわ・・・<br>

累積和を作ったときに(S) S7 ≡ S3 なら P で割れるだって！？まじか！すごいっす！みたいな。<br>


### 2020/05/28
 [この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/05/28/231530)
### [ABC106 C- To Infinity](https://atcoder.jp/contests/abc106/tasks/abc106_c)
[文字列、大きい数]<br>
これはまああれですね。

あなたは2の5000乗が10^18を超えるということに気が付きますか？　<br>

### 2020/05/29
### [ABC166 E- This Message Eill Self-Destruct in 5s](https://atcoder.jp/contests/abc166/tasks/abc166_e)
[この日の日記](https://iloveconviniboshi.hatenablog.com/entry/2020/05/30/015359)<br>

[連想配列,式変形]<br>
・2人の持つ番号の差の絶対値が、2人の身長の和に等しい。
そのような(i,j)(i != j) の組を求めよ。という問題
つまり　$a[i] + a[j] = |i-j|$ を満たすi,jの組を求める。
組み合わせを数えるから、(i,j)と(j,i)は同じ物として考える。
j > i となるような組だけ求めればいい。
先程の式を変形すると$a[j] + j = i - a[i]$となる。(iとjに着目して左辺と右辺に分ける)

つまり、各jに対して、a[j] + j が i - a[i] となるものを数えてあげればよくて、これを数える為にi < j となるiを全部見ることは愚かなので、連想配列に格納することで、a[j] + j = i - a[i] を満たすiをMAP[a[j] + j] を見るだけで数えられる！（やった〜！）

### [ABC070 D- Transit Tree Path](https://atcoder.jp/contests/abc070/tasks/abc070_d)
[木、DFS,深さ優先探索]<br>
まぁ、深さでも幅優先探索でもどっちでもいいとは思うけど（知らん）<br>

とりあえず求めるのは、Kが固定サれているっていうので、Kから各頂点への距離を最初に全部調べて上げればいい。
（与えられるグラフは木なので、Kから各頂点への距離はただ1つに定まる）

後はQ回のクエリで,1と8が与えられたら、1からKへの距離+Kから8への距離を答えとして出力する。

この問題、最近のABCで出たらdiffはどんなもんだろう…2017年8月の問題で、diffiが1190だけど、今でたら1050ぐらいまで下がるのかな？それとも茶パフォぐらいまで落ちるのかな？

個人的には深さ優先探索は書くのが苦手だから4桁diffあるような気がするけど...

### [ARC062 / ABC046 D- AtCodeerくんと変なじゃんけん](https://atcoder.jp/contests/arc062/tasks/arc062_b)
[貪欲？？]<br>
これは何でしょうか…？

TopCodeer君がpを出した後、AtCoDeer君がpかgかをとりあえず考えてみた。
p-gで負けの時、ポイントは-1, その後1点にするためには2回勝たないと行けない…
（だからソレがどうした？？）みたいなよくわからないことを考えてみた結果、パーを出せるときはパーを出しておけ。みたいな考えになってとりあえず提出してみたラACした。<br>

解説見ました。天才かよ・・・・・・・・・・・・・・・・・・・・・・・！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！

一回全部グー出したとして、どこをPに変えるかを考える…すげええ！！！！！！！！！

#### 2020/05/30
[この日の記事]
### [ABC089 D- Practical Skill Test](https://atcoder.jp/contests/abc089/tasks/abc089_d)
[累積和,コスト,割った余り]<br>
LとRが与えられた時、L -> R のコストは L % D を K とした時（ただし,K = 0のときはK = Dとする), K -> R のコストから K -> L のコストを引いたものとして求められる。
(A -> B -> C という経路があれば、BとCの距離はAとCの距離引くAとBの距離的な）

### [SoundHound Inc Programming Contest2018 C- Ordinary Beauty](https://atcoder.jp/contests/soundhound2018-summer-qual/tasks/soundhound2018_summer_qual_c)
[期待値の線形性]<br>
なんや難しそうな問題だなぁ…
隣り合う二項について美しさを獲得できるかどうかで求めていけないかな…うんぬん…とかしていて結局解けないことが分かりました。

解説PDFを見て1mm理解,その後、[数学/競プロメモ](http://tutuz.hateblo.jp/entry/2018/07/09/222217)この方の記事を読んで1cm位理解しました。
なるほど。まぁ、二項間について着目しようという発想はヨカッタですね。各2項間について、得られる美しさの期待値を求める。他の2項間についても、美しさを得られる期待値は同じなので、存在する二項間がm-1個あるから、各二項間の美しさの期待値 * (m-1)が答え。ふうん。面白いじゃん。
期待値の線形性ね。なるほど。

### [NOMURA プログラミングコンテスト2020 C- Folia](https://atcoder.jp/contests/nomura2020/tasks/nomura2020_c)
[二分木,木の構築?,葉の数]<br>


### 2020/05/31
### [ABC169-A Multiplication 1](https://atcoder.jp/contests/abc169/tasks/abc169_a)
[yarudake]<br>
### [ABC169-B Multiplication 2](https://atcoder.jp/contests/abc169/tasks/abc169_b)
[いじめ,オーバーフロー]<br>
1e18を超えた時の判定がむずいので
$ now * a[i] > 1e18 $ ってことは
$ now > 1e18 / a[i] $(式変形)かぁ、って思ってそうしたら行けた。


### [ABC169-C Multiplication 3](https://atcoder.jp/contests/abc169/tasks/abc169_c)
[いじめ,オーバーフロー,小数]<br>

### [ABC169-D Div Game ](https://atcoder.jp/contests/abc169/tasks/abc169_d)
[素因数]<br>
$ N = a ^ x * b ^ y * c ^ z $みたいな形してるとき、xを1+2+3+...+kって感じで分割するのが良くて…みたいな感じでやってったら行けた。

### [ABC169-E Count Median](https://atcoder.jp/contests/abc169/tasks/abc169_e)
[中央値,最大化,最小化]<br>

何も分かっていないので解説動画を見よう！！！

### 2020/06/01

[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/06/02/021404)<Br>
### [ABC 096 D- Five, Five Everywhere](https://atcoder.jp/contests/abc096/tasks/abc096_d)
[面白い,素数,合成数]<br>
解説ACなのですが、感動しました。

{x1, x2, x3, x4, x5} のxiがそれぞれ5 * k + a (aが5で割った余り)という形で表されるとき x1 ~ x5 までの和は 5 * hoge + 5 * a なので5の倍数だね！！ﾌﾌﾝ

### [ABC092 C- 2D Plane 2N Points](https://atcoder.jp/contests/arc092/tasks/arc092_a)
[ペア作成、貪欲(的),最適な選び方]<br>
こういう問題よくあるよね。好きだよ。好きだよ。<br>

<br> あれです、クイズ番組で10人が問題を解く。難易度は1〜10までで10個ある。って時、自分が解けるなかで一番難しい物解いてあげよう。っていうやつだよ。<br>


### [AGC024 B- BAckfront](https://atcoder.jp/contests/agc024/tasks/agc024_b)
[操作の最小回数,数列並び替え]<br>

?2?3??4??5?　みたいになっている時、（この文字列は9文字)2345以外の?に操作を加えることで
1 2345 6789っていう風にすることが出来る。!!!!つまり、与えられた数列の中で、 k (k+1) (k+2) (k+m) っていう順に並んでいるモノの最大値を求めて上げればいいって。

### 2020/06/02

[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/06/03/102002)<br>

### [AGC 032 B- Balanced Neigbors](https://atcoder.jp/contests/agc032/tasks/agc032_b)
[グラフ,グラフの構築]<br>
解けなかったけど、なんかグラフ関連の問題なんてまだ累計50問も解いてないだろうし、そもそも考える方法が分かっていないみたいな節ある。<br>
ただ、今回の問題だと完全グラフをまず構築してみる。とかそういう物を頂いたので収穫はありかと思われます！！！

完全グラフ(頂点i,j(i != j) の2頂点について、どのi,jの組み合わせも辺がある)を考えて、その時の各頂点の隣接している頂点の和を見てみる（(1~Nの和) - (見ている頂点番号)) 。
そこから考えていくととても良い！！　へーかっけえ
おれもこんな問題が解ける天才になりてえな

### [ABC097 D- Equals](https://atcoder.jp/contests/abc097/tasks/arc097_b)
 [UnionFind, 連結,好きな回数操作]<br>

 a <-> b <-> cって感じでaとbの入れ替え、bとcの入れ替えが出来るなら、abcの順列(abc, acb, bac, bca, cab, cba)はどれでも作ることが出来る。
 <br>

 つまり、(1 <= k <= n) の k が最初入っていた場所と、kが本来ある場所が関節的にでも繋がっていればkは目的の場所へ移動することが出来る。
 <br>
 自力AC,やったぜ。
 <br>
 連結なら全部目的の場所に行ける、っていうのは、なんかまぁ、バブルソートでどんな数列でも昇順に出来るし、見たいなノリで考えるとタシカニな〜みたいなうっすらとした感覚がある。
(この、swap操作って、バブルソートみたいなもんじゃね（Sirankedo)

### [M-SOLUTIONS プロコンオープン D- Maximum Sum of Minimum](https://twitter.com/259_Momone/status/1086563591866597376)
[得点最大化,深さ優先探索,幅優先探索]<br>

葉には一番小さい要素を入れる。というふうにしてみたのですが駄目でした。解説ACでぷ。
深さ優先探索を書いてみようと思ったらバグ梅小宮で解けなかったのでおとなしく幅優先探索を。

この問題名でググると他の方の解説記事あって、それとても良いと思ったから俺の記事なんか読むよりそっち見てみて。<br>
c1 >= c2 >= ... >= cn とすると、ci( 1 <= i <= n) は最大でも(i-1)回しか足せない。<br>ってことが分かるので、　可能かどうかは分からないが、最大でも c2+...+cn が答え。（まぁ、可能)

どっかを木の根として、根から幅優先探索でも深さ優先探索でも良いが、Cの大きいものから入れて行くと良いとのこと。

ちなみに解説の森が云々っていうのはわからんかった(元気もりもり森鴎外なら知ってる)

### [CODE FESTIVAL 2017 Final](https://atcoder.jp/contests/cf17-final/tasks/cf17_final_c)
[時計,円,場合分け,実装重い,bit全探索(的な)]<br>
s = 0 〜12としたときに、達成出来るかで全探索しようと思ってpriority_queueを使って実装したのですが9WA出して諦めました。（なんだろう、こういう時原因を突き詰めるまでやったほうが良いとは思うが体力が)<br>


### 2020/06/03

[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/06/03/102002)<br>
### [ABC137 D- Summer Vacation](https://atcoder.jp/contests/abc137/tasks/abc137_d)
[優先度付きキュー,(貪欲法)]<br>
解説を見て、あぁ、M-1日目から順に考えていくのか…ってなったよね。
以下解説PDFより引用

> こういった問題は、**制約の厳しい方から**見ていくと見通しが良くなることが多いです。
> したい操作は
- 候補の追加
- 候補の中から最大のものを取り出す

<br>
にゃあ. 0日目に受けれる仕事は多い。M-1日目に受けれる仕事は少ない（日数の制約上受けれる（というか受けれるっちゃどれも受けれるが、報酬が間に合わない))ので**制約がきびしい**


### [AGC024 C- Sequence Growing Easy](https://atcoder.jp/contests/agc024/tasks/agc024_c)
[操作,数列]<br>
(もはやタグ付がテキトウ)
当日の記事に、頭の流れ書いた。

### 2020/06/05

[この日の記事](https://iloveconviniboshi.hatenablog.com/entry/2020/06/04/051242)<br>
### [AGC031 B- Reversi](https://atcoder.jp/contests/agc031/tasks/agc031_b)
- [数列の操作,オセロ,数え上げ]<br>

頭パンクしちゃうのでパス。


### [ABC114 D- 756](https://atcoder.jp/contests/abc114/tasks/abc114_d)
- [約数の個数,数え上げ]<br>

約数の個数が75個って言うのはどういうことかって言うと、 75 = 3 * 5 * 5であることを考えて,
(x,y,z) = (74,0,0),(24,2,0),(14,4,0),(4,4,2) の4つが考えられる…。

(14,4,0)の時を取り上げて、 k = a^14 * b^4 と表せるとき、kの約数の個数は75個だな〜…
<br>
このとき、**aとしてかんがえられるものが何通りあるか、っていうのと、bとしてかんがえられるものが何通りあるか**、って言うのをかんがえてあげれば、 a ^ 14 * b ^4 で表せる数っていうのは a * (b - 1)通りあるな。<br>

あと、これは俺が間違えたことなんだけど, a * (b - 1)　と b * (a - 1)はチガウから注意しようね。

### [エイシング　プログラミングコンテスト2019](https://atcoder.jp/contests/aising2019/tasks/aising2019_c)
- [幅優先探索,交互に移動]
b2からw1は行けるのに、b2からw2,w3,w4へは行けないのがありえない。っていうのはどうやって示そう。
<br>
数学の素養が虚無だからテキトウなこと言うけど、
b2からw1へ行けたってことは、w1からb1へ行くことが可能じゃん。すると,b1からw1,w2,w3,w4へ行けるんだから、一回b1を経由して上げればw2,w3,w4へ行けるってことは理解できそう。

で、幅優先探索で行ける島を見つけてあげて、島に含まれるblackとwhiteの数の積を答えに足す。っていうのをやってあげれば答えが求まる。

僕はこれに　バグを埋め込んで一生泣いてた。

### [diverta2019 Programming Contest2 C- Seccessive Subtraction](https://atcoder.jp/contests/diverta2019-2/tasks/diverta2019_2_c)
- [数列の操作]<br>
(天才が)考察をすると,N個の要素について、最低でも1つは+と-があって、他のものについては+にも-にも出来ると言う事が分かります。

そして、肝心な操作の順番ですが、 イメージとしては、+にしたいやつは(aをのぞいて)2回 x,y のyとして選ぶことで正に戻す。みたいな感じかな。。


### [2020/06/06](https://iloveconviniboshi.hatenablog.com/entry/2020/06/06/232849)
### [AGC019 B - Reverse and Compare](https://atcoder.jp/contests/agc019/tasks/agc019_b)
-[数え上げ,要素の反転]<br>

"aabbb"みたいなのがあったら、どの'a'をどの'b'と交換するか。みたいなことを考えるだけだと思いますが。<br>
だから、'a'~'z'についてそれをやるだけですね。
'a'と'b','a'と'c',...,'a'と'z'次は'b'と'c', 'b'と'd', ... , 'b'と'z'って感じで、ね。

### [ABC055 / ARC069 D- Managerie](https://atcoder.jp/contests/arc069/tasks/arc069_b)
-[嘘つきと正直者,構築?]
Menagerieという英単語は、動物園という意味だそうです。<br>

2匹を決めてやると、その後2匹目がSheepで発言が'o'なら、3匹目は1匹目と同じ動物。というふうに決めていくことが出来る。<br>

1,2番目の動物の決め方は {wolf/Sheep} {wolf/wolf}, {Sheep,wolf}{Sheep,Sheep}の4通りしか無いので、4つの場合について、動物を決めていって、証言に嘘がないかを見てやれば良い。

似たような問題がbit全探索する問題であったような気がするな〜(ちょうどブログサボってた時期に解いたかも)

### [ARC062 C- AtCoDeerくんと選挙速報](https://atcoder.jp/contests/arc062/tasks/arc062_a)
- [最小化,DP,数式変形]<br>
面白い問題ですね（解けなかったけど)

解説ACです。
まず、一番最初の速報の段階でx:yのとき、票はx,y票が最小ということは分かる。<br>
次に、得票数の比がT:A(問題文と文字を合わせた）のとき、得票数はT * x[i], A * x[i]であるとします。
ってやっていくのであれば、x[n-1]を最小化してあげれば得票数も最小になります。
これをなんか美味いこと数式作ってやると解ける！すげ〜！

### [ABC152 E-Flatten](https://atcoder.jp/contests/abc152/tasks/abc152_e)
- [LCM,素因数分解、オーバーフロー]

全てのiについてAi * Bi をLCMにしたらいいってのは分かる気がします。
しかし、LCMを頑張って求めるとオーバーフロー！！ｱｱｱｱｱｱｱｱｱｱ！！！ってなりますね。<br>（本番なりました）
そこで、LCMを求めるのではなく、LCMを素因数分解した形を持ってやるという発想です。

賢いですね。そうすればうまく行く。

### [ABC099 D-Good Grid](https://atcoder.jp/contests/abc099/tasks/abc099_d)
- [MOD3,最小値,計算量削減]

とりあえず、問題の意図としては、**使う色は3色だけになるぽよ**ってことが分かりました。
じゃ,(i+j)%3が0,1,2で何色を塗るか30 * 29 * 28 通り全部試すか…ってやろうとするとO(N^2 C^3)で10^9ぐらいで許してくれません。（意地悪)<br>

で、かんがえを変えて、とりえずMOD3が0,1,2のものそれぞれについて、色i( 1 <= i <= C)にした時の違和感を保持しておきます。<br>

すると、MOD3が0のもの、1のもの、2のもので、違和感が小さい順にしたものを3つずつ取ってきて上げると、3^3=27通りのうち、どれかは採用出来るようになっています。<br>
で、採用出来るかどうかを見てあげて最小値取ってあげる。

### [2020/06/07](https://iloveconviniboshi.hatenablog.com/entry/2020/06/08/004903)

### [ABC128 D- equeue](https://atcoder.jp/contests/abc128/tasks/abc128_d)
- [全探索(的な?),最大化]<br>

この問題のポイントは以下に挙げる100000007つです。
1. 操作の回数はK回以下
2. 宝石を筒に戻す操作は最後に行えば良い。
3. 左からと右から、何個ずつ取り出すかで場合分け.

1の**K回以下**という制約によって、右から取り出して右に入れて右から取り出して右に入れる。という操作(4回)を、右から取り出した後、戻すという2回の操作に出来ます。<br>
<br>

### [ABC134 E- Sequence Decomposing](https://atcoder.jp/contests/abc134/tasks/abc134_e)
- [deque,最小化,LIS,LDS]

なんですかこれ、難しい。なんとなく、要素を左から見ていって、見ている要素を何と同じ色にするか、ってとき、出来るだけ大きい数字のものと一緒にすればいいっていうのは分かった。
<br>

### [ABC138 E- Strings of Impurity](https://atcoder.jp/contests/abc138/tasks/abc138_e)
- [部分列,超巨大文字列, 二分探索,] <br>

うーん、なんとも…<br>
超巨大文字列s'の何文字目を使うかっていうのを保持するのではなくて、sの何文字目を使うかでやっていくらしい。<br>
そのためにsを2つくっつけたもので見ていくと。<br>

解説シャキョウACだけどちょっと理解は進んだよ。<br>

あ〜少しずつ分かってきた。面白い問題だね。k

### [Tenka1 Programmer Beginner Contest](https://atcoder.jp/contests/tenka1-2018-beginner/tasks/tenka1_2018_d)<br>
- [構築,数式イジイジ,楽しい日曜日]

以下考察。
**1~Nは、どれもちょうど2つの集合に含まれる**ということから、1が2個、2が2個…Nが2個ということで、S1からSnまでに含まれる要素の個数は全部で2 * N 個有りますね。 <br>
次に、構築する集合がk個の時、S1~Skのk個の集合を構築してあげます。<br>
ここで次に、もう一つの条件を見ます。
**S 1 , S 2 , .  .  .  , S k のうちどの 2 つの集合をとっても、それらに共通して含まれる要素はちょうど 1 つである** 。つまり、S1はS2と共通してa1を共通して持つ、S1はS3と共通してa2を持つ…S1はSkと共通してa(k-1)を持つ。という風になります。<br>
よって、S1は要素を(k-1)個もちます。　他の集合S2~Skに対しても同様のことが言えるのでS1,S2,...,Skは全て(k-1)個の要素をもちます。<br>

そして、S1からSkがそれぞれ(k-1)個の要素を持つ時、<br>
S1の要素の個数　+　S2の要素の個数 + ... + Skの要素の個数　= k * (k-1) <br>
これが2 * N と一致していれば、そのような集合は作れます（証明:AC)<br>


### [CODE FESTIVAL 2017 Final A-AKIBA](https://atcoder.jp/contests/cf17-final/submissions/14084686)
- [if文]<br>
分からんかったので力で通しました。

```cpp
int main()
{
	string s;
	cin >> s;
	if(s=="AKIHBR") cout << "YES" << endl;
	else if(s=="KIHABR") cout << "YES" << endl;
	else if(s=="AKIHABR") cout << "YES" << endl;
	else if(s=="KIHBAR") cout << "YES" << endl;
	else if(s=="AKIHBAR") cout << "YES" << endl;
	else if(s=="KIHABAR") cout << "YES" << endl;
	else if(s=="AKIHABAR") cout << "YES" << endl;
	else if(s=="KIHBRA") cout << "YES" << endl;
	else if(s=="AKIHBRA") cout << "YES" << endl;
	else if(s=="KIHABRA") cout << "YES" << endl;
	else if(s=="AKIHABRA") cout << "YES" << endl;
	else if(s=="KIHBARA") cout << "YES" << endl;
	else if(s=="AKIHBARA") cout << "YES" << endl;
	else if(s=="KIHABARA") cout << "YES" << endl;
	else if(s=="AKIHABARA") cout << "YES" << endl;
	else if(s=="KIHBR") cout << "YES" << endl;
	else cout << "NO" << endl;
}
```

### [2020/06/08](https://iloveconviniboshi.hatenablog.com/)

### [AGC039 B-Graph Partition](https://atcoder.jp/contests/agc039/tasks/agc039_b)
- [ワーシャルフロイド法,二部グラフ判定,グラフの直径]<br>

> 各辺が隣り合う番号の頂点を結んでいるようにする。
> 各集合がNo Empty<br>
> どういうときに出来るか。二部グラフじゃないと駄目なことが分かる。全部の辺が偶数グループと奇数グループを結んでいるはず。<br>

二部グラフではないとき、どう頑張っても全ての辺にたいして隣り合う頂点集合の頂点同士を結ぶことは出来ない。<br>
二部グラフであるとき、二色で（白と黒)分けたものの、白から見て其の隣の黒を2,其の隣（最初の白じゃないやつ）を3…としていけば条件を満たすグラフは作れる。
うーん。なぜ二部グラフなら作れるのか。って言うのを理解するのが難しい‥けど。

頂点集合の数を最大っていうのを無視する。<br>
すると、白を集合番号0、黒を1としてしまえば、全ての辺に対して、頂点番号k,k+1を結んでいる。というのは作れる。
この時、**二部グラフだから**黒同士を結んでいる（白同士を結んでいる）辺は存在しないので条件は満たしている（最大値は知らない）




### [ABC100 D-Patisserie ABC](https://atcoder.jp/contests/abc100/tasks/abc100_d)
- [BIT全探索,価値の最大化]

テキトウに、M個選んだ時の綺麗さの和,おいしさの和,人気度の和をX,Y,Zとでもしておきましょう.<br>
このとき、(X、つまり綺麗さの合計の絶対値) + (Y,つまりおいしさの合計の絶対値) + (Z,い人気度の合計の絶対値) = S とでも置いておきます。
すると、S = +-(X) +-(Y) +-(Z) ですね。+-はプラスかマイナスかのどちらか。的なニュアンスで。<br>

となると、X,Y,Z,それぞれについて正に大きくするのを目指す。負に大きくするのを目指すかでわけでかんがえると良さそうだな…って気がします。

### [ABC047 D- 高橋君と見えざる手](https://atcoder.jp/contests/abc047/tasks/arc063_b)
- [コストの最小化,差の更新,差の最大]<br>

i番目の町まで見た時、i-1番目の町までで一番安い物を売ることを考える。<br>
(2番目に安いものを売るよりも、一番安いものを売ったほうが利益が大きいから)

そして、i-1番目の町までで買ったりんごをi番目の町で売った時の利益がiまで見たときに最大なら、其の個数を管理する。

### [ABC059 C-Sequence](https://atcoder.jp/contests/abc059/tasks/arc072_a)
- [二通り試す,操作の最小回数]<br>

なるほどね。i番目までの和が偶数のときと奇数の時を二通り試すのか〜…<br>
0番目までの和はいじらなくていいだろ。って無意識に思ってました。


### [ABC120 D- Decayed Bridges](https://atcoder.jp/contests/abc120/tasks/abc120_d)
- [UnionFind,逆からみる]

M番目の橋から順に見ていきます。<br>
まず、M番目の橋をつなげたことで、A[M]とB[M]が行き来出来るようになります。
逆にこの橋がなくなることで,A[M]とB[M]が行き来出来ないようになります。<br>
この時増える不便さは1(A[M]とB[M]の一組だけ行き来できなくなるので.)
この、値"1"を heru という配列の0番目に格納します。

次にM-1番目の橋を見ます。<br>
この時、M-1番目の橋を繋げたことで、何組の島が新しく行き来可能になったかを見ます。
この値を heru という配列の1番目に格納します。

これを1番目の橋までやっていきます。<br>
heru という配列を逆順にします。
M回出力します。i回目の出力は、heruの0からiまでの値の和。<br>


### [2020/06/09](https://iloveconviniboshi.hatenablog.com/entry/2020/06/09/144623)
### [AGC020 B- Ice Rink Game](https://atcoder.jp/contests/agc020/tasks/agc020_b)
- [後ろから,最大と最小,操作]<br>

a[i]人組を作る操作で、人数はa[i]倍数人になる。
a[i]人組を作る操作で,N人組になるとき、操作の前では(N/a[i]) * a[i]　人かな？<br>
ﾁｮｯﾄﾑｽﾞｶｼｲ(解説AC)
何書けばいいか分からないくらいにはわからないな。


### [ABC080 D- Recording](https://atcoder.jp/contests/abc080/tasks/abc080_d)
- [実装,同じチャンネルはお得]<br>

時刻1~100010ぐらいまでについて、テレビが始まる時間と終わる時間を保持、終わった瞬間同じchで別番組が始まる場合はソレも保持。

### [ABC106 D- AtCoder Express 2](https://atcoder.jp/contests/abc106/tasks/abc106_d)
- [二次元累積和]

始めて二次元累積和の問題触りました。<br>
良い言葉を書くには理解が浅すぎる。<br>

### [ABC126 E- 1 or 2](https://atcoder.jp/contests/abc126/tasks/abc126_e)
- [UnionFind,Disjoint-Set,コストの最小化,数式]<br>

A2 + A4 ≡ 0(mod2)って言われたら、A2が分かればA4も決まります。A4が分かればA2も分かります。
<br>
A4 + A5 ≡ 1(mod2)って言われていたら、さっきの手順でA2,A4が分かっているのでA5も分かります。<br>

### [ABC153 F- Silver Fox vs Monster](https://atcoder.jp/contests/abc153/tasks/abc153_f)
- [疑似累積和,区間に対する操作,queue]<br>

i体目にギリギリ届くように落とした爆弾の効果が、i+何体目まで及ぶか。っていうのをqueueで扱えるようにしたのですね。<br>
```
while(q.front().first < x) 
```
っていう書き方賢いですね。(q.front().firstは、効果が切れる時の座標、xは今見てるモンスターの座標)

### [AGC023 B- Find Symmetried](https://atcoder.jp/contests/agc023/tasks/agc023_b)
- [計算量減らせ,線対称]<br>

A,Bで成り立つ時,A+1,B+1についても成り立つ！！！！<br>
(A,B)->(A+1,B+1)は全部右下（イメージ)に1個ずつずらすだけなので、対象であるかどうかには影響しない！！！<br>
だからA=5, B=6 をみる変わりにA=0,B=1を見れば良い。（A=0とB=0~N-1を見てやればいい！！）

### [2020/06/10](https://iloveconviniboshi.hatenablog.com/entry/2020/06/11/155113)

### [ABC033 B- LRUD Game](https://atcoder.jp/contests/agc033/tasks/agc033_b)
- [場合分け、勝てる区間] <br>

駒が盤面から落ちる場合、右から落ちるのか、左に落ちるのか。上から落ちるのか、下から落ちるのか。この4通りを見てやるのが僕的には楽だと思います。<br>

解説動画だと、勝てる区間？とやらがあるみたいですが、そちらについては理解が追いつきませんでした。<br>

### [第5回 ドワンゴからの挑戦状 予選](https://atcoder.jp/contests/dwacon5th-prelims)

- [桁ごとにみる,実装,for文はまとめろ]<br>

2^k > 2^(k-1) + 2^(k-2) + ... + 2^0 <br>
めちゃくちゃ時間かかった
ツカレタ。<br>

2^40ぐらいから,そいつを採用出来るか見ていく（部分列の和の最大は,a[0] ~ a[n-1]の和、すなわち10^9 * 10^3 で10^12　≒ 2^40ぐらいなので)

### [ABC131 E- Friendships](https://atcoder.jp/contests/abc131/tasks/abc131_e)
- [グラフの構築,構築ゲー]

構築ゲーは、極端な例ヲかんがえてやると良いらしい。
作れる上限と下限を考える。
### [2020/06/12](https://iloveconviniboshi.hatenablog.com/entry/2020/06/12/163734)
### [AGC041 B- Voting Judges](https://atcoder.jp/contests/agc041/tasks/agc041_b)
- [二分探索、単調性,実装頑張れ,二分探索の端っこ]<br>
```cpp
ng = n + 1;
```
これはWA

```cpp
ng = n;
```
これはAC。<br>
…難しいよ…

写経ACじゃないので自力ACと言っても過言ではない。<br>

まず、得点5が採用できるなら、得点5以上は全部採用できる。<br>
得点4は採用できるか分からない。

つまり、得点Kが採用可能なとき、K以上は全部採用出来るから、其のようなKの下限を求めろっていう、二分探索が使える。<br>

A[i]が採用可能かを判定してあげる。<br>
A[i]がｷﾞﾘｷﾞﾘ採用できる〜〜って時をかんがえて挙げると、P位にてあげればいい。そうするとき、どうやって票を振り分けて行くかを考えればOK !!
### [ABC165 D- Floor Function](https://atcoder.jp/contests/abc165/tasks/abc165_d)
- [床関数,数式,最大値、周期、割った余り]

単調増加関数、周期がB,,,....
<br>
まぁまず、xの値をNまで全探索するのはO(N)で N <= 10^12なので無理。

式の値がBで周期になってるってこと、気づくの無理じゃね…？(代入しないで式で気づくの無理そう)
周期がBってことに気付ければB-1の時一番嬉しいって分かるな

### [2020/06/13](https://iloveconviniboshi.hatenablog.com/entry/2020/06/14/075905)
### [ARC074 C- Chocolate Bar](https://atcoder.jp/contests/arc074/tasks/arc074_a)
- [面積、差の最小化]<br>

二週間前に解こうとして、解けなくて投げ出した問題をちゃんとACしました（やった〜)<br>

[提出コード1](https://atcoder.jp/contests/arc074/submissions/14203774)<br>
[提出コード2](https://atcoder.jp/contests/arc074/submissions/14203781)<br>

線の入れ方は、{横に引くのを二本,縦に引くのを二本,横と縦1本ずつ}
<br>
の3通り。(と見せかけて、縦横一本ずつは少しチガウ)

### [AtCoder Beginner Contest 079 C- Train Ticket](https://atcoder.jp/contests/abc079/tasks/abc079_c)

- [全探索,(bit全探索)]<br>
8通り全部ifで書くのがめんどくさいのでbit全探索しました。

### [2020/06/14,15](https://iloveconviniboshi.hatenablog.com/entry/2020/06/16/123632)
### [ABC170 E- Smart Infants](https://atcoder.jp/contests/abc170/tasks/abc170_e)<br>
- [multiset,ラムダ式,集合の管理,イテレーター,set]<br>

multisetから、ある値xを一個だけ消したい時は,s.erase(s.find(x))
配列の要素の先頭の値は(配列の名前をsとすると） 
```cpp
*(s.begin())
```
末尾の要素は
```cpp
*(s.rbegin())
```
で取得出来る。

### [Codeforces Round #599(Div.2) A.Maximum Square](https://codeforces.com/contest/1243/problem/A)
- [全探索]<br>
辺の長さ1 ~ 1000が作れるか全部見てあげても間に合う。全体の計算量はO(KN^2) <= 10^7かな
各辺の長さLについて、N枚の板がL以上かを見る。その枚数がL以上なら辺Lは作れる。

### [Codeforces Round #599 (Div. 2) B2. Character Swap(Hard Versiion](https://codeforces.com/contest/1243/problem/B2)
- [操作、整列]<br>
操作が2n回まで出来るってことは、ある文字を希望通りの位置に持ってくることは出来る。<br>

### [Codeforces Round #599 (Div. 2) C. Tile Painting](https://codeforces.com/contest/1243/problem/C)

- [割った余り？,実験,最大化]<br>

Nが素因数一種類で構成されているならその素因数が答え。(N = 3^9なら3が答え)<br>
Nが2種類以上の素数で構成されているなら答えは1<br>(記事に落書きあり)

### [2020/06/16,17](https://iloveconviniboshi.hatenablog.com/entry/2020/06/18/045320)
## [東京海上日動プログラミングコンテスト](https://atcoder.jp/contests/tokiomarine2020)
### C. Lamps
- [操作回数の最大]

最大でも50回ぐらい操作をすれば値は収束する。（僕は1000回ぐらい回せばええやろっていってTLEでした。うざい)

###[Codeforces Round #514 (Div. 2) A.Cashier](https://codeforces.com/contest/1059/problem/A)
- [切り捨て]<br>
客が返ってから次の客がくるまでの時間(最後に客が来る時間をL(一日の長さ)としておくと都合がいい)
で、何回休憩が取れるかを取っていく。

###[Codeforces Round #514 (Div. 2) B.](https://codeforces.com/contest/1059/problem/B)
ポチになる可能性があるのは、外周をぐるっとする1マスの枠より内側にあるので、ソレを全部ポチとして採用するか見てやる。<br>

###[Codeforces Round #514 (Div. 2) C.](https://codeforces.com/contest/1059/problem/C)
- [落とし込み,約数,最大公約数,場合分け]<br>

最初取る最大公約数は絶対1って言うのは分かる。<br>
じゃあ、出来るだけ早い段階でGCDが2以上となるようにしたい。<br>
サンプルを見てみると、N = 3 のときは、3がGCDとして取れるようになってる。<br>

まぁなんか、早くGCD大きくしたいよ〜ってとき、最低でも要素数/2 ぐらいすればGCD大きく出来るよ。的な。


### [ABC170 D- Not Divisible](https://atcoder.jp/contests/abc170/tasks/abc170_d)
- [素数っぽいやつ,エラトステネスの篩っぽいやつ]

まず入力を昇順に並び替えとく。
2が与えられたら,4,6,8,...は以後出てきても答えに加算はされない。みたいなエラトステネスの篩っぽいことをして素数っぽいやつの数を数えればいい。解けた時自分が天才かと思った。<br>

### [ABC157 E-Simple String Queries](https://atcoder.jp/contests/abc157/tasks/abc157_e)
- [set,集合を管理する,query,アルファベット]<br>

'a' ~ 'z'の26文字についてを管理する。<br>
'a'なら'a'が何文字目にあるかを保持。このように'a'のある位置を管理する配列~'z'のある位置を管理する配列を用意する。<br>

文字の置き換えqueryに対しては、置き換わる前の文字列が何かを見て、其の文字の集合から、其の文字の位置を削除。（S自体も置き換える)<br>
新しい文字cに対して、cが何番目にあるかを管理している配列に対して、追加する。

範囲queryに対しては、'a'~'z'があるかを1文字ずつ判定<br>
これは、setの中身に対してLi文字目以降ではじめてc( 'a' ~ 'z'がc)が出てくる場所を見つける。見つけた位置がRより手前なら（Li以降で見つけているので)文字cがある。<br>

今度似たような問題が出たら自分で解きてえ

### [ABC141 E- Who Says a Pun?](https://atcoder.jp/contests/abc141/tasks/abc141_e)

- [文字列,DP,後ろからDP,Z-Algorithm]

dp[i][j] := i からと j から始めたときに一致する最大の長さ<br>

DPを使うことによって、i文字目から見たsubstringとj文字目から見たsubstringについて、何文字共通するかを全てのi,jの組についてO(N^2)で求めることが出来る。
<br>

### [EDPC F-LCS](https://atcoder.jp/contests/dp/tasks/dp_f)
- [DPの復元,DP,最長共通部分列問題,部分列]<br>

最長の長さを取ることは出来たんだけど、DPの復元が分からなかった。<br>
けんちょんさんの記事読んだんだけど、そのDPの値がどこから来たのかっていうのを考えるとわかりやすかった。

### [EDPC G- Longest Path](https://atcoder.jp/contests/dp/tasks/dp_g)
- [DP,有向グラフ,再帰関数,トポロジカルソート]<br>

DPの表って、出来ているものから出来ていないものを作っていくイメージだったんだけど、今回のような、（僕の中のイメージで）葉から根に向かって値を作っていく（根が呼び出しのもと)ようなときには、再帰関数を使えば逆から埋めていけるようだ！！（久しぶりに再帰書いた（書いてない））
[f:id:niboshi_bisyoujo:20200618044720j:plain]<br>

### [2020/06/18](https://iloveconviniboshi.hatenablog.com/entry/2020/06/18/095841)
### [EDPC H- Grid 1](https://atcoder.jp/contests/dp/tasks/dp_h)<br>
- [DP,迷路,幅優先探索]<br>

僕が解けるDPだ、ありがたいですね。<br>
あるマスが通過可能なマスの時、其のマスへ行く方法は、**左のマス**から行くか、**上のマス**(まぁ、どこを上と見るかは人によると思うけど)から行くかの二通りしか無い。<br>
この時、左のマスへ行く方法がL通り、上のマスへ行く方法がU通りあるなら、其のマスへ行く方法はL+U通りだなあ。ってやつ。<br>
初期条件として、(1,1) へ行く方法が1通りだというのさえ知っていれば解ける。

### [EDPC I- Coins](https://atcoder.jp/contests/dp/tasks/dp_i)<br>
- [確率DP]<br>

解けた〜！！（やった〜）
小数が出てくるから確率大っ嫌いなんですけど、doubleで通ったのでよしです。<br>

僕は１次元dpで解きました。
表がN枚出る確率 -> 表がN-1枚出る確率 -> ... -> 表が0枚出る確率
という順番で後ろから更新しました。<br>
i枚目のコインについて見ている時,表がK枚出る確率は、K-1枚表が出る確率 * i枚目が表 + K枚表 * i枚目が裏<br>
事故らないようにDPしてるので事故りません.<br>

### [EDPC J-Sushi](https://atcoder.jp/contests/dp/tasks/dp_j)
- [期待値DP]<br>

０枚の皿の数、1枚の皿の数の枚数、2枚の皿の枚数が重要そうだなっていうところまではなんとなく思いました。<br>
漸化式の部分が完全な理解とはほど遠いですね。<br>

### [CODE FESTIVAL 2016 qual C](https://atcoder.jp/contests/code-festival-2016-qualc/tasks/codefestival_2016_qualC_c)
- [矛盾判定,何通り]<br>

二人の証言から、山の高さが確定したタイミングというのをかんがえました。<br>
まず、0番目の山の高さはt[0]であることは分かります。<br>
(t[0] := (0~0)番目までの山の中で最大の高さ。 )<br>
同様に、n-1番目野山の高さはa[n-1]であることも分かります。<br>
(a[n-1] := (n-1 ~ n-1)番目までの山の中で最大の高さ)<br>

### [2020/06/19](https://iloveconviniboshi.hatenablog.com/entry/2020/06/24/091510)

### [AGC002 C-Knot Puzzle](https://atcoder.jp/contests/agc002/tasks/agc002_c)
- [天才パズル,未証明貪欲,dequeではない,達成可否]<br>

この問題、dequeで端から小さい方を取る。みたいな感じでやると死にます。

L = 8<br>
3 5 2 4 4 1 <br>
をかんがえて
小さい方から取ると　L(left) RRR となって、5,2が残ります。すると、もうほどけません。
でも、4 4 を残してやればほどけます。

これがdequeでやった時死ぬコード。<br>

では、どうすれば良かったか、
それは、　a[i] + a[i+1] の最大となる二点を残して上げるのが一番良いです。<br>
これがL以上であれば、絶対に達成出来ます。<br>

### [ABC075 D-Axis-Parallel Rectangle](https://atcoder.jp/contests/abc075/tasks/abc075_d)
- [五重ループ,点を含む個数,二次元累積和っぽさ]<br>
[AtCoderExpress2](https://atcoder.jp/contests/abc106/tasks/abc106_d)この問題にニているものを感じたが、制約で二次元累積和出来ない…ってなった。<br>
解説を見ると、二次元累積和が使えるらしい。(まじか)<br>
採用する長方形の xの左端、右端,yの上端下端を全探索(候補はそれぞれ点の数だけ)。賢いなああああああ・・・・<br>

### [AGC003 C-BBuBBBlesort!](https://atcoder.jp/contests/agc003/tasks/agc003_c)<br>
- [天才パズル,偶奇,操作の最小化]<br>

何回要素の反転行っても良いんだって。<br>
まず、Aの偶数番目の要素を取り出して考えると、これは操作2だけで任意の順番に並び替えることが出来ます。<br>
3つの順番を反転とあるが、1つ目と3つ目だけに着目すると、ただこの2つの要素が入れ替わっているだけなため、偶数番目の要素が2つswapされるだけです。<br>
数列はswap操作だけでソート出来るので、偶数番目だけを昇順に並び替えることは操作1を一回も行わずに行うことが出来ます。<br>
奇数番目も同様です。

### [ABC144 E-Gluttony](https://atcoder.jp/contests/abc144/tasks/abc144_e)<br>
- [二分探索のプロ,内積の最小化]<br>

**伝家の宝刀二分探索**!!! a[i] * f[i] をある値に出来るかを計算するコストはO(N)。 a[i] * f[i] であり得る値は最大でも10^12　、log(10^12) は40ぐらい、これなら行けるぞ。<br>

まず、前提として、数列aとfがあって、a[i] * f[i] の最大を最小にしようってしたとき、aは昇順、fは降順（逆でもいい）っていうのは使えそうだ。<br>
ちなみにこれは、a[i]に修行させた時、減るコストはf[i]なので、f[i]が大きいものに大して修行させたときのありがたみがでかいよね。的なかんがえ（あとで解説読む)<br>

それで、a[i] * f[i] の最大値をMに出来るかっていう時、其の判定をどうするかをかんがえます<br>
各iについてa[i] * f[i] = Mにするための修行回数を数えます。
このとき、(iの修行した後の消化コスト) * f[i] が Mを下回るとき、其の値はMを下回る（＝もおっけ)最大のf[i]の倍数です。<br>
よって、iが修行する回数は max(0,a[i] - M / f[i])として求められます。<br>
例えば、a[i] = 3, f[i] = 9 のとき、M = 15を目指すとすると、 修行する回数はmax(0, a[i](3) - M(15) / f[i](9)) = max(0, 3-1) = max(0,2) = 2となって、二回修行すればいい。<br>
これをN人全員見てあげて、必要な修行回数がK以下だったら、Mは達成可能ということになります。
よって、Mが達成可能化はO(N)で判別出来ることが分かりました（やったね)<br>

### [CODE FESTIVAL 2016 Final C-Interpretation](https://atcoder.jp/contests/cf16-final/tasks/codefestival_2016_final_c_)<br>

- [通訳,UnionFind,集合の管理]

1. 各i人目について,Ki個の言語Li1,Li2, ... , LiKiをユニオンファインドで合併する.<br>
2. 0人目が話せる言語をXとする
3. 各i人について、iが話せる言語を一つ持ってきて、Xとiが同じ集合にあれば,とりあえずok
4. Xとiが同じ集合になければNOを出力して終わり。
5. とりあえずokがN人全員について言えたらYES

### [ARC090 D- People on a Line](https://atcoder.jp/contests/arc090/tasks/arc090_b)<br>
- [写経AC,有向重み付きグラフ,矛盾判定]<br>

難しいですね。(何をコメントしたらいいかわからない)<br>
とりあえず、数式で繋がっている頂点（人の位置)は相互に関係しているので、一つ決めた時もう一つも決まる。そこから派生してもう一つも決まる。みたいなのはグラフで管理していけばいいみたいです。<br>
A - B間の距離が3の時,Aから右に3行けばB、とともに、Bから左に3行けばA、っていう辺を2つ作ります。<br>
これでうまく行くっぽいです、難しいですね。
とりあえず人の写経コード貼っときます（こら)

### [ABC040 C-柱柱柱柱柱](https://atcoder.jp/contests/abc040/tasks/abc040_c)<br>
- [動的計画法]<br>

動的計画法の初級っぽい問題(バグらせたけど)<br>
i本目の柱へ行くコストを最小化しながら更新していけばいい。
綺麗なコードが書きたいな

### [ABC036 C-座圧](https://atcoder.jp/contests/abc036/tasks/abc036_c)<br>
- [ソート,連想配列]<br>

実装頑張れの問題。<br>
まず、aを昇順に整列したものが手に入れば、各値をどうしたいかが分かる。aを整列したとき一番小さいものが0,2番目が1ってなる。<br>

よって、各値が何になってほしいかを連想配列で管理してやれば良い。<br> 

### [ABC035 C-オセロ](https://atcoder.jp/contests/abc035/tasks/abc035_c)<br>
- [優先度付きqueue,ノリと根性]<br>

L~Rの区間をヒックリ返しますよ〜ってとき、何回ひっくり返している。っていうのを保持しておいて、で、Rを過ぎたら其の回数を減らす。。。みたいなことを…
Lが来るたびに何回ひっくり返してるかを+1して、Rをすぎるたびに-1する。

爆弾でモンスター倒すやつ。みたいな考え方を使って解きました。<br>
あ、これ、配列でも解けるな。<br>気合で。
あ、これ配列使ってやるのいもす法って言うらしい。（ってかそもそもpriority_queueも配列を使っているのでは)
ちょっと実装してみるか.


### [ABC030 C-飛行機乗り](https://atcoder.jp/contests/abc030/tasks/abc030_c)<br>
- [うなぎってなんだよ,priority_queue]<br>

N,Mが10^5程度なので、2 * 10^5 回、それぞれ採用するかどうか見るぐらいなら余裕で間に合います。
<br>
どれぐらい余裕かって言うと、生まれたての子鹿を片手で捻り潰すぐらいには余裕です（こら)<br>

飛行機に乗っている時間っていうのは短いので、乗れるなら速いうちに乗ったほうが良いよね。<br>
だから、空港Aから乗れる一番速いのに乗る,空港Bにつく。Bから乗れる速いのに乗る。<br>(速いじゃなくて早いなんだけどね)<br>
っていうのを実装してやれば行けるね。

### [2020/06/20](https://iloveconviniboshi.hatenablog.com/entry/2020/06/21/021133)
### [ABC022 C- Blue Bird](https://atcoder.jp/contests/abc022/tasks/abc022_c)
- [天才パズル,ワーシャルフロイド法,全点対間最短距離,閉路から経路]<br>

想定解法が賢すぎる。<br>
閉路に対して、ある頂点を1個除いてやれば、辺の数が2個減った経路になる。<br>


###	[ABC021 C- 正直者の高橋くん](https://atcoder.jp/contests/abc021/tasks/abc021_c)<br>
- [BFS,最短経路,経路の数え上げ]<br>

ミスったこと、1e9+7で割った余りを出力するのを忘れていた
<br>
- 難しかったこと 
BFSのときに、既にみた頂点とか、そこに行く道の最短であるよってことをどうやって書くかに悩んだ。<br>

Aからの距離がKの頂点xに行く最短の道順が何通りあるか。<br>
それは、Aからの距離がK-1であり、さらにそこから1進むとxに行ける頂点を(x0,x1,...,)とします。<br>
すると、Aからxへの最短の道順の個数は、Aからx0までの個数、Aからx1までの個数…って感じ。<br>

### [ABC020 C-壁抜け](https://atcoder.jp/contests/abc020/tasks/abc020_c)
- [二分探索,幅優先探索が難しい]<br>

あるxが達成可能かを判定しよう！
xが可能ならx-1は可能なのは分かると思う。単調性があるってやつだね〜<br>
最初は、黒を通る回数をできるだけ少なくして、出来るだけ最短手数で行けばいいって思ったんだけど、必ずしもそうじゃないたぷ…
S####<br>
.###G<br>
.....<br>
みたいな時、最短で行くよりなんとなく.だけ通ってS->Gの方が良さそうなパターンもあるたぷ…<br>
だから、x の値を二分探索で求めた
### [2020/06/21](https://iloveconviniboshi.hatenablog.com/entry/2020/06/22/144247)
### [ABC016 C- 友達の友達](https://atcoder.jp/contests/abc016/tasks/abc016_3)
- [set,重複は許さない]<br>


### [ABC171 A~E](https://atcoder.jp/contests/abc171/tasks)

#### [A- αlphabet](https://atcoder.jp/contests/abc171/tasks/abc171_a)<br>
- [英小文字と英大文字,知らない関数]<br>

解説放送3秒だけ見ました。
どうやら、is_lower,is_upperという関数がc++にはあるらしいです。すごいですね。

#### [B- Mix Juice](https://atcoder.jp/contests/abc171/tasks/abc171_b)<br>
- [ソート,最小化]<br>
やすいのをK個買えば良い

#### [C- One Quadrillion and One Dalmatians](https://atcoder.jp/contests/abc171/tasks/abc171_c)
- [26進数変換、バグ梅小宮]<br>

10進数を2進数に変換するノリでやってあげればノリノリ。<br>

### [D- Replacing](https://atcoder.jp/contests/abc171/tasks/abc171_d)<br>
- [連想配列,和]<br>

Bi を Ci に変えるたびに、a0が3個、a1が514個、a2が3個。みたいにやるのはめんどくさいです。<br>（計算量的にもね)<br>

最初に全部の和を求めておきます(sum)。<br>
biがciに変わる時、sumからはbi*(biの個数)が引かれ、ci*(biの個数)がたされます。この操作をするだけです。それぞれの数字が何個あるかは連想配列で管理してあげましょう。<br>

#### [E- Red Scarf](https://atcoder.jp/contests/abc171/tasks/abc171_e)<br>
- [XOR,XORの性質]<br>

XORの基本的な性質として、 K XOR K = 0 がありますね。<br>
また、 K XOR 0 = K です。<br>（**多分**)<br>

[ABC147 D- Xor Sum4](https://atcoder.jp/contests/abc147/tasks/abc147_d)<br>
この回で、XORワケワカランくて調べてたときに上の性質は知りました。結局其の性質を知っても上の問題は解けなかったんだけどね。<br>

で、つまり、a[0] ~ a[n-1]までのXORを取ったものに対してa[i] のXORを取れば、a[0] ~ a[n-1] (a[i]は除く)のXORを取ったものが求められるじゃん。え、なめてるの？って感じで通しました。(E,でしょ？え、これで通るよね？でもEだよ？通らなかったらどうしよう…って思いながら提出するとACでした)<br>
### [2020/06/22](https://iloveconviniboshi.hatenablog.com/entry/2020/06/24/083721)
### [ABC123 D-Cake 123](https://atcoder.jp/contests/abc123/tasks/abc123_d)<br>
- [大きい方から何番目,優先度付きキュー]<br>

結構頑張った。難しい。<br>
まず、x,y,zがそれぞれ10^3を最大取るので、x * y * z通りの美味しさを全て列挙するのは無理無理無理無理カタツムリ(10^9列挙したら時間が無理で死ぬ)<br>


なんとなく半分全列挙みたいな言葉が浮かんで、それは関係ないんだけど、とりあえず,Aから1個、Bから1個ずつとるx * y通りの組み合わせなら10^6個の組み合わせ（が最大）なので全部並べてソートも出来るな。ってことが分かった<br>

当然ながら、美味しさが一番大きいものは、 Aから最大、Bから最大、Cから最大。<br>

AとBから1個ずつ取ったx * y 通りの美味しさの組み合わせの配列（？？）(AB配列って言っとく)を昇順にソートしてやると、各Ciを使ったときに美味しさが一番大きい条件って,Ci+ABの一番大きいやつ。<br>

これを z　個優先度付きキューにブチこんでやって、ってやれば解けた。（すごい)<br>

C0,C1,C2,...,Cz-1に対して一番大きいのはAB[n-1]にCi( 0 <= i <= z-1)を足したものだな〜なイメージから行ける（俺は天才だからソレで行ける)
### [2020/06/23](https://iloveconviniboshi.hatenablog.com/entry/2020/06/25/220832)
#### [ABC122 D- We Like AGC](https://atcoder.jp/contests/abc122/tasks/abc122_d)<br>
- [DP]<br>

ダメになるパターンを列挙して頑張る。
DPの配列に、1文字前,2文字前、3文字前のアルファベットが何かの状態をもたせる。

### [ARC089 D- Xor Sum 2](https://atcoder.jp/contests/arc098/tasks/arc098_b)<br>
- [Xorの性質,尺とり法]<br>

xorは、繰り上がりの無い足し算。<br>
010と100のように、各bit桁ごとに、立っているもののかずが1個以下のとき
010 xor 100 = 010 + 100 と一緒。<br>

### [2020/06/26](https://iloveconviniboshi.hatenablog.com/entry/2020/06/26/121340?_ga=2.8802485.1892439041.1593090626-483240232.1590084557)<br>
#### [ABC145 E- All-you-can-eat](https://atcoder.jp/contests/abc145/tasks/abc145_e)<br>
- [ﾁｮｯﾄﾖｸﾜｶﾗﾅｲ,最適化,分かったかも]<br>

注文する料理の中で、時間が最も係るものを最後に注文すればいい。だから時間で昇順にソートしておくと良い。

ただのDPだけでは解けず<br>
```cpp
	rep(i,n){
		rep(j,t){
			chmax(dp[i+1][j], dp[i][j]);
			int nj = j + p[i].first;
			if(nj < t)
			chmax(dp[i+1][nj], dp[i][j] + p[i].second);
		}
		int now = dp[i][t-1]+p[i].second;  // ここが要
		chmax(ans,now);
	}
```
int now = dp[i][t-1]+p[i].second; 
が重要アル<br>
こいつが、一個だけ食べるのに係る時間を無視して食える。みたいなことを意味している。<br>


### [ABC133 E- Virus Tree 2](https://atcoder.jp/contests/abc133/tasks/abc133_e)<br>
- [木,mod数え上げ]<br>
解けた！！

どの頂点から色を決めて行っても一緒だろ（数え上げの経験から）<br>
だから、テキトウに根を決めて、其の色を塗る。<br>
BFSで次の頂点を見る。（この時の注目する頂点をvとする)<br>
vの周りで、既に色が塗られている頂点を数えて、vをk-(今数えた数)通りで塗る。<br>
って言うことをやっていきました。既に塗ったかどうかはboolの配列で管理しました。

### [ABC132 E- Hopscotch Addict](https://atcoder.jp/contests/abc132/tasks/abc132_e)<br>
- [有向グラフ,グラフの拡張,ちょうどゴール]

始めて見るタイプの難しいグラフの問題でした。写経ACです。
頂点sから頂点tに、どうにかして３の倍数回の移動でゴールしたい<br>
そんなときは、頂点に状態を持たせて、1つの頂点を3倍に拡張してやるといいらしいです。<br>
まぁ、ちょっと理解あれだけど、知識増えたってことでヨシ。

### [2020/09/02](https://iloveconviniboshi.hatenablog.com/entry/2020/09/02/220539?_ga=2.98818008.733986864.1599051941-1402813250.1599051941)


### [ARC013 B-引っ越しできるかな？](https://atcoder.jp/contests/arc013/tasks/arc013_2)
- [最適化,最小化]<br>
それぞれの荷物について、縦、横、高さがありますが、どれが縦とか横とか別にどうでもいいので、用意したい箱の縦、横、高さを、縦が一番短く、高さが一番長くするようにしようかな。っていう解法。（証明不明）<br>
つまり、入力で与えられる N, M, L を N <= M <= L とする。 N <= M <= L でないならば、適当にN,M,Lを入れ替えてやる。
そうして、N0 ~ Ncのうち最大のものが箱の縦の長さ。<br>
M0 ~ Mc のうち最大のものが箱の横の長さ。<br>って感じでやれば解ける。
<br>
解説でもなんでもないな。

うーん、お気持ちを言えば、いったん全ての荷物について、どの辺を縦にして、どの辺を横にして、どの辺を高さにするか、向きを決めてやる。って感じかな。

各荷物の一番短い辺の長さを縦として採用したい！！！<br>みたいなね。

### [CODE FESTIVAL 2014 決勝 D-パスカルの三角形](https://atcoder.jp/contests/code-festival-2014-final/tasks/code_festival_final_d)
- [パスカルの三角形もどき,ﾋﾗﾒｷ~]<br>
パスカルの三角形を実際に書いてみたら、(1-indexed)で左から2番目の数は1ずつ増えていってることが分かるから、任意の数がパスカルの三角形に登場することが分かる。

具体的には、ある数AはA+1段目の左から2番めに出てきます（あ、答え言っちゃった）

### [dwangoプログラミングコンテスト B-ニコニコ文字列](https://atcoder.jp/contests/dwango2015-prelims/tasks/dwango2015_prelims_2)
- [部分文字列,数え上げ,ほんのひと粒の涙]<br>
ｴｯﾄﾈ,この問題の答えの最大値は,5 * 10^4 の2乗なんだけど、それは2^32に収まらないのでlong long を使おうね。（そのときの入力は、2525252525...25(5万組の25)です)<br>

## [この日の日記(11/10)](https://iloveconviniboshi.hatenablog.com/entry/2020/11/10/064953)
### [ABC066 D-11](https://atcoder.jp/contests/abc066/tasks/arc077_b)<br>
- [ncm,包除原理(とまでは言わない?)]<br>

まず,答えに影響するのは，a[i] == a[j] (i != j)となるようなa[i]という値ではなく，
iとjの値です．<br>
どの数字が2つあるかっていうのは興味がなくて，同じ数字が，どれくらい離れた距離にでてくるのかということにしか興味がありません．<br>

まぁ，どうにかして2つの被ってる値の距離を求めて，その2つの間にある数字の数を mid としましょう<br>
(つまり, a[i], a[i+1], a[i+2], ... , a[i+mid], a[j] です(j-i-1がmid);
さて，ここまで書いた上で投げやりですが，[解説PDF](https://img.atcoder.jp/arc077/editorial.pdf)が分かりやすいのでこれを読んでください．<br>

ちなみに，なんの数字が被っている．というのは実は簡単に知ることができます．
sum = a_0 + a_1 + ... + a_n;とすると，<br>
sum - (n * (n+1) / 2) の計算結果の値が2つでてきています．<br>

### [ABC005 D-おいしいたこ焼きの焼き方](https://atcoder.jp/contests/abc005/tasks/abc005_4)<br>
- [たこ焼きのタコは食べれる,二次元累積和,実装神]<br>

某んちょんさんのコードを写経しました．<br>
[コード](https://atcoder.jp/contests/abc005/submissions/18021202)<br>
何が素晴らしいかって，面積vを0〜n * n でループを回すんじゃなくて，長方形の左上と右下（伝われ！）の4点を4重ループで回して，x1,x2,y1,y2を決めて,その時の面積を求めることで val[v]を更新する．っていうところがイケメンだなって思いました．<br>

さて，二次元累積和って難しいですよね<br>

### [ABC086 D-Checker](https://atcoder.jp/contests/abc086/tasks/arc089_b)<br>
- [二次元累積和,反転GG,条件の変換,激難,市松お粗末]<br>
**困りました，このモンダイについての考察は大嘘を含んでいます．見るな**

このモンダイ，まだ自力できてないけどニャン<br>
何が感動するかって，(2 * k) * (2 * k)のサイズしか考えなくて良くなることもそうなんだけど，
白がx[i] , y[i]にあるっていう条件は，黒がx[i]+k, y[i]にある (もしくはx[i],y[i]+k)っていうのと同値であると変形できるんす！！<br>(すげー)<br>
もう一個同値としては，x[i], y[i]に黒があるっていう条件は， x[i] - 2k, y[i]に黒があるっていう条件と一緒(y[i] - 2kでも良い)ってことなんすね〜〜.<br>

つまりx[i], y[i] 黒 -> x[i]%2k, y[i]%2k 黒 って変換をしちゃおうってね！<br>

こっから先の二次元累積和は，難しい．また今度．<br>

### [ABC155 D-Pairs](https://atcoder.jp/contests/abc155/tasks/abc155_d)<br>
- [二分探索，lower_bound, upper_bound, 二分探索の自力実装,むずかしめ，条件の言い換え]<br>

解説動画からの引用的な雑書きになる．
<br>
K番目に来る数をxとすると, xは**x未満の数がK個未満であるもののうち，最大の値**と言い換えることができます．<br>

たとえば，1,2,3,3,4,5,6 っていうのが遭って，K = 2だとしよう<br>
**x未満の数がK個未満であるもののうち，最大の値**という条件を見ていこう！
<br>
K = 2 だよ<br>
1は，1未満（0以下)の数が0個(< K)なのでOK<br>
2は2未満(1以下)の数が1個(< K) なので OK<br>
3は,3未満(2以下)の数が2個( == K) なので NG<br>
よって，条件を満たすものの最大の値は2で,実際の答えも2です<Br>

次に,K=3のとき(もう一回数列貼っておくね)<br>
1,2,3,3,4,5,6<br>
1は1未満（0以下)の数が0個(< K)なのでOK<br>
2は2未満(1以下)の数が1個(< K) なので OK<br>
3は3未満(2以下)の数が2個(<  K) なので OK<br>
4は4未満(3以下)の数が4個(>=  K) なので NG<br>
よって，条件を満たすものの最大の値は3で，実際の答えも3だからOK~~<br>

とまあ，この条件の言い換えが重要で，**x未満の数がK個未満であるもののうち，最大の値**という条件には単調性が生まれるんですよね（日本語知らん)， X < Y のとき，Yが条件を満たしていたら,Xも条件を満たしているんですよね<br>
天才かよ．と思いました．<br>

後は，x未満の数が何個あるか数えるパートですね．<br>
これは，a_0 からa_1, ... ,a_nに対してそれぞれ何個あるかの和を求めます．<br>
今,a_iについてa_i * a_j < x となるようなjの最大値を知りたいです!!<br>
一回簡単のためにa_iは正の数としておきましょう．あ，あと数列aはソート済みってことにしといて．<br>

はいじゃあ，a_i * hoge < x のとき，式変形をして
<br>
hoge < x / a_i ですね<br>
つまり，x/a_i は条件を満たしてくれる，そして， x/a_i + 1 は条件(a_iとの積 < x)を満たしてくれません<br>
x/a_i + 1 = searchとでも置いておきましょう．<br>
はい．今，aがソート済みであるとき， search以上の値が最初に出てくる位置，はlower_boundを用いて求めることができますね．<br>
これで，a_iに対して a_i * hoge < x となるhogeが何個あるかは求めることができます．<br>
lower_boundで求まった位置をjとすると，a[j-1]までならa_i * a[j-1] < x なので，hogeはj個あります．
<br>
iを0からn_1までやって，hogeが合計何個あるかをtmp個としましょう<br>
この時tmp < K だったら，xは**x未満の数がK個未満であるもの**です．<br>

ハイ次，さっきは，aが全て正の数だと言っていましたが，aに負の値が含まれているときを考えよう．<br>

-5,-3, -3, -2, -1, -1,  0, 4 , 5 みたいなときや<br>
まぁなんかテキトウに，x = 11とでもして a_0=-5)に対して，a_0 との積が11未満になるものの数を数えよう．
<br>
これをさっきと同じふうに search = (x/a_i + 1)としてしまうと，search = (11/(-5) + 1) = -1?になります(負の値の除算分からん)で，正の値のときと同じように，search以上の値が最初に出てくる位置(j)を求めると,  j = 3 と出てきますね(a_j = -1)<br>
でもでもでもでも，さっき(aが正だけのとき)は， j = 3 として出てきたら，
a_i * a_0 もa_i * a_1 もa_i * a_2 も全部x未満だったじゃん？でも今回は違うんだよ<br>
だってほら，a_i (=-5) * a_0 (= -5) = 25じゃん<br>
x = 11 じゃん．<br>
25 > 11 じゃん<br>

つまり，a_i < 0 のときは，aを右からみて何個取れるか，って考えなきゃいけないんだ！！<br>
俺はここで実装つまらせて泣いて泣いて泣いて泣いてたんだけど,でも実はこれってupper_boundを使えばよくて(DA?GOの口調)...<br>
aが昇順になってることから，まぁ二分探索で位置求めるのが楽っていうのはそれはそうです．<Br>
探す値が -1 っていうのは間違ってますね．<Br>
ここでは，a_i * (探す値) >= xとなってほしいのに， a_i * (-1) = -5 * -1 = 5 で，x(=11)よりも小さいです．<br>
だからどうやら，a_iが負の時は，探す値を x/a_i - 1としなきゃいけないみたいですね(へー)<br>
今回は，11/(-5) - 1 = -3 としてsearchが取れて，-5 * -3 = 15 > 11 なのでなるほど確かにそのようになっていますね．<br>
-5,-3, ( * )-3, -2, -1, -1,  0, 4 , 5の中から-3を探す時，米印をつけた方の-3の位置を見つけて欲しいです．<br>
なんでかっていうと,a_iが-5のときに a_i * hoge < x になるものは，<br>
-5,-3, -3, [-2, -1, -1,  0, 4 , 5] のように[]で囲った部分でしゅ<br>
だから，upper_boundで，-3以上となるindexのなかで最大のものを…(あれ？嘘じゃん),-3以下となる値で一番右の位置を求めないといけないじゃん．


### [ABC093 D-Worst Case](https://atcoder.jp/contests/abc093/tasks/arc094_b)<br>
- [二分探索,良い位置,二項の積の性質]<br>
面白いモンダイですね．<br>
とりあえずまぁ，二分探索を使うということが分かったという前提（はい)でやっていきます<br>

今，高橋くんよりスコアの低い人物がX人はokかngかを判定したいです．<br>
X人に対して，1試合メと2試合目で何位だったかを考えると，1試合目では1位からX位（とちゅうでA[i]があるならX+1位まで)のX人,
2試合目では1位からX位（途中でB[i]があるならB[i]位を除いてX+1位まで)のX人としてあげるのがいいことは何となく分かると思います．<br>
X位の人を使わないで Y位(X < Y)にしたって,スコアが大きくなるだけで損なだけだしね．<br>
で，1試合目と2試合目の組？みたいなのを考えた時，1試合目で1位だった人は2試合目でX位ぐらい(2試合目として採用する順位の中で一番順位的に悪いやつ)だったことにしてって感じでやると，<br>
X人についての1試合目のスコア * 2試合目のスコア っていうものの最大値を最小にすることが出来るっピ<br>
まぁ，こんな感じで最大値の最小値が高橋くんのスコアよりモヒかければ，X人は達成出来る．って感じでやっていけばええんや．<br>
がんばれ，俺は頑張った．<br>

### [ABC182 E- Akari](https://atcoder.jp/contests/abc182/tasks/abc182_e)<br>
- [まだ解説読んでない,分解，Lamp,実装がんばえ]<br>

ランプを見つける度に上下を照らして，左右を照らして…ってやると脳がバグります（僕はバグりました)<Br>
そこで，ランプを2種類あると考えます．
<br>
左右のみを照らすランプと，上下のみを照らすランプの2つです．<br>
H * W のマス目を2つ用意します．
1つは，左右のみを照らすランプを考えるようのマス目<br>
もう1つは，上下のみを照らすランプを考えるようのマス目<br>

それぞれのマス目の上で，左右のみマス目では，
ランプの隣が壁じゃなければ，そのマスの右もランプに感染させる．みたいなことをします．<br>
すると，..o..#..みたいなマス目が(.は何もないます，oはランプ，#は壁)<Br>
..ooo#..に変化します．<br>
次に，ランプの隣が壁じゃなければ，そのますの左もランプに感染させる．ってことをします．
<br>
するとooooo#..ってなります．<br>

上下のみてらすランプがあるマス目でも，同じようなことをします．<br>

この操作をした後に，H * W ます全部に対して， 左右のみランプ， 上下のみランプのマスのどっちかでランプとして感染済み(もしくは元からランプだった)なら，照らされるマスとしてカウントする．っていうことをやってやります<br>

## [2021年1月11日](https://iloveconviniboshi.hatenablog.com/entry/2021/01/11/044531?_ga=2.73309914.871680361.1610307933-877367824.1610307933)<br>
### [ABC188 F-+1-1x2](https://atcoder.jp/contests/abc188/tasks/abc188_f)
[DFS,深さ優先探索,数字操作,メモ化再帰]
これ難しくないですか.難しいですね.
## [2021年 1月 12日](https://iloveconviniboshi.hatenablog.com/entry/2021/01/12/040251)

### [パナソニックプログラミングコンテスト (ABC186) E-Throne](https://atcoder.jp/contests/abc186/tasks/abc186_e)
[拡張ユーグリッド,extgcd,逆元]<br>
S + X * K = α * N (α は1以上の整数)よなるような最小のXを求めよという問題.<br>
X * K ≡  -S (mod N) を解く.みたいなノリっぽいですね.<br>

ここで X ≡ -S * (Kの逆元) として解きたいなあ.みたいな感じなんだけど,ここから先が分からなくて解けなかった.<br>
そのうち理解したくなったら蟻本の260pを見よう♡
ちなみに,逆元に関する知識として,
mod が素数じゃない時は,逆元が存在しないときもあるらしいよ.
素数じゃないときは,互いに素なら存在する.らしい!!!
## [2021年 1月 17日,解いた問題](https://iloveconviniboshi.hatenablog.com/entry/2021/01/17/094840?_ga=2.99226391.805908328.1610746273-483240232.1590084557)
### [ARC007 C-節約生活](https://atcoder.jp/contests/arc007/tasks/arc007_3)
- [bitDP,集合を管理するDP]
問題の概要<br>'oxoxooo'みたいなのを繰り返し使い,oとxが重なった部分はoにすることで,'ooooooo'にしたい.(ちょっとめんどくさい言い換え)<br>

## [2021年1月19日解いた問題](https://iloveconviniboshi.hatenablog.com/entry/2021/01/19/071455?_ga=2.165123135.1272425326.1611008184-1138787412.1611008184)
### [ABC007 D-禁止された数字](https://atcoder.jp/contests/abc007/tasks/abc007_4)
[桁DP,MOD使わないぴょん,遷移4通り?,もらうDP]
K以下の整数の中で,4か9を含んでしまう整数は何通りありますか?<br>
桁DPを頑張る.良かったら記事見て

## [2021年8月8日解いた問題](https://iloveconviniboshi.hatenablog.com/entry/2021/08/08/050314)
### [AGC053 A- ><again](https://atcoder.jp/contests/agc053/tasks/agc053_a)
[良い非負整数列,整数列の分解]

## [2021年8月10日解いた問題](https://iloveconviniboshi.hatenablog.com/entry/2021/08/08/050314)
### [COLOCON -Colopl programming contest 2018- C- すぬけそだてーーごはんーー ](https://atcoder.jp/contests/colopl2018-qual/tasks/colopl2018_qual_c)


[嬉しい,素数の個数,全探索,bitDP,UnionFindではない]<br>
## [2021年8月11日解いた問題](https://iloveconviniboshi.hatenablog.com/entry/2021/08/12/202621)
### [ABC195 F- Coprime Present](https://atcoder.jp/contests/abc195/tasks/abc195_f)

[嬉しい,[素数](http://d.hatena.ne.jp/keyword/%C1%C7%BF%F4)の個数,bitDP,UnionFindではない]<br>

昨日やった[すぬけそだてーーごはんーー](https://atcoder.jp/contests/colopl2018-qual/tasks/colopl2018_qual_c)の制約が厳しい版です(情報提供・あさか，こいつは本番で通した．犯罪だね)．   
### [ABC073 D- Joisino's travel](https://atcoder.jp/contests/abc073/tasks/abc073_d)

[ワーシャるフロイド法,next_permutation,bitDPによる巡回セールスマンっぽい]<br>


### [ABC180 E- **E - Traveling Salesman among Aerial Cities**](https://atcoder.jp/contests/abc180/tasks/abc180_e)

[ワーシャルフロイド法,bitDP,巡回セールスマン]<br>

Joisino's travelのように，next_permutationを用いていたら実行時間が間に合わないっすね．17の階乗は，10を8回以上かけているのでどう考えても間に合わないです．<br>

## [2022年2月10日](https://iloveconviniboshi.hatenablog.com/entry/2022/02/10/190309)

久しぶりに競プロ解いた問題の解説書いたわあ(解説…?）

###  [ABC226 D - Teleportation](https://atcoder.jp/contests/abc226/tasks/abc226_d)

[全探索、辞書型配列,比の約分]

1. 各頂点から(自身以外の)各頂点へ、1つの魔法のみを使って移動する
2. 1つの魔法であれば、何回使ってもいい
3. 任意の頂点から、任意の頂点へ、上記のルールで移動するとき、魔法が最小で何種類あればいいかを求める問題



### [ABC232 C - Graph Isomorphism](https://atcoder.jp/contests/abc232/tasks/abc232_c)

[順列全探索,,nextpermutation,頭壊れる]  
next permutationっぽいなコレ。こういう問題頭壊れるｯｽﾈ



## [2022年2月11日](https://iloveconviniboshi.hatenablog.com/entry/2022/02/11/232939)

###   [ABC225 C - Calendar Validator](https://atcoder.jp/contests/abc225/tasks/abc225_c)

- [書けばわかる、サンプルがすべてじゃない、オーバーフローしない、灰diff]

灰色diffだけど、そこそこ難しい。サンプルが通っても勝ちじゃない<br>

書けばわかるんだけど、行列Aを書くと、こうなるよ

[2020-03-28](https://iloveconviniboshi.hatenablog.com/archive/2020/03/28)

[2022-04-03](https://iloveconviniboshi.hatenablog.com/archive/2022/04/03)

## [4月3日](https://iloveconviniboshi.hatenablog.com/entry/2022/04/03/195520)

[ABC246-E Bishop 2](https://atcoder.jp/contests/abc246/tasks/abc246_e)

[01-BFS, 普通のBFSじゃTLE,斜め移動]

- [ユーザ解説](https://atcoder.jp/contests/abc246/editorial/3728) by [**sounansya**](https://atcoder.jp/users/sounansya)が優秀すぎるデス…（CV.チノちゃん)

自分はこのTLEが出るところまでできましたが、TLEを取ることができなかった…力不足デス…（CV.チノちゃん)
普通の幅優先探索しようとすると、queueに入れて…って感じでまわしますよね。でもそれだとTLE…どうしてTLEになってしまうかは分かりません(ｴｰｯ！！(cv.はちわれ))

### [ABC246-F typewriter](https://atcoder.jp/contests/abc246/tasks/abc246_f)

[動的計画法、桁DP的な？文字列数え上げ、ncm,]

厄介な問題デス…<br>

'a'と'b'のみの長さLの文字列と、'b'と'c'飲みの長さLの文字列の個数は一緒です。それぞれは干渉しません。


## [2020-04-04](https://iloveconviniboshi.hatenablog.com/entry/2022/04/04/193621)

### [ABC174 F- Range Set Query](https://atcoder.jp/contests/abc174/tasks/abc174_f)

[Mo's Algorithm, 区間クエリ,区間の種類]

Moの中身は分からないけど、とりあえずこれ参照しよう！
[こーど](https://atcoder.jp/contests/abc174/submissions/30719970)
注意点として、C++を使っていたら cin や cout endlをしちゃうとTLEになります（うげ〜）

### [2022年4月11日くらい](https://iloveconviniboshi.hatenablog.com/entry/2022/04/11/010603)

### [ARC138 A-Lerger Score](https://atcoder.jp/contests/arc138/tasks/arc138_a)

[添字を持った配列、優先度付きキュー、だんだん選べるものが増えていくタイプ,ソート]

スコアをS+1にすると誤読していた。
1点以上上げれば良いのだから、Aにある要素を一つだけそれより大きいものに変えてやれば良い。

### [ARC138 B- 01 Generation](https://atcoder.jp/contests/arc138/tasks/arc138_b)

[0と1からなる数列の構築、構築、操作を逆に考える]
操作を逆に考えると、ヤル操作は、後ろの０を取るか、前の０を取ってFlipかの２通り。

後ろの０を取るのを優先してやって、空の文字列にできれば勝ち

### [ARC138 D-Differ by K bits](https://atcoder.jp/contests/arc138/tasks/arc138_d)

[XORの基底？]
なんか頑張った気がするけど解けなかった。難しかった。よう復習。

### [ABC247 C- 1 2 1 3 1 2 1](https://atcoder.jp/contests/abc247/tasks/abc247_c)

[再帰、butilin_ctz, popcount]

[naoyaさんのGCCのビルトイン関数メモ](https://naoyat.hatenablog.jp/entry/2014/05/12/143650)が参考になりそう。

適当な再帰関数を書いてあげると通る。

### [ABC247 D- Cylinder](https://atcoder.jp/contests/abc247/tasks/abc247_d)

[DはdequeueのD,何が何個あるかが大事]

5を５個追加ってとき、5,5,5,5,5って追加するなじゃなくて、(5,5)を追加する。

### [ABC247 E- Max Min](https://atcoder.jp/contests/abc247/tasks/abc247_e)

[セグ木？うるせえよ。DP、状態を持つDP] <br>

### [ABC247 F- Cards](https://atcoder.jp/contests/abc247/tasks/abc247_f)

[Lucas数、連続した2個のうち1個は取るやつ、リュカ数]

類題があった気がするけど忘れた。ブログを書こうね。<br>

見たことがある感じ、カードの表裏は辺を貼るみたいなの典型なのかな？<br>

UnionFindでくっつけて、みたいな感じなところは直感で出来たんだけど、島のサイズに対する答えの求め方がわからなかった。でもそれがLucas数ってやつになるらしい

注意点としては例えば5つに対して取る取らないを決める。ただし、連続して2回取らないをしちゃだめってトキ

xoxoxはNGです。みたいな感じな注意がある。でもそれもリュカ数で数えられちゃうらしい。すごい。

##  [2022年4月13日](https://iloveconviniboshi.hatenablog.com/entry/2022/04/13/133508)

### [ABC236 F- Spices](https://atcoder.jp/contests/abc236/tasks/abc236_f)

[XORの基底、内部は分からない、類題あり、解説動画優秀、掃き出し法]

[先日行われたARC138 D-Differ by K bits](https://atcoder.jp/contests/arc138/tasks/arc138_d)の類題ってことで良いですか？良いですよ。<br>

掃き出し法のわけが分からない実装ですが、

- [公式解説 ](https://youtu.be/kuZBAs80RRo) by [**admin**](https://atcoder.jp/users/admin)

を見るとちょっとだけ「あー、そんな感じノコとしてるのね。知らんけど」ってなります。

```cpp
for(int e : order){
		
		for(int b : basis){
			chmin(e, e ^ b);
		}
		if(e){
			basis.push_back(e);
		
		}
	}
```

このコード、Twitterでのし袋さんがのけてたやつみたいな感じです。

これをすると、basisに配列 orderの中から基底が取り出せるらしい

### [2022年5月8日　日記](https://iloveconviniboshi.hatenablog.com/entry/2022/05/08/100952)

本気解説，書いた。親愛なる先輩へ，愛をこめて。

### [ABC248 F- Keep Connect](https://atcoder.jp/contests/abc248/tasks/abc248_f)

[連結DP, 連結状態,がんばれ,記事書いた]<br>

連結DPとかいうのに初挑戦した。
気持ち，桁DPに似ている。絶対不可能な状態には遷移しないように注意しつつ，okな状態(連結な状態),非連結な状態みたいな感じ。
ただ，桁DPと違って，一度連結になったとしてもその後連結じゃないみたいな感じになるっていうのがややこしいところ。

#### [AGC057 A- Antichain of Integer Strings](https://atcoder.jp/contests/agc057/tasks/agc057_a)

[凶悪二分探索,愚直死ぬ,わけわからん]

よく分からないけど，わかるのはWriterのmaspyさんが天才ってことだけ。
