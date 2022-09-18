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
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void coT() {cout <<"Takahashi"<<endl;}
void coA(){cout <<"Aoki"<<endl;}

void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 9'000'000'000'000'000'000;
vector<int> to[200'005];
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
const int MAX_N = 200500;
int main()
{
	ll n, k;
	cin >> n>> k;
	vector<int> a(MAX_N);
	rep(i,n) cin >> a[i];
	map<int, int> mp;

	unionfind uf(MAX_N);
	vector<int> ans(MAX_N-1);
	rep(i,n){
		debug(i);
		ll x = a[i];
		// x以上のキー取得
		auto begin = mp.lower_bound(x);
		if(begin != mp.end()){
			// 見つかった
			int key = begin->first;
			debug(key);
			int val = begin->second;
			debug(val);
			mp.erase(begin);
			// mp[key]を消して、mp[x]=val+1にしたい
			if(val == k-1){
				uf.unite(x,key);
				ans[uf.find(x)] =i+1; //とりあえず山の代表値の答えを確定させる
				ans[x] = i+1; // 代表値決めるだけじゃ不安だから、一応一番最新に置いたやつの答えも入れとくか
			} else {
				mp[x] = val+1;
				uf.unite(x,key);
			}
		} else {
			if(k ==1){
				ans[x] = i+1;
				continue;
			} else 
				mp[x] = 1;
		}
	}
	For(i,1,n+1){
		int now = ans[uf.find(i)];
		if(now == 0) cout << -1 << endl;
		else cout << now << endl;
	}
}
