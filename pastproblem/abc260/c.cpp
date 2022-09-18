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
//Write From this Line
int main()
{
	ll n, x, y;
	cin >> n>> x>> y;
	// Lv nの赤い宝石を1個持っている
	vector<ll> red(11,0);
	vector<ll> blue(11,0);
	red[n] = 1;
	bool flag=true;
	while(flag){
		flag = false;
		for(int i = 10; i >= 2; i--){
			// レベルiの宝石を操作する
			if(red[i]){
				// n-1の赤1個
				ll num = red[i];
				red[i-1] += num;
				red[i] -= num;
				// x個
				blue[i] += num * x;
				flag =true;
			} 
			if(blue[i]){
				ll num = blue[i];
				// n-1の赤一個
				red[i-1] += num;
				blue[i] -= num;
				// n-1の青Y個
				blue[i-1] += num * y;
				flag = true;
			}
		}
	}
	cout << blue[1] << endl;
}
