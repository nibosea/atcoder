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
	// とりあえずエラトステネス奮っとく
	// 後UnionFind
	ll n;
	cin >> n;
	vector<ll> a(n), b(n);
	rep(i,n) cin >> a[i] >> b[i];
	ll c = 2*n; 
	mf_graph<ll> g(c+2);
	ll s=c;
	ll t=c+1;
	ll MAX_N  = 2e7+100;
	vector<bool> isPrime(MAX_N,true);
	rep(i,2)isPrime[i] = false;
	for(ll i = 2; i <= MAX_N; i++){
		if(isPrime[i]){
			ll j = i + i;
			while(j <= MAX_N){
				isPrime[j] = false;
				j += i;
			}
		}
	}
	// ここまでふるい
	rep(i,n){
		g.add_edge(s,i,b[i]);
		g.add_edge(n+i,t,INF);
	}
	rep(i,n){
		For(j,i,n){
			ll sum = a[i] + a[j];
			ll left = i;
			ll right = j;
			if(isPrime[sum]){
				ll num = min(b[i],b[j]);
				if(i==j)num = b[i] / 2;
				g.add_edge(left,right,num);
			}
		}
	}
	cout << g.flow(s,t) << endl;
}
