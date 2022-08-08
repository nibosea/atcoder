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
using  mint = modint998244353;
vector<int> to[200'005];
//Write From this Line
const int COMSIZE = 1e7+100;

long long fac[COMSIZE], finv[COMSIZE], inv[COMSIZE];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < COMSIZE; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
int main()
{
	ll n, m, k;
	cin >> n>> m>> k;
	map<int, int> mp;
	// 手の数だけ考えてみる
	rep(i,m){
		int u, v;
		cin >> u>> v;
		--u, --v;
		mp[u]++;
		mp[v]++;
	}
	mint ans = 0;
	ll bi = 0;
	ll ki = 0;
	rep(i,n){
		if(mp[i] % 2 == 1){
			ki ++;
		}
		else {
			bi++;
		}
	}
	COMinit();
	// 奇数になる組み合わせ
	// k個選ぶ
	for(int i = 1; i <= k; i += 2){
		// 奇数をi個選ぶ偶数をk-i個
		ans += COM(ki,i) * COM(bi,k-i);
	}
	mint tans = COM(n,k);
	tans -= ans;
	cout << tans.val() << endl;
}

