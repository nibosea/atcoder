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
const ll INF = 1'000'000'000'000'000'000;
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
bool judge_touch(ll x, ll y,ll r, ll x2, ll y2, ll r2){
	ll dR = abs(r-r2);
	ll X = abs(x-x2);
	ll Y = abs(y-y2);
	ll d = abs(r-r2);
	ll dist = X*X + Y*Y; // 中心管の距離 d
	// 半径の差のにじょう r1-r2
	ll R = (r-r2) * (r-r2);
	if(dist < R) return false;
	if(dist == R) return true;
	if(R < dist && dist < (r+r2)*(r+r2)) return true;
	if(dist == (r+r2)*(r+r2)) return true;
	return false;
}
int main()
{
	ll n;
	cin >> n;
	ll sx, sy, tx, ty;
	cin >> sx>> sy>> tx>> ty;
	vector<ll> x(n), y(n),r(n);
	rep(i,n) cin >> x[i] >> y[i] >> r[i];
	unionfind uf(n);
	rep(i,n){
		For(j,i+1,n){
			if(judge_touch(x[i], y[i], r[i], x[j], y[j], r[j])) uf.unite(i,j);
		}
	}
	ll ii = -1;
	ll jj = -1;
	rep(i,n){
		// 円の中心と、sx,syの距離がr[i]であるかをチェックする
		if(r[i]*r[i] == (x[i]-sx)*(x[i]-sx) + (y[i]-sy)*(y[i]-sy)){
			ii = i;
		}
		if(r[i]*r[i] == (x[i]-tx)*(x[i]-tx) + (y[i]-ty)*(y[i]-ty)){
			jj = i;
		}
	}
	debug(ii);
	debug(jj);
	if(uf.same(ii,jj)){
		coY();
	}else coN();
}
