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
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void coT() {cout <<"Takahashi"<<endl;}
void coA(){cout <<"Aoki"<<endl;}

void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    rep(i,n) cin >> a[i];
    rep(i,n) cin >> b[i];
    vector<P> ans(n);
    // ans[i] = [l,r) := a[i]は、bの先頭l項からr-1項の間なら一致する
    map<int, int> mpa;
    map<int, int> mpb;
    int diff = 0;
    // まだ出てきてないものがあるかもしれないので、それを管理する
    int r = 0;
    int l = -1; 
    rep(i,n){
        // ans[i]を求め
        int num = a[i];
        if(mpa[num] == 0) diff++;
        mpa[num]++;
        while(r < n && mpa[b[r]] ){
            if(mpb[b[r]] == 0) {
                diff--;
                if(diff == 0) l = r;
            }
            mpb[b[r]]++;
            r++;
        }
        if(diff){
            ans[i] = P(-1,-1);
        } else {
            ans[i] = P(l,r);
        }
        //printf("l = %d, r = %d\n", l, r);
    }
    int q;
    cin >> q;
    rep(i,q){
        int x, y;
        cin >> x>> y;
        --x; --y;
        auto [l,r] = ans[x];
        if(l <= y && y < r){
            coY();
        } else {
            coN();
        }
    }

    rep(i,n){
        //cout << ans[i].first << " " << ans[i].second << endl;
    }
}
