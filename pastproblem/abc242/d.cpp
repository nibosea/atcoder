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
int main()
{
    string s;
    cin >> s;
    int q; cin >> q;
    rep(i,q){
        ll t, k;
        cin >> t >> k;
        // t回操作したときのk番目の文字は，元の文字列のナニの影響を受けるか考える
        ll num = 1;
        // *= 2 を t 回したら，1文字あたりが何文字に拡張されるか分かる
        ll cnt = t;
        while(1){
            if(cnt == 0)break;
            num *= 2;
            cnt--;
            if(num >= 1e18){
                break;
            }
        }
        ll ind = 0;
        if(cnt != 0) ind = 0;
        else {
            // num が何回はいるか
            ind = (k-1) / num;
        }
        // indの何番目の文字を求めるのか
        ll ban = k % num;
        if(ban == 0) ban = num;
        // ban is 1-indexed
        // s[ind] を t 回操作したときのk番目の文字を答える
        // 初出の時のアルファベットが何かを知らべる
        ll x = ban;
        ll ki = 0;
        ll gu = 0;
        ll num_cnt = 0;
        while(true){
            if(x == 1) break;
            num_cnt++;
            if(x%2) ki++;
            else gu ++;
            x = (x+1)/2;
        }
        if(gu > ki){
            ki += ll(inf) * (ll)3;
        }
        ll mozi = (s[ind] - 'A') + ki - gu;
        mozi %= 3;
        mozi += (t-num_cnt);
        mozi %= 3;
        cout << char('A'+mozi) << endl;
        // 該当する操作回数の内に，最初の文字から何回変化するかを考える
    }
}