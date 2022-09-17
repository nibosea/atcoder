#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(ll i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void coT() {cout <<"Takahashi"<<endl;}
void coA(){cout <<"Aoki"<<endl;}

void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const ll dy[] = {0,0,1,-1};
const ll dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<ll> to[200'005];
//Write From this Line
ll modpow(ll x, int a) {
    x %= MOD;
    ll re = 1;
    while (a > 0) {
        if (a % 2 == 1)re = (re*x) % MOD;
        x = (x*x) % MOD;
        a /= 2;
    }
    return re;
}

mint dp[1005][5005];
int main()
{
    ll n, m, k;
    cin >> n>> m>> k;

    // k = 0のとき、M ^ N 通り
    if(k == 0){
        cout<< modpow(m, n) << endl;
        return 0;
    }
    // k != 0 のとき、出てくる数値は5000個未満である。
    // 最小値を全探索
    
    vector<mint> sum(5005,0);
    vector<mint> sum2(5005,0);
    for(int mm = 1; mm <= m; mm++){
        // 最小値がmmのとき、数の選び方が何通りあるか
        dp[1][mm] = 1;// １個決めて,mmのときは１通り
        sum[mm] = sum[mm-1] + dp[1][mm];
    }
    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= m; j++){
            // dp[i][j]への遷移を考える
            // dp[i][j]へこれるのは、dp[i-1][x]のxがj-k以下のもの。
            // つまり、dp[i-1][1] ~ dp[i-1][j-k]のsum
            ll neko = max(0ll,j-k);
            dp[i][j] += sum[neko];
            sum2[j] = sum2[j-1] + dp[i][j];
        }
        sum=sum2;
    }
    mint ansn = 1;
    rep(i,n){
        ansn *= (i+1);
    }
    mint anssum = 0;
    For(i,1,m+1){
        cout << dp[n][i].val() << endl;
        ll x = dp[n][i].val();
        anssum += x;
        // x通りに対して、それぞれどうやって並べるかは、n!通りある
        // n! * xをansに足していく
    }
    ansn *= anssum;
    cout << ansn.val()<< endl;
}
