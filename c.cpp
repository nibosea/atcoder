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
	int t;
	cin >> t;
	vector<string> S(t);
	rep(i,t) cin >> S[i];
	rep(oppai,t){
		string s = S[oppai];
		int n = s.size();
		vector<int> a(n);
		rep(i,n){
			a[i] = (s[i] - '0');
			if(a[i] == 0){
				a[i] = 10;
				a[i-1]--;
			}
		}
		while(true){
			// a[i]/3 <= a[i+1]3 ... ってないとダメ
			int tmp = 0;
			int saidai = inf;
			int saisyou = -1;
			rep(i,n){
				int necc = (a[i]+2) / 3;
				if(necc > saidai) {
					// 必要回数が多すぎる
					a[i]--;
					a[i+1]+=10;
					tmp = -1;
					break;
				} else {
					chmin(saisyou,necc);
				}
			}
			if(tmp != -1) break;
		}
		int M = 0;
		rep(i,n){
			chmax(M,a[i]);
		}
		cout << (M + 2) / 3 << endl;
	}
}
