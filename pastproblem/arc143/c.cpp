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
void coT() {cout <<"First"<<endl;}
void coA(){cout <<"Second"<<endl;}

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
    ll n, x, y;
    cin >> n>> x>> y;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll w = x+y-1;
    //初手負けのパターン
    bool f = true;
    rep(i,n){
        if(x<=a[i])f=false;
    }
    if(f){
        coA();
        return 0;
    }
    // 操作しちゃえば勝のパターン
    f = true;
    rep(i,n){
        if(w<a[i])f=false;
    }
    if(f){
        coT();
        return 0;
    }
    // 実は２手で勝負が決まらない場合、絶対先手が勝てるとかありそう
    // ２手だけ全通り試せないかな？
    // 青木の価値筋
    bool aoki = true;
    rep(i,n){
        // 全部win + x以下なら勝てる説？　
        if(a[i] <= w+x)continue;
        else aoki = false;
    }
    rep(i,n){
        a[i] -= x;
    }
    bool nekochan = false;
    rep(i,n){
        if(a[i] >= y) nekochan = true;
    }
    if(!nekochan){
        coT();
        return 0;
    }
    if(aoki){
        coA();
        return 0;
    }
    if(x<=y){
        coT();
        return 0;
    } else {
            coA();
            return 0;
    }
    // 高橋は、n個のうち、１個以上選んでw+xにすることが出来る

}
