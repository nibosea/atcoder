#include <bits/stdc++.h>

using namespace std;
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

const int COMSIZE = 1e7+100;
const int COMMOD = MOD;

long long fac[COMSIZE], finv[COMSIZE], inv[COMSIZE];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < COMSIZE; i++){
        fac[i] = fac[i - 1] * i % COMMOD;
        inv[i] = COMMOD - inv[COMMOD%i] * (COMMOD / i) % COMMOD;
        finv[i] = finv[i - 1] * inv[i] % COMMOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % COMMOD) % COMMOD;
}

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
ll power(ll n, ll p, ll mod) {
  ll r = 1;
  for (; p > 0; p >>= 1) {
    if (p & 1ll) r = r % mod * n % mod;
    n %= mod;
    n = n * n % mod;
  }
  return r;
}
int main()
{
	int n;
	cin >> n;
	vector<P> Pa(n);
	rep(i,n) cin >> Pa[i].first;
	rep(i,n) cin >> Pa[i].second;
	SORT(Pa);
	// 多分だけど、順列っていうのが大事な成約になっている気がする
	// つまり各数字 1 ~ Nについて、ゲットする方法は二通りしか考えられない
	// UnionFindで島の数をかぞえる
	COMinit();
	unionfind uf(n);
	rep(i,n){
		auto [x,y] = Pa[i];
		--x; --y;
		uf.unite(x,y);
	}
	map<int, bool> mp;
	vector<ll> lucas(n,0);
	lucas[0] = 1;
	lucas[1] = 3;
	for(int i = 2; i < n; i++){
		lucas[i] = lucas[i-1] + lucas[i-2];
		lucas[i] %= MOD;
	}
	ll ans = 1;
	rep(i,n){
		int p = uf.find(i);
		if(mp[p])continue;
		mp[p] = true;
		int N = uf.size(i);
		if(N==1) continue;
		debug(N);
		// lucas[i]をかける
		ans *= lucas[N-1];
		ans %= MOD;
	}
	cout << ans << endl;
}
