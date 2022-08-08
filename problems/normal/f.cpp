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

const int dy[] = {0,1,-1,0};
const int dx[] = {1,0,0,-1};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	int n;
	cin >> n;
	vector<string> S(n);
	rep(i,n) cin >> S[i];
	mf_graph<int> g(n*n+2);
	int s = n*n;
	int t = s+1;
	rep(i,n){
		rep(j,n){
			if((i+j)%2){
				if(S[i][j] == 'B') S[i][j] = 'W';
				else if(S[i][j] == 'W') S[i][j] = 'B';
			}
			if(S[i][j] == 'B'){
				g.add_edge(i*n+j,t,inf);
			}
			if(S[i][j] == 'W'){
				g.add_edge(s,i*n+j,inf);
			}
			rep(k,4){
				int nx = i + dx[k];
				int ny = j + dy[k];
				if(nx < 0 || ny < 0|| nx >= n || ny >= n)continue;
				g.add_edge(i*n+j,nx*n+ny,1);
			}
		}
	}

	cout << (n-1)*n + (n-1) * n - g.flow(s,t) << endl;
}
