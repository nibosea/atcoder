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
	ll n, m;
	cin >> n >> m;
	vector<ll> a(n+1);
	rep(i,n+1) cin >> a[i];
	vector<ll> c(n+m+1);
	rep(i,n+m+1) cin >> c[i];
	vector<ll> b(m+1);
	vector<ll> sum(n+m+1, 0);
	int cnt = 0;
	for(int i = m; i >= 0; i--){
		// b[i]を求める
		ll mul = c[i+n];
		ll now = sum[i+n];
		cnt++;
		// b[i] * a[n] + now = mul となるようにb[i]を決めればいい
		b[i] = (mul - now) / a[n];
		rep(j,n+1){
			int ind = i + j;
			sum[ind] += b[i] * a[j];
		}
	}
	rep(i,m+1){
		cout << b[i] << " ";
	}
	cout << endl;
}
