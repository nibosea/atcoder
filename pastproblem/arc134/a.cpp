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
    int n; ll l, w;
    cin >> n >> l >> w;
    ll ans = 0;
    ll mae = 0;
    ll usiro = 0;
    rep(i,n){
        ll x; cin >> x;
        // 」前からｘまでを覆わないといけない
        ll diff = x - mae;
        mae = x+w;
        if(diff>0){
            ans += (diff-1+w) / w;
        }
        // 引いたシートによって、a[i+1]よりも先を覆っている可能性がある・・・？ いや、それはない
    }
    // L までを覆う
    ll diff = l - mae;
    if(diff>0){
        ans += (diff-1+w) / w;
    }
    cout << ans << endl;
}