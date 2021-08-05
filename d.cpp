#include <bits/stdc++.h>
using namespace std;

using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
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
    int n, m;
    cin >> n >> m;
    rep(i,m){
        int x, y;
        cin >> x >> y;
        x--, y--;
        to[x].push_back(y);
        to[y].push_back(x);
    }
    queue<int> q;
    q.push(0);
    vector<int> done(n,0);
    done[0] = 1;
    vector<P> ans(n,P(0,INF));
    ans[0] = P(1,0);
    while(!q.empty()){
        int v = q.front(); q.pop();
        int now = ans[v].second; // vまでの手数
        for(auto nv: to[v]){
            // now + 1とnvまでの手数を確認する
            if(now+1 > ans[nv].second) continue;
            if(now+1 == ans[nv].second){
            }
            else {
                // 手数が短くなる
                ans[nv] = P(ans[v].first,now+1);
                q.push(nv);
            }
        }
    }
    cout << ans[n-1].first << endl;
}