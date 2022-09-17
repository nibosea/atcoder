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
ll dp[100500][5];// 0~4;
int main()
{
	int n;
	cin >> n;
	vector<array<int, 3>> v(n+10);
	int t = 0;
	rep(i,n){
		rep(j,3)cin >> v[i][j];
		chmax(t,v[i][0]);
	}
	v[n][0] = inf;
	rep(i,100500) rep(j,5) dp[i][j] = -1;
	dp[0][0] = 0;
	int ind = 0;// v[ind]
	for(int i = 1; i <= t;i++){
		//dp[i][x] wo motomeru
		if(i == v[ind][0]){
			int cat = v[ind][1];
			int big = v[ind][2];
			ind++;
			// tukamaeru koto wo kangaeru
			for(int x=0; x <= 4; x++){
				for(int y = x - 1; y <= x+1; y++){
					if(y<0)continue;
					if(y >= 5)continue;
					if(x==cat){
						if(dp[i-1][y] ==-1) continue;
						chmax(dp[i][x], dp[i-1][y] + big);
					} else {
						if(dp[i-1][y] ==-1) continue;
						chmax(dp[i][x], dp[i-1][y]);
					}
				}
			}
		}
		else {
			for(int x=0; x <= 4; x++){
				for(int y = x - 1; y <= x+1; y++){
					if(y<0)continue;
					if(y >= 5)continue;
					if(dp[i-1][y] ==-1) continue;
					chmax(dp[i][x], dp[i-1][y]);
				}
			}
		}
	}
	ll ans = 0;
	rep(i,5)chmax(ans,dp[t][i]);
	cout << ans << endl;
}
