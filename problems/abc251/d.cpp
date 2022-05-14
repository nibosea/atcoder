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
int main()
{
	ll w;
	cin >> w;
	vector<ll> ans(310,0);
	int cnt = 0;
	int M = 0; // 2数で作れるカズの最大
	while(cnt < 300){
		if(M+1 > 1000000){
			// M+1を入れることが出来ない
			assert(false);
		}
		if(M == 0)ans[cnt++] = M + 1;
		else ans[cnt++] = M;
		M += ans[cnt-1];
		if(M > w) break;
		if(cnt >= 3) M -= ans[cnt-3];
	}
	cout << cnt << endl;
	rep(i,cnt){
		cout << ans[i] << " ";
	}
	rep(i,ans.size()){
		For(j,i,ans.size()){
		}
	}
	cout << endl;
}
