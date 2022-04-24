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
	int n, a, b, c, d, e, f, x;
	cin >> a>> b>> c>> d>> e>> f>> x;
	int sum = 0;
	ll T = 0;
	ll Ao = 0;
	int cnt = 0;
	while(sum < x){
		sum++;
		if(cnt < a) T += b;
		cnt++;
		if(cnt >= a + c) cnt = 0;
	}
	cnt = 0;
	sum = 0;
	while(sum < x){
		sum++;
		if(cnt < d) Ao += e;
		cnt++;
		if(cnt >= d + f) cnt = 0;
	}
	if(T > Ao){
		coT();
	} else if(T == Ao){
		puts("Draw");
	} else coA();
}
