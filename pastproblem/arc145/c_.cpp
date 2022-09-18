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

const int COMSIZE = 1e7+100;

long long fac[COMSIZE], finv[COMSIZE], inv[COMSIZE];

// テーブルを作る前処理
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
using mint = modint998244353;
//Write From this Line
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
	COMinit();
	int n;
	cin >> n;
	// 2*x と2*x-1をペアにできない時すべてが破滅へと導かれるであろう…
	// (2*x, 2*x-1)のペアをペアxとする
	// p[i] がペアxi のうちの数字の一つであるとする
	// p[i+1]がペアx[i+1]のうちの数字の一つであるとする
	// A B C の順番であるような木の枝がK本だとする
	// A B C の順番が一つ決まったら
	// A,B,C ,,, はN個あるので、　N!のABCの並びがある
	// それぞれのABCの並びについて、2^n通りがある。
	//  K * 2^N * N!が答え。多分
	// K はDPで求まったりしないかな？
	// K は1 * 3  -1 * 3...手感じな気がする
	mint K = 1;
	K = COM(2*n,n) - COM(2*n,n-1);
	// 2*Nを求める (計算量 N)
	mint Po = mint(2).pow(n);
	// N!を求める (計算量 N)
	int N = n;
	mint kai = 1;
	while(N){
		kai *= N;
		N--;
	}
	// 純粋にやっても間に合いそう
	mint ans =  K * Po;
	ans *= kai;
	debug(K.val());
	debug(kai.val());
	debug(Po.val());
	
	cout << ans.val()<< endl;

}
