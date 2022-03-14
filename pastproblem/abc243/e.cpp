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


struct unionfind {
	vector<int> d;
	unionfind(int n=0): d(n,-1) {} //このコロンってなんですか
	int find(int x){
		if (d[x] < 0) return x; //x:根
		return d[x] = find(d[x]);//x:子 -> xの親の根を返す
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);//根同士をくっつける。
		if ( x ==  y) return false ; 
		/*連結成分が一致してるんだったらfalse返す。
			minimum spanning tree (クラスカル法と言うのをやるときに、くっつけたかどうかを取れると嬉しい.
			chmin/chmaxみたいなノリかな
		 */
		if ( d[x] > d[y]) swap(x,y);//xの方が大きいようにする（ただしサイズは負デモっているので不等号が逆）
		d[x] += d[y] ; //xにyをくっつける.
		d[y] = x;
		return true; 
	}
	bool same(int x, int y) { return find(x) == find(y) ; }
	int size(int x) { return -d[find(x)];}
};

//Write From this Line
using Edge = pair<int, pair<int, int>>;
int main()
{
    ll n, m;
    cin >> n >> m;
    unionfind uf(n);
    vector<Edge> edges(m);

    rep(i,m){
        ll a, b, c;   cin >> a >> b>> c;
        --a, --b;
        edges[i] = Edge(c, make_pair(a,b));
    }
    SORT(edges);

    ll ans = 0;
    vector<vector<ll>> d(n,vector<ll> (n,INF));
    rep(i,n){
        d[i][i] = 0;
    }
    map<int, bool> use;
    rep(i,m){
        ll w = edges[i].first;
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;

        if(uf.same(u,v)){
            continue;
        }
        uf.unite(u,v);
        use[i] = true;
        d[u][v] = w;
        d[v][u] = w;
    }
    rep(i,n){
        rep(j,n){
            rep(k,n){
                chmin(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    rep(i,m){
        if(use[i]) continue;
        ll w = edges[i].first;
        ll u = edges[i].second.first;
        ll v = edges[i].second.second;
        if(chmin(d[u][v], w)){
            d[v][u] = w;
        } else {
            ans++;
        }
    }
    // ここから，全点間の距離を求める
    cout << ans << endl;
}