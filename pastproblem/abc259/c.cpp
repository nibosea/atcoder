#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
typedef pair<int,int> P;
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
	string s,t ;
	cin >> s>>t ;
	int n = s.size();
	int m = t.size();
	vector<pair<char,int>> a(0);
	vector<pair<char,int>> b(0);
	char c;
	int cnt = 0;
	rep(i,n){
		if(i == 0){
			c = s[i];
			cnt = 1;
		} else {
			if(c == s[i]){
				cnt++;
				if(i == n-1){
					a.push_back({c,cnt});
					c = s[i];
					cnt = 1;
				}
			} 
			else {
				// 異なるなら集計
				a.push_back({c,cnt});
				c = s[i];
				cnt = 1;
				if(i == n-1){
					a.push_back({c,cnt});
					c = s[i];
					cnt = 1;
				}
			}
		}
	}
	cnt = 0;
	rep(i,m){
		if(i == 0){
			c = t[i];
			cnt = 1;
		} else {
			if(c == t[i]){
				cnt++;
				if(i == m-1){
					b.push_back({c,cnt});
					c = t[i];
					cnt = 1;
				}
			} 
			else {
				// 異なるなら集計
				b.push_back({c,cnt});
				c = t[i];
				cnt = 1;
				if(i == m-1){
					b.push_back({c,cnt});
					c = t[i];
					cnt = 1;
				}
			}
		}
	}
	//for(auto [x,y]:a){
	//	cout << x << "," << y << "/";
	//}
	//cout << endl;
	//for(auto [x,y]:b){
	//	cout << x << "," << y << "/";
	//}
	//cout << endl;
	if(a.size() != b.size()){
		coN();
		return 0;
	}
	else {
		rep(i,a.size()){
			if(a[i].first != b[i].first){
				coN();
				return 0;
			} else {
				int num = a[i].second;
				int num2 = b[i].second;
				if(num == 1){
					if(num2 >= 2){
						coN();
						return 0;
					}
				} else {
					if(num > num2){
						coN();
						return 0;
					}
				}
			}
		}
	}
	coY();
}
