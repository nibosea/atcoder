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
const int dY[] = {-1,-1,-1,0,0,1,1,1};
const int dX[] = {-1,0,1,-1,1,-1,0,1};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i,n) cin >> a[i];
	// n-1回の移動でとなるようにする
	ll ans = 0;
	rep(i,n){
		rep(j,n){
			rep(k,8){
				// 移動する方向はdX[k], dY[k]
				string tmp = "";
				tmp.push_back(a[i][j]);
				int nx=i;
				int ny=j;
				rep(l,n-1){
					 nx +=  dX[k];
					 ny +=  dY[k];
					if(nx<0)nx+=n;
					if(ny<0)ny+=n;
					nx %= n;
					ny %= n;

					tmp.push_back(a[nx][ny]);
				}
				ll TMP = stoll(tmp);
				chmax(ans,TMP);
			}
		}
	}
	cout << ans << endl;
}
