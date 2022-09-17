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
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int g_keta(int x){
	int ret = 0;
	while(x != 0){
		ret ++;
		x/=10;
	}
	return ret;
}
int g_ten(int x){
	int ret = 1;
	while(g_keta(ret) < g_keta(x)){
		ret *= 10;
	}
	return ret;
}
int g_kakusi(int x){
	string s = to_string(x);
	s = s.substr(1);

	//if(s[0] == '0'){
	//	s[0] = '1';
	//	For(i,1,s.size()){
	//		s[i] = '0';
	//	}
	//}
	int ret = stoi(s);
	ret++;
	return ret;
}
int g_saki(int x){
	string s = to_string(x);
	s = s[0];
	return stoi(s);
}
void solve(){
	int l, r;
	cin >> l>> r;	
	int r_keta = g_keta(r);
	int l_keta = g_keta(l);
	if(r_keta == l_keta){
		cout << r - l + 1 << endl;
		return ;
	}
	int ten = g_ten(r);
	// rと同じ桁数の100....
	int ans = 0;
	// ten から r までを取得する

	ans += (r - ten + 1);
	int kakusi = g_kakusi(r);
	if(kakusi < l) kakusi = l;


	if(g_saki(r) == 1){ 
		ans += (ten - kakusi);
	}
	cout << ans << endl;
	return ;
}
int main()
{
	int t;	
	cin >> t;	
	while(t--){
		solve();
		//cout << "二度とやらんわこんなクソゲー";
	}
}
