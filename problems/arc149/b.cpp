#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(ll i = (a) ; i < (b) ; ++i)
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
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 9'000'000'000'000'000'000;

vector<ll> to[200'005];
//Write From this Line

int MAX_N = 300050;
int n, A[300050], dp[300050], B[300050];
int dp2[300050];
int LEN2 = 0, L2[300050];

int LEN = 0, L[300050]; // LEN は L の長さ（例：L[4] まで書き込まれている場合 LEN=4）

int main()
{
	cin >> n;
	vector<int> neko(n), baka(n);
	rep(i,n) cin >> neko[i];
	rep(i,n) cin >> baka[i];
	vector<P> ab(n);
	rep(i,n){
		ab[i] = P(neko[i],baka[i]);
	}
	SORT(ab);
	For(i,1,n+1){
		A[i] = ab[i-1].first;
		B[i] = ab[i-1].second;
	}

	// 動的計画法
	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
		dp[i] = pos;
		// 配列 L を更新
		L[dp[i]] = A[i];
		if (dp[i] > LEN) LEN += 1;
	}

	for (int i = 1; i <= n; i++) {
		int pos = lower_bound(L2 + 1, L2 + LEN2 + 1, B[i]) - L2;
		dp2[i] = pos;
		// 配列 L を更新
		L2[dp2[i]] = B[i];
		if (dp2[i] > LEN2) LEN2 += 1;
	}
	cout << LEN + LEN2 << endl;
}
