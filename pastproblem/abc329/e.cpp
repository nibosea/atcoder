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
  string s, t;
  cin >> s >> t; 
  map<char,int> mp; // 文字cがTの何番目にあるか
  rep(i,m){
    if(mp[t[i]] !=0)continue;
    mp[t[i]] = i + 1;
  }
  // X:N文字の'#'
  // 連続するM文字をTで置き換える。
  // x を sに一致させることが出来るか。
  if (s == t) {
    coY();
    return 0;
  }
  vector<int> ss(0);
  // 左から作っていく。
  string X = "";
  rep(i,n) X += '#';
  rep(i,n) {
    cout << X << endl;
    if (s[i] == X[i]) continue;
    int num = mp[s[i]]; // Tのnum番目に、欲しい文字がある。
    debug(num);
    // 1だったら、そのまま置けばいい
    if(num == 0) {
      coN();
      return 0;
    }
    // 2だったら、1個前から起き始める。
    // 3だったら、2個前から起き始める。 
    int start = i - num  + 1;
    ss.push_back(start);
    if(start < 0) {
      coN();
      return 0;
    }
    if (start + m - 1 >= s.size()) {
      coN();
      return 0;
    }
    for(int k = 0, j = start; j < start + m; j ++, k++){
      X[j] = t[k];
    }
  }
  // ssに入ってるやつを逆から操作すればいい。
  REV(ss);
  rep(i,ss.size()){ 
    int now = ss[i];
    rep(j,m){
      X[now+j] = t[j];
    }
  }
  if(X == s) coY();
  else coN();
}
