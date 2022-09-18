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
const ll INF = 9'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	ll n, x, y, z;
	cin >> n>> x>> y>> z;
	// 数学の点、受験番号(小),英語の点,合計点Z人
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<ll> b(n);
	rep(i,n) cin >> b[i];
	// とりあえず点数を格納
	vector<P> math(n,P(-1,1));
	rep(i,n){
		math[i] = P(a[i],-i);
	}
	SORT(math);
	REV(math);
	vector<bool> pass(n,false);
	rep(i,x){
		ll human = -math[i].second;
		pass[human] = true;
	}
	vector<P> eng(n,P(-1,1));
	rep(i,n){
		if(pass[i])continue;
		eng[i] = P(b[i], -i);
	}
	SORT(eng);
	REV(eng);
	rep(i,y){
		ll human = -eng[i].second;
		pass[human] = true;
	}
	rep(i,n) a[i] += b[i];
	vector<P> sum(n,P(-1,1));
	rep(i,n){
		if(pass[i]) continue;
		sum[i] = P(a[i],-i);
	}
	SORT(sum);
	REV(sum);
	rep(i,z){
		int human = -sum[i].second;
		pass[human] = true;
	}
	rep(i,n){
		if(pass[i]){
			cout << i + 1 << endl;
		}
	}
}
