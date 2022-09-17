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
    int n, k, q;
    cin >> n>> k>> q;
    vector<int> a(k);
    rep(i,k) cin >> a[i];
    vector<int> l(q);
    rep(i,q) cin >> l[i];
    // a[i]番目にコマがある
    map<int,int> mp;
    // 左からi番目にあるコマの位置
    int cnt = 1;
    rep(i,k){
        mp[cnt]=a[i];
        cnt++;
    }
    rep(i,q){
        int x = l[i];
        // 左からx番目のコマの位置
        int pos = mp[x];
        if(pos==n)continue;
        // 一番右なら何もしない　
        if(mp[x+1] == pos + 1) continue;
        // １個みぎにする
        mp[x] = pos + 1;
    }
    for(auto x:mp){
        if(x.second == 0) continue;
        cout << x.second << " " ;
    }
    cout << endl;
}
