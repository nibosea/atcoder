#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<char,int> P;
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
int main()
{
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i,n) cin >> p[i];
	rep(i,n) p[i]--;
	ll odd_even = 0;
	int even = 0;
	int odd = 1;
	ll ans = 0;
	vector<P> ans_a(0);
	rep(i,n){
		if(i%2!=p[i]%2){
			odd_even++;
			int ind = i - 2;
			if(p[i]%2==0){
				while(ind >= odd){
					ans++;
					ans_a.push_back(P('B',ind));
					swap(p[ind],p[ind+2]);
					ind -= 2;
				}
				odd++;
			} else {
				while(ind >= even){
					ans++;
					ans_a.push_back(P('B',ind));
					swap(p[ind],p[ind+2]);
					ind -= 2;
				}
				even++;
			}
			if(p[i]%2 == 0){
				// i-2, i-4, i-6 ..., 
			} else {
			}
		}
	}
	// とりあえず、これで整理できた
	// 偶奇をそろえる
	rep(i,n){
		if(p[i]%2 != i%2){
			ans++;
			ans_a.push_back(P('A',i));
			swap(p[i],p[i+1]);
		}
	}

	// 後は愚直に、小さいほうから見つけるだけ
	rep(i,n){
		if(i!=p[i]){
			int ind = -1;
			For(j,i+1,n){
				if(p[j] == i){
					ind = j-2;
					break;
				}
			}
			while(ind >= i){
				swap(p[ind],p[ind+2]);
				ans++;
				ans_a.push_back(P('B',ind));
				ind -= 2;
			}
		}
	}

	cout << ans << endl;
	for(auto x: ans_a){
		cout << x.first << " " << x.second+1 << endl;
	}
}
