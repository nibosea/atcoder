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
void solve(){
	ll n, m;
	cin >> n>> m;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	// mod m
	// 2乗全探索は無理だけど、やっちゃおｗ
	ll ans = 0;
	rep(i,n){
		rep(j,n){
			ll left = (a[i] % m) - (a[j] % m);
			if(left < 0){
				left += m;
			}
			left %= m;
			ll now = a[i] + a[j] + left;
			chmax(ans,now);
		}
	}
	cout << ans << '\n';
}
int main()
{
	ll t;
	cin >> t;
	rep(i,t)solve();
}
