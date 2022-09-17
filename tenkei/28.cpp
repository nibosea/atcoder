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
	int n;
	cin >> n;
	vector a(1010,vector<int>(1010,0));
	vector b(1010,vector<int>(1010,0));
	vector c(1010,vector<int>(1010,0));
	rep(i,n){
		int x1, y1, x2, y2;
		cin >> x1>> y1>> x2>> y2;
		a[x1][y1]++;
		a[x2][y2]++;
		a[x1][y2]--;
		a[x2][y1]--;
	}
	rep(i,1000){
		rep(j,1000){
			b[i+1][j] = b[i][j] + a[i][j];
		}
	}
	rep(i,1000){
		rep(j,1000){
			c[i][j+1] = c[i][j] + a[i][j];
		}
	}
	map<int, int> mp;
	For(i,0,1010){
		For(j,0,1010){
			int num = b[i][j] + c[i][j];
			mp[num]++;
		}
	}
	For(i,1,n+1){
		printf("%d\n", mp[i]);
		//cout << mp[i] << endl;
	}
}
