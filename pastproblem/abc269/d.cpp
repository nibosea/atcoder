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

const ll dy[] = {-1,-1,0,0,1,1};
const ll dx[] = {-1,0,-1,1,0,1};
const ll mod = 1e9+7;
const ll MOD = 998244353;
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 9'000'000'000'000'000'000;

vector<ll> to[200'005];
//Write From this Line
bool math[2050][2050];
int main()
{
	int n;
	cin >> n;
	rep(i,n){
		int x, y;
		cin >> x>> y;
		x += 1000;
		y += 1000;
		math[x][y] = true;
	}
	ll ans = n;
	queue<P> q;
	rep(i,2001){
		rep(j,2001){
			if(math[i][j]){
				math[i][j] = false;
				q.push(P(i,j));
				while(!q.empty()){
					auto [x,y] = q.front(); q.pop();
					rep(k,6){
						int nx = x + dx[k];
						int ny = y + dy[k];
						if(nx < 0 || ny < 0) continue;
						if(math[nx][ny]){
							ans--;
							q.push(P(nx,ny));
							math[nx][ny] = false;
						}
					}
				}
			}
		}
	}
	cout << ans << endl;
}
