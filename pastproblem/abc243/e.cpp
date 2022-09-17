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
vector<int> to[405];
// 迂回路判定；；
int main()
{
	int n, m;
	cin >> n>> m;
	vector g(n,vector<int>(n,-1));
	vector<P> edge(m);
	rep(i,m){
		int a, b;
		cin >> a>> b;
		--a, --b;
		g[a][b] = i;
		edge[i] = P(a,b);
	}
	vector<int> dis(n,-1); dis[0] = 0;
	vector<P> memo(n);
	queue<int> que; que.push(0);
	vector<bool> use(m,false);
	while(!que.empty()){
		int i = que.front(); que.pop();
		rep(j,n) if(dis[j] == -1 && g[i][j] != -1){
			dis[j] = dis[i] + 1;
			memo[j] = P(i,g[i][j]); //iから辺g[i][j]を使ってjに行ける
			use[g[i][j]] = true;
			que.push(j);
		}
	}
	if(dis[n-1] == -1){
		rep(i,m) cout<<-1 <<endl;
		return 0;
	}
	rep(i,m){
		if(!use[i]){
			//puts("not use");
			cout << dis[n-1] << endl;
		}
		else {
			//　辺iを使わないようにしてdfs
			vector<int> now_dis(n,-1); now_dis[0] = 0;
			queue<int> q; q.push(0);
			vector<bool> seen(n,false);
			while(!q.empty()){
				int j = q.front();q.pop();
				rep(k,n){
					if(now_dis[k] == -1 && g[j][k] != -1 && g[j][k] != i){
						now_dis[k] = now_dis[j] + 1;
						q.push(k);
					}
				}
			}
			cout << now_dis[n-1] << endl;
		}
	}
}
