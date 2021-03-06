#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define Per(i, a, b)    for(int i = (a) ; i>=(b);--i)
#define per(i, n)       Per(i,n,0)
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
//Write From this Line
int main()
{
	int n, k , x;
	cin >> n>> k >> x;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	// k枚のクーポンがある。
	SORT(a);
	REV(a);
	rep(i,n){
		// a[i] >= xなら使う
		if(a[i] >= x){
			ll use = 0;
			use = a[i]/ x;
			if(k==0) break;
			if(use > k){
				use = k;
			}
			a[i] -= use*x;
			k -= use;
		} else {
			break;
		}
	}
	// この処理をした後なら、大きい順に１枚使うかどうかだけでok
	SORT(a);
	REV(a);
	ll ans = 0;
	rep(i,n){
		if(k){
			a[i] = 0;
			k--;
		}
		ans += a[i];
	}
	cout << ans << endl;
}
