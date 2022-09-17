#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define Per(i, a, b)    for(int i = (a) ; i>=(b);--i)
#define per(i, n)       Per(i,0,n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Line
ll dp[1010][15][15][15];
// dp[i][a1][a2][a3] := 長さがiで、長さがjの部分増加列の最後尾として考えられる最小値がajであるような数列の数
int main()
{
    ll n, m; cin >> n >> m;
    dp[0][m+1][m+1][m+1] = 1;
    rep(i,n)For(a1,1,m+2)For(a2,1,m+2)For(a3,1,m+2){
        For(x,1,m+1){
            // 数列のi+1項目をxとする
            if(x<=a1)  dp[i+1][x][a2][a3] += dp[i][a1][a2][a3];
            else if(x<=a2)  dp[i+1][a1][x][a3] += dp[i][a1][a2][a3];
            else if(x<=a3)  dp[i+1][a1][a2][x] += dp[i][a1][a2][a3];
            dp[i+1][x][a2][a3] %= MOD;
            dp[i+1][a1][x][a3] %= MOD;
            dp[i+1][a1][a2][x] %= MOD;
        }
    }
    ll ans = 0;
    For(a1,1,m+1)For(a2,a1+1,m+1)For(a3,a2+1,m+1){
        ans += dp[n][a1][a2][a3];
        ans %= MOD;
    }
    cout << ans << endl;
}