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
vector<int> to[200'005];
int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    rep(i,n) cin >> h[i];
    rep(i,m){
        ll u, v;
        cin >> u >> v;
        u--, v--;
        to[u].push_back(v);
        to[v].push_back(u);
    }

    queue<P> que; // 親をメモするため
    que.push(P(0,-1));
    vector<ll> score(n,-INF);
    score[0] = 0;
    ll ans = 0;
    while(!que.empty()){
        ll v = que.front().first;
        ll p = que.front().second;
        que.pop();
        ll now = score[v];
        for(auto nv: to[v]){
            if(nv == p) continue;
            ll diff = h[nv] - h[v];
            if(diff > 0) diff *= -2;
            else diff *= -1;
            ll nscore = now + diff;
            //printf("v: %d, nv: %d, score:%lld\n", v,nv,nscore);
            if(chmax(score[nv], nscore)){
                que.push(P(nv,v));
                chmax(ans,nscore);
            }
        }
    }
    cout << ans << endl;
}