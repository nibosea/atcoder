//https://algo-logic.info/combination/
//https://algo-logic.info/calc-pow/
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
//Write From this Line

const int COMSIZE = 30;
const int COMMOD = MOD;

long long fac[COMSIZE], finv[COMSIZE], inv[COMSIZE];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < COMSIZE; i++){
        fac[i] = fac[i - 1] * i % COMMOD;
        inv[i] = COMMOD - inv[COMMOD%i] * (COMMOD / i) % COMMOD;
        finv[i] = finv[i - 1] * inv[i] % COMMOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % COMMOD) % COMMOD;
}
ll dp[30];
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
		x %= MOD;
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
		ret %= MOD;
		x %= MOD;
        x *= x;
		x %= MOD;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}
int main()
{
	ll n, l;
	cin >> n>> l;
	COMinit();
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	vector<ll> bits(n);

	rep(i,n){
		ll bit = 0;
		rep(j,s[i].size()){
			int num = s[i][j] - 'a';
			bit |= (1<<num);
		}
		bits[i] = bit;
	}
	ll ans = 0;

	dp[1] = 1;
	For(i,2,27){
		// dp[i] := i^L - i_C_(i-1) * dp[i-1] - i_C_(i-2) * dp[i-2]
		if(l<i) continue;
		ll now = modpow(i,l,MOD);
		ll minus = 0;
		for(int j = i - 1; j >= 1; j--){
			minus += COM(i,j) * dp[j];
			minus %= MOD;
		}
		dp[i] = now - minus;
		if(dp[i] < 0) dp[i] += MOD;
	}
	//
//	For(i,1,27){
//		cout << dp[i] << " ";
//	}
//	cout << endl;
	for(int tmp = 1; tmp < (1<<26); tmp++){
		bool can = false;
		rep(j,n){
			if((tmp&bits[j]) == tmp) can = true;
		}
		if(!can) continue;
		bitset<26> nowbit(tmp);
		int use = nowbit.count();
		ans += dp[use];
		ans %= MOD;
	}
	cout << ans << endl;
}
