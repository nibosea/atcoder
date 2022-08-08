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
const ll INF = 9'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	// sはABからなる。
	string t = s;
	REV(t);
	if(s==t){
		coY();
		return 0;
	}
	if(n==2){
		if(s[0] == s[1]){
			coY();
		} else {
			coN();
		}
		return 0;
	}
	// s[i] と　s[n-i] が異なる時、操作をしなければ行けない。
	if(s[0] == 'B' && s[n-1] == 'B'){
		coY();
		return 0;
	}
	if(s[0] == 'A' && s[n-1] == 'A'){
		coY();
		return 0;
	}
	if(s[0] == 'B' && s[n-1] == 'A'){
		coY();
		return 0;
	} else {
		coN();
		return 0;
	}

}
