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
	vector<int> p(2*n);
	rep(i,2*n) cin >> p[i];
	vector<int> ans(0);
	rep(i,n){
		int num = p[2*i];
		int num2 = p[2*i+1];
		if(num > num2){
			ans.push_back(2*i+1);
			swap(p[2*i],p[2*i+1]);
		}
	}
	for(int i = 1; i < 2*n; i+=2){
		if(p[i] < p[i+1]){
			ans.push_back(i+1);
		}
	}
	cout << ans.size() << endl;
	for(auto x: ans){
		cout << x << " ";
	}
	cout << endl;
}
