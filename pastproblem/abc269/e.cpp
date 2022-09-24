#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(ll i = (a) ; i < (b) ; ++i)
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

const ll dy[] = {0,0,1,-1};
const ll dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 9'000'000'000'000'000'000;

vector<ll> to[200'005];
//Write From this Line
int main()
{
	int n;
	cin >> n;
	int ng = 0;
	int ok = n; 
	while(ok-ng>1){
		// ２分探索
		int mid = (ng + ok) / 2;
		printf("? %d %d %d %d",1,n,ng+1,mid);
		cout << endl;
		int t;
		cin >> t;
		if(t == -1){
			return 0; // 失敗
		}
		int soutei = (mid - ng);
		if(soutei == t) ng = mid;
		else ok = mid;
	}
	int ok_i = ok;
	ng = 0;
	ok = n; 
	while(ok-ng>1){
		// ２分探索
		int mid = (ng + ok) / 2;
		printf("? %d %d %d %d",ng+1,mid,1,n);
		cout << endl;
		int t;
		cin >> t;
		if(t == -1){
			return 0; // 失敗
		}
		int soutei = (mid - ng);
		if(soutei == t) ng = mid;
		else ok = mid;
	}
	int ok_j = ok;
	printf("! %d %d",ok_j,ok_i);
	cout << endl;
}
