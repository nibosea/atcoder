Q=int(input())
query=[]
L_pointer=0
R_pointer=0
sum_list=[]
for j in range(Q):
    #print('L:',L_pointer,'/R:',R_pointer)
    #print(query)
    this_query = list(map(int,input().split()))
#　数字query[1]をquery[2]回突っ込んでいる
    if this_query[0]==1:
        R_pointer+=this_query[2]
        for i in range(this_query[2]):
            query.append(this_query[1])
    elif this_query[0]==2:
        sum=0
        for i in range(this_query[1]):
            sum += query[L_pointer+i]
        L_pointer+=this_query[1]
        sum_list.append(sum)

for i in sum_list:
    print(i)
