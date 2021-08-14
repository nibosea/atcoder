#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef tuple<ll,ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define fore(i, a) for(auto &i: a)
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
vector<P> to[10'005]; // to[i] の中身は，頂点，重み
int main()
{
	ll n;
	cin >> n;
	map<P, int> hen; 
	rep(i,n-1){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		to[a].push_back(P(b,c,i));
		to[b].push_back(P(a,c,i));
	}
	// それぞれの辺に対して意味を持たせたい
	queue<int> q;

	q.push(0);
	int depth = 0;
	vector<int> dep(n,-1);
	dep[0] = 0;
	map<int, bool> mp;
	mp[0] = true;
	vector<pair<ll,ll>> depweight(n-1);
	while(!q.empty()){
		int v = q.front(); q.pop();
		int ndep = dep[v] + 1;
		for(auto x: to[v]){
			ll nv, cost, hen;
			tie(nv,cost,hen) = x;
			if(mp[nv]) continue;
			dep[nv] = ndep;
			mp[nv] = true;
			q.push(nv);
			depweight[hen] = {cost,ndep};
		}
	}
	ll M = 0;
	SORT(depweight);
	for(auto x:depweight){
		printf("(%lld, %lld),", x.first, x.second);
		chmax(M, x.second);
	}
}
