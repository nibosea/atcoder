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
int main()
{
	ll n, k;
	cin >> n>> k;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	// 0 -> x -> ... -> x -> ... -> x -> 最後
	// xまでが何回か。x -> xを何回繰り返せるか。最後 xから何回操作を行うか
	ll x = 0;
	ll ans = 0;
	map<ll,ll> mp;
	ll cnt = 1;
	while(mp[x] == 0){
		k--;
		mp[x] = cnt++;
		ll ame = a[x];
		ans += ame;
		x = ans % n;
		if(k==0) break;
	}
	debug(ans);
	if(k == 0){ cout << ans << endl; return 0;}
	ll period = cnt - mp[x];
	debug(period);
	// 周期が何回入るか
	ll times = k / period;
	k %= period;
	ll period_num = 0; //x -> xの直前まででいくつ飴が取れるか
	ll y = x;
	while(true){
		ll ame = a[y];
		period_num += ame;
		y += ame;
		y %= n;
		if(y == x) {
			break;
		}
	}
	debug(period_num);
	ans += times * period_num;
	debug(k);
	// 残りはxを追加するところから。
	debug(ans);
	rep(i,k){
		ll ame = a[x];
		debug(ame);
		ans += ame;
		x += ame; x %= n;
	}
	cout << ans << endl;
}
