#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(ll i = (a) ; i < (b) ; ++i)
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

const ll dy[] = {0,0,1,-1};
const ll dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<ll> to[200'005];
//Write From this Line
int cnt = 0;
int ask(int x, int y){
    printf("? %d %d",x,y);
    cout << endl;
    cnt++;
    int d;
    cin >> d;
    return d;
}
void print_ans(int d){
    printf("! %d", d);
    cout << endl;
    return ;
}
int main()
{
    int n;
    cin >> n;
    vector<int> dist(n+1,0);
    vector<int> dist2(n+1,0);
    rep(i,n-2){
        int ko = ask(1,i+3);
        dist[i+3] = ko;
    }
    rep(i,n-2){
        int ko = ask(2,i+3);
        dist2[i+3] = ko;
    }
    // 距離が1の場合の判定を行いたい
    // どちらもから距離1があれば…
    bool f = false;
    For(i,3,n+1){

    }
    int M = inf;
    for(int i = 3; i <= n; i++){
        // 共通の祖先を見つければいい
        debug(i);
        int d1 = dist[i];
        int d2 = dist2[i];
        int cost = d1 + d2;
        chmin(M,d1+d2);
    }
    if(M == inf){
        print_ans(1);
        return 0;
    }
    print_ans(M);
}
