#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define fore(i, a) for(auto &i: a)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const ll MOD = 998244353;
//Write From this Line
ll n;
vector<P> p;
void input(){
    cin >> n;
    p.resize(n);
    rep(i,n){
        cin >> p[i].first >> p[i].second;
    }
    SORT(p);
    //rep(i,n){
    //    printf("(%lld, %lld)\n", p[i].first, p[i].second);
    //}
}
int main()
{
    input();
    ll ok = 0, ng = 1e9;
    while(ng - ok > 1){
        ll k =(ok + ng) / 2;
        queue<P> q;
        ll M = -1;
        ll m = 1e9+5;
        bool flag = false;
        rep(i,n){
            while(!q.empty() && p[i].first - q.front().first >= k){
                ll x, y;
                tie(x,y) = q.front(); q.pop();
                chmax(M,y);
                chmin(m,y);
            }
            if( M-p[i].second >= k) flag = true;
            if(p[i].second-m >= k) flag = true;
            q.push(p[i]);
        }
        if(flag) ok = k;
        else ng = k;
    }
    cout << ok << endl;
}