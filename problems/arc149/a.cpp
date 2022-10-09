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
bool mysort(string a, string b){
	if(a.size() > b.size()) return true;
	if(b.size() > a.size()) return false;
	if(a == b) return true;
	int A = a[0] - '0';
	int B = b[0] - '0';
	if(A>B) return true;
	else return false;
}
int main()
{
	int n, m;
	cin >> n>> m;
	vector<string> ans(0);
	bool f = false;
	For(i,1,10){
		ll num = 0;
		ll tmp = 0;
		rep(j,n){
			num *= 10;
			num += i;
			num %= m;
			if(num == 0){
				tmp = j +1;
			}
		}
		string now = "";
		char c = '0' + i;
		rep(j,tmp){
			now += c;
		}
		if(tmp != 0){
			f=true;
			ans.push_back(now);
		}
		//ans.push_back(now);
	}
	sort(ans.begin(),ans.end(),mysort);
	if(f) cout << ans[0] << endl;
	else cout << -1 << endl;

}
