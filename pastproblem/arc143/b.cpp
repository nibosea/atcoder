#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(ll i = (a) ; i < (b) ; ++i)
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

const ll dy[] = {0,0,1,-1};
const ll dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<ll> to[200'005];
//Write From this Line
int main()
{
    int n;
    cin >> n;
    // どのマスも、
    if(n == 1){
        cout << 0 << endl; 
        return 0;
    }

    ll M = n * n;
    ll m = 1;
    mint ans = 0;
    mint kou = 1;
    for(int i = 1; i <= M - 2*n + 1; i++){
        kou *= i;
    }
    for(ll z = 1; z <= n * n; z++){
        // 条件を満たさないセルの中に書かれている値を一つ決める
        // 行には、自身より大きい値しか来てはいけない
        // まず、zの位置でM通り
        mint now = M;
        ll cnt_M = (M - z);
        ll cnt_m = (z - m);
        if(cnt_M < n - 1) continue;
        if(cnt_m < n - 1) continue;
        // cnt_M個を同じ行のn-1マスに配る -> (cnt_M) P (n-1)　通り
        mint x = 1;
        rep(i,n-1){
            x *= cnt_M;
            cnt_M --;
        }
        mint y = 1;
        rep(i,n-1){
            y *= cnt_m;
            cnt_m --;
        }
        // cnt_m個を同じ列のn-1マスに配る
        // now * x * y が、セルが条件満たさないようにするため、残りのM-2n+1マスについてはどうでもいい　
        now *= x;
        now *= y;
        now *= kou;
        ans += now;
    }
    // M-2n+1をここでまとめて処理する　
    //ans *= kou;
    // N*Nのかいじょうひくあんｓが答え
    mint tans = 1;
    rep(i,n*n) tans *= i+1;
    tans -= ans;
    cout << tans.val() << endl;
}

