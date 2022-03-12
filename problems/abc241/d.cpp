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
const ll INF = 1'000'000'000'000'000'010;
//Write From this Line
int main()
{
    multiset<ll> ms;
    int q; cin >> q;
    ms.insert(INF);
    ms.insert(-1);
    while(q--){
        ll t, x;
        cin >> t >> x;
        if(t == 1){
            ms.insert(x);
        } else {
            int k; cin >> k;
            if(t == 2){
                // x以下の要素の内大きい方からk番目
                //x+1以上となるインデックスを見つける
                auto itr1 = ms.lower_bound(x+1);
                // itr1がms内かどうかを調べたい
                // k回マイナスしたい
                bool flag = true;
                rep(i,k){
                    if(*itr1 == -1){
                        // minus出来ない
                        flag = false;
                    } else {
                        itr1--;
                    }
                }
                if(*itr1 == -1) flag = false;
                if(flag) cout << *itr1 << endl;
                else cout << -1 << endl;
                
            } else if (t==3){
                // x以上の内小さい方からk番目
                // x以上のインデックスを見つける
                //iterator ind = ms.lower_bound(x);
                //debug(ind);
                auto itr1 = ms.lower_bound(x);
                bool flag = true;
                rep(i,k-1){
                    if(*itr1 == INF){
                        flag =false;
                    } else {
                        itr1++;
                    }
                }
                if(*itr1 == INF) flag = false;
                if(flag)cout << *itr1 << endl;
                else cout << -1 << endl;
            }
        }
    }
}