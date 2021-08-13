#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define fore(i, a) for(auto &i: a)
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
ll dist[205][205];
ll dp[(1<<10)][10];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, m, n;
	cin >> N >> m >> n;
	vector<int> r(n);
	rep(i,n) cin >> r[i];
	rep(i,n) r[i]--;
	rep(i,N)rep(j,N){
		if(i == j) dist[i][j] = 0;
		else dist[i][j] = INF;
	}
	rep(i,m){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		dist[a][b] = c;
		dist[b][a] = c;
	}
	rep(k,N) rep(i,N) rep(j,N) chmin(dist[i][j], dist[i][k] + dist[k][j]);
	rep(i,(1<<n)){
		rep(j,10){
			dp[i][j] = INF;
		}
	}
	rep(j,n){
		dp[0][j] = 0;
	}
	for(int tmp = 0; tmp < (1 << n); tmp++){
		rep(j,n){
			//dp[tmp][j] からの遷移を考える
			// k へ移動する r[j] -> r[k];
			rep(k,n){
				chmin(dp[tmp|(1<<k)][k], dp[tmp][j] + dist[r[j]][r[k]]);
				// r[j] -> r[k]
			}
		}
	}
	ll ans = INF;
	for(int tmp = 0; tmp < (1 << n); tmp++){
		rep(j,n){
			//printf("dp[%d][%d] = %lld\n", tmp,j, dp[tmp][j]);
		}
	}
	rep(j,n){
		chmin(ans, dp[(1<<n)-1][j]);
	}
	cout << ans << endl;
}
