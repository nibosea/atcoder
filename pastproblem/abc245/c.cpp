#include <bits/stdc++.h>
#include <atcoder/all>

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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	vector<ll> b(n);
	rep(i,n) cin >> a[i];
	rep(i,n) cin >> b[i];
	ll ok1 = a[0];
	ll ok2 = b[0];
	For(i,1,n){
		ll n1 = -1;
		ll n2 = -1;
		// ok1 から a, bがそれぞれ作れるか
		if(ok1 != -1){
			if(abs(a[i] - ok1) <= k){
				// ok1 から a[i]に行くことが可能
				n1 = a[i];
			} 		
			if(abs(b[i] - ok1) <= k){
				n2 = b[i];
			} 		
		}

		if(ok2 != -1){
			if(abs(a[i] - ok2) <= k){
				// ok2 から a[i]に行くことが可能
				n1 =a[i];
			} 		
			if(abs(b[i] - ok2) <= k){
				n2 = b[i];
			} 		
		}
		if(n1 == -1 && n2 == -1){
			coN();
			return 0;
		}
		ok1 = n1;
		ok2 = n2;
	}
	coY();
}
