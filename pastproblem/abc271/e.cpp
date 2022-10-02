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
/*Write Under this comment
  ☆ 自☆ 由☆ 記☆ 述☆ 欄☆
*/
int main()
{
	ll n, m, k;
	cin >> n>> m>> k;
	vector<ll> a(m),b(m),c(m);
	rep(i,m) cin >> a[i] >> b[i] >> c[i];
	vector<ll> e(k);
	rep(i,k) cin >> e[i];
	rep(i,k) e[i]--;

	ll first = 1;
	map<ll,ll> mp;
	vector<bool> can(n+100,false);
	rep(i,n+100){
		mp[i] = INF;
	}
	can[1] = true;
	mp[1] = 0;
	rep(i,k){
		// 道iを使うか
		int miti = e[i];
		ll start = a[miti];
		ll end = b[miti];
		ll cost = c[miti];
		if(can[start]){
			ll ncos = mp[start] + cost;
			chmin(mp[end],ncos);
			can[end] = true;
		}
	}
	if(mp[n] == INF){
		cout << -1 << endl;
		return 0;
	}
	cout << mp[n] << endl;
}
