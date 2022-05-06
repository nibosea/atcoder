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
int main(){
	ll n;
	cin >> n;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	bitset<60> bit(0);
	unsigned long long M = 0;
	vector<ll> ans(n);
	rep(i,n){
		ans[i] = M;
		unsigned long long now = (1ll<<t[i]);
		bitset<60> bit(now);

		// 大きくなるなら、大きくして終わり
		if(chmax(M,now)) continue;
		for(int j = t[i]; j < 60; j++){
			if( M&(1ll<<j) ){
				bit.set(j);
			}
		}
		if(chmax(M,bit.to_ullong())) continue;
		// そうでもなければ、0を見つけて1にして、それより右側を0にする
		ll j = t[i]+1;
		while(true){
			if(bit.test(j)){
				bit.reset(j);
			} else {
				// j bit目が立っていないなら、1にしてループ終わり
				bit.set(j);
				break;
			}
			j++;
		}
		chmax(M,bit.to_ullong());
	}
	cout << M << endl;
}
