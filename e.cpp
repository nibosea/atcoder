#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
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
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n, m;
	cin >> n >> m;
	vector<P> p(m);
	rep(i,m){
		cin >> p[i].second >> p[i].first;
		if(p[i].second > n / 2){
			p[i].second = n - p[i].second;
		}
	}
	SORT(p);
	bool flag = false;
	ll ans = 0;
	ans = p[0].first * (n - 2);

	int memo = p[0].second;
	
	rep(i,m){
		if(p[i].second == 1 || (n % p[i].second != 0)){
			//cout << "ta\n";
			// ok 
			flag = true;
			ans += p[i].first;
			break;
		} 
		if(n % 2 && memo != p[i].second){
			if(memo % p[i].second != 0 && p[i].second % memo != 0){
				// 奇数なときは，違う数字ならおk
				flag = true;
				//cout << "pi\n";
				ans += p[i].first;
				break;
			}
		} 
		if(n % 2 == 0){
			// 偶数なら，memoとnowがたがいに祖ならおｋ
			// 
			int now = p[i].second;
			if(memo % p[i].second != 0 && p[i].second % memo != 0){
			//cout << "ok\n";
				flag = true;
				ans += p[i].first;
				break;
			}	
		}
	}
	if(flag == false) ans = -1;
	cout << ans << endl;
}
