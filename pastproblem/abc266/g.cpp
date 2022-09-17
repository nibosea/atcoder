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
int main()
{
	int R, G, B, K;
	cin >> R>> G>> B>> K;
	// RG ga k ko
	ll RG = K;
	R -= K;
	G -= K;
	// (R,G,B) R,G ha narabanai
	// RG wo K ko
	mint rg_other = 1;
	ll other = R+G+B;
	for(int i = 1; i <= K + R+G+B; i++){
		rg_other *= i;
	}
	for(int i = 1; i<= K; i++){
		rg_other /= i;
	}
	for(int i = 1; i <= other; i++){
		rg_other /= i;
	}
	debug(rg_other.val());
	// other not include RG
	mint ans = rg_other;
	ll left = R + G + B;
	if(R && G){
		// R , G ga nokotteru
		mint rg2_other = 1;
		ll other2 = R+G+B-2;
		for(int i = 1; i <= K + 1 + other2; i++){
			rg2_other *= i;
		}
		for(int i = 1; i<= K+1; i++){
			rg2_other /= i;
		}
		for(int i = 1; i <= other2; i++){
			rg2_other /= i;
		}
		mint neko = rg2_other - ans;
		cout << neko.val() << endl;

	} else {
		for(int i = 1; i<=left;i++){
			ans *= i;
		}
		For(i,1,R+1) ans /= i;
		For(i,1,G+1) ans /= i;
		For(i,1,B+1) ans /= i;
	}
	cout << ans.val() << endl;
}
