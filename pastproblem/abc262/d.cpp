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
ll dp[105][105][105];
int main()
{	
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	// 1個以上選んで平均が整数になるものの数え上げ // Nが100
	// k個選んで平均が整数になる->Sumが%k == 0
	// dpであまりを持つ
	// dp[i][j][k]:=i個選んで%jがkの物の数とか？
	// 1個はどれもおｋ
	ll ans = n;
	dp[0][0][0] = 1;
	// 初期化したい
	For(i,2,n+1){
		rep(x,105)rep(y,105)rep(z,105)dp[x][y][z]=0;
		dp[0][0][0] = 1;
		rep(j,n){
			ll num = a[j];
			num %= i;
			for(int k = 0; k <= i; k++){
				rep(md,i){
					dp[j+1][k+1][(md+num)%i] += dp[j][k][md];
					dp[j+1][k][md] += dp[j][k][md];
					dp[j+1][k+1][(md+num)%i] %= MOD;
					dp[j+1][k][md] %= MOD;
				}
			}
		}
		ans += dp[n][i][0];
		ans %= MOD;
	}
	cout << ans << endl;
}
