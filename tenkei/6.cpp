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
int main()
{
/* 26個、配列の要素がNのものを用意する。
1個目の配列は、a[1~N]で、i番目より後に出てくるaの位置。みたいな感じで作る。
26＊10^5でこの配列は作れるので、いけそう
*/
	int n, k;
	cin >> n>> k;
	string s;
	cin >> s;
	vector next_app(26, vector<int>(n+1,-1));
	for(int i = n-1; i >= 0; i--){
		int c = s[i] - 'a';
		rep(j,26){
			// next_app[j][i] := jがi番目を含めて以降に初めて出てくる位置を格納する
			if(c == j){
				// i番目に+1する
				next_app[j][i] = i;
			} else {
				next_app[j][i] = next_app[j][i+1];
			}
		}
	}

	string ans = "";
	int left = k;
	rep(i,n){
		rep(j,26){
			if(left==0) break;
			// 一番最初に見つけたものを採用する
			if(next_app[j][i] == -1) continue;
			// next番目に飛んだら文字数足りなくなるかもしれない
			int next = next_app[j][i];
			// next番目に飛んだ場合の残りの文字数を考える
			int nokori = n - next ;
			if(nokori < left) continue; 
			// 選んで良い場合
			ans += char(j+'a');
			left--;
			i = next ;
			break;
		}
	}
	cout << ans;
	cout << endl;
}
