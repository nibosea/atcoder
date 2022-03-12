def solve():
    n,m=map(int,input().split())
    A=[]
    for i in range(n):
        x,y=map(int,input().split())
        A.append([x,y])
    
    ans=-10
    past_sum=0
    past=0
    all=0
    s=0

    for i in range(n):
        x,y=A[i][0],A[i][1]
        l,r=0,y
        while r-l>1:
            cen=(r+l)//2
            t=cen
            if all+(t//2)*(2*all+(t-1)*x)>=0:
            #if all+t*s+t*(t+1)//2*x>=0:
                # n/2 * (2a + (n-1)d)) 
                # t/2 * (2all + (t-1)x)
                l=cen
            else:
                r=cen
        
        #print(l)
        if x>=0:
            l=y
        if i==0:
            l=max(l,1)
        now=all+(l//2)*(2*all+(l-1)*x)
        #print(l,now)
        ans=max(ans,now)

        all=x*(y*(y+1)//2)+all+y*s
        s=s+y*x

        #print(all)
    res.append(ans)

res=[]

for _ in range(int(input())):
    solve()
print(*res)