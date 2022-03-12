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
    int n; cin >> n; 
    vector<string> s(n), t(n);
    rep(i,n) cin >> s[i];
    rep(i,n) cin >> t[i];

    auto rot = [&](vector<string> a){
        vector<string> res(n, string(n,'.'));
        rep(i,n){
            rep(j,n){
                res[j][n-1-i] = a[i][j];
            }
        }
        return res;
    };

    auto normalize = [&](vector<string> a){
        int li = n, lj = n;
        rep(i,n)rep(j,n) if(a[i][j] == '#') {
            li = min(li,i);
            lj = min(lj,j);
        }
        vector<string> res(n, string(n, '.'));
        rep(i,n)rep(j,n) if(a[i][j] == '#') {
            res[i-li][j-lj] = '#';
        }
        return res;
    };

    auto same = [&](vector<string> a, vector<string> b){
        return normalize(a) == normalize(b);
    };

    rep(ri,4){
        if(same(s,t)){

            cout << "Yes" << endl;
            return 0;
        }
        t = rot(t);
    }
    coN();
}