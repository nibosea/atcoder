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
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	vector<int> h(3);
	rep(i,3) cin >> h[i];
	vector<int> w(3);
	rep(i,3) cin >> w[i];

	// 全探索
	vector<vector<int>> hw(3,vector<int>(3,0));
	// まず h(3)が行ごとの結果を表しているので、行から考える
	// 2行くらい決めたら残りは確定するんじゃね？ って考えたら、4マスの全探索だから、　３０＾４
	ll ans = 0;
	for(int h0 = 1; h0 <= h[0]-2; h0++){
		hw[0][0] = h0;
		for(int h1 = 1; h0 + h1 < h[0]; h1++){
			hw[0][1] = h1;
			hw[0][2] = h[0] - (h0+h1);
			//もう一行同じことする
			for(int ha0 = 1; ha0 <= h[1]-2; ha0++){
				hw[1][0] = ha0;
				for(int ha1 = 1; ha0 + ha1 < h[1]; ha1++){
					hw[1][1] = ha1;
					hw[1][2] = h[1] - (ha0+ha1);
					int x = w[0] - hw[0][0] - hw[1][0];
					int y = w[1] - hw[0][1] - hw[1][1];
					int z = w[2] - hw[0][2] - hw[1][2];
					hw[2][0] = x;
					hw[2][1] = y;
					hw[2][2] = z;
					if(x+y+z != h[2]) continue;
					if(x>=1&&y>=1&&z>=1){
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}
