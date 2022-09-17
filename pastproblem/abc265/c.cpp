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
	ll h, w;
	cin >> h>> w;
	vector<string> G(h);
	rep(i,h) cin >> G[i];
	vector used(h,vector<bool> (w,false));
	int i = 0; int j = 0;
	used[i][j] = true;
	while(true){
		int ni = i;
		int nj = j;
		if(G[i][j] == 'U'){ ni -= 1; }
		if(G[i][j] == 'L') nj -= 1;
		if(G[i][j] == 'D') ni += 1;
		if(G[i][j] == 'R') nj += 1;
		if(ni < 0 || ni >= h || nj < 0 || nj >=w ){
			i++; j ++;
			cout << i << " " << j << endl;
			return 0;
		}
		if(used[ni][nj]){
			cout << -1 << endl;
			return 0;
		}
		i = ni;
		j = nj;
		used[i][j] = true;
	}
}
