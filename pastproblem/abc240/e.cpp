#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<ll, ll> P;
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
vector<vector<int>> g;
bool seen[200010];
int cnt = 1;
vector<P> ans;
P dfs(int v){
    if(seen[v]) return ans[v];
    seen[v]=true;
    ll m = INF;
    ll M = 0;
    bool flag=true;
    for(auto vv:g[v]){
        if(seen[vv])continue;
        auto tmp = dfs(vv);
        chmax(M,tmp.second);
        chmin(m,tmp.first);
        flag=false;
    }
    if(flag){
        m=cnt;
        M=cnt;
        cnt++;
    }
    ans[v] = P(m,M);
    return ans[v];
}
int main()
{
    int n; cin >> n;
    g.resize(n);
    ans.resize(n);
    rep(i,n-1){
        int a,b; cin >> a >> b;
        a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    P p = dfs(0);
    rep(i,n){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
}