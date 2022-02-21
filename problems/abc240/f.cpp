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
    ll t; cin >> t;
    rep(i,t){
        ll n,m; cin >> n >> m;
        ll ans = -4; // 考えられる最小値を答えとしておく
        ll now_b = 0;
        ll now_c = 0;
        rep(j,n){
            ll x, y; cin >> x >> y;
            if(j==0){
                ans=x;
            }
            // ここでbの最後とcの最後を求める
            // さらに、過程での最大値を求めて大きくなるかを判定する
            ll next_c = now_c+ (y*(2*(now_b+x)+(y-1)*x))/2;
            ll next_b = now_b+ x*y;
            if(next_b>=0){
                //全部足しちゃえばいい,つまり、next_cとansの大きい方
                chmax(ans,next_c);
            } else {
                // next_bが負になるのであれば、now_bが正であるところまで足したい
                // このとき、普通に考えればxは負なので...
                // 2分探索で求める
                if(now_b<0){
                    //元から負なら何もしなくていい
                } else {
                    ll ok = 0;ll ng = y;
                    while(ng-ok>1){
                        ll mid = (ok+ng) / 2;
                        if(now_b + mid*x >= 0){
                            ok = mid;
                        } else {
                            ng = mid;
                        }
                    }
                    // okが求まった。
                    //初稿now_b + x, 項数 okの等差数列の和
                    if(ok != 0){
                        ll kouho = now_c+ (ok*(2*(now_b+x)+(ok-1)*x))/2;
                        chmax(ans,kouho);
                    }
                }
            }
            // 更新
            now_b=next_b;
            now_c=next_c;
        }
        cout << ans << endl;
    }
}