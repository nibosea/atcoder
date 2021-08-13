#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef tuple<ll,ll,ll> T;
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
ll dist[20][20];
ll dp[(1<<20)][20];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<T> x(n);
	rep(i,n){
		int a, y, z;
		cin >> a >> y >> z;
		x[i] = {a,y,z};
	}
	rep(i,n){
		rep(j,n){
			int ix, iy, iz;
			int jx, jy, jz;
			tie(ix,iy,iz) = x[i];
			tie(jx,jy,jz) = x[j];
			ll tmp = abs(ix - jx) + abs(iy - jy);
			tmp += max(0, jz - iz);
			dist[i][j] = tmp;
		}
	}
	rep(i,n) dist[i][i] = 0;
	rep(k,n) rep(i,n) rep(j,n) chmin(dist[i][j], dist[i][k] + dist[k][j]);

	// DP 作るぞ
	rep(i,(1<<n))rep(j,n) dp[i][j] = INF;
	dp[0][0] = 0; 

	for(int tmp = 0; tmp < (1 << n); tmp++){
		rep(i,n){
			// dp[tmp][i] から移動する
			rep(j,n){
				// i -> j
				chmin(dp[tmp|(1<<j)][j], dp[tmp][i] + dist[i][j]);
			}
		}
	}
	ll ans = INF;
	rep(i,n){
		chmin(ans, dp[(1<<n)-1][i] + dist[i][0]);
	}
	cout << ans << endl;
}
