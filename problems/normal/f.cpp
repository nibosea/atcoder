// touristのパクリ
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
void tourist(){
	int n;
	cin >> n;
	vector<int> order(1<<n);
	vector<int> c(1<<n);
	For(i,1,1<<n) cin >> c[i];
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int i, int j){
		return c[i] < c[j];
	});
	vector<int> basis(n);
	ll ans = 0;
	for (int x : order){

		int mask  = x;
		rep(i,n){
			if(mask&(1<<i)){
				if(basis[i] == 0){
					basis[i] = mask;
					break;
				}
			mask ^= basis[i];
			}
		}
		if(mask != 0) {
			ans += c[x];
			}
	}
	cout << ans << endl;
}
int main()
{
	tourist();
}
