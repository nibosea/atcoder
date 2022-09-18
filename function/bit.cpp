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
/*Write under this comment
	自由記述欄
	https://scrapbox.io/pocala-kyopro/%E8%BB%A2%E5%80%92%E6%95%B0
	これわかりやすい
*/ 

struct BIT{
	private:
		vector<int> bit;
		int N;
	public:
	BIT(int size) {
		N =size;
		bit.resize(N+1);
	}
	// 一点更新
	void add(int a, int w){
		for(int x = a; x <= N; x += x & - x){
			bit[x] += w;
		}
	}
	// 1~Nまでの和
	int sum(int a){
		int ret = 0;
		for(int x = a; x > 0; x-= x & -x)ret += bit[x];
		return ret;
	}
};
int main()
{
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];
	ll ans = 0;
	BIT b(n); // 
	rep(i,n){
		ans += i - b.sum(v[i]); // BITの総和-自分んより左側=自分より右側
		b.add(v[i],1);
	}
	cout << ans << endl;
}
