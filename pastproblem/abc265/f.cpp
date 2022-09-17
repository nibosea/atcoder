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
mint dp[105][1005][1005];
int main()
{
	ll n, d;
	cin >> n>> d;
	vector<ll> p(n);
	rep(i,n) cin >> p[i];
	vector<ll> q(n);
	rep(i,n) cin >> q[i];
	// dp[i][j][k]:= i jigen mitatokini kyori ga j dearuyouna monono kazu
	dp[0][0][0] = 1;
	For(i,1,n+1){
		rep(j,1001){
			// genjiten kyori j
			rep(k,1001){
				for(int now = j - d; now <= j+d; now++){
					int nj = abs(now - p[i-1]);
					int nk = abs(now - q[i-1]);
					if(nj <= d && nk <= d){
						dp[i][nj][nk] += dp[i-1][j][k];
					}
				}
			}
		}
	}
	mint ans = 0;
	rep(i,d+1){
		rep(j,d+1){
			ans += dp[n][i][j];
		}
	}
	cout << ans.val() << endl;
}
