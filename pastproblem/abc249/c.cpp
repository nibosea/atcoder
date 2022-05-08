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
	int n, k;
	cin >> n>> k;
	vector<string> S(n);
	rep(i,n) cin >> S[i];
	// k個だけ選ぶ。
	int ans = 0;
	for(int tmp = 0; tmp < (1<<n); tmp++){
		bitset<15> bit(tmp);


		vector<int> cnt(26,0);
		rep(j,n){
			if(bit.test(j)){

				string nn = S[j];
				rep(k,nn.size()){
					char c = S[j][k];
					int CC = c - 'a';
					cnt[CC]++;
				}
			}
		}
		int now = 0;
		rep(j,26) now += (cnt[j] == k);
		chmax(ans,now);
	}
	cout << ans << endl;
}
