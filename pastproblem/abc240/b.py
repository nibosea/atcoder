n = int(input())
a = list(map(int, input().split()))
ans = 0
for i in range(n):
    appeared = False;
    for j in range(i):
        if a[i] == a[j]:
            appeared = True
    if not appeared:
        ans += 1
print(ans)