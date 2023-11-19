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
  vector<vector<int>> a(9,vector<int>(9,0));
  rep(i,9)rep(j,9) cin >> a[i][j];
  rep(i,9)rep(j,9) --a[i][j];
  // 条件1
  // 行ごとに１～９が一個ずつある
  bool OK1 = true;
  rep(i,9){
    vector<bool> check(9,false);
    rep(j,9){
      check[a[i][j]] = true;
    }
    // 行を見終わった
    rep(j,9){
      if(check[j] == false) OK1 = false;
    }
  }

  // 条件2
  // 列ごとに１～９が一個ずつある
  rep(i,9){
    vector<bool> check(9,false);
    rep(j,9){
      check[a[j][i]] = true;
    }
    // 列を見終わった
    rep(j,9){
      if(check[j] == false) OK1 = false;
    }
  }

  if(!OK1){
    coN();
    return 0;
  }
  // 条件3 3x3ごとに見る

  rep(i,3){
    rep(j,3){
      int x = i*3;
      int y = j*3;
      vector<bool> check(9,false);
      rep(x1,3){
        rep(y1,3){
          int X = x + x1;
          int Y = y + y1;
          check[a[X][Y]] = true;
        }
      }
      rep(k,9){
        if(check[k] == false) OK1 = false;
      }
    }
  }
  if(!OK1){
    coN();
    return 0;
  }
  coY();
}
