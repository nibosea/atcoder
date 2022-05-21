#==================
#参考
#https://qiita.com/jamjamjam/items/e066b8c7bc85487c0785

### 一文字受け取る
## str型
#s = input()
## int型
#s = int(input())

### (1,N)行列を受け取る
## str型・listに格納
# s = input().split()
## str型・それぞれの変数に格納
# a, b, c = input().split()
## int型・listに格納
# s = list(map(int, input().split()))
## int型・それぞれの変数に格納
# a, b, c = map(int, input().split())
#==================
N = int(input())
S = []
S_index_list = []#S[i][j] := i番目のスロットにおける数字jのインデックス
best_time = 10*(N+1)

for n in range(N):
    s = input()
    S.append(s)
    index_list = [0,0,0,0,0,0,0,0,0,0]
    for i in range(10):
        num = int(s[i])
        index_list[num] = i
    S_index_list.append(index_list)

for num in range(10): #num := 今揃えたい数字
    used_current_time_list = [0,0,0,0,0,0,0,0,0,0]
    for n in range(N): #n個目のスロットをチェックするよ
        time = S_index_list[n][num] # time := スロットnのnumを得るために押す最速の時間
        used_current_time_list[time] += 1

    current_time = 0 #numを揃える為にかかった時間
    mode_time = 0 #used_current_time_listの最頻値
    mode_time_index = 10 #mode_timeを得るためのインデックス
    last_time = 0 
    for time in range(10):
        if used_current_time_list[time] >= mode_time:
            mode_time = used_current_time_list[time]
            mode_time_index = time
        if used_current_time_list[time] != 0:
            last_time = time

        if mode_time == 1:#秒数が散らばっているときは、一番最後だけ採用すればOK
            current_time = last_time 
        else:#秒数が偏っているときは一番回数が多いやつを考えてあげる
            current_time = (mode_time - 1) * 10 + mode_time_index

    if current_time < best_time:
        best_time = current_time

print(best_time)
