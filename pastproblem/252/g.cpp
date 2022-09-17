#include <bits/stdc++.h>
#include <atcoder/all>

using mint = atcoder::modint998244353;
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
mint dp[505][505];
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(i,n){
        dp[i][i] = 1;
        dp[i][i+1] = 1;
    }
    for(int w = 2; w <= n-1; w++){ // wの上限が分からん　範囲だから…n-1?
        for(int l = 0; l + w < n; l++){
            int r = l + w;
            // dp[l][r]]を作成する。
            // どこの直属の子にするかを全探索したい
            int cnt = 0;
            for(int p = r - 1; p >= l; p--){
                bool judge = true;
                if(p != r - 1){
                    int num = a[p+1];
                    if(num > a[r]) judge = false;
                }
                if(judge) cnt ++;
            }
            dp[l][r] += dp[l][r-1] * cnt;
        }
    }
    cout << dp[0][n-1].val() << endl;
    rep(i,n){
        rep(j,n){
            cout << dp[i][j].val() << " ";
        }
        cout << endl;
    }
}
