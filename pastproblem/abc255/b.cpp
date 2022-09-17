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
ll dist(ll x1, ll y1, ll x2, ll y2){
    ll dx = (x1-x2);
    ll dy = (y1-y2);
    return dx*dx + dy*dy;
}
int main(){
    ll  n, k;
    cin >>  n>> k;
    vector<ll> a(k);
    rep(i,k) cin >> a[i];
    rep(i,k) a[i]--;
    vector<ll> x(n), y(n);
    rep(i,n) cin >> x[i] >> y[i];
    // 2点間の距離の最大値
    ll ans = 0;
    rep(i,n){
        // 頂点iと最も近くにあって、あかりがついているものとの距離
        ll M = 1e18;
        rep(j,k){
            // 距離を小さくする
            ll di = dist(x[i],y[i],x[a[j]],y[a[j]]);
            chmin(M,di);
        }
        chmax(ans,M);
    }
    cout << setprecision(15);
    double cans = sqrt(ans);
    cout <<cans << endl;
}
