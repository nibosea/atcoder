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
//Write From this Line
ll keta(ll x){
	ll ret = 0;
	while(x){
		ret++;
		x/=10;
	}
	return ret;
}
void solve(){
	int l, r;	
	cin >> l >> r;
	// f(x) := min(10x, pow(x,n)+x);
	// f(x) > r となる最小のxを求める
	ll ok = r, ng = 0; // ok  を←にする
	auto judge = [&](ll x){
		ll n = keta(x);
		//f(x)を求める
		ll Poo = 1;
		while(n--){
			Poo*=10;
		}
		Poo+=x;
		ll fx = min(Poo, 10*x);
		return fx;
	}; 
	while(ok - ng > 1){
		ll mid = (ok+ng)/2;
		if(mid < l) {
			ng = mid;
			continue;
		}
		if(judge(mid) > r) ok = mid;
		else ng = mid;
	}
	ll Left=ok;
	// f(x) > r となる最大のxを求める
	cout << r - Left + 1 << endl;
	
}
int main()
{
  int t;
  cin >> t;
  rep(i,t) solve();
	

}

