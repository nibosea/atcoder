#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
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
int dp[310][310][310];
int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> A(n), B(n);
    rep(i,n){
        cin >> A[i] >> B[i];
    }
    rep(i,n+1)rep(tako,301)rep(tai,301) dp[i][tako][tai] = inf;
    dp[0][0][0] = 0;
    rep(i,n){
        rep(tako,x+1){
            rep(tai,y+1){
                if(dp[i][tako][tai] < inf){
                    chmin(dp[i+1][tako][tai], dp[i][tako][tai]);
                    chmin(dp[i+1][min(tako+A[i],x)][min(tai+B[i],y)], dp[i][tako][tai]+1);
                }
            }
        }
    }
    int ans = dp[n][x][y] < inf ? dp[n][x][y] : -1;
    cout << ans << endl;
}