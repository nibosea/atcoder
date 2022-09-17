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
//Write From this Line

ll dp[200'005][2][2][2];
int main()
{
	int n, MAX, MIN;
	cin >> n>> MAX>> MIN;
	// n , max, min
	dp[0][0][0][1] = 1;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	rep(i,n){
		int num = a[i];
		// dp[i] からの遷移を行う。
		// numだけ使った場合を考える
		//ここにかけ
		int imam = 0;
		int imaM = 0;
		if(MIN <= num && num <= MAX){
			if(num == MIN) imam = 1;
			if(num == MAX) imaM = 1;
			dp[i+1][imam][imaM][0] += 1;
		}
		
		rep(mi,2){
			rep(Mi,2){
				rep(ti,2){
					// dp[i][mi][Mi][ti] からの遷移を行う。
					//　取るという選択肢があるかどうかのチェック
					bool use = true;
					if(num < MIN || num > MAX){
						use = false;
					}
					int nti = 0;
					if(!use){
						// その要素は使えないので、not_useつまり 次のtiはかならず 1にする
						nti = 1;
						dp[i+1][mi][Mi][nti] += dp[i][mi][Mi][ti];
					} else {
						// 使う方にも行けるし、使わない方にも行ける
						int nmi = mi;
						int nMi = Mi;
						if(ti == 0){
							// 取らない方への遷移も行う
							dp[i+1][nmi][nMi][1] += dp[i][mi][Mi][ti];
							// 取る場合
							if(num == MIN) nmi = 1;
							if(num == MAX) nMi = 1;
							dp[i+1][nmi][nMi][0] += dp[i][mi][Mi][ti];
						} else {
							// ti = 1のとき、取らないの方へそのまま遷移する
							dp[i+1][nmi][nMi][1] += dp[i][mi][Mi][ti];
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	rep(i,2){
		ans += dp[n][1][1][i];
	}
	cout << ans << endl;
}
