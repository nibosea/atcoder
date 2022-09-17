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
mint dp[70][70];
ll f(ll x){
    ll ret = 0;
    while(x){
        ret++;
        x/=2;
    }
    return ret;
}
int main()
{
    ll n, m;
    cin >> n>> m;

    if(n == 1){
        cout << m << endl;
        return 0;
    }
    if(n >= 61){
        cout << 0 << endl;
        return 0;
    }
    // nがでかすぎるから、単純なDPじゃダメそう。
    // dp[i][j] := i個数列を決めたときに、j bit 目が立っているものの数。
    vector<mint> cnt(65,0);
    // 1以上M以下の数で、最上位iビット目が立っているものの数を求める
    // M が 2新数でK桁のとき、最上位を0にした時の数+1が...
    ll keta = f(m);
    //debug(keta);
    ll num = m ^ (1<<(keta-1));
    num ++;
    //debug(num);
    cnt[keta] = num;
    debug(keta);
    if(n >= keta+1) {
        cout << 0 << endl;
        return 0;
    }
    mint neko = 1;
    rep(i,keta-1){
        cnt[i+1] = neko;
        neko *= 2;
    }
    cnt[0] = 0;
    for(auto x: cnt){
        //cout << x.val() << " ";
    }
    //cout << endl;
    dp[0][0] = 1;
    for(ll i = 0; i < n; i++){
        bool flag = true;
        for(ll j = 0; j < 63; j++){
            if(dp[i][j] != 0){
                for(ll k = j + 1; k < 63; k++){
                    dp[i+1][k] += dp[i][j] * cnt[k];
                    flag = false;
                }
            }
        }
        if(flag) {
            cout << 0 << endl;
            return 0;
        }
    }
    mint ans = 0;
    for(ll j = 0; j <= 60; j++){
        ans += dp[n][j];
    }
    rep(i,5){
        rep(j,5){
            //cout << dp[i][j].val() << " ";
        }
        //cout << endl;
    }
    cout << ans.val() << endl;
    
}
