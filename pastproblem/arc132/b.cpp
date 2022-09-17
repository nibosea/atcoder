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
    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    // 1 2 3 .... か、n, n-1 , ... ,1の順に結局なっているはず。
    //まず、1を見つける
    int ind = -1;
    rep(i,n){
        if(p[i] == 1){
            ind = i;
        }
    }
    bool up = false;
    if(p[0] % n + 1 == p[1] % n) up = true;
    if(up){
        //puts("up");
    }
    bool f = true;
    rep(i,n){
        if(p[i] != i+1) f=false;
    }
    if(f){
        cout << 0 << endl;
        return 0;
    }
    if(up){
        // ひっくり返して全部送るか、最初から全部送るか。
        int ans = ind;
        //debug(ind);
        int el = (n - ind) + 2;
        ans = min(ans,el);
        cout << ans << endl;
    } else {
        // downのとき、
        // 送ってからひっくり返すか、ひっくり返してから送るか
        int ans = (ind + 1) + 1;
        int el = 1 + (n - ind - 1);
        ans = min(ans,el);
        cout << ans << endl;
    }
}