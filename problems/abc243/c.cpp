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
#define per(i, n)       Per(i,n,0)
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
    vector<tuple<int,int,char>> t(n);
    vector<P> p(n);
    rep(i,n){
        // (y,x);
        cin >> p[i].second >> p[i].first;
    }
    string s;
    cin >> s;
    rep(i,n){
        // (y,x)
        t[i] = {p[i].first, p[i].second, s[i]};
    }
    SORT(t);
    // y,x
    bool diff = true;
    int memo = p[0].first;
    bool R = false;
    rep(i,n){
        int x,y;
        char c;
        tie(y,x,c) = t[i];
        if(memo == y){
            if(c == 'L'){
                if(R){
                    coY();
                    return 0;
                }
            } else {
                R = true;
            }
        } else {
            R = false;
            if(c == 'R') R = true;
            memo = y;
        }
    }
    coN();
}