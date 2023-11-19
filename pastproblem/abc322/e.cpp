#include <bits/stdc++.h>

using namespace std;
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
ll dp[105][4000];
int main()
{
  int n, k, p;
  cin>>n>>k>>p;
  vector<vector<int>> a(n,vector<int>(k, 0));
  vector<int> c(n);
  rep(i,n){
    cin >> c[i];
    rep(j,k){
      cin >>  a[i][j];
    }
  }

  rep(i,100)rep(j,4000) dp[i][j] = -1;
  dp[0][0] = 0;
  ll m = pow(p,k);
  rep(i,n){
    rep(j,m){
      if(dp[i][j] == -1) continue;
      rep(x, k){
        // x個目のパラメータ
        rep(x1, )
      }

    }


  }





}
