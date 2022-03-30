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
vector<int> to[100500];
ll dp[(1<<20)][20];
int main()
{
	int n, m;
	cin >> n>> m;
	vector<int> a(m), b(m);
	rep(i,m) cin >> a[i] >> b[i];
	rep(i,m){
		int x = a[i];
		int y = b[i];
		--x, --y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	int k; cin >> k;
	vector<int> c(k);
	rep(i,k) cin >> c[i];
	rep(i,k) c[i]--;
	map<int, int> mp;//頂点iはcでいうとｋろのindexいくつ？
	rep(i,k){
		int x = c[i];
		mp[x] = i+1; //falseのために1スタートにsルウ
	}
	// cに含まれている要素が一番左に来るし、一番右もcに含まれている要素。cの両端を全探索？
	vector d(k,vector<ll>(k,INF));
	rep(i,k) d[i][i] = 0;
	rep(i,k){
		// iから各頂点への最短距離を求める
		queue<P> q;
		q.push({c[i],0});
		vector<bool> seen(n,false);
		seen[c[i]] = true;
		while(!q.empty()){
			int v = q.front().first;
			int cost = q.front().second;
			q.pop();
			if(mp[v]){
				int ind = mp[v] - 1;
				d[i][ind] = cost;
			}
			for(auto nv: to[v]){
				if(seen[nv])continue;
				seen[nv] = true;
				q.push({nv,cost+1});
			}
		}
	}

	rep(i,(1<<k)){
		rep(j,k){
			dp[i][j] = INF;
		}
	}
	rep(i,k) dp[1<<i][i] = 1;
	for(int tmp = 0; tmp < (1<<k); tmp++){
		rep(v,k){
			// 今いる頂点
			rep(nv, k){
				// 次に行く頂点
				chmin(dp[tmp|(1<<nv)][nv], dp[tmp][v]+d[v][nv]);
			}
		}
	}
	ll ans = INF;
	rep(i,k) chmin(ans, dp[(1<<(k))-1][i]);
	cout << ((ans==INF)? -1 : ans ) << endl;
	//cout << ans << endl;
}
