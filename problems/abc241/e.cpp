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
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll x = 0;
    map<ll, ll> mp;
    ll cnt = 0;
    ll sum = 0;
    ll start = -1;
    ll syuki = -1;
    while(true){
        // 繰り返しの回数を知る
        cnt++;
        debug(x);
        if(mp[x]){
            start = x;
            syuki = cnt - mp[x];
            break;
        }
        mp[x] = cnt;
        sum += a[x];
        x = sum % n;
    }
    debug(cnt);
    debug(syuki);
    debug(start);
    // 0 -> x -> ... -> xみたいな感じだとしたら…?
    // 何回繰り返せるか
    ll kaisi = mp[start];
    if(mp[start] >= k){
        //純粋にk回求めてやればいい
        ll ans1 = 0;
        ll fi = 0;
        rep(i,k){
            ans1 += a[fi];
            fi = ans1 % n;
        }
        cout << ans1 << endl;
        return 0;
    }
    // kaisiまでの和を 求めたい
    x = 0;
    ll ans = 0;
    while(x != start){
        ans += a[x];
        x = ans % n;
        k--;
    }
    ll repeat = k / syuki;
    k -= (syuki * repeat);
    ans += repeat * sum;
    x = start;
    rep(i,k){
        ans += a[x];
        x = ans % n;
    }
    cout << ans << endl;
}