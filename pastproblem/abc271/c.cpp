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
int main()
{
	int n;
	cin >> n;
	priority_queue<int> pq;
	map<int, int> mp;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	rep(i,n){
		pq.push(a[i]);
		mp[a[i]]++;
	}
	For(i,1,n+1){
		while(mp[a[i]] > 1){
			pq.push(inf);
			mp[inf]++;
			mp[a[i]]--;
		}
	}
	// 読み始める前に行う
	For(i,1,n+1){
		if(!mp[i]){
			// 手元にないなら、読みたい
			int cnt = 0;
			while(!pq.empty()){
				if(cnt == 2) break;
				int num = pq.top(); pq.pop();
				if(mp[num]){
					cnt++;
					mp[num]--;
				}
			}
			if(cnt == 2){
				mp[i] = 0;
			} else {
				cout << i-1 << endl;
				return 0;
			}
		} else {
			// 手元にあるが、たくさんあるというとき
			while(mp[i] > 1){
				pq.push(inf);
				mp[inf]++;
				mp[i]--;
			}
			mp[i] = 0;
		}
	}
	cout << n << endl;
}
