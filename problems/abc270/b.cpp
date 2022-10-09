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
bool aida(int x, int y, int z){
	// x < y < z or z < y < x 
	if(x < y && y < z) return true;
	if(z < y && y < x) return true;
	else return false;
}
int main()
{
	int goal, wall, hammer;
	cin >> goal>> wall>> hammer;
	// not wall
	int start = 0;
	if( aida(start, wall, goal) ){
		// aida ni kabe gaarru
		if(aida(start,wall,hammer)){
			// wall 
			cout << -1 << endl;
		} else {
			int ans = 0;
			ans += abs(start-hammer);
			ans += abs(hammer-wall);
			ans += abs(wall-goal);
			cout << ans << endl;
		}
	} else {
		cout << abs(start-goal) << endl;
	}
}
