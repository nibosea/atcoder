#include <bits/stdc++.h>

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
vector<int> to[200'005];
int main()
{
	int n;
	cin >> n;
	rep(i,n-1){
		int a, b;
		cin >> a>> b;
		--a, --b;
		to[a].push_back(b);
		to[b].push_back(a);
	}
	// 木の直径
	int s = 0;
	queue<int> q;
	vector<int> seen(n,-1);
	int last_ind = 0;
	auto add = [&](int nv, int ncost){
		if(seen[nv]==-1) {
			seen[nv] = ncost;
			q.push(nv);
			last_ind = nv;
		}
		return ;
	};
	add(0,0);
	while(!q.empty()){
		int v = q.front(); q.pop();
		int cost = seen[v] + 1;
		for(auto nv: to[v]){
			add(nv,cost);
		}
	}
	s = last_ind;
	rep(i,n) seen[i] = -1;
	add(s,0);
	while(!q.empty()){
		int v = q.front(); q.pop();
		int cost = seen[v] + 1;
		for(auto nv: to[v]) add(nv,cost);
	}
	cout << seen[last_ind] + 1 << endl;
}
