// すぬけコードマネマネ
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
	int n , m; cin >> n >> m;
	vector<P> cho(n);
	vector<P> hako(m);
	rep(i,n) cin >> cho[i].first;
	rep(i,n) cin >> cho[i].second;
	rep(i,m) cin >> hako[i].first;
	rep(i,m) cin >> hako[i].second;
	
	SORT(cho);
	REV(cho);
	SORT(hako);
	REV(hako);

	int qi = 0;
	multiset<int> s;
	rep(i,n){
		auto [x,y] = cho[i];
		while(qi < m && hako[qi].first >= x){
			s.insert(hako[qi].second);
			qi++;
		}
		auto it = s.lower_bound(y);
		if (it == s.end()){
			coN();
			return 0;
		}
		s.erase(it);
	}
	coY();
}
