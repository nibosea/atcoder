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
ll rotate(ll x){
    //debug(x);
    string ret_s = "";
    string s = to_string(x);
    int n = s.size();
    rep(i,n-1){
        ret_s.push_back(s[i+1]);
    }
    ret_s.push_back(s[0]);
    ll ret = stoll(ret_s);
    //debug(ret);
    return ret;
}
int main()
{
    ll a, n; cin >> a >> n; // 1から、a倍、を使ってNにする
    queue<ll> que;
    que.push(n);
    map<ll, int> mp;
    mp[n] = 0;
    // 辿りつかなかった場合が多分必要。
    while(!que.empty()){
        ll now = que.front(); que.pop();
        //debug(now);
        int cost = mp[now];
        if(now == 1){
            cout << cost << endl;
            return 0;
        }
        if(now % a == 0){
            // aで割り切れるときは、割ります
            ll next = now / a;
            if(mp[next] == 0 && next != n) {
                mp[next] = cost+1;
                que.push(next);
            }
        }
        // 回文的なことをする
        if(now < 10) continue;
        // 先頭が0だったら飛ばす
        int sento = now;
        while(sento >= 10) sento/=10;
        if(sento == 0) continue;
        ll next = rotate(now);
        if(next != n && mp[next] == 0) {
            mp[next] = cost+1;
            que.push(next);
        }
    }
    cout << -1 << endl;
}