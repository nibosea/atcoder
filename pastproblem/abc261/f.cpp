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
	int n;
	cin >> n;
	vector<P> cx(n);
	// 色ごとに数を格納して、ソートしておく、
	map<int,int> mp;
	vector<map<int,int>> vmp(n+1);
	vector<int> c(n);
	rep(i,n) cin >> c[i];
	vector<int> x(n);
	rep(i,n) cin >> x[i];
	rep(i,n){
		int col = c[i];
		int num =x[i];
		//まず、自身より小さいものの数を調べる
		// mpを使って、num以上となる最小の位置を求める。そこ-1までになんこあるか
		auto itr = mp.lower_bound(num);
		// 色ごとに数字を持っておきたい
		mp[num]++;
		vmp[col][num]++;
	}
}
