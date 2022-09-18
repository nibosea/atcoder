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
const ll inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	ll n;
	cin >> n;
	vector<ll> x(n);
	rep(i,n) cin >> x[i];
	vector<ll> c(n);
	rep(i,n) cin >> c[i];
	vector<bool> hated(n, false);
	rep(i,n){
		x[i]--;
		hated[x[i]] = true;
	}
	// hated[i] = falseの人は考慮しない
	// ある閉路について、最小の数値のみを考慮すればいい
	vector<bool> used(n,false);
	queue<ll> q;
	ll ans = 0;
	rep(i,n){
		if(used[i])continue;
		if(!hated[i]){
			// そいつが嫌われていないなら、絶対閉路にならない
			used[i] = true;
			continue;
		}
		q.push(i);
		ll M = inf;
		bool roop = true;
		bool troop =false;
		// iが閉路に含まれているかをチェックする
		int v = i;
		int nv;
		while(v!=i){
			chmin(M,c[v]);
			v = x[v];
			if(v==i){
				break;
			}
			if(used[v]) {
				roop = false;
				nv = v;
				troop=true;
			}
			used[v] = true;
		}
		if(roop){
			// i が roopに含まれている
			// iから始まるやつをused true。
			ans += M;
		} else {
			// iからはループが始まらないので、used を falseに戻したい
			if(troop){
				// i以外のnvはループになる
				// i->...->nvをfalse
				// nv から で最小を足す
				v = i;
				while(v != nv){
					v = x[v];
					used[v] = false;
				}
				M = inf;
				int nnv = nv;
				while(nv != nnv){
					chmin(M,c[nv]);
					nv = x[nv];
				}
				used[nnv] = true;
				ans += M;
			} else {
				// 全部trueでいい
			}
		}
		if(roop){
			puts("ropp");
		}
		if(troop){
			puts("troop");
		}
		used[i] = true;
		//debug(M);
	}
	cout << ans << endl;
}
