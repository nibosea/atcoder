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


vector<P> value; // ノードの値を持つ配列
ll N;             // 葉の数

void update(ll i, ll x) {
    // i 番目の葉の値を x に変える
    i += N - 1; // i 番目の葉のノード番号
    value[i] = P(x,i);
    while (i > 0) {
        i = (i - 1) / 2; // ノード i の親ノードの番号に変える
        value[i] = min(value[i * 2 + 1],
                       value[i * 2 + 2]); // 左右の子の min を計算しなおす
    }
}

P query(ll a, ll b, ll k, ll l, ll r) {
    // [a, b) の区間に対するクエリについて
    // ノード k （区間 [l, r) 担当）が答える
    if (r <= a || b <= l) return P(inf,-1); // 区間が被らない場合は inf を返す
    if (a <= l && r <= b)
        return value[k]; // ノード k の担当範囲がクエリ区間 [a, b)
                         // に完全に含まれる
    else {
        P c1 = query(a, b, 2 * k + 1, l, (l + r) / 2); // 左の子に値を聞く
        P c2 = query(a, b, 2 * k + 2, (l + r) / 2, r); // 右の子に値を聞く
		if(c1.first < c2.first) return c1;
		else return c2;
	
    }
}
int main()
{
	ll n, m;
	cin >> n>> m;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	value = vector<P> (2*n-1,P(inf,-1));


	vector<ll> first(n,0);
	rep(i,m){
		ll x, v;
		cin >> x>> v;
		--x, --v;
		first[x] += a[v];
		first[v] += a[x];
		to[x].push_back(v);
		to[v].push_back(x);
	}
	rep(i,n)cout << first[i] << " ";
	cout << endl;
	rep(i,n){
		update(i,first[i]);
	}
	ll ans = 0;
	rep(i,n){
		// get min
		P m = query(0,n+1,0,0,n);
		printf("(%d,%d)\n", m.first, m.second);
		chmax(ans,m.first);
		int v = m.second;
		int num = a[v];
		debug(num);
		first[v] = inf;
		update(v,first[v]);
		for(auto nv: to[v]){
			if(first[nv] == inf) continue;
			first[nv] -= num;
			debug(nv);
			debug(first[nv]);
			update(nv,first[nv]);
		}
		for(auto x: first){
			cout << x << " ";
		}
		cout << endl;
	}
	cout << ans << endl;
}
