#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
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
vector<P> to[200'005];
//Write From this Line
int main()
{
	// 多分ダイクストラ法?
	ll n, m;
	cin >> n>> m;
	// 辺のコストの小さい順に取り出す
	map<P,ll> hen;
	rep(i,m){
		ll a,b,c;
		cin >> a>>b>>c;
		--a, --b;
		to[a].push_back(P(b,c));
		to[b].push_back(P(a,c));
		hen[{a,b}] = i+1;
		hen[{b,a}] = i+1;
	}
	// 0->それぞれの場所　のコスト最小
	// 辺のコストの小さい順に見ていい気がする...
	vector<ll> dist(n,INF);
	dist[0] = 0;
	priority_queue<P,vector<P>, greater<P>> pq;
	pq.push({0,0}); // 0へのコスト、0
	vector<ll> use(0);
	// どの辺を使うのかの情報がほしい。。。
	vector<ll> oya(n,-1);
	oya[0] = -1;
	while(!pq.empty()){
		auto [cost, v] = pq.top(); pq.pop();
		// costと、どこから来たかの情報が欲しいかも？
		if(dist[v] < cost) continue;
		ll pare = oya[v];
		//  v と pareの辺を見つける
		ll ind = hen[{v,pare}];
		if(ind == 0) ind = hen[{pare,v}];
		if(v != 0) use.push_back(ind);
		for(auto x: to[v]){
			ll nv = x.first;
			ll len = x.second;
			ll ncost =cost + len;
			if(dist[nv] > ncost){
				dist[nv] = ncost;
				oya[nv] = v;
				pq.push({ncost,nv});
			}
		}
	}
	rep(i,n-1){
		cout << use[i] << " ";
	}
}
