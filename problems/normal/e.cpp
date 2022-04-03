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
ll dp[105][100100];
int main()
{
	int N, W;
	cin >> N>> W;
	vector<int> w(N), v(N);
	rep(i,N) cin >> w[i] >> v[i];
	// dp[i][j]:= 品物をi個まで選んだとき、価値がj以上となる。おもさの最小
	rep(i,103){
		rep(j,100010){
			dp[i][j] = INF;
		}
	}
	dp[0][0] = 0;
	rep(i,N){
		ll wei = w[i];
		ll kati = v[i];
		rep(j,100010) dp[i+1][j] = dp[i][j];
		rep(j,100010){
			if(dp[i][j] == INF) continue;
			ll n_kati = j + kati;
			chmin(dp[i+1][n_kati], dp[i][j] + wei);
		}
	}
	ll ans = 0;
	rep(j,100010){
		if(dp[N][j] <= W) chmax(ans,(ll)j);
	}
	cout << ans << endl;
}
