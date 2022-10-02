from collections import defaultdict, deque
N = int(input())
A = list(map(int,input().split()))
A_d = deque()
ans = 0
seen = defaultdict(int)
A.sort()

for a in A:
    seen[a]=+1
    A_d.append(a)
    if ans+1 == a:
        A_d.pop()
        ans += 1

if N<=1:
    print(ans)
    exit()

remain = N - ans 
while remain >= 2 or (ans+1 in seen and seen[ans+1] > 0):
    if ans+1 not in seen:
        r1 = A_d.pop()
        r2 = A_d.pop()
        seen[r1] -= 1
        seen[r2] -= 1
        remain -=2
    else:
        seen[ans+1] -= 1
        remain -=1
    ans +=1
print(ans)

