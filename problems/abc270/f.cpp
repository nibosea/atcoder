#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> TA;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(ll i = (a) ; i < (b) ; ++i)
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

const ll dy[] = {0,0,1,-1};
const ll dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 9'000'000'000'000'000'000;

vector<P> to[200'005];
//Write From this Line
int main()
{
	int n, m;
	cin >> n>> m;
	vector<ll> x(n);
	rep(i,n) cin >> x[i];
	vector<ll> y(n);
	rep(i,n) cin >> y[i];
	rep(i,m){
		ll a, b, z;
		cin >> a>> b>> z;
		to[a].push_back(P(b,z));
		to[b].push_back(P(a,z));
	}
	ll cost = 0;
	priority_queue<P, vector<P>, greater<P>> air_pq;
	priority_queue<P, vector<P>, greater<P>> sea_pq;
	priority_queue<P, vector<P>, greater<P>> pq;
	vector<bool> aired(n+1,false);
	vector<bool> seaed(n+1,false);
	rep(i,n){
		air_pq.push({x[i],i+1});
		sea_pq.push({y[i],i+1});
	}
	pq.push(P(0,1));
	while(con != n){
		auto [now_cost,ver] = pq.top();
		pq.pop();
		if(connect[ver])continue;
		connect[ver] = true;
		con ++;
		cost += now_cost;
		debug(ver);
		debug(cost);
		ll kaso = INF;
		for(auto next: to[ver]){
			auto [nv, next_cost] = next;
			if(connect[nv]) continue;
			chmin(kaso,next_cost);
			pq.push(P(next_cost,nv)); // 道路の場合、next_costでver -> nv
		}
		// もしかしたら、仮想よりも小さく行けるかもしれない
		If
		ll air = x[ver-1] * (!aired[ver]);
		ll sea = y[ver-1] * (!seaed[ver]);
		while(!air_pq.empty() && air+pq_air.top() <= kaso){
		}
	}
	cout << cost << endl;
}
