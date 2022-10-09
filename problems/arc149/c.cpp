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
int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a(n,vector<int>(n,0));
	vector<bool> is_prime(10000,true);
	is_prime[0] = false;
	is_prime[1] = false;	
	for(int i = 2; i * i < 10000; i++){
		if(is_prime[i] == false) continue;
		for(int j = i * 2; j <= 10000; j+= i){
			is_prime[j] = false;
		}
	}


	int cnt = 0;
	vector<bool> used(n*n+1, false);
	if(n%2==0){
		int cnt = 1;
		rep(i,n/2){
			rep(j,n){
				a[i][j] = cnt;
				cnt += 2;
			}
		}
		int x = n/2 -1; 
		rep(j,n){
			int cnt = 2;
			while(true){
				if(used[cnt]){
					//cout << "Used: " << cnt << endl;
					cnt += 2;
					continue;
				} else {
					int sum = a[x][j] + cnt;
					if(!is_prime[sum]){
						a[x+1][j] = cnt;
						used[cnt] = true;
						break;
					}
				}
				cnt += 2;
			}
		}
		cnt = 2;
		for(int i = n/2 +1; i < n; i++){
			rep(j,n){
				while(used[cnt]){
					cnt += 2;
				}
				a[i][j] = cnt;
				used[cnt] = true;
			}
		}
	} else {
		int cnt = 1;
		rep(i,n){
			rep(j,n){
				if(cnt > n*n) break;
				a[i][j] = cnt;
				used[cnt] = true;
				cnt += 2;
			}
		}
		int y = n/2+1;
		debug(y);
		int x = n/2;
		// saikyou no guusu wo ireru
		debug(x);
		cnt = 2;
		while(true){
			// a[x][y] decide;
			int sum1=a[x-1][y] + cnt;
			int sum2=a[x][y-1] +cnt;
			if(!is_prime[sum1] && !is_prime[sum2]){
				a[x][y] = cnt;
				used[cnt] = true;
				break;
			}
			cnt += 2;
			
		}
	}
	rep(i,n){
		rep(j,n){
			cout << a[i][j] << " ";
		} cout << endl;
	}
}
