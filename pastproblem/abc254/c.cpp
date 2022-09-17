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
    ll n, k;
    cin >> n>> k;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    if(k == 1) SORT(a);

    // もとから昇順ならok
    bool f = true;
    rep(i,n-1){
        if(a[i+1] < a[i]){
            f=false;
        }
    }
    if(f) {
        coY();
        return 0;
    }
    if(k == 1){
        coN();
        return 0;
    }
    // k飛ばしの島で考えないといけない。
    rep(i,n){
        priority_queue<int,vector<int>, greater<int>> pq;
        int j = i;
        while(j < n){
            pq.push(a[j]);
            j += k;
        }
        j = i;
        int cnt = 0;
        while(j < n){
            ll now = pq.top();
            a[j] = now;
            pq.pop();
            j+=k;
            cnt++;
        }
    }
    f = true;
    rep(i,n-1){
        if(a[i+1] < a[i]){
            f=false;
            coN();
            return 0;
        }
    }
    if(f) {
        coY();
        return 0;
    } else {
        coN();
    }
}
