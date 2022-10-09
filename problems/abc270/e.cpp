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
int main()
{
	ll n, k;
	cin >> n>> k;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];

	ll ok = k;
	ll ng = 0;
	while(ok - ng > 1){
		ll mid = (ok+ng)/2;
		// mid週でクリアできるか
		ll num = 0;
		rep(i,n){
			num += min(mid,a[i]);
			if(num >= k){
				break;
			}
		}
		if(num >= k) ok = mid;
		else ng = mid;
	}
	// ok - 1 hiku
	ll cnt = 0;
	rep(i,n){
		ll kazu = min(ok-1,a[i]);
		cnt += kazu;
		a[i] -= kazu;
	}
	rep(i,n){
		if(cnt >= k)break;
		if(a[i]){
			a[i]--;
			cnt++;
		}
	}
	rep(i,n){
		cout << a[i] << " ";
	} cout << endl;
}
