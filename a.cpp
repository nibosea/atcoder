#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
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
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m; 
	cin >> n >> m; 
	map<P,ll> cost;
	rep(i,m){
		int a, b, c;
		cin >> a >> b >> c;
		--a, --b;
		cost[{a,b}] = c;
	}
	vector<vector<ll>> ans(n+1,vector<ll> (n+1,inf));
	ll sum = 0;
	rep(s,n){
		rep(t,n){
			if(s==t) ans[s][t] = 0;
			if(cost[{s,t}]) ans[s][t] = cost[{s,t}];
			else ans[s][t] = inf;
			if(ans[s][t] == inf) sum += 0;
			else sum += ans[s][t];
		}
	}
	debug(sum);
	For(k,1,n){
		vector<vector<ll>> tmp(n+1,vector<ll> (n+1,0));
		rep(s,n){
			rep(t,n){
				if( (ans[s][k+1] == inf || ans[k+1][t] == inf) && ans[s][t] == inf){
					tmp[s][t] = 0;
				} else {
					tmp[s][t] = ans[s][k+1] + ans[k+1][t];
					chmin(tmp[s][t], ans[s][t]);
					sum += tmp[s][t];
				}
			}
		}
		swap(tmp,ans);
		debug(sum);
	}
	cout << sum << endl;
}
