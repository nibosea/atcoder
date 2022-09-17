#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int b[1000];
    int v=3;
    for(int i=0;i<1000;i++)
    {
        int x=v;
        int ans=0;
        while(x>0)
        {
            x=x&(x-1);
            ans++;
        }
        while(ans%2!=0)
        {
            v++;
            ans=0;
            x=v;
            while(x>0)
            {
                x=x&(x-1);
                ans++;
            }
        }
        b[i]=v;
        v++;
    }
    for(int j=0;j<t;j++)
    {
        int n;
        cin>>n;
        for(int j=0;j<n;j++) cout<<b[j]<<" ";
        cout<<endl;
    }
    return 0;
}
