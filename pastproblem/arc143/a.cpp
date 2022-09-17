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
int main()
{
    vector<ll> a(3);
    rep(i,3) cin >> a[i];
    SORT(a);
    ll m = a[2];
    ll ans = m;
    ll cnt = m;
    rep(i,3) a[i] -= m;
    // cnt回までどれかに足すことが出来る
    bool f = true;
    rep(i,3) if(a[i] != 0)f=false;
    if(f){
        cout << ans << endl;
        return 0;
    }
    ll minus = 0;
    rep(i,2){
        minus += a[i];
    }
    minus *= -1;
    if(minus <= cnt){
        cout << ans << endl;
        return 0;
    } else {
        cout << -1 << endl;
        return 0;
    }
}
