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
	int n;
	cin >> n;
	vector<P> p(n);
	rep(i,n) cin >> p[i].first >> p[i].second;
	double ans = 0;
	rep(i,n){
		auto [cx, cy] = p[i];
		// 中心となる点
		vector<double> args(0);
		rep(j,n){
			if(i==j)continue;
			auto [nx, ny] = p[j];
			nx -= cx;
			ny -= cy;
			double arg = atan2(ny,nx)*180 / PI;
			args.push_back(arg);

		}
		SORT(args);
		int sz = args.size();
		rep(j,sz){
			double arg = args[j];
			double find = (arg+180);
			if(find >= 360) find -= 360;
			int ind = lower_bound(args.begin(),args.end(), find) - args.begin();
			// ind-1, ind , ind + 1ぐらいをやっておけば良さそう
			ind--;
			rep(k,3){
				if(ind < 0) {
					ind++;
					continue;
				}
				if(ind >= sz) continue;
				//arg と args[ind]の角度を求める
				double arg2 = args[ind];
				double diff = abs(arg- arg2);
				double kaku = min(diff, 360-diff);
				chmax(ans,kaku);
				ind++;
			}
		}
	}
	cout << setprecision(15);
	cout << ans << endl;
}
