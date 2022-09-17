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
	int n,q ;
	scanf("%d%d", &n,&q);
	vector<int> p(n+1);
	rep(i,n-1){
		int parent;
		scanf("%d",&parent);
		p[i+2] = parent;
		to[parent].push_back(i+2);
	}
	p[1] = -1; // root
	vector<bool> pushed(n+20,false);
	while(q--){
		int m;
		cin >> m;
		vector<int> omote(m);
		rep(i,m){
			int x;
			scanf("%d",&x);
			omote[i]=x;
		}
		int ans = 0;
		rep(i,m){
			int now = omote[i];
			ans += 1 + to[now].size();
			pushed[now] = true;
			if(p[now]==-1) continue;
			if(pushed[p[now]]) ans-=2;
		}
		rep(i,m){
			pushed[omote[i]] = false;
		}
		printf("%d\n",ans);
	}
}
