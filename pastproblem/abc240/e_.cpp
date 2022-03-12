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

int n;
vector<int> G[200005];
int L[200005], R[200005];
int leaf[200005];

int id = 1;
void dfs(int v, int p){
    if(v!=&&G[v].size()==1){
        leaf[v]=id;
        cout << "v:"<< v << ", ";
        debug(leaf[v]);
        id++;
        return;
    }
    for(auto u:G[v]) if(u!=p) dfs(u,v);
}

void dfs2(int v, int p){
    if(leaf[v]){
        L[v] = R[v] = leaf[v];
        return;
    }
    L[v] = 1e9; R[v] = -1e9;
    for(auto u: G[v]){
        if(u==p)continue;
        dfs2(u,v);
        L[v] = min(L[v],L[u]);
        R[v] = max(R[v], R[u]);
    }
}

int main(){
    cin >> n;
    int u, v;
    rep(i,n-1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1,-1);
    dfs2(1,-1);
 for(int i = 1; i <= n; i++) cout << L[i] << " " << R[i] << "\n";
}