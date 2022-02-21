#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int,int> P;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)

int main()
{
    int n; 
    cin >> n;
    vector<int> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    map<P,bool> mp;
    rep(i,n){
        rep(j,n){
            if(i == j) continue;
            int x1,x2,y1,y2;
            x1=x[i] - x[j];
            y1=y[i] - y[j];
            // x1-x2, y1-y2 をGCD(正)で割る
            int G = __gcd(x1,y1);
            G=abs(G); //一応明示的に正の値に変換しておく
            x1 /= G;
            y1 /= G;
            mp[P(x1,y1)]=true;
        }
    }
    int ans = 0;
    for(auto x:mp){
        ans++;
    }
    cout << ans << endl;
}