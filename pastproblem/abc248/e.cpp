#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
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
void coT() {cout <<"Takahashi"<<endl;}
void coA(){cout <<"Aoki"<<endl;}

void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	ll n, K;
	cin >> n>> K;
	vector<P> xy(n);
	rep(i,n){
		cin >> xy[i].first >> xy[i].second;
	}
	SORT(xy);
	// 2点選ぶ
	if(K == 1){
		cout << "Infinity" << endl;
		return 0;
	}
	ll ans = 0;
	// 同じ直線を数えないように注意する
	map<tuple<ll,ll,double>, bool> mp;
	map<ll, bool> mp_x;
	map<ll, bool> mp_y;
	// y = ax + bを求める
	rep(i,n){
		For(j,i+1,n){
			// 二本のせんが通る直線を求める
			ll x1, y1, x2, y2;
			tie(x1,y1) = xy[i];
			tie(x2,y2) = xy[j];
			// 2点を通る直線
			ll dx = (x1-x2);
			ll dy = (y1-y2);
			if(dy == 0){
				// y = aのグラフ
				ll y = y1;
				ll cnt = 0;
				if(mp_y[y])continue;
				rep(k,n){
					ll x3, y3;
					tie(x3,y3) = xy[k];
					if(y == y3) cnt++;
				}
				mp_y[y]=true;
				if(cnt >= K) ans++;
				continue;
			} else if(dx == 0){
				ll x = x1;
				ll cnt = 0;
				if(mp_x[x])continue;
				rep(k,n){
					ll x3, y3;
					tie(x3,y3) = xy[k];
					if(x == x3) cnt++;
				}
				mp_x[x] = true;
				if(cnt>=K) ans++;
				continue;
			} else {
				// bは4変数で一意に決まる
				
				double b = y1 - ((dy*x1)/dx);
				// b が小数になってしまうことがありそう
				ll cnt = 0;
				if(mp[{dx,dy,b}])continue;
				if(mp[{-dx,-dy,b}])continue;
				rep(k,n){
					ll x3, y3;
					tie(x3,y3) = xy[k];
					ll le = dx*y3;
					ll ri = (dy*x3) + (dx*b);
					if(le == ri) cnt++;
				}
				if(cnt>=K) ans++;
				mp[{dx,dy,b}]=true;
				mp[{-dx,-dy,b}]=true;
				continue;
			}
		}
	}
	cout << ans << endl;
}
