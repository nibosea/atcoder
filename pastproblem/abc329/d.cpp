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
// 独自の比較関数を定義
struct ComparePairs {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) {
        // 第一要素が大きい順に、第一要素が同じ場合は第二要素が小さい順にソート
        if (p1.first != p2.first) {
            return p1.first < p2.first;  // 大きい順にソート
        } else {
            return p1.second > p2.second;  // 小さい順にソート
        }
    }
};

int main()
{
  int n, m;
  cin >> n >> m;
  vector<int> a(m); 
  rep(i,m) cin >> a[i];
  //得票数と、候補者番号。さらには、候補者番号は小さい順に入れる。
  // priority_queueっぽい? 
 priority_queue<pair<int, int>, vector<pair<int, int>>, ComparePairs> pq;
 vector<int> votes(n+1,0);
 rep(i,m){
  int vote = a[i];
  votes[vote] ++;
  pq.push({votes[vote], vote});
  int now = pq.top().second;
  cout << now << endl;

 }

}
