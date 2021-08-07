#include <bits/stdc++.h>
using namespace std;

using ll = long long;
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
	int n, q;
	cin >> n >> q;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	rep(i,q){
		ll x;
		cin >> x;
		// xより小さい数が何個あるかを調べる
		ll ok = 0, ng = n;
		while(ng - ok > 1){
			ll mid = (ok + ng) / 2;
			if(a[mid] <= x) ok = mid+1;
			else ng = mid;
		}
		// a[ok]は，ｘ以下
		debug(ok);
	}
}