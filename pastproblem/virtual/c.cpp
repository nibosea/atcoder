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
struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n,-1) {} //このコロンってなんですか
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

struct edge {
    int cost;
    int a;
    int b;
    int num;
};
bool comp(edge a, edge b){
    if(a.cost == b.cost){
        if(a.a == b.a){
            return a.b <= b.b;
        }
        return a.a <= b.a;
    } else {
        return a.cost <= b.cost;
    }
}
int main()
{
    int n,m,q;
    cin >> n >> m >> q;
    // costでソート、2辺を持つ,
    UnionFind uf(n);
    vector<edge> ed(m+q); 
    rep(i,m){
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        edge now = {c,a,b,0};
        ed[i] = now;
    }
    rep(i,q){
        int a, b, c; cin >> a >> b >> c;
        --a, --b;
        edge now = {c,a,b,i+1};
        ed[i+m] = now;
    }
    sort(ed.begin(),ed.end(),comp);
    rep(i,m+q){
        edge now = ed[i];
        //printf("cost:%d, hen_a:%d, hen_b:%d, bool:%d\n",now.cost,now.a,now.b,now.num);
    }
    vector<string> ans(q,"No");
    rep(i,q+m){
        edge now = ed[i];
        int a = now.a;
        int b = now.b;
        if(uf.same(a,b)){
            //つながってるなら何もしない
            continue;
        }
        if(now.num){
            ans[now.num-1] = "Yes";
        } else {
            uf.unite(a,b);
        }
    }
    rep(i,q){
        cout << ans[i] << endl;
    }
}