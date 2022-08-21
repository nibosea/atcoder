#include <bits/stdc++.h>

using namespace std;
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
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
vector<string> s;
//Write From this Line
bool seen[1000][1000];
P mae[1000][1000];
int h, w;
void dfs(int x,int  y){
	seen[x][y] = true;
	rep(i,4){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0 || ny<0||nx>=h||ny>=w)continue;
		if(seen[nx][ny]) continue;
		if(s[nx][ny] == '#') continue;
		mae[nx][ny] = P(x,y);
		dfs(nx,ny);
	}
}
int main()
{
	cin >> h>> w;
	s.resize(h);
	rep(i,h) cin >> s[i];
	int sx, sy;
	int gx, gy;
	// set (sx,sy) (gx,gy);
	rep(i,h){
		rep(j,w){
			if(s[i][j] == 's') {
				sx = i, sy = j;
			}
			if(s[i][j] == 'g') {
				gx = i, gy = j;
			}
		}
	}
	dfs(sx,sy);
	if(seen[gx][gy]){
		coY();
		int nowy = gy;
		int nowx=  gx;
		while(nowy != sy && nowy != sx){
			printf("(%d,%d),",nowx,nowy);
			nowx = mae[nowx][nowy].first;
			nowy = mae[nowx][nowy].second;
		}
	}
	else coN();

}
