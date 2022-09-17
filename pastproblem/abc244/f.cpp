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

vector<int> to[2010];
ll dp[(1<<18)][20];
int main()
{
	int n,m ;
	cin >> n>>m ;
	rep(i,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	for(int tmp = 0; tmp < (1<<n); tmp++){
		rep(i,n) dp[tmp][i] = inf;
	}
	rep(i,n) dp[0][i] = 0;
	rep(i,n){
		dp[(1<<i)][i] = 1;
	}

	// 構築
	queue<pair<int,ll>> q;
	// first にいて,bitset<17>のパターン
	rep(i,n){
		ll tmp = (1<<i);
		q.push({i,tmp});
	}
	while(!q.empty()){
		int v = q.front().first;
		int bitf = q.front().second;
		q.pop();
		ll cost = dp[bitf][v];
		for(auto nv: to[v]){
			//次のbit
			ll nbit = bitf;
			nbit ^= (1<<nv);
			if(chmin(dp[nbit][nv], cost+1)){
				q.push({nv,nbit});
			}
		}
	}
	ll ans = 0;
	for(int tmp = 0; tmp < (1<<n); tmp++){
		ll m = inf;
		rep(i,n){
			chmin(m,dp[tmp][i]);
		}
		a/fda
		ans += m;
		afjdksa
	}

	cout << ans << endl;
}
