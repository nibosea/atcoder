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
vector<int> to[200500];
ll dp[100100][10];
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	dp[1][a[0]] = 1;
	For(i,1,n){
		int x = a[i];
		rep(j,10){
			int next = x + j;
			int nnext = x * j;
			next %= 10;
			nnext %= 10;
			dp[i+1][next] += dp[i][j];
			dp[i+1][nnext] += dp[i][j];
			dp[i+1][next] %= MOD;
			dp[i+1][nnext] %=MOD;
		}
	}
	rep(k,10)
	cout << dp[n][k] << endl;
}
