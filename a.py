import sys
sys.setrecursionlimit(10000)

# input
N,M = map(int, input().split())
G=[[] for i in range(N)]
# G[i] は都市iから道路で直接つながっている都市のリスト
for i in range(M):
    A,B=map(int,input().split())
    G[A-1].append(B-1)

## dfs
def dfs(v):
    if temp[v]: return # 同じ頂点を2度以上調べないため return
    temp[v] = True
    for vv in G[v]: dfs(vv)

ans = 0

# 都市i からスタート
for i in range(N):
    temp = [False] * N
    dfs(i)
    ans += sum(temp)

print(ans)
