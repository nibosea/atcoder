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
bool inField(int x, int y, int n){
    if(x < 0 || y < 0) return false;
    if(x >= n || y >= n) return false;
    return true;
}
int main()
{
    int n; cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    rep(i,n){
        rep(j,n){
            // s[i][j]から横に6個を見る
            int cnt = 0;
            int ok = 2;
            rep(k,6){
                if(!inField(i,j+k,n)) continue;
                if(s[i][j+k] == '#') cnt++;
                else {
                    if(ok>0){
                        cnt++;
                        ok--;
                    } else {
                        // okがないなら無理
                        break;
                    }
                }
            }
            if(cnt == 6){
                coY();
                return 0;
            }
        }
    }
    rep(i,n){
        rep(j,n){
            // s[i][j]からtateに6個を見る
            int cnt = 0;
            int ok = 2;
            if(i+5>=n) continue;
            rep(k,6){
                if(!inField(i+k,j,n)) continue;
                if(s[i+k][j] == '#') cnt++;
                else {
                    if(ok>0){
                        cnt++;
                        ok--;
                    } else {
                        // okがないなら無理
                        break;
                    }
                }
            }
            if(cnt == 6){
                coY();
                return 0;
            }
        }
    }
    // 斜めの判定をどうするか
    rep(i,n){
        rep(j,n){
            // s[i][j]から右下に6つのマスを見る
            int cnt = 0;
            int ok = 2;
            rep(k,6){
                if(!inField(i+k,j+k,n)) continue;
                if(s[i+k][j+k] == '#') cnt++;
                else {
                    if(ok>0){
                        cnt++;
                        ok--;
                    } else {
                        // okがないなら無理
                        break;
                    }
                }
            }
            if(cnt == 6){
                coY();
                return 0;
            }
        }
    }
    rep(i,n){
        rep(j,n){
            // s[i][j]から左下に6つのマスを見る
            int cnt = 0;
            int ok = 2;
            rep(k,6){
                if(!inField(i+k,j-k,n)) continue;
                if(s[i+k][j-k] == '#') cnt++;
                else {
                    if(ok>0){
                        cnt++;
                        ok--;
                    } else {
                        // okがないなら無理
                        break;
                    }
                }
            }
            if(cnt == 6){
                coY();
                return 0;
            }
        }
    }
    coN();
}
