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
#define Per(i, a, b)    for(int i = (a) ; i>=(b);--i)
#define per(i, n)       Per(i,0,n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
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
ll dp[250050][2];
int main()
{

    string s; cin >> s;
    dp[0][1] = 1; // 1 ha equal
    int n = s.size();
    rep(i,(n+1)/2){
        ll j = n - 1 - i;
        // i == j なら特別なことしなきゃいけないのかな？ 
        rep(k,26){
            char c = 'A' + k;
            if(s[i] == c){
                // equal は equal, 
                // i+1以降でequal
                // miman は miman
                dp[i+1][1] += dp[i][1];
                dp[i+1][0] += dp[i][0];
            } else if(c < s[i]) {
                // equal -> miman
                // miman -> miman
                dp[i+1][0] += dp[i][1];
                dp[i+1][0] += dp[i][0];
            }
            dp[i+1][1] %= MOD;
            dp[i+1][0] %= MOD;
        }
    }
    ll ans = 0;
    rep(i,26){
        ans += dp[(n+1)/2][0];
        ans += dp[(n+1)/2][1];
        ans %= MOD;
    }
    cout << ans << endl;
}