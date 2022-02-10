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
    string s;
    cin >> s;
    string t;
    t = s;
    REV(t);
    int cnt = 0;
    rep(i,t.size()){
        if(t[i] == 'a'){
            cnt++;
        } else{
            break;
        }
    }
    int n = s.size();
    rep(i,s.size()){
        if(s[i] == 'a'){
            cnt--;
        } else{
            break;
        }
    }
    if(s==t){
        coY();
        return 0;
    }
    // tの後ろにcnt個aを加える
    string pl = "";
    rep(i,cnt){
        pl += 'a';
    }
    s = pl + s;
    t = t + pl;
    if(s==t){
        coY();
    } else coN();
}