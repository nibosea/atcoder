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
ll cnt(ll x, ll y){
	// xに何回+iしたら、yが立っているところはすべて立っているようにできるか
	if(x <= y){
		return y - x;
	} else {
		//yで1だが、xで0の一番で回所を探す 
		ll now = 31;
		while(now >= 1){
			if( !(x & (1<<now)) && (y&(1<<now))) {
				return y - x;
			} else {
				y &= ~(1 << now);
				x &= ~(1 << now);
			}
			now--;
		}
		return now;
	}
}
int main()
{
	// 2分探索
	ll n, m, k;
	cin >> n>> m>> k;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	ll ng = (1ll<<32); 
	ll ok = 0;
	while(ng-ok>1){
		ll mid = (ng+ok) / 2;
		// すでにmidよりでかい場合とそうでない場合
		// maekaramiteikebaii
		ll sets = 0;
		ll sum = 0;
		bool f = false;
		priority_queue<ll,vector<ll>, greater<ll>> q;
		rep(i,n){
			ll now = cnt(a[i],mid);
			q.push(now);
		}
		rep(i,k){
			sum += q.top(); q.pop();
		}
		if(sum <= m) ok = mid;
		else ng = mid;

		
	}
	cout << ok << endl;
}
