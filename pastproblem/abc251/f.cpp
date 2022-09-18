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
//Write From this Line
vector<int> to[200050];
vector<P> T1, T2;
bool visited[200005];
void dfs(int v){
	visited[v] = true;
	for(auto nv :to[v]){
		if(!visited[nv]){
			T1.push_back(P(v,nv));
			dfs(nv);
		}
	}
}
void bfs(){
	rep(i,200005)visited[i] = false;
	queue<int> q;
	visited[0] = true;
	q.push(0);
	int v;
	while(!q.empty()){
		v = q.front();q.pop();
		for(auto nv:to[v]){
			if(!visited[nv]) {
				T2.push_back(P(v,nv));
				visited[nv] = true;
				q.push(nv);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n>> m;
	rep(i,m){
		int x, y;
		cin >> x>> y;
		--x, --y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	// T1の構築、連結成分の１ループを見つければいい
	dfs(0);
	bfs();
	for(auto p:T1) cout << p.first+1 << " " <<  p.second+1 << endl;
	for(auto p:T2) cout << p.first+1 << " " << p.second+1 << endl;
}
