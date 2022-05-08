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

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Line
ll dp[3005][3005][2];
int main()
{
	ll n, p;
	cin >> n >> p;
	/* dp[i][j][con] := i 列目まで見たときに
		 									j 辺削除していて
											i 列目の上下がなんらかの経路で繋がっているか(connectか)
											最終的な答えは，dp[n][J(1<=n-1)][con]
	*/ 
	dp[0][0][0] = 1;
	dp[1][0][1] = 1;
	dp[1][1][0] = 1;
	for(int i = 1; i < n; i++){
		// i+1列目を決める( i-1列　と　i列の間の辺と，i列の縦の辺をどうするかを考える
		// 配るDPで考えたい
		for(int j = 0; j <= n - 1; j++){
			// j辺削除している状態からの遷移
			for(int con = 0; con <= 1; con++){
				if(con == 0){
					// i列目の上下が繋がっていない場合
					// 2辺削除することは出来ない。どのように２本削除しても，その後一生連結でなくなる
					// 1辺削除する場合
						/*	縦の辺を１本削除
									not conへの遷移となる
								横の１本をどっちか消す場合
									i+1がconへの遷移となりそうだが，
									実はこの場合，連結にはならないので１本だけ消してconにすることは無理。
									よって，０本削除でconへの遷移がうまれる
						 */
					//not con
					dp[i+1][j+1][0] += dp[i][j][0];
					dp[i+1][j+1][0] %= p;
					// con
					dp[i+1][j][1] += dp[i][j][0];
					dp[i+1][j][1] %= p;
				} else {
					// conからの遷移
					// 0本削除は何も考えなくてもconっぽい感じするしconだろ
					dp[i+1][j][1] += dp[i][j][1];
					dp[i+1][j][1] %= p;
					// 1本削除どのように削除いても，conなので，どのポン消すかで３通りうまれる
					dp[i+1][j+1][1] += 3 * (dp[i][j][1]);
					dp[i+1][j+1][1] %= p;
					/* 2本削除
						 	縦と横1本を消す場合，
									not　conへの遷移となる
							横の2本を消す場合
									conではあるが，全体として今後どう頑張っても連結にならないのでむり
					 */
					// 縦と横を１本ずつ消す。どっちの横を残すかで二通り
					dp[i+1][j+2][0] += dp[i][j][1] * 2;
					dp[i+1][j+2][0] %= p;
				}
			}
		}
	}
	ll ans = 0;
	For(i,1,n){
		cout << dp[n][i][1] << endl;
	}
}
