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
	int n, q;
	cin >> n>> q;
	map<int, int> mp; // i番目にある数字
	map<int, int> mp2; //iがある位置
	rep(i,n){
		mp[i+1] = i + 1;
		mp2[i+1] = i + 1;
	}
	vector<int> a(q);
	rep(i,q) cin >> a[i];
	rep(i,q){
		int x = a[i];
		// xの位置
		int iti_x = mp2[x];
		int iti_nx = iti_x + 1;
		if(iti_nx == n + 1) iti_nx = n - 1;
		int nx = mp[iti_nx];
		mp[iti_x] = nx;
		mp[iti_nx] = x;
		mp2[x] = iti_nx;
		mp2[nx] = iti_x;
	}
	rep(i,n){
		cout << mp[i+1] << " ";
	}
	cout << endl;
}

