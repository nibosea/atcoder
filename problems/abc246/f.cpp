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
vector<long long> fact_inv, inv, Com;
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
void init_nCk(int n, int SIZE) {
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < SIZE + 5; i++) {
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
    Com.resize(SIZE + 5);
    Com[0] = 1;
    for (int i = 1; i < SIZE + 5; i++) {
        Com[i] = Com[i - 1] * ((n - i + 1) * inv[i] % MOD) % MOD;
    }
}
/*  nCk :MODでの二項係数を求める(前処理 int_nCk が必要)
    計算量:O(1)
*/
long long nCk(int k) {
    return Com[k];
}
long long pow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;  // n の最下位bitが 1 ならば x^(2^i) をかける
		ret%=MOD;
        x *= x;
        n >>= 1;  // n を1bit 左にずらす
    }
    return ret;
}
int main()
{
	ll n, l;
	cin >> n>> l;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	vector<ll> bits(n);

	init_nCk(l,25);
	rep(i,26){
		cout << nCk(i) << " ";
	}
	cout << endl;
	rep(i,n){
		ll bit = 0;
		rep(j,s[i].size()){
			int num = s[i][j] - 'a';
			bit |= (1<<num);
		}
		//debug(bit);
		bits[i] = bit;
	}
	ll ans = 0;
	for(int i = 1; i < (1<<26); i++){
		//bitで表すような文字の選び方が可能かどうかを判定する
		// i & s[i]が　iであれば作成可能
		bool can = false;
		rep(j,n){
			if((i & bits[j]) == i){
				can = true;
				break;
			}
		}
		if(!can) continue;
		// i の立ってる数が文字数よりも長い場合は作成できないことに注意
		bitset<26> a(i);
		int use = a.count();
		if(use > l) continue;
		// l - 1 choose use - 1 を答えに足す
		ll now = nCk(use);
		debug(i);
		debug(now);
		ll mul1 = 1;
		ll USE = use;
		while(USE){
			mul1 *= use;
			mul1 %= MOD;
			USE--;
		}
		ll mul2 = pow(use,l-use); // (use)^(L-use)
		now *= mul1;
		now %= MOD;
		now *= mul2;
		now %= MOD;
		ans += now;
		ans %= MOD;
		debug(now);
	}
	cout << ans << endl;
}
