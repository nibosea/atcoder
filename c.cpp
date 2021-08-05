#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
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
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int n, m;	
	cin >> n >> m;	
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	vector<int> b(m);
	rep(i,m) cin >> b[i];
	SORT(a), SORT(b);

	int ans = inf;
	rep(i,n){
		// a[i]に対して，a[i]以上となる最小のjを見つける
		int ng = -1, ok = m - 1;
		while(ok - ng > 1) {
			int mid = (ok + ng) / 2;
			if(b[mid] >= a[i]) ok = mid;
			else ng = mid;
		}
		chmin(ans, abs(a[i]-b[ok]));
		if(ok > 0) chmin(ans,abs(a[i]-b[ok-1]));
	}
	cout << ans << endl;
}
