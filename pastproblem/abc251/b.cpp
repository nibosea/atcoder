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
	ll n, w;
	cin >> n>> w;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<bool> ans(w+1,false);
	rep(i,n){
		if(a[i] <= w){
			ans[a[i]]= true;
		}
		For(j,i+1,n){
			if(a[i]+a[j] <= w){
				ans[a[i]+a[j]]= true;
			}
			For(k,j+1,n){
				ll num = a[i] + a[j] + a[k];
				if(num <= w){
					ans[num]=true;
				}
			}
		}
	}
	int lk = 0;
	rep(i,w+1){
		lk += ans[i];
	}
	cout << lk << endl;
}
