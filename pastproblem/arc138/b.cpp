#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)

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
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];

	int l = 0; 
	int r = n - 1;
	bool reverse = false;
	int cnt = 0;
	while(r>=l){
		// reverseなときは、1が消える
		if(a[r] == 0 + reverse){ 
			// reverseがtrueのとき、reverseは数値の１として扱われる。 
			// reverseがfalseのとき、reverseは数値の0として扱われる。
			// a[r] == (0 + 0)
			r--;// bの操作を行う

			
		} else if(a[l] == 0 + reverse){
			l++;
			//cout << "左を消\n";
			reverse = 1 - reverse;
		}
		else {
			//cout << "操作無理\n";
			coN();
			return 0;
		}
	}
	coY();
}
