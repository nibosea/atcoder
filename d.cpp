#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define fore(i, a) for(auto &i: a)
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
ll dp[100005][10];
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    // n * 10 なら行ける。配列持てる。
    rep(i,n) cin >> a[i];
    // dp[i][j]:= i個の要素を削除した時点で、一番左がjでである
    dp[0][a[0]] = 1;
    for(int i = 1; i < n; i++){
        //dp[i]を作る
        int num = a[i];
        rep(j,10){
            int sum = (j + num) % 10;
            int mul = (j * num) % 10;
            dp[i][sum] += dp[i-1][j];
            dp[i][mul] += dp[i-1][j];
            dp[i][sum] %= MOD;
            dp[i][mul] %= MOD;
        }
    }
    rep(i,10){
        cout << dp[n-1][i] << endl;
    }
}