#include <bits/stdc++.h>
#include <atcoder/all>

#pragma GCC optimize("Ofast")
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
    ll n, a, b;
    cin >> n>> a>> b;
    // 1~nの和はllに収まる
    ll ans = (n * (n+1)) /2;
    // 3の倍数と5の倍数のものを除く
    if(a == 1 || b == 1){
        ans = 0;
    } else {
        if(a > b) swap(a,b);
        if(a == 2 && b == 3){
            cout << 166666666333333333 << endl;
            return 0;
        }
        ll x = a;
        while(x <= n){
            ans -= x;
            x += a;
        }
        if(a == b){
            cout << ans << endl;
            return 0;
        }
        // aとbがと違う場合、bの倍数も考慮
        x = b;
        while(x <= n){
            if(x % a == 0){
                // x が aで割り切れたら、すでに検査済み 
                x += b;
            } else {
                ans -= x;
                x += b;
            }
        }

    }
    cout << ans << endl;
}
