#include <bits/stdc++.h>

using namespace std;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}

int main()
{
    int n,m; cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i,m){
        int x,y;
        cin >> x >> y;
        --x,--y;
        a[i] = x; b[i] = y;
    }
    vector<int> c(m), d(m);
    map<P,bool> mp;
    rep(i,m){
        int x,y;
        cin >> x >> y;
        --x,--y;
        c[i] = x; d[i] = y;
        mp[P(x,y)] = true;
    }
    vector<int> p(n);
    rep(i,n) p[i]=i;
    do {
        bool flag=true;
        rep(i,m){
            int x, y;
            x = a[i]; y = b[i];
            if(mp[P(p[x],p[y])] || mp[P(p[y],p[x])]) continue;
            else flag = false;
        }
        if(flag){
            coY();
            return 0;
        }
    } while(next_permutation(p.begin(),p.end()));
    coN();

}