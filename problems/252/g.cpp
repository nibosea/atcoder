#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = atcoder::modint1000000007;
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
mint dp_tree[505][505];
mint dp_forest[505][505];
int main()
{
	int n;
	cin >> n;
	vector<int> c(n);
	rep(i,n) cin >> c[i];
	rep(i,n) dp_tree[i][i] = 1;
	// 森を作り->木を作る
	for(int w = 0; w < n; w++){
		for(int L = 0; L < n; L++){
			int R = L + w;
			//dp_forest[L][R] = sum
			// 	dp_tree[L][R] +
			// 	dp_tree[L][i-1] * dp_forest[i][R] (C_L < C_i) Lを根とする木をiを最左とする森の左におくので、C_L < C_iが必要。
			mint sum = 0;
			for(int i = L + 1; i <= R; i++){
				if(c[L] < c[i]) sum += dp_tree[L][i-1] * dp_forest[i][R];
			}
			sum += dp_tree[L][R];
			//debug(sum.val());
			dp_forest[L][R] = sum;
			if(L){
				dp_tree[L-1][R] = dp_forest[L][R];
			}
		}
	}
	cout << dp_tree[0][n-1].val() << endl;
	rep(i,n){
		rep(j,n){
			cout << dp_tree[i][j].val() << " ";
		}
		cout << endl;
	}
	cout << "forest\n";
	rep(i,n){
		rep(j,n){
			cout << dp_forest[i][j].val() << " ";
		}
		cout << endl;
	}
}
