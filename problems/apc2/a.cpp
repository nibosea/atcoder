#include <bits/stdc++.h>

using namespace std;
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
void solve(int h,int w,int y,int x,int ny,int nx){
	// (Y,X) (a,b) -> (p,q) 
	int diff_x = nx - x;
	int diff_y = ny - y ;
	// diff_xの絶対値だけ横移動を行う。
	int absx = abs(diff_x);
	int absy = abs(diff_y);
	// 左右対象だから、Xが上の方向に行く場合だけを考えると楽。
	// 横に移動するとき、下に行くなら少しだけ楽できる。
	// 横にabsx回動くとき、absxだけ下に行くことになる。
	ll ans = 0;
	if(absx){
		y -= x;
		ans += absx;
		bool oktate = (y-1 >= 1) + (y+1 <= h);
		if(!oktate) {
			cout << -1 << endl;
			return;
		}
		bool tre = (x-1 >= 1) + (x+1 <= w);
		if(!tre){
			cout << -1 << endl;
			return;
		}
		if(y<1){
			ans += 1-y;
			y = 1;
		}
		// 後は上に動くだけ
		if(ny < y){
			//下に行かないと行けない
			// y -> ny
			int ni = (ny-y) / 2;
			int iti = (ny-y) % 2;
			ans += ni * 2 + iti * 3;
		}
		ans += ny - y;
	} else if(absy){
		if(y < ny){
			ans += ny - y;
		} else {
			bool tre2 = (x - 1 >= 1);
			tre2 += (x+1 <= w);
			if(!tre2){
				cout << -1 << endl;
				return ;
			}
			int ni = (ny-y) / 2;
			int iti = (ny-y) % 2;
			ans += ni * 2 + iti * 3;
		}
	}
	cout << ans << endl;
	return ;
}
int main()
{
	int t; cin >> t;
	while (t--){
		int h, w;
		cin >> h>> w;
		int a, b;
		cin >> a>> b;
		int p, q;
		cin >> p>> q;
		// b -> qにした後にaを合わせる。　仮にaがpよりも高いのであれば、低くする
		// どっちの手法で低くするんだろう。
		solve(h,w,a,b,p,q);
	}
}
