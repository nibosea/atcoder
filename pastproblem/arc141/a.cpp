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
int f(ll x){
    // xの桁数を返す
    int num = 0;
    while(x > 0){
        num ++ ;
        x /=  10;
    }
    return num;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        string X;
        cin >> X;
        ll x = stoll(X);
        ll n = X.size();
        // Xの前n/2
        ll ans = 0;
        // 目標が何桁かも定まっていない
        for(int obj = n; obj >= 2; obj--){
            // 目標はobj桁
            for(int i = 1; i < obj; i++){ 
                // i桁を２個以上でobj桁にする
                if(obj%i !=0 )continue;
                ll ng = 1e18;
                // okをi桁にしないといけない
                string OK = "1";
                while(OK.size() != i){
                    OK = OK + '0';
                }
                ll ok = stoll(OK);
                //cout << "i: " << i << ", ok: " << ok << endl;
                while(ng - ok > 1){
                    ll mid = (ok+ng) / 2;
                    // midがi桁じゃないと困る
                    string now = to_string(mid);
                    if(now.size() != i){
                        ng = mid;
                        continue;
                    }
                    // obj桁になるまで連結する
                    string tmp = "";
                    while(tmp.size() != obj){
                        tmp = tmp + now;
                    }
                    if(stoll(tmp) <= x){
                        ok = mid;
                        chmax(ans, stoll(tmp));
                    } else {
                        ng = mid;
                    }
                }
                // ok をi個つなげたものを出力
                // ok を 
                string tmp = "";
                while(tmp.size() != obj){
                    tmp = tmp + to_string(ok);
                }
                if(stoll(tmp) <= x) chmax(ans, stoll(tmp));
            }
        }
        cout << ans << endl;
    }
}
