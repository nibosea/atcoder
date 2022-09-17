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
    ll n, l, r;
    cin >> n>> l>> r;
    // とりあえず、l番目とr番目を出しとくか? 
    // 1スタートはn-1個ある
    ll sum = 0;
    ll x = 1;
    while(sum < l){
        sum += (n-x);
        x++;
    }
    if(sum > l){
        x--;
        sum -= (n-x);
    }
    ll diff = (l - sum);
    debug(diff);
    ll x1l = x;
    ll x1r = x1l + diff;
    //printf("x1_l, x1_r = %lld, %lld\n", x1l, x1r);
    x = 1;
    while(sum < r){
        sum += (n-x);
        x++;
    }
    if(sum > r){
        x--;
        sum -= (n-x);
    }
    diff = (r - sum);
    debug(diff);
    ll x2l = x;
    ll x2r = x2l + diff;
    //printf("x2_l, x2_r = %lld, %lld\n", x2l, x2r);
    // 
    vector<int> ans(n+1,0);
    // xよりも若い数字については、変わるわけがない
    for(int i = 1; i < x1l; i++){
        ans[i] = i;
    }
    // x1l から n 個見て、それぞれの数字の最初の出現を見つけたい
    map<int, int> mp;
    int xx = x1l;
    int yy = x1r; //(xx,yy) から、1個ずつ増やしていく
    int cnt = l;
    while(cnt <= r){
        // それぞれの数値の相方を見つける
        if(mp[xx] == 0) {
            mp[xx] = yy;
            cnt++;
        }
        if(mp[yy] == 0){
            mp[yy] = xx;
            cnt++;
        }
        yy++;
        if(yy > n){
            xx ++;
            yy = xx + 1;
        }

    }
    for(int i = 1; i <= n; i++){
        if(mp[i] == 0) mp[i] = i;
    }
    for(int i = 1; i <= n; i++){
        cout << mp[i] << " ";
    }
    cout << endl;
    for(int i = x1l; i <= n; i++){
        ll next = mp[i];
        // 若くなったら俺で終わり
        if(next < i) ans[next] = i;
        else {
            // next -> mp[next] は?
            ll n2 = mp[next];
            ans[n2] = i;
        }
    }
    rep(i,n){
        cout << ans[i+1] << " ";
    }
}
