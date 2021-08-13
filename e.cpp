#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef tuple<int,ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define fore(i, a) for(auto &i: a)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
int DX[] = {-1,-1,-1,0,0,1,1,1};
int DY[] = {-1,0,1,-1,1,-1,0,1};
//Write From this Line
int main()
{
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i,h){
		cin >> s[i];
	}
	priority_queue<P,vector<P>,greater<P>> q;
	q.push(P(0,0,0));
	vector<vector<int>> cnt(h,vector<int>(w,inf));
	cnt[0][0] = 0;
	while(!q.empty()){
		int cost,vx, vy;
		tie(cost,vx,vy) = q.top(); q.pop();
		if(vx == h-1 && vy == w-1){
			cout << cost << endl;
			return 0;
		}
		rep(i,4){
			int nx = vx + dx[i];
			int ny = vy + dy[i];
			if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if(s[nx][ny] == '#'){
				//壊す -> そのマスにcost+1で行くことができる．
				// そのマスをはじめとして，殴っとく
				if(chmin(cnt[nx][ny], cost + 1)){
					q.push(P(cost+1,nx,ny));
				}
				rep(j,8){
					int NX = nx + DX[j];
					int NY = ny + DY[j];
					if(NX >= 0 && NX < h && NY >= 0 && NY < w){
						if(chmin(cnt[NX][NY], cost + 1)){
							q.push(P(cost+1,NX,NY));
						}
					}
				}
			}
			else {
				if(chmin(cnt[nx][ny], cost)){
					q.push(P(cost,nx,ny));
				}
			}
		}
	}
}
