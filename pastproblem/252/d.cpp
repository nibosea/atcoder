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
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	map<ll, ll> mp;
	rep(i,n){
		mp[a[i]]++;
	}
	// 2つ一致、3つ一致を数え上げて全体から引く
	ll ans = 1; // ans = nC3
	ans *= n * (n-1) * (n-2);
	ans /= 6;
	ll minus = 0;
	for(auto x: mp){
		ll kazu = x.second;
		// kazu C 2
		ll tmp = 0;
		if(kazu >= 2){
			tmp += (kazu * (kazu-1)) / 2; // 2つ選ぶ場合
			// 残り一つを他のn-kazuから選ぶ
			tmp *= (n-kazu);
		}
		if(kazu >= 3){
			// 3つ選ぶ倍kazuC3
			ll neko = 1;
			neko *= (kazu * (kazu-1) * (kazu-2))/6;
			tmp += neko;
		}
		minus += tmp;
	}
	cout << ans - minus << endl;
}
