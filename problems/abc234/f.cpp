#include <bits/stdc++.h>

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
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Line
const int MAX = 510000;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

void add(ll &a, ll b){
    a += b;
    if(a >= MOD) a-=MOD;
}
ll dp[5010][30];
int main()
{
    COMinit();
    string s; cin >> s;
    ll n = s.size();
    vector<int> cnt(26,0);
    rep(i,n){
        int c = s[i] - 'a';
        cnt[c]++ ;
    }
    dp[0][0] = 1;
    int sum = 0;
    for(int i = 1; i <= 26; i++){
        int num = cnt[i-1];
        rep(j,n+1){
            if(dp[j][i-1] == 0) break;
            rep(k,num+1){
                int len = j + k;
                ll next = dp[j][i-1] * COM(len,k);
                next %= MOD;
                add(dp[len][i],next);
            }
        }
        sum += num;
    }
    ll ans = 0;
    For(i,1,n+1){
        add(ans, dp[i][26]);
    }
    cout << ans << endl;

}