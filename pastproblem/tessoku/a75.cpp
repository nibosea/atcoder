#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
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

vector<ll> to[200'005];
//Write From this Line
ll dp[3000];
int main()
{
	int n;
	cin >> n;
	vector<P> td(n);
	rep(i,n) cin >> td[i].second >> td[i].first;
	SORT(td);
	for(int i = 0; i < n; i++){
		int time = td[i].second;
		int dead = td[i].first;
		for(int j = dead; j >= 0; j--){
			// 解き終わる時間
			int start = j - time;
			if(start < 0) continue;
			dp[j] = dp[start]+1;
		}
	}
	ll ans = 0;
	rep(i,1500){
		chmax(ans,dp[i]);
	} cout <<ans << endl;
}
