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
int main()
{
	ll n, x, y;
	cin >> n>> x>> y;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	SORT(a);
	ll sum = 0;
	rep(i,n) sum += a[i];
	ll ok = a[0];
	ll ng = (sum / n) + 1;
	// 二分探索
	while(ng - ok > 1){
		ll mid = (ng + ok) / 2;
		// mid が達成可能かを判定する
		ll need = 0;
		ll mo = 0;
		rep(i,n){
			if(a[i] < mid){
				// 小さいなら、操作をすることで大きくしないといけない
				ll diff = mid - a[i];
				// 操作を必要な回数は切り上げ
				need += (diff + x-1) / x;
			} else if (a[i] > mid){
				// 何回まで操作で小さく出来るか
				ll diff = a[i] - mid;
				// 5大きくて4ずつ下がるなら、1回だけ可能
				mo += diff / y;
			}
		}
		if(need <= mo){
			ok = mid;
		} else {
			ng = mid;
		}
	}
	cout << ok << endl;
}
