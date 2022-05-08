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
	ll n, x;
	cin >> n>> x;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	SORT(a);
	ll d = a[n-1] - a[0];
	if(x > d){
		// 全部2倍して、あるやつだけxを加える。みたいな感じでやれば、差を縮めて行くことが出来るので、やがて差が0になる
		cout << 0 << endl;
		return 0;
	}
	ll ok = d, ng = -1;
	auto judge = [&](ll mid){
		// 差をmid以内にすることが出来るか。
		// ひとまず、一番でかくするやつを決めたいので、
		// 既に差がmid以内のやつを無視する
		// a[n-1]-midに収まらない中で一番でかいやつを求める
		auto itr = lower_bound(a.begin(),a.end(), a[n-1]-mid) - a.begin();
		if(itr == 0){
			// 全部okなのでtrue
			return true;
		}
		debug(a[itr-1]);
		return true;
	};
	while(ok - ng > 1){
		ll mid = (ok+ng)/2;
		debug(mid);
		if(judge(mid)) ok = mid;
		else ng = mid;
	}
	cout << ok << endl; 
}
