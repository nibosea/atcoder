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

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
//Write From this Lijjjjjjjjjne
int main()
{
    int n, m; cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> b(m);
    rep(i,m) cin >> b[i];
    int dist = inf;
    rep(i,n-1){
        if(a[1+i] != a[0] || a[n-1-i] != a[0]){
            dist = i+1;
            break;
        }
    }
    int ans = 0;
    bool flag = false; // distの移動をしたかどうか
    int now = a[0];
    rep(i,m){
        if(now != b[i]){
            if(flag) ans++;
            else if(dist == inf){
                cout << -1 << endl;
                return 0;
            } else {
                ans += dist;
                flag = true;
            }
        }
        now = b[i];
        ans++; // 実際に0,1を取る操作
    }
    cout << ans << endl;
}