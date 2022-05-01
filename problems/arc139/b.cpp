#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
typedef pair<int,int> P;
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
const ll inf = 1001001001;
const ll INF = (1e18) + 2;
vector<int> to[200'005];
//Write From this Line
ll solve_1(ll x, ll n){
	// 1増やすのにx円
	ll ret = x * n;
	return ret;
}
ll solve_1b(ll x, ll b, ll z, ll n){
	// 1増やすのにx円、b増やすのにz円, nを作る
	// bを可能な限りしたほうが良いことはわかっている
	ll ret = 0;
	ll use = (n / b); // nにbは何回行けるか
	ret += use * z;
	ret += (n%b) * x;
	return ret;
}
ll solve_all(ll x, ll a, ll y, ll b, ll z , ll n){
	// aとbを出来るだけ多く使いたい。1は調整に使うだけ。
	if(a==b){
		// 少ないy,zのうち少ない方を使えばいい
		ll mon = y;
		if(y > z) mon = z;
		return solve_1b(x,a,mon,n);
	}
	// 最小公倍数
	ll G = __gcd(a,b);
	ll L = (a/G) * b;
	// Lを作るのにa,bのどちらがお得かを考える
	ll use_a = L/a; // use_a回 a を使えばLを作れる
	ll use_b = L/b;
	ll T = (n / L);  // n　に LはT回入る
	ll ans = 0;
	if(use_a * y < use_b * z){
		ans += T * (use_a * y);
	} else {
		ans += T * (use_b * z);
	}
	n -= L*T;
	// 残ったnに対して、暗黒熱実装で解く。
	// bは最大で何回使えるか
	if(n == 0) return ans;
	ll M = n / b;
	ll BU = INF;
	// n 円を出来るだけ安く作ろう大作戦
	ll byen = z * M;
	ll left = n - (M*b);
	while(M>=0){
		ll tmp = solve_1b(x,a,y,left);
		if(BU > (tmp + byen)){
			BU = tmp + byen;
		}
		M--;
		byen -= z;
		left += b;
	}
	ans += BU;
	return ans;
}
void solve(){
	ll N,A, B, X, Y, Z;
	cin >> N>>A>> B>> X>> Y>> Z; // (1,X), (A,Y), (B,Z);
	bool use_a = true;
	bool use_b = true;
	if(X*A <= Y){
		use_a = false;
	}
	if(X*B <= Z){
		use_b = false;
	}
	if(use_a && use_b){
		cout << solve_all(X,A,Y,B,Z,N) << endl;
		return ;
	}
	if(use_a){
		cout << solve_1b(X,A,Y,N) << endl;
		return ;
	}
	if(use_b){
		cout << solve_1b(X,B,Z,N) << endl;
		return ;
	}
	cout << solve_1(X,N) << endl;
	return ;
	
}
int main()
{
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
