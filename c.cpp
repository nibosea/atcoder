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
	int h, w, n;
	cin >> h >> w >> n;
	// A Bをそれぞれ座標圧縮するだけ
	vector<int> A(n), B(n);
	rep(i,n){
		cin >> A[i] >> B[i];
	}
	vector<int> AA = A, BB = B;
	auto leftunique = [&](vector<int> x){
		sort(x.begin(),x.end());
		x.erase(unique(x.begin(),x.end()),x.end());
		return x;
	};
	AA = leftunique(AA), BB = leftunique(BB);
	for(int i = 0; i < n; i++){
		int ans = lower_bound(AA.begin(), AA.end(), A[i]) - AA.begin();
		int ans2 = lower_bound(BB.begin(), BB.end(), B[i]) - BB.begin();
		++ans, ++ans2;
		cout << ans << " " << ans2 << endl;
	}
}
