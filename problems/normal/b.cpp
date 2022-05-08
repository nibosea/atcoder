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
//Write From this Line
ll dp[200100][2][2][2][2];
int main()
{
	ll n;cin >>n;
	vector<pair<ll,char>> a(2*n);
	rep(i,2*n) cin >> a[i].first >> a[i].second;
	SORT(a);
	rep(i,200100)rep(j,2)rep(k,2)rep(l,2)rep(m,2) dp[i][j][k][l][m] = INF;
	dp[0][0][0][0][0]=0;
	rep(i,2*n){
		// 色として使う場合
		char col = a[i].second;
		if(col == 'R'){
			rep(j,2){
				rep(k,2){
					rep(l,2){
						rep(m,2){
							chmin( dp[i+1][j][k][l][m] , dp[i][(1-j)][k][l][m]);
						}
					}
				}
			}
		}
		if(col == 'G'){
			rep(j,2){
				rep(k,2){
					rep(l,2){
						rep(m,2){
							chmin( dp[i+1][j][k][l][m] , dp[i][j][1-k][l][m]);
						}
					}
				}
			}
		}
		if(col == 'B'){
			rep(j,2){
				rep(k,2){
					rep(l,2){
						rep(m,2){
							chmin( dp[i+1][j][k][l][m] , dp[i][j][k][1-l][m]);
						}
					}
				}
			}
		}
		// 白として使う場合
		rep(j,2){
			rep(k,2){
				rep(l,2){
					rep(m,2){
						if(m == 0){
							chmin( dp[i+1][j][k][l][m] , ll(dp[i][j][k][l][1-m] + a[i].first));
						}
						else {
							chmin( dp[i+1][j][k][l][m] , ll(dp[i][j][k][l][1-m] - a[i].first));
						}
					}
				}
			}
		}
	}
	ll ans = INF;
	rep(m,2){
		chmin(ans, dp[2*n][0][0][0][m]);
	}
	rep(i,2*n+1){
		rep(j,2) {
		//	debug(j);
			rep(k,2)rep(l,2)rep(m,2){
				//cout << dp[i][j][k][l][m] << " ";
			}
			//cout << endl;
		}
		//cout << endl;
	}
	cout << ans << endl;
}