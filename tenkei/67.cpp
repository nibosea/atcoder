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
ll octet_to_ten(string s){
	// 下の桁から足して行けば良い
	ll x = 1;
	ll ret = 0;
	for(int i = s.size() - 1 ; i >= 0 ; i--){
		ret += x * int(s[i]-'0');
		x *= 8;
	}
	return ret;
}

string ten_to_nine(ll n){
	string ret = "";
	if(n==0) return "0";
	while(n>0){
		ll num = n % 9;
		ret = char('0'+num) + ret;
		n/=9;
	}
	return ret;
}
int main()
{
	string n;
	cin >> n;
	ll k; 
	cin >> k; 
	while(k--){
		ll N = octet_to_ten(n);
		string next = ten_to_nine(N);
		n = next;
		rep(i,n.size()) n[i] -= 3*(n[i]=='8');
			
	}
	cout << n << endl;
}
