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
const ll INF = 9'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	ll n, c;
	cin >> n>> c;
	// bitごとに考えれば気持ちよくなりそう
	vector<int> t(n), a(n);
	rep(i,n) cin >> t[i] >> a[i];
	bitset<32> bit;
	bit = c;
	map<P,bool> XOR;
	map<P,bool> OR;
	map<P,bool> AND;
	XOR[{0,0}] = 0;
	XOR[{0,1}] = 1;
	XOR[{1,0}] = 1;
	XOR[{1,1}] = 0;
	OR[{0,0}] = 0;
	OR[{0,1}] = 1;
	OR[{1,0}] = 1;
	OR[{1,1}] = 1;
	AND[{1,1}] = 1;
	AND[{0,1}] = 0;
	AND[{1,0}] = 0;
	AND[{0,0}] = 0;
	mp[P,bool] func;
	rep(i,n){
		int oep = t[i];
		int num =a[i];
		bitset<32> now;
		if(ope == 1){
			// AND
			if(i==0) func = AND;

		}
		if(ope == 2){
			// OR
			if(i==0) func = OR;
		}
		if(ope == 3){
			if(i==0) func = XOR;
			// XOR
			// まず、bitに
		}
		cout << bits << endl;
	}
}
