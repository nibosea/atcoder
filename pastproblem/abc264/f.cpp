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
const ll INF = 1'000'000'000'000'000'000;

vector<ll> to[200'005];
//Write From this Line
ll dp[2010][2010][2][2];
int main()
{
	int h, w;
	cin >> h>> w;
	vector<ll> R(h);
	rep(i,h) cin >> R[i];
	vector<ll> C(w);
	rep(i,w) cin >> C[i];
	vector<vector<int>> S(h+5,vector<int>(w+5,0));
	rep(i,h){
		string s;
		cin >> s;
		rep(j,w){
			if(s[j] == '1') S[i][j] = 1;
		}
	}
	// dp[i][j]:= min_cost to (i,j)
	rep(i,2010)rep(j,2010)rep(x,2)rep(y,w)dp[i][j][x][y] = INF;
	//dp[i][j][x][y]:= (i,j)
	dp[0][0][0][0] = 0;
	dp[0][0][1][1] = R[0] + C[0];
	int now = S[0][0];
	rep(i,h){
		rep(j,w){
			bool same = (now == S[i][j+1]);
			bool same2 = (now == S[i+1][j]);
			rep(x,2){
				rep(y,2){
					// dp[i][j][x][y]からの繊維
					if((same && x) || (!same && !x)){
						chmin(dp[i][j+1][x][1], dp[i][j][x][y] + C[j+1]);
					} else {
						chmin(dp[i][j+1][x][0], dp[i][j][x][y]);
					}
					if((same2 && y) || (!same2 && !y)){
						chmin(dp[i+1][j][1][y], dp[i][j][x][y] + R[i+1]);
					}else {
						chmin(dp[i+1][j][0][y], dp[i][j][x][y] );
					}
				}
			}
		}
	}
	ll ans = INF;
	rep(x,2)rep(y,2){
		chmin(ans,dp[h-1][w-1][x][y]);
	}
	rep(i,2010)rep(j,2010)rep(x,2)rep(y,w)dp[i][j][x][y] = INF;
	//dp[i][j][x][y]:= (i,j)
	dp[0][0][0][1] = C[0];
	dp[0][0][1][0] = R[0];
	now = 1-now;
	rep(i,h){
		rep(j,w){
			bool same = (now == S[i][j+1]);
			bool same2 = (now == S[i+1][j]);
			rep(x,2){
				rep(y,2){
					// dp[i][j][x][y]からの繊維
					if((same && x) || (!same && !x)){
						chmin(dp[i][j+1][x][1], dp[i][j][x][y] + C[j+1]);
					} else {
						chmin(dp[i][j+1][x][0], dp[i][j][x][y]);
					}
					if((same2 && y) || (!same2 && !y)){
						chmin(dp[i+1][j][1][y], dp[i][j][x][y] + R[i+1]);
					}else {
						chmin(dp[i+1][j][0][y], dp[i][j][x][y] );
					}
				}
			}
		}
	}
	rep(x,2)rep(y,2){
		chmin(ans,dp[h-1][w-1][x][y]);
	}
	cout << ans << endl;
}
