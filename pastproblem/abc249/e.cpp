#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;
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
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
ll dp[10000][10060];
int main()
{
	ll n,MOD;
	cin >> n>>MOD;
	if(n<=2){
		cout << 0 << endl;
		return 0;
	}
	dp[0][0] = 1;
	dp[1][2] = 26;
	dp[1][2] %= MOD;
	cout << "neko1" << endl;
	For(i,1,n+1){
		ll ni = i+1;
		rep(j,n+1){
			dp[ni][j] += dp[i][j]; // ←　同じ文字を入れるパターン
			dp[ni][j] %= MOD;
			if(dp[i][j]){
				// 10 に対して操作を行った。このとき、10個前、100個前、1000個前と同じ文字を入れた可能性があるので、考慮する
				ll X = 10;
				rep(k,3){
					ll NI = ni - X + 1;
					if(NI > 0){
						// 文字数が増えるのにカウントをプラスしてしまっているので、それを取り除く
						dp[ni][j] -= dp[NI][j];
						if(dp[ni][j] < 0){
							dp[ni][j] += dp[NI][j];
						}
						// 逆に、文字数が増えるところにプラスし忘れているので、プラスする
						// 
						dp[ni][j+1] += dp[NI][j];
						if(dp[NI][j] == 0){
							dp[ni][j+1] += 26;
						}
						dp[ni][j+1] %= MOD;
					}
					X *= 10;
				}
			}
			// 10個入れたとき、１００個、１０００個入れると、文字数が１ずつ伸びるのでそれを考慮する
			// 違う文字を入れるなら、j+2文字になる。// 入れ方は25通り
			dp[ni][j+2] += dp[i][j] * 25;
			dp[ni][j+2] %= MOD;
		}
	}
	cout << "neko2" << endl;
	ll ans = 0;
	for(ll i = 1; i < n; i++){
		ans += dp[n][i];
		ans %= MOD;
	}
	rep(i,21){
		cout << i << ": ";
		rep(j,11){
			printf("%10lld ", dp[i][j]);
		}
		cout << endl;
	}
	cout << ans << endl;
}
