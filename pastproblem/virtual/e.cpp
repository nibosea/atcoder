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
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Line

int main()
{
    ll h, w;
    cin >> h >> w;
    ll k; cin >> k;
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    //初期ますのスコア、 初期ますと同じ行（初期ますはのぞく)のスコア, 初期マスと同じ列のスコア、それ以外
    ll fi = 1, gyo = 0, retu = 0, exp = 0;
    rep(i,k){
        ll ffi = (gyo * (w-1)) % MOD + (retu * (h - 1)) % MOD;
        ffi %= MOD;
        ll ggyo = fi + (gyo * (w-2))%MOD + (exp * (h-1))%MOD;
        ggyo %= MOD;
        ll rretu = fi + (retu * (h-2))%MOD + (exp * (w-1))%MOD;
        rretu %= MOD;
        ll eexp = gyo + retu + (exp *(h-2))%MOD + (exp *(w-2))%MOD;
        eexp %= MOD;
        fi = ffi;
        gyo=ggyo;
        retu=rretu;
        exp=eexp;
    }
    if(x1==x2&&y1==y2){
        cout << fi << endl;
    } else if(x1 == x2){
        cout << gyo << endl;
    } else if(y1==y2){
        cout << retu << endl;
    } else {
        cout << exp << endl;
    }

}