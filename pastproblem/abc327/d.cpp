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
/*Write Under this comment
  ☆ 自☆ 由☆ 記☆ 述☆ 欄☆
*/
int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  vector<int> b(m);
  rep(i,m) cin >> a[i];
  rep(i,m) cin >> b[i];

  vector<int> col(n+1,-1);
  map<int,bool> mp;
  rep(i,m){
    int x = a[i];
    int y = b[i];
    --x; --y;
    to[x].push_back(y);
    to[y].push_back(x);
  }

  rep(i,n){
    if(mp[i])continue;
    queue<int> q;
    col[i] = 0;
    q.push(i);
    while(!q.empty()){
      int v = q.front();
      int now = col[v];
      q.pop();
      for(auto nv: to[v]){
        if(mp[nv]){
          // すでに到達済み頂点だったら、色の検査だけ行う
          int ncol = col[nv];
          if(now == ncol){
            coN();
            return 0;
          } else {
            continue;
          }
        }
        // 未到達の場合
        mp[nv] = true;
        // 色もまだ決まっていないはずなので、違う色にする
        col[nv] = 1-now;
        q.push(nv);
      }
    }
  }
  coY();
}