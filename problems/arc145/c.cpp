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
const ll MOD = 998244353 ;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 9'000'000'000'000'000'000;
vector<int> to[200'005];
using mint = modint998244353;
//Write From this Line
int main()
{
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
	int K = 1;
	int neko = 1;
	rep(i,n-1){
		K += neko;
		K %= MOD;
		neko *= 3;
		neko %= MOD;
	}
	// 2*Nを求める (計算量 N)
	int Po = 1;
	// 2^n
	rep(i,n){
		Po *= 2;
		Po %= MOD;
	}
	// N!を求める (計算量 N)
	int N = n;
	int kai = 1;
	while(N){
		kai *= N;
		N--;
		kai %= MOD;
	}
	// 純粋にやっても間に合いそう
	ll ans =  K * Po;
	ans %= MOD;
	ans *= kai;
	ans %= MOD;
	cout << ans << endl;
	

}
