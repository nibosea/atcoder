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
    int n,k; cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<bool> ans(k+1,true); ans[0] = false;
    rep(i,n){
        for(int j = 2; j * j <= k; j++){
            if(a[i] < j) continue;
            if(!ans[j])continue;
            if(a[i] % j == 0){
                int tmp = j;
                while(tmp <= k){
                    ans[tmp] = false;
                    tmp+=j;
                }
            }
        }
        // k が素数の場合
        if(__gcd(a[i],k) != 1){
            ans[k] = false;
        }
        if(a[i] <= k)ans[a[i]] = false;
    }
    ans[1] = true;
    int num = 0;
    rep(i,k+1){
        if(ans[i]) num++;
    }
    cout << num << endl;
    rep(i,k+1){
        if(ans[i]) cout << i << endl;
    }
}