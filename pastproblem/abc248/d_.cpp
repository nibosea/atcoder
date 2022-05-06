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
struct Mo {
	int n;
	vector< tuple< int, int, int > > lr;

	explicit Mo(int n) : n(n) {}

	int get_x(int q){
		int ll, rr, xx;
		tie(ll,rr,xx) = lr[q];
		return xx;
	}
	void add(int l, int r, int x) { /* [l, r) */
		lr.emplace_back(l, r, x);
	}

	template< typename AL, typename AR, typename EL, typename ER, typename O >
		void build(const AL &add_left, const AR &add_right, const EL &erase_left, const ER &erase_right, const O &out) {
			int q = (int) lr.size();
			int bs = n / min< int >(n, sqrt(q));
			vector< int > ord(q);
			iota(begin(ord), end(ord), 0);
			sort(begin(ord), end(ord), [&](int a, int b) {
					int ll, rr, xx;
					tie(ll,rr,xx) = lr[a];
					int ll2, rr2, xx2;
					tie(ll2,rr2,xx2) = lr[b];
					int ablock = ll / bs, bblock = ll2 / bs;
					if(ablock != bblock) return ablock < bblock;
					return (ablock & 1) ? rr > rr2 : rr < rr2;
					});
			int l = 0, r = 0;
			for(auto idx : ord) {
				int ll, rr, xx;
				tie(ll,rr,xx) = lr[idx];
				while(l > ll) add_left(--l);
				while(r < rr) add_right(r++);
				while(l < ll) erase_left(l++);
				while(r > rr) erase_right(--r);
				out(idx);
			}
		}

	template< typename A, typename E, typename O >
		void build(const A &add, const E &erase, const O &out) {
			build(add, add, erase, erase, out);
		}
};
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	SORT(a);
	// 後ろにめちゃくちゃでかい数字を入れる　{ x1, x2, x3, ..., ∞ };  昇順で入っている
	a.push_back(inf);
	int sz = a.size() - 1; // aの配列の一番最後のindex
	ll L, R;
	cin >> L >> R;
	debug(sz);
	int ng = -1, ok = sz;
	while(ok - ng > 1){
		int mid =(ng+ok)/2;
		if(a[mid] >= L){
			ok = mid;
		} else {
			ng = mid;
		}
	}
	puts("id_L = ok");
	debug(ok);
	debug(ng);
	ng = -1, ok = sz;
	while(ok - ng > 1){
		int mid =(ng+ok)/2;
		if(a[mid] >= R){
			ok = mid;
		} else {
			ng = mid;
		}
	}
	puts("id_R = ok");
	debug(ok);
	debug(ng);



	while(ok - ng > 1){
		int mid = (ok+ng)/2;
		if(judge(mid) == true) ok = mid;
		else ng = mid;
	}
}
