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
using Edge = pair<int, pair<int, int>>;
// 迂回路判定；；
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<Edge> edges(m);

    vector<vector<ll>> d(n,vector<ll> (n,INF));
	vector<vector<ll>> dp(n,vector<ll> (n,INF));
    rep(i,n){
        d[i][i] = 0;
    }
    rep(i,m){
        ll a, b, c;   cin >> a >> b>> c;
        --a, --b;
        edges[i] = Edge(c, make_pair(a,b));
		chmin(d[a][b],c);
    }
    SORT(edges);
    rep(k,n){
        rep(i,n){
            rep(j,n){
				chmin(dp[i][j], d[i][k]+d[k][j]);
            }
        }
    }
    ll ans = 0;
    map<int, bool> use;
    rep(i,m){
        ll w = edges[i].first;
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;
		if(d[u][v] <= dp[u][v])ans++;
		//if(d[u][v] < w) ans++;

    }
    // ここから，全点間の距離を求める
    cout << ans << endl;
}
