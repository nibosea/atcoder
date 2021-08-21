#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define fore(i, a) for(auto &i: a)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Line
ll dp[1005][1<<10][11]; // i文字目まで、bitがj,最後に見たのはk
int main()
{
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(n);
    rep(i,n) a[i] = (s[i] - 'A' + 1);
    dp[0][0][0] = 1;
    rep(i,n){
        // a[i] を使うことを考える。
        int num = a[i];
        rep(j,(1<<10)){
            rep(k,11){
                // dp[i][j][k] から a[i]が使えるということは、a[i]がnumであるとき、bitのnumが立っていない。
                // もしくは、k == numであれば良い。 k==0でもおｋ
                // 取らないという選択肢はいつでも取れる bitは変わらん
                dp[i+1][j][k] += dp[i][j][k];
                dp[i+1][j][k] %= MOD;
                if( (j&(1<<num-1)) == 0||num == k||k == 0){
                    //numを取るとき。
                    dp[i+1][j|(1<<(num-1))][num] += dp[i][j][k];
                    dp[i+1][j|(1<<(num-1))][num] %= MOD;
                }
            }
        }
    }
    ll ans = 0;
        rep(j,(1<<10)){
            For(k,1,11){
                ans += dp[n][j][k];
                ans %= MOD;
            }
        }
    cout << ans << endl;
}