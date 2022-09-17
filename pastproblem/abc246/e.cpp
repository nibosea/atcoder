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

const int dy[] = {1,-1,-1,+1};
const int dx[] = {1,-1,+1,-1};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Line
bool inField(int x, int y, int X, int Y){
	if(x < 0 || y < 0 || x >= X || y >= Y) return false;
	return true;
}
int main()
{
	int n;
	cin >> n;
	ll sx, sy;
	cin >> sx>> sy;
	ll gx, gy;
	cin >> gx>> gy;
	sx--; sy--; gx--;gy--;
	vector<string> field(n);
	rep(i,n) cin >> field[i];
	if( (sx+sy)%2 != (gx+gy)%2){
		cout << -1 << endl;
		return 0;
	}
	vector dp(n,vector<ll> (n,inf));
	map<P,bool> usin;
	dp[sx][sy] = 0;
	usin[P(sx,sy)] = true;
	queue<P> q;
	q.push(P(sx,sy));
	while(!q.empty()){
		auto [x,y] = q.front();
		usin[P(x,y)] = true;
		ll cost = dp[x][y] + 1;
		q.pop();
		rep(i,4){
			int nx = x;
			int ny = y;
			while(true){
				nx +=dx[i];
				ny +=dy[i];
				if(!inField(nx,ny,n,n)) break;
				if(field[nx][ny] == '#') break;
				if(usin[P(nx,ny)]) break;
				if(chmin(dp[nx][ny],cost)){
					q.push(P(nx,ny));
					if(nx == gx && ny == gy){
						cout << cost << endl;
						return 0;
					}
				} 	
				if(dp[nx][ny] <= dp[x][y]) break;
			}
		}
	}
	if(dp[gx][gy] == inf){
		cout << -1 << endl;
		return 0;
	}
	cout << dp[gx][gy] << endl;
}
