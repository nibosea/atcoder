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
//後ろから構築していけばよさそうな気がする
    int n; cin >> n;
    vector<int> s(n);
    rep(i,n) cin >> s[i];
    vector<int> a(n+2);
    ll l1 = -1, r1 = s[2]+1;
    // a[2] としてあり得るものをやっていく。
    while(r1 - l1 > 1){
        int m1 = l1 + (r1 - l1) / 2;
        // M1
        bool m1fin=false;
        for(int i = 2; i < n + 3; i += 3){
            // ガンマ+kみたいなのを考えないといけない
            ll now1=m1;
            if(i-3>=0){
                now1 += s[i-2] - s[i-3];
            }
            a[i] = now1;
            if(now1 < 0){
                // 制約違反してしまたｔので、l1かr1をいじらないといけない。どっち?
                // 小さくなった結果now1が負になってしまったので、大きくしないといけない
                l1 = m1;
                m1fin = true;
                break;
            }
            for(int j = i; j >= i-2; i--){
                if(m1 >s[j]){
                    // m1はデカすぎるので、小さくする必要がある
                    r1=m1;
                    // M1まで戻る
                    m1fin = true;
                    break;
                }
            }
            if(m1fin){
                break;
            }
            // m1 でokの時、ここまでくる, 次は、m2 を決める
        }
        // m1finの時ここまで来る
        if(m1fin) continue;
        ll l2 = -1, r2 = s[2]+1-a[3];
        // a[2] としてあり得るものをやっていく。
        while(r2 - l2 > 1){
            int m2 = l2 + (r2 - l2) / 2;
            // M2
            bool m2fin=false;
            for(int i = 1; i < n + 3; i += 3){
                // beta+kみたいなのを考えないといけない
                ll now2=m2;
                if(i-3>=0){
                    now2 += s[i-2] - s[i-3];
                }
                a[i] = now2;
                if(now2 < 0){
                    // 制約違反してしまたｔので、l2かr2をいじらないといけない。どっち?
                    // 小さくなった結果now2が負になってしまったので、大きくしないといけない
                    l2 = m2;
                    m2fin = true;
                    break;
                }
                for(int j = i; j >= i-1; i--){
                    if(m2 + a[i+1] >s[j]){
                        // m2はデカすぎるので、小さくする必要がある
                        r2=m2;
                        // M2まで戻る
                        m2fin = true;
                        break;
                    }
                }
                if(m2fin){
                    break;
                }
                // m2 でokの時、ここまでくる, 次は、m2 を決める
            }
            // m2finの時ここまで来る
            if(m2fin) continue;
            ll l3 = -1, r3 = s[0]+1-a[3]-a[2];
            // a[3] としてあり得るものをやっていく。
            while(r3 - l3 > 1){
                int m3 = l3 + (r3 - l3) / 2;
                // M3
                bool m3fin=false;
                for(int i = 0; i < n + 3; i += 3){
                    // beta+kみたいなのを考えないといけない
                    ll now3=m3;
                    if(i-3>=0){
                        now3 += s[i-3] - s[i-3];
                    }
                    a[i] = now3;
                    if(now3 < 0){
                        // 制約違反してしまたｔので、l3かr3をいじらないといけない。どっち?
                        // 小さくなった結果now3が負になってしまったので、大きくしないといけない
                        l3 = m3;
                        m3fin = true;
                        break;
                    }
                    for(int j = i; j >= i; i--){
                        if(m3 + a[i+1] >s[j]){
                            // m3はデカすぎるので、小さくする必要がある
                            r3=m3;
                            // M3まで戻る
                            m3fin = true;
                            break;
                        }
                    }
                    if(m3fin){
                        break;
                    }
                    // m3 でokの時、ここまでくる, 次は、m3 を決める
                }
                // m3finの時ここまで来る
                if(m3fin) continue;
                else {
                    rep(i,n+2){
                        cout << a[i] << " " ;
                    }
                    cout << endl;
                    return 0;
                }
            }
        }
    }
}