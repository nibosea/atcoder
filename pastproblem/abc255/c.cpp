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
    ll x, a, d, n;
    cin >> x>> a>> d>> n;
    if(d == 0){
        //　差０
        cout << abs(x-a) << endl;
        return 0;
    }
    auto f = [&](ll k){
        return a + (k-1) * d;
    };
    ll ans = 2e18;
    ans += 1000;
    debug(ans);
    if(d > 0){
        // Amidがxを上回る最小のmidを求める
        ll ok = n;
        ll ng = 0;
        while(ok-ng>1){
            ll mid = (ok + ng) / 2;
            if(f(mid) >= x){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        ll num = f(ok);
        chmin(ans, abs(num - x));
        if(ok != 1) num -= d;
        chmin(ans,abs(num-x));
        // xが末項よりもでかい場合は？
    } else {
        // Amidがxを上回る最大のmidをm止める
        ll ok = 1;
        ll ng = n + 1;
        while(ng - ok > 1){
            ll mid = (ok+ng)/2;
            if(f(mid) >= x) ok = mid;
            else ng = mid;
        }
        ll num = f(ok);
        chmin(ans, abs(num - x));
        if(ok != n) num += d;
        chmin(ans,abs(num-x));
    }
    cout << ans << endl;
}
