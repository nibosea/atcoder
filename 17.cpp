#include <bits/stdc++.h>

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
	int n, m;
	cin >> n>> m;
	vector<P> p(m);
	rep(i,m){
		int x,y;
		cin >> x>>y;
		--x, --y;
		p[i] = P(x,y);
	}
	vector<int> va_L(n,0); // va_L[i]:= 点iにLがある辺の個数
	vector<int> va_R(n,0); // va_R[i]:= 点iにRがある辺の個数
	vector<int> vb_L(n+1,0); // vb_L[i]:= 点iまで[0,i)にLがある辺の個数の累積
	vector<int> vb_R(n+1,0); // vb_R[i]:= 点iまでにRがある辺の個数の累積　

	// va_L, va_Rを作成
	rep(i,m){
		int l,r;
		tie(l,r)= p[i];
		va_L[l]++;
		va_R[r]++;
	}
	
	// vb_L, vb_Rの作成
	rep(i,n){
		vb_L[i+1] = vb_L[i] + va_L[i];
		vb_R[i+1] = vb_R[i] + va_R[i];
	}
	rep(i,n+1){
		cout << vb_L[i] << " ";
	}
}
