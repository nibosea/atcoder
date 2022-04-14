// SCC 今日連結成分分解　よくわからない E8の写経。
// 連結成分ごと二分回出来るらしい
#include <bits/stdc++.h>

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
int N, M;
int A[1 << 18], B[1 << 18];

// Graph
bool used[1 << 18];
vector<int> G[1 << 18];
vector<int> H[1 << 18];
vector<int> I;
long long cnts = 0;
void dfs(int pos){
	used[pos] = true;
	for (int i:G[pos]){
		if(!used[i])dfs(i);
	}
	I.push_back(pos);
}

void dfs2(int pos){
	used[pos]=true;
	cnts++;
	for(int i : H[pos]){
		if(used[i]==false)dfs2(i);
	}
}
int main()
{
	cin >> N >> M;
	For(i,1,M+1){
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		H[B[i]].push_back(A[i]);
	}

	For(i,1,N+1){
		if(used[i] == false) dfs(i);
	}

	ll ans = 0;
	REV(I);
	For(i,1,N+1) used[i] = false;
	for(int i : I){
		if(used[i]) continue;
		cnts = 0;
		dfs2(i);
		ans += (cnts *(cnts-1LL))/2LL;
	}
	cout << ans << endl;
}
