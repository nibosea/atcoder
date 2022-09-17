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

const ll dy[] = {0,0,1,-1};
const ll dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
ll g_keta(ll x){
	ll ret = 0;
	while(x != 0){
		ret ++;
		x/=10;
	}
	return ret;
}
ll g_ten(ll x){
	ll ret = 1;
	while(ret * 10 <= x){
		ret *= 10;
	}
	return ret;
}
ll g_kakusi(ll x){
	string s = to_string(x);
	s = s.substr(1);
	if(s[0] == '0'){
		s[0] = '1';
		For(i,1,s.size()){
			s[i] = '0';
		}
	}
	ll ret = stoll(s);
	ret++;
	return ret;
}
void solve(){
	ll l, r;
	cin >> l>> r;
	ll ans = r - l + 1;
	ll ten = g_ten(r);
	if(ans > ten){
		// 一考の余地あり
	}
}
int main()
{
	ll t;	
	cin >> t;	
	while(t--){
		solve();
	}
}
