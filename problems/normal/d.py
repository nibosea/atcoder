def binary_search(x, ind):
    ok = len(idx[x])
    ng = -1
    while (ok - ng) > 1:
        mid = (ok+ng)//2
        
        if idx[x][mid] >= ind:
            ok = mid
        else:
            ng = mid
        #print(mid,ok,ng)
    return ok

N = int(input())
A = list(map(int, input().rstrip().split()))
Q = int(input())
Query = [list(map(int, input().rstrip().split())) for i in range(Q)]

idx = [[] for i in range(N)]

for i, a in enumerate(A):
    idx[a-1].append(i)
    #print("i: ")
    #print(i)
    #print("a: ")
    #print(a)
#print(idx)

for q in Query:
    l,r,x = q
    l_ind = binary_search(x-1,l-1)
    #r_ind = binary_search(x-1,r)
    r_ind = binary_search(x-1,r-1)
    print(r_ind - l_ind)
    
    
