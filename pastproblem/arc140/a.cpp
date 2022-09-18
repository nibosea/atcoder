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
	string s;
	cin >> s;
	// tをk文字まで変えて、s[0]..s[k] == s[k+1]...s[n]となるようにし、その文字数が答え
	// というのはちょっと違う。ある繰り返しの文字列だけでSが構成されるように変形し、その文字数が答え。
	int ng = 0, ok = n;
	auto judge = [&](int x){

		// k文字まで変えて良い。
		// 長さxの文字列に分割することが出来るか
		// どの文字列にあわせるか？
		// n / x個に分割出来るはず
		if(n%x!=0) return false;
		//0..x-1文字目までで、もっとも出現回数が多いものに寄せる
		int bun = n / x; // bun個に分割出来るってことは…?

		int now = 0;
		rep(i,x){
			vector<int> cnt(26,0);
			rep(j,bun){
				// x * j + i
				char c = s[x*j+i];
				int cc = c - 'a';
				cnt[cc]++;
			}
			// i文字目を合わせるコストは、bun文字のうち
			int M = 0;
			rep(j,26) chmax(M,cnt[j]);
			now += (bun - M);
		}

		return now <= k;
	};
	for(int mid = 1; mid < n; mid++){
		if(judge(mid)){
			cout << mid << endl;
			return 0;
		}
	}
	cout << n << endl;
}
