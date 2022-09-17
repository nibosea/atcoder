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
	string t;
	cin >> t;
	vector<bool> s(11,false);
	For(i,1,11){
		if(t[i-1] == '1') s[i] = true;
	}
	bool one = true;
	if(s[1] == 1) one = false;
	if(!one){
		coN();
		return 0;
	}
	// 7 / 4 / 2 / 1 / 3 / 6 / 10 
	bool f = false;
	if(s[8]) s[2] = 1;
	if(s[9]) s[3] = 1;
	if(s[5]) s[1] = 1;
	if(s[7]){
		if(s[4]){
			// No;
		} else {
			if(s[2] || s[1] || s[3] || s[6] || s[10]) f = true;
		}
	}
	if(s[4]){
		if(s[2]){
			// No;
		} else {
			if(s[1] || s[3]  || s[6] || s[10]) f= true;
		}
	}
	if(s[2]){
		if(s[1]){
		}
		else {
			if(s[3] || s[6] || s[10]) f = true;
		}
	}
	if(s[1]){
		if(s[3]){
		} else {
			if(s[6] || s[10]) f=true;
		}
	}
	if(s[3]){
		if(s[6]){
		} else {
			if(s[10]) f = true;
		}
	}
	if(f){
		coY();
		return 0;
	} else {
		coN();
	}
}
