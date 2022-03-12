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
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Line
const int COMSIZE = 1e7+100;
const int COMMOD = MOD;

long long fac[COMSIZE], finv[COMSIZE], inv[COMSIZE];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < COMSIZE; i++){
        fac[i] = fac[i - 1] * i % COMMOD;
        inv[i] = COMMOD - inv[COMMOD%i] * (COMMOD / i) % COMMOD;
        finv[i] = finv[i - 1] * inv[i] % COMMOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % COMMOD) % COMMOD;
}

inline void add_MOD(int &a, int b){ a+=b; if(a>=MOD)a-=MOD;}
int main()
{
    COMinit();
    int n, x,y,z;
    cin >>n>>x>>y>>z;
    {
    int xx = x+y, yy = x-y;
    x=xx;y=yy;
    }
    auto calc =[&](int p, int q) -> ll{
        if((p+q)%2!=0) return 0;
        return COM(p, (p+q)/2);
    };

    int ans = 0;
    rep(i,n+1){
        ans = (ans + COM(n,i) * calc(i,z)%MOD * calc(n-i, x)%MOD * calc(n-i,y)%MOD) %MOD;
    }
    cout << ans << endl;
}