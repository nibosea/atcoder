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
ll dp[505][505];
int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n) cin >> p[i];
	//xを新たに木に追加するときのコトを考える
	// xm < x,  x < XMとしてかんがえる, xは根の子供になるか、1個前の頂点の子になるか、1子前の頂点の親の子になるか…
	// つまり！ｘをp[i]としたとき、yをp[i-1]とする
	// yの親をたどっていったときの子になれるかどうかで判断すれば良い！
	//ただパターン数が多いのでどうやって考えラb良いかわからに
	dp[1][0] = 1; // 1の親が0であるようなものは1通り
	// iの子の最小値がkであるようなモノがの何通りあるか
	dp[1][501] = 1;
	For(i,1,n){
		int num = a[i];
		for(int j = 1; j <= 501; j++){
			// dp[i][j] := iの子の最小値がjであるものが何通りあるか
			if(dp[i][j] >= 1){
				// jがnumよりも小さいなら、そこにつける？
			}
		}
	}
}
