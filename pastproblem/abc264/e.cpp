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
const ll INF = 9'000'000'000'000'000'000;

vector<ll> to[200'005];
//Write From this Line
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
int main()
{
	int n, m, e;
	cin >> n>> m>> e;
	vector<P> edges(e);
	rep(i,e){
		int x, y;
		cin >> x>> y;
		--x, --y;
		edges[i] = P(x,y);
	}
	vector<bool> is_cut(e,0);
	int q;
	cin >> q;
	vector<int> adds(0);
	rep(i,q){
		int x;
		cin >> x;
		--x; 
		is_cut[x] = 1;
		adds.push_back(x);
	}
	// kirenai sen ha ikkatu kanri siteokitai
	// is_cut[x] = 0 no  graph tukuru
	unionfind uf(n+m);
	vector<bool> terasu(n+m, false);
	rep(i,m){
		terasu[i+n] = true;
	}
	int ans = 0;
	rep(i,e){
		if(!is_cut[i]){
			// use hen
			auto [x1,x2] = edges[i];
			if(uf.same(x1,x2)) continue;
			int p1 = uf.find(x1);
			int p2 = uf.find(x2);
			if(terasu[p1] && terasu[p2]) uf.unite(x1,x2);
			else if(!terasu[p1] && !terasu[p2]) uf.unite(x1,x2);
			else {
				// 片方だけ照らしてあるのであれば、照らしていない側をans ni plus
				int sz = 0;
				if(!terasu[p1]) sz=uf.size(p1);
				else sz = uf.size(p2);
				ans += sz;
				uf.unite(p1,p2);
				terasu[p1] = true;
				terasu[p2] = true;
			}
		}
	}
	//cout << ans << endl;
	vector<int> out(0);
	out.push_back(ans);
	// hen tuika
	REV(adds);
	rep(i,q){
		int x = adds[i];
	//edegs[x];
		auto [x1,x2] = edges[x];
		int p1 = uf.find(x1);
		int p2 = uf.find(x2);
		if(terasu[p1] && terasu[p2]) uf.unite(x1,x2);
		else if(!terasu[p1] && !terasu[p2]) uf.unite(x1,x2);
		else {
			// 片方だけ照らしてあるのであれば、照らしていない側をans ni plus
			int sz = 0;
			if(!terasu[p1]) sz=uf.size(p1);
			else sz = uf.size(p2);
			ans += sz;
			uf.unite(p1,p2);
			terasu[p1] = true;
			terasu[p2] = true;
		}
		out.push_back(ans);
	}
	out.pop_back();
	REV(out);
	for(auto x: out){
		cout << x << endl;
	}
}
