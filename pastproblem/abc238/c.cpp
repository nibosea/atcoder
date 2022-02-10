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
int main()
{
    ll n; cin >> n;
    // 桁数ごとに処理する
    ll M = 9;
    ll m = 1;
    ll ans = 0;
    ll minus = 0;
    while(true){
        // m ~ M までを処理する
        bool end = false;
        if(chmin(M,n)) end=true; // この回が最終
        ll now;
        ll M1 = M; M1 %= MOD;
        ll m1 = m; m1 %= MOD;
        //cout << "m,M:= " << m1 << ", " << M1 << endl;
        ll x1 = (M1-m1+1);
        ll x2 = (x1+1);
        //debug(x1);
        if(x1%2==0) x1 /= 2;
        else x2 /= 2;
        x1 %= MOD;
        x2 %= MOD;
        now = x1 * x2; now %= MOD;
        ans += now; ans %= MOD;
        //// 項数かけるminusを引く
        //ll th = (M-m+1);
        //th %= MOD;
        //th *= minus;
        //th %= MOD;
        ////ans -= th;
        //while(ans<0) ans += MOD;
        m *= 10;
        M *= 10; M += 9;
        if(m == 1e18) break;
        if(M<0){
            M = 1e18;
        }
        //minus *= 10; minus += 10;
        //minus %= MOD;
        //debug(ans);
        if(end)break;
    }
    cout << ans << endl;
}