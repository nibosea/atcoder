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
vector<int> to[200'005];
//Write From this Line
int main()
{
	map<P,ll> mp;
	ll n;
	cin >> n;
	map<ll, ll> M;
	vector<vector<P>> pe(n);
	rep(i,n){
		ll m;
		cin >> m;
		rep(j,m){
			ll p, e;
			cin >> p>> e;
			pe[i].push_back({p,e});
			mp[{p,e}]++;
			chmax(M[p],e);
		}
	}
	ll now_p = 0;
	ll ans = 0;
	rep(i,n){
		rep(j,pe[i].size()){
			auto [x,y] = pe[i][j];
			// x^y という数、x^(y+1)以上が存在しなければ、ok
			// x^y のyの最大値を求めておく
			if(mp[{x,y}] != 1) continue;
			if(M[x]==y){
				ans++;
				//printf("(%lld, %lld)\n",x, y);
				break;
			}
		}
	}
	if(n == 1){
		cout << 1 << endl;
		return 0;
	}
	if(ans == n)ans--;
	cout << ans+1<< endl;
}
