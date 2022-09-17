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
vector<int> ans[204];
int main()
{
	int n;	
	cin >> n;	
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	rep(i,n){
		// 取ってない状態の0と、取った後の0を別で考えられていない
		rep(j,200){
			// あまりがjの状態からの遷移
			if(j != 0 && ans[j].size() == 0) continue;
			int sz = ans[j].size();
			if(sz >= 1){
				if(ans[j][sz-1] == i+1) continue;
			}
			// jの状態からの遷移が可能
			ll nj = j + (a[i]); nj %= 200;
			if(ans[nj].size() != 0) {
				// njへの到達が初めてじゃないなら、これが答えとして構築出来る
				coY();
				cout << ans[nj].size() << " ";
				for(auto x: ans[nj]){
					cout << x << " ";
				}
				cout << endl;
				cout << ans[j].size() + 1 << " ";
				for(auto x: ans[j]) {
					cout << x << " ";
				}
				cout << i+1 << endl;
				return 0;
			} else {
				// nj への到達が初めてなら、jの遷移にiを追加する
				ans[nj] = ans[j];
				ans[nj].push_back(i+1);
			}
		}
		int num = a[i]%200;
		if(ans[num].size() >= 2){
			// 実現可能
			coY();
			cout << 1 << " " << i + 1 << endl;
			cout << ans[num].size() << " ";
			for(auto x :ans[num]) {
				cout << x << " ";
			} cout << endl;
			return 0;

		}
	}
	coN();
}
