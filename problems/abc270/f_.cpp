#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll,ll> TA;
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
	vector<ll> x(n+1);
	rep(i,n) cin >> x[i+1];
	vector<ll> y(n+1);
	rep(i,n) cin >> y[i+1];
	rep(i,m){
		ll a, b, z;
		cin >> a>> b>> z;
		to[a].push_back(P(b,z));
		to[b].push_back(P(a,z));
	}
	ll cost = 0;
	priority_queue<P, vector<P>, greater<P>> sea_pq;
	priority_queue<P, vector<P>, greater<P>> air_pq;
	priority_queue<TA, vector<TA>, greater<TA>> pq;
	pq.push({0,1,2,-1}); // コスト、移動先、移動方法、前の頂点
	vector<bool> kuko(n+1,false);
	vector<bool> minato(n+1,false);
	
	rep(i,n){
		air_pq.push({x[i+1],i+1});
		sea_pq.push({y[i+1],i+1}); // air
	}
	int con = 0;
	vector<bool> connect(n+1,false);
	bool fly = false;
	bool umi = false;
	while(con != n){
		auto [now_cost,ver,how,mae] = pq.top();
		pq.pop();
		if(connect[ver])continue;
		if(how == 0 || how == 1){
			if(how == 0){
				if(kuko[mae]) cost -= x[mae];
				kuko[mae] = true;
				kuko[ver] = true;
			} else {
				if(minato[mae]) cost -= y[mae];
				minato[mae] = true;
				minato[ver] = true;
			}
		}
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
			pq.push(TA(next_cost,nv,2,ver));
		}
		ll air = x[ver] * (!kuko[ver]);
		ll sea = y[ver] * (!minato[ver]);
		while(!air_pq.empty() && air + air_pq.top().first <= kaso){
			auto [fee, NV] = air_pq.top();
			air_pq.pop();
			if(connect[NV]) continue;
			pq.push({air+fee,NV,0,ver});
		}
		while(!sea_pq.empty() && sea + sea_pq.top().first <= kaso){
			auto [fee, NV] = sea_pq.top();
			sea_pq.pop();
			if(connect[NV]) continue;
			pq.push({sea+fee,NV,1,ver});
		}
	}
	cout << cost << endl;
}
