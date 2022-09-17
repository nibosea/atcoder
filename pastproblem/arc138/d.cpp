// 参考, XORの基底作りたいときこれパクれば良いっぽい　https://note.com/syamashi/n/n6259f445e307 syamashiさん
// 解法の正当性　こいくちさん　https://koikuchi3.hatenablog.com/entry/2022/04/10/154856
// 写経元 kmjpさん　https://atcoder.jp/contests/arc138/submissions/30827374　
#include <bits/stdc++.h>

using namespace std;
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
#define debug(x)  cerr << #x << " = " << (x) << endl;
vector<int> to[200'005];
//Write From this Line
int main()
{
	int n, k;
	cin >> n>> k;
	if(n == 1){
		coY();
		cout << "0 1" << endl;
		return 0;
	}
	if(k%2==0||k==n){
		coN();
		return 0;
	}
	vector<int> T, cand;
	int x;
	rep(i,1<<n) if(__builtin_popcount(i) == k) {
		x = i;
		for(auto& t: T) x = min(x,t^x);
		if(x){
			T.push_back(x), cand.push_back(i);
			// candが基底
		}
	}
	coY();
	int y;
	rep(i,1<<n){
		x=i^(i>>1);
		y=0;;
		rep(j,n) if(x&(1<<j)) y^=cand[j];
		cout << y << " ";
	}
	cout << endl;
}
