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
	int n, l;
	cin >> n>> l;
	int k;
	cin >> k;
	vector<int> a(n+2);
	a[0] = 0;
	rep(i,n) cin >> a[i+1];
	a[n+1] = l;
	n+=2;
	// 一回も切らないという選択肢がある
	/*001
		K回切った時の長さがX以上にできるかの二分探索
		長さがXを超えたら切る。長さLまでの切り目を見た後に、切り目がK個以上あればスコアXは達成できる。
		Xを大きくする
	*/
	ll ng = l, ok = 0;
	while(ng-ok>1){
		ll mid = (ng+ok) / 2;
		int now = 0;
		int len = 0;
		int cut = 0;

		bool flag = true;
		rep(i,n){
			len += a[i] - now;
			now = a[i];


			if(len >= mid){
				len = 0;
				cut++;
			}
		}


		if(!flag){
			cut = 0;
			ng = mid;

		}
		if(cut > k) {
			ok = mid;

		}
		else {
			ng = mid;

		}
	}
	cout << ok << endl;
}
