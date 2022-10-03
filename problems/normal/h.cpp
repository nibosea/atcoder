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
/*Write Under this comment
  ☆ 自☆ 由☆ 記☆ 述☆ 欄☆
*/
/*最長増加部分列 Longest Incremental Subsequence (LIS) */
int LIS(vector<int> A){
	int N = A.size(); 
	vector<int> dp(N+1,inf);
	/* dp[i]:=長さiのLISを作る時、i項目の値 */
	dp[0] = 0;/*配列Aの値は1以上*/
	int ans = 0;
	rep(i,N){
		/* A[i]<XとなるXの位置を見つける */
		int pos = lower_bound(dp.begin(),dp.end(),A[i]+1) -dp.begin();
		chmax(ans,pos);
		dp[pos] = A[i];
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	cout << LIS(a) << endl;
}
