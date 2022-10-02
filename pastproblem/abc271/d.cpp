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

bool dp[105][10050][2];
int main()
{
	int n; cin >> n; int s; cin >> s; vector<int> a(n), b(n); rep(i,n) cin >> a[i] >> b[i];
	dp[0][0][0] = true;
	dp[0][0][1] = true;
	rep(i,n){
		rep(j,s){
			rep(k,2){
				if(dp[i][j][k]){
					dp[i+1][j+a[i]][0] = true;
					dp[i+1][j+b[i]][1] = true;
				}
			}
		}
	}
	bool f = false;
	rep(k,2){
		if(dp[n][s][k]){
			f=true;
		}
	}
	string ans = "";
	if(f){
		int j = n;
		while(j){
			if(dp[j][s][0]){
				ans += 'H';
				j--;
				s-= a[j];
			} else {
				ans += 'T';
				j--;
				s-= b[j];
			}
		}
		REV(ans);
		coY();
		cout << ans << endl;
	} else {
		coN();
	}
}
