#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define Per(i, a, b)    for(int i = (a) ; i>=(b);--i)
#define per(i, n)       Per(i,n,0)
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
//Write From this Line
int main()
{
	int n, q;
	cin >> n>> q;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	for(auto x: a){
		cout << x << " ";
	} cout << "\nok\n";

	int cnt = 0;
	vector<int> ans(n);
	iota(ans.begin(),ans.end(),0);
	while(q--){
		for(auto x: ans){
			cout << (x+cnt)%n << " ";
		} cout << endl;
		int t, x, y;
		cin >> t>> x>> y;
		--x, --y;
		if(t==1){
			// swap a(x), a(y);
			int indx = x + cnt;
			int indy = y + cnt;
			indx %= n;
			indy %= n;
			swap(ans[indx],ans[indy]);
		}
		else if(t==2){
			// shift
			// a[0] -> a[1];
			cnt++;
		}
		else {
			// out
			debug(x);
			int neko = (x-cnt);
			if(x<0) neko += n;
			int ind = ans[neko];
			ind %= n;
			debug(ind);
			cout << a[ind] << endl;
		}
	}
}
