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
	int n, m;
	scanf("%d %d", &n, &m);
	int A, B, C, D, E, F;
	scanf("%d %d %d %d %d %d", &A, &B, &C, &D, &E, &F);
	map<P,bool> field; // syogai
	rep(i,m){
		int x, y;
		scanf("%d %d", &x, &y);
		cin >> x>> y;
		field[P(x,y)] = true;
	}
	map<P,mint> now;
	now[P(0,0)] = 1;
	int ti = clock();
	queue<P> q;
	map<int, bool> mp;
	rep(i,n){
		for(auto neko: now){
			auto [x,y] = neko.first;
			ll na = x + A;
			ll nb = y + B;
			ll nc = x + C;
			ll nd = y + D;
			ll ne = x + E;
			ll nf = y + F;
			ll cost = now[P(x,y)];
			now[P(x,y)] = 0;
			// この段階でもうnowは使わない
			if(!field[P(na,nb)]) now[P(na,nb)] += cost;
			if(!field[P(nc,nd)]) now[P(nc,nd)] += cost;
			if(!field[P(ne,nf)]) now[P(ne,nf)] += cost;
		}
		int t2 = clock();
		now = next;
		ti += clock() - t2;
	}
	mint ans = 0;
	for(auto neko: now){
		ans += neko.second;
	}
	cout << ans.val() << '\n';
	printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
}
