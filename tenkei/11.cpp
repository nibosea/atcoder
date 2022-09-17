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
ll dp[5010][5010];
int main()
{
	ll n;
	cin >> n;
	ll MAX_D = 0;
	vector<tuple<int, int, int>> t(n);
	rep(i,n){
		ll d, c, s;
		cin >> d>> c>> s;
		t[i] = {d,c,s};
	}
	SORT(t);
	rep(i,n){
		ll d, c, s;
		tie(d,c,s) = t[i];
		rep(j,5000){
			// dp[i][j]　を決める
			chmax(dp[i+1][j], dp[i][j]);
			if(j + c <= d){
				dp[i+1][j+c] = max(dp[i+1][j+c], dp[i][j] + s);
			}
		}
		
	}
	ll ans = 0;
	rep(i,5010) chmax(ans, dp[n][i]);
	cout << ans << endl;
}
