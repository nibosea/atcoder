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

vector<vector<int>> g;
map<int, vector<int>> mp;
vector<int> x;
bool seen[100010];
vector<int> dfs(int v){
    vector<int> num;
    if(seen[v]) return num;
    seen[v] = true;
    for(auto vv:g[v]){
        auto tmp = dfs(vv);
        num.insert(num.end(), tmp.begin(),tmp.end());
    }
    num.push_back(x[v]); 
    sort(num.begin(),num.end(),greater<int>());
    vector<int> hoge;
    rep(i, min(20, (int)num.size())) hoge.push_back(num[i]);
    mp[v] = hoge;
    return hoge;
}
int main()
{
    int n, q; cin >> n >> q;
    g.resize(n);
    x.resize(n);
    rep(i,n) cin >> x[i];
    rep(i,n-1){
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> num;
    num = dfs(0);

    while(q--){
        int v, k; cin >> v >> k;
        v--; k--;
        //auto tmp = mp[v];
        //cout << tmp[k] << endl;
        cout << mp[v][k] << endl;
    }
}