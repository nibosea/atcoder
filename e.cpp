#include <bits/stdc++.h>
using namespace std;

using ll = unsigned long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define fore(i, a) for(auto &i:a)
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
using vs = vector<string> ;
int N, K;
int ans;
string S[8];


int main(){
    cin >> N >> K;
    rep(i,N) cin >> S[i];
    set<ll> que;
    rep(y,N) rep(x,N) if (S[y][x] == '.') que.insert(1ll << (y * N + x));
    For(k,1,K){
        set<ll> nxt;
        fore(cu, que){
            rep(y,N) rep(x,N) if(S[y][x]=='.' && !(cu &(1ll << (y*N+x)))){
                bool ok =false;
                rep(d,4){
                    int xx = x + dx[d];
                    int yy = y + dy[d];

                    if(0 <= xx && xx < N && 0 <= yy && yy < N){
                        if(S[yy][xx] == '.' && (cu & (1ll << (yy * N + xx)))){
                            ok = true;
                        }
                    }
                }
                if (ok)
                    nxt.insert(cu | (1ll << y * N + x));
            }
        }
        swap(que,nxt);
    }
    int ans = que.size();
    cout << ans << endl;
}