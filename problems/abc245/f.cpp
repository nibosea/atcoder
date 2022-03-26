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
vector<bool> glok(200050);
vector<int> to[200050];

bool seen[200050];
bool dfs(int v){
	if(glok[v]){
		return true;
	}
	if(seen[v]){
		// また来た！ってときは、return 
		glok[v] = true;
		return true;
	}
	seen[v] = true;
	for (auto nv: to[v]){
		if(dfs(nv)) {
			glok[v] = true;
			return true;
		}
	}
	seen[v] = false;
	return false;
}
int main()
{
	int n, m; cin >> n >> m;
	rep(i,m) {
		int x, y;
		cin >> x>> y;
		x--;y--;
		to[x].push_back(y);
	}
	
	vector<bool> ans(n,false);
	rep(i,n){
		if(ans[i]) continue;
		if(glok[i]) ans[i] = true;
		// dfsでやったほうがいい
		dfs(i);
	}
	int ans2 = 0;
	rep(i,n){
		ans2 += ans[i];
	}
	cout << ans2 << endl;
}