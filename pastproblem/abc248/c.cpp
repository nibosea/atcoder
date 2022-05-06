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
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
ll dp[55][3000];
int main()
{
	ll n, m, k;
	cin >> n>> m>> k;
	// N項の和がK以下。
	// 各項は1~Mまでの値をとる
	// 何通りあるか
	// N <= 50;
	dp[0][0] = 1;
	rep(i,n){
		// 1項ずつ決める
		rep(j,k+1){
			// dp[i][j]:= i項目までで和がjのときの通り数
			For(k,1,m+1){
				// kを入れる
				dp[i+1][j+k] += dp[i][j];
				dp[i+1][j+k] %= MOD;
			}
		}
	}
	ll ans = 0;
	For(i,1,k+1){
		ans += dp[n][i];
		ans %= MOD;
	}
	cout << ans << endl;
}
