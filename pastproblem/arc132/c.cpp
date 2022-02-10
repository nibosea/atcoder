#include <bits/stdc++.h>

using namespace std;
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
ll dp[1000][15];
int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> p(n);
    int cnt = 0;
    map<int, bool> mp;
    rep(i,n){
        if(a[i] == -1){
            cnt++;
        } else {
            mp[a[i]] = true; //使用済み
        }
        p[i] = a[i];
    }
    dp[0][d] = 1;
    rep(i,n){
        //debug(i);
        if(a[i] != -1){
            int now = a[i] - i - 1;
            int ind = d + now;
            //debug(ind);
            // dp[i]を全部足す
            ll sum = 0;
            rep(j,15){
                sum += dp[i][j];
                sum %= MOD;
            }
            dp[i+1][ind] = sum;
        }
        else {
            int numl = i + 1 - d;
            numl = max(1,numl);
            int numr = i + 1 + d;
            numr = min(n,numr);
            ll sum = 0;
            rep(j,15){
                sum += dp[i][j];
                sum %= MOD;
            }
            //printf("l = %d, r = %d\n", numl, numr);
            for(int j = numl; j <= numr; j++){
                if(mp[j]) continue;
                // jが使われていない時, 添え字は？
                int diff = i + 1 - j;
                int ind = d - diff;
                // dp[i+1][ind] = dp[i]の合計-...
                ll minus = 0;
                // ind を1あげる、i+1をi,i-1へする
                int kind = ind + 1;
                int ki = i;
                while(kind < 15 && ki >= 0){
                    minus += dp[ki][kind];
                    minus %= MOD;
                    kind++;
                    ki--;
                }
                ll mew = sum - minus;
                if(mew < 0) mew += MOD;
                dp[i+1][ind] = mew;
            }
        }
    }
    rep(i,n+1){
        rep(j,15){
            //cout << dp[i][j] << ", ";
        }
        //cout << endl;
    }
    ll ans = 0;
    rep(i,15){
        ans += dp[n][i];
        ans %= MOD;
    }
    cout << ans << endl;
}