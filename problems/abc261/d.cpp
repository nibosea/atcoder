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
ll dp[5010][5010];
int main()
{
	ll n, m;
	cin >> n>> m;
	vector<ll> x(n);
	rep(i,n) cin >> x[i];
	map<ll, ll> bonus;
	rep(i,m){
		ll c,y;
		cin >> c>>y;
		bonus[c] = y;
	}
	rep(j,5010){
		For(i,1,5010){
		dp[j][i] = -1;
		}
	}
	dp[0][0] = 0;
	// dp[i][j]:=i回目でj回連続で表がでたときのもらえるお金の最大値
	rep(i,n){
		// dp[i][j]からの遷移を考える
		rep(j,n+1){
			if(dp[i][j] == -1) continue;
			// 表が出る
			ll ren = j + 1; // ren 回連続で表
			ll bo = bonus[ren];
			// x[ren-1]¥もらう
			ll get = x[i] + bonus[ren];
			chmax(dp[i+1][ren] , dp[i][j] + get);
			// 表が出る
			chmax(dp[i+1][0] , dp[i][j]);
		}
	}
	ll ans = 0;
	For(i,0,n+1){
		chmax(ans,dp[n][i]);
	}
	cout << ans << endl;
}
