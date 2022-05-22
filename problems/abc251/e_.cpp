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
//Write From this Line
ll dp[300005][2];
int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n+1);
	rep(i,n) cin >> a[i+1];
	// 連続して2回上げないという選択をすることが出来ない。
	// dpをinf
	ll LN = 300005;
	rep(i,LN) rep(j,2)dp[i][j] = INF;
	// dp[i][j] := i匹目まで見て、iに餌を上げた(1),餌を上げていない(0); i-1引目までは食べている
	// TODO 1とNに餌を上げる
	// dp[N-1]までを求めればいい
	dp[1][1] = a[n]; //1匹目まで見て、1に餌を挙げた場合
	dp[1][0] = 0;
	for(ll i = 1; i < n; i++ ){
		// dp[i]からの遷移を考える
		ll cost = a[i];
		rep(j,2){
			if(j == 0){
				// i匹目が食っていないとき
				if(i == 1) continue;
				chmin(dp[i][1], dp[i][j] + a[i-1]);
				chmin(dp[i][1], dp[i][j] + a[i-1]);
				// a[i]で食べる場合
				chmin(dp[i][1], dp[i][0] + a[i]);
				chmin(dp[i+1][1], dp[i][0] + a[i]);
			} else {
				// i 匹目が食っているときの遷移
				// 食う
				chmin(dp[i+1][1], dp[i][1] + a[i]);
				chmin(dp[i+1][0], dp[i][1]);
			}
		}
	}
	ll ans = dp[n-1][1];
	// TODO 1と2に餌を上げる場合
	rep(i,LN) rep(j,2)dp[i][j] = INF;
	dp[2][1] = a[1];
	dp[1][1] = a[1];
	for(ll i = 2; i < n; i++ ){
		// dp[i]からの遷移を考える
		ll cost = a[i];
		rep(j,2){
			if(j == 0){
				// i匹目が食っていないとき
				if(i == 1) continue;
				chmin(dp[i][1], dp[i][j] + a[i-1]);
				chmin(dp[i][1], dp[i][j] + a[i-1]);
				// a[i]で食べる場合
				chmin(dp[i][1], dp[i][0] + a[i]);
				chmin(dp[i+1][1], dp[i][0] + a[i]);
			} else {
				// i 匹目が食っているときの遷移
				// 食う
				chmin(dp[i+1][1], dp[i][1] + a[i]);
				chmin(dp[i+1][0], dp[i][1]);
			}
		}
	}
	chmin(ans,dp[n][1]);
	cout << ans << endl;
}
