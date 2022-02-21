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
int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> b(n,vector<int> (m));
    rep(i,n)rep(j,m) cin >> b[i][j];
    int a = b[0][0];
    rep(i,n){
        int tmp = a;
        int age = (b[i][0] + 6) / 7;
        rep(j,m){
            // 途中で、商の切り上げが変わったらダメ
            int agenow = (b[i][j] +6) / 7;
            if(agenow != age) {
                coN();
                return 0;
            }
            if(b[i][j] == tmp) tmp++;
            else {
                coN();
                return 0;
            }
        }
        a += 7;
    }
    coY();
}