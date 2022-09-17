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
ll dp[2010][2010][2];
int main()
{
	int n, m, k, s, t, x;
	cin >> n>> m>> k>> s>> t>> x;
	--s, --t;
	--x;
	rep(i,m){
		int u, v;
		cin >> u >> v;
		--u, --v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	// 到達できなければ０
	queue<int> q;
	map<int,bool> mp;
	q.push(s);
	mp[s]=true;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto nv:to[v]){
			if(mp[nv])continue;
			q.push(nv);
			mp[nv]=true;
		}
	}
	if(!mp[t]){
		cout << 0 << endl;
		return 0;
		// 未達の可能性を消しておく
	}
	dp[0][s][0]=1; // dp[0][s][0]:=0かい移動した。sにいる。xを偶数回
	rep(i,k){
		rep(j,n){
			rep(kk,2){
				if(dp[i][j][kk] != 0){
					// jからいける頂点にプラスする
					for(auto nv: to[j]){
						int k = kk;
						if(nv == x){
							k++;
							k%=2;
						}
						dp[i+1][nv][k] += dp[i][j][kk];
						dp[i+1][nv][k] %= MOD;
					}
				}
			}
		}
	}
	cout << dp[k][t][0] << endl;
}
