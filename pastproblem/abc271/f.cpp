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
int main()
{
	ll n;
	cin >> n;
	vector<vector<ll>> a(n,vector<ll> (n));
	rep(i,n)rep(j,n)cin>>a[i][j];
	// a[i][j]に行って、XORが k である時が何通りあるか
	map<P,ll> mp0;
	for(ll i = 0; i < (1<<(n-1)); i++){
		bitset<20> bit(i);
		ll sum = a[0][0];
		ll x = 0;
		ll y = 0;
		rep(j,n-1){
			if(bit.test(j)){
				// 横に行く
				sum ^= a[x][y+1];
				y++;
			} else {
				// 下に行く
				sum ^= a[x+1][y];
				x++;
			}
		}
		mp0[P(x,sum)]++;
	}
	map<P,ll> mp1;
	for(ll i = 0; i < (1<<(n-1)); i++){
		bitset<20> bit(i);
		ll sum = a[n-1][n-1];
		ll x = n-1;
		ll y = n-1;
		rep(j,n-1){
			if(bit.test(j)){
				// 横に行く
				sum ^= a[x][y-1];
				y--;
			} else {
				// ueに行く
				sum ^= a[x-1][y];
				x--;
			}
		}
		sum ^= a[x][y];
		mp1[P(x,sum)]++;
	}
	ll ans = 0;
	for(auto x:mp0){
		ll col = x.first.first;
		ll val = x.first.second;
		ll mul = x.second;
		mul *= mp1[P(col,val)];
		ans += mul;
	}
	cout << ans << endl;
}
