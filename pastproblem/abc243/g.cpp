#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define Per(i, a, b)    for(int i = (a) ; i>=(b);--i)
#define per(i, n)       Per(i,n,0)
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
map<ll, ll> memo;
ll dfs(ll x){
    if(memo[x]) return memo[x];
    ll X = sqrt(x) / 1;
    debug(X);
    if(X == 1){
        return memo[x] = 1;
    }
    // 1 ~ 4の数字まではいる
    ll now = 1;
    ll ret = 1;
    ll ind = -1;
    for(ll i = 2; i*i <= X; i++){
        ind = i;
        // now ~ i*i - 1までいける
        ll cnt = (i*i - 1) - now + 1;
        debug(cnt);
        ret *= cnt * dfs(i);
        now = i*i;
    }
    if(ind != -1){
        ret *= dfs(ind);
    }
    return memo[x] = ret;
}
void solve(ll x){
    cout << dfs(x) << endl;
}
int main()
{
    int t; cin >> t;
    vector<ll> x(t);
    rep(i,t) cin >> x[i];

    solve(x[0]);
    rep(i,t){
        //solve(x[i]);
        
    }
}