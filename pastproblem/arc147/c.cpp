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
int main()
{
	int n;
	cin >> n;
	vector<P> lr(n);
	vector<P> lr2(n);
	rep(i,n) cin >> lr[i].first >> lr[i].second;
	rep(i,n) {
		lr2[i] = lr[i];
		swap(lr2[i].second,lr2[i].first);
	}
	SORT(lr2);
	ll m = inf;
	ll M = 0;
	rep(i,n){
		chmin(m,lr[i].first);
		chmin(M,lr[i].second);
	}
	SORT(lr);
	rep(i,n) {
		swap(lr2[i].second,lr2[i].first);
	}
	ll score = inf;
	ll ok = M;
	ll ng = 0;
	vector<ll> arr1(n);
	while(true){
		ll man = (ok + ng) / 2;
		rep(i,n/2){
			auto [l,r] = lr2[i];
			arr1[i] = min(r,man);
		}
		For(i,n/2,n){
			auto [l,r] = lr2[i];
			arr1[i+(n/2)] = max(l,man);
		}
		SORT(arr1);
		ll ans = 0;
		ll mul = n-1;
		for(int i = 0; mul > 0; i++, mul -= 2){
			ans += mul * (arr1[n-1-i] - arr1[i]);
		}
		if(chmin(score,ans)){
			ok = man;
			continue;
		}
		else break;
	}
	cout << score << endl;
}
