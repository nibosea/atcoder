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
bool mySort(P x, P y){
	if(x.first == y.first){
		x.second > y.second;
	}
	if(x.second == y.second){
		return x.first < y.first;
	}
	return x.first < y.first;
}
bool cover(P x, P y){
	int l1 = x.first, l2 = y.first;
	int r1 = x.second, r2 = y.second;
	if(l2 <= l1){
		if(r2 >= l1) return true;
		else return false;
	} else if(l2 <= r1){

		return true;
	} else {
		return false;
	}
}
int main()
{
	int n;
	cin >> n;
	vector<P> lr(n);
	rep(i,n) cin >> lr[i].first >> lr[i].second;
	sort(lr.begin(), lr.end(), mySort);
	int L = lr[0].first;
	int R = lr[0].second;
	For(i,1,n){
		P p = P(L,R);
		if(cover(p, lr[i])){
			if(L > lr[i].first) L = lr[i].first;
			if(R < lr[i].second) R = lr[i].second;
		}
		else {
			cout << L << " " << R << endl;
			L = lr[i].first;
			R = lr[i].second;
		}
	}
	cout << L << " " << R << endl;
}
