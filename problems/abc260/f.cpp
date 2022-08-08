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
vector<int> to[400'005];
//Write From this Line
int main()
{
	ll s, t, m;
	cin >> s>> t>> m;
	rep(i,m){
		int x, y;
		cin >> x>> y;
		to[x].push_back(y);
		to[y].push_back(x);
	}
	// 2頂点を選ぶ
	rep(i,t){
		int s1 = 1 + s + i;
		// s1からBFSを2回までやる
		queue<int> q;
		vector<bool> used(400000,false);
		for(auto nv: to[s1]){
			if(used[nv]) continue;
			used[nv] = true;
			q.push(nv);
		}
		// qには距離1で行けるものが入っている
		vector<int> neko(400000, 0);
		while(!q.empty()){
			int v = q.front();
			q.pop();
			for(auto nv:to[v]){
				if(nv == s1) continue;
				if(neko[nv]){
					// s1 nv, v, neko[nv]
					cout << s1 << " " << nv << " " << v << " " << neko[nv] << endl;
					return 0;
				} else {
					// nvはs2に該当
					neko[nv] = v;
				}
			}
		}
	}
	cout << -1 << endl;
}
