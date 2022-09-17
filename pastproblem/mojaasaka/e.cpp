/*
dを素因数分解した結果の各素因数の指数は高々1であるので、一番小さい素因数をx[0]とすると、
d = x[0] * x[1] * ... * x[k]と表せるが、kは高々９程度であることが示せる。
というのも、素数を小さいほうから並べると、
２，３，５，７，１１，１３，１７，１９，２３，２９となり、
これらの積は1e9より大きい。
これが最小の素因数たちのときのケースであるから、x[0]>2であるときは、もっと少ない組の素因数に分解できることが分かる。

高々９個程度の素因数に分解できることが分かったので、bit全探索を用いることができる。
*/
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
ll dp[(1<<11)];
int main()
{
	ll d;
	cin >> d;
	int n;
	cin >> n;
	vector<ll> a(n),b(n);;
	rep(i,n) cin >> a[i]>>b[i];
	vector<ll> fuctorize(0);
	for(ll i = 2; i * i <= d; i++){
		if(d%i==0){
			fuctorize.push_back(i);
			while(d%i==0){
				d/=i;
			}
		}
	}
	if(d!=1){
		fuctorize.push_back(d); // これneed
	}
	int num = fuctorize.size(); // 素因数の数

	vector<ll> mask(n,0);
	rep(i,n){
		ll tmp=0;
		rep(j,num){
			if(a[i]%fuctorize[j]==0){
				tmp += (1<<j);
			}
		}
		mask[i] = tmp;
		//`cout << bitset<11>(tmp) << endl;
	}
	// initialize
	rep(i,(1<<11)) dp[i] = INF;
	dp[0] = 0;
	// dp[1111111] no min 
	for(int i = 0; i < n; i++){
		for(int bit = 0; bit < (1<<num); bit++){
			if(dp[bit] == INF)continue;
			int next = (bit | mask[i]);
			chmin(dp[next],dp[bit]+b[i]);
		}
	}
	ll ans = (dp[(1<<num)-1]);
	if(ans == INF) cout << -1 << endl;
	else cout << ans << endl;
}

