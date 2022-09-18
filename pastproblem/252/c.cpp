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
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i,n) cin >> s[i];
	// 各秒数に対して、リールを一つしか選択することが出来ない。
	// 同じ番目にあった場合、10秒待つ必要がある。
	int ans = inf;
	rep(i,10){
		// iで揃える
		vector<int> cnt(10,0);
		rep(j,n){
			string t = s[j];
			rep(k,10){
				int num = t[k] - '0';
				if(num == i){
					cnt[k]++;
				}
			}
		}
		int tmp = 0;
		rep(j,10){
			int neko = (cnt[j] - 1) * 10 + j;
			tmp = max(tmp,neko);
		}
		ans = min(tmp, ans);
	}
	cout << ans << endl;
}
