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
	ll n, a, b;
	cin >> n>> a>> b;
	// O(N)は通せない
	if(n < a){
		cout << 0 << endl;
		return 0;
	}
	ll x = n / a;
	if(a == 1){
		cout << n << endl;
		return 0;
	}
	// Ax は n を超えない。
	ll ans = 0;
	x -= 1;
	// A*1 ~ とA*2 ~ と A*(x-1) ~は、B回勝てる
	// 領域がかぶる場合が在る…
	if(x >= 0)
		ans += x * min(a,b);
	x++;
	// A*x ~NとA*x + b-1のうち、小さい方まで勝てる
	ll m = min(a*x + b-1, n);
	if(x*a <= n){
		ans += m - (x*a) + 1;
	}
	cout << ans << endl;
}
