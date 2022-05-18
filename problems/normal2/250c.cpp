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
    ll n;
    cin >> n;
    vector<ll> cnts(1e7,0);
    ll cnt = 0;
    vector<ll> prime;
    rep(i,2) cnts[i] = 0;
    //cnt[i]:= i以下の素数の数
    for(ll i = 2; i <= 1e6; i++){
        if(cnts[i] == 0){
            // prime
            ll j = i+i;
            prime.push_back(i);
            while(j < 1e6+10){
                cnts[j] = 1;
                j+=i;
            }
            cnt++;
        }
        cnts[i] = cnt;
    }
    ll ans = 0;
    for(auto x: prime){
        ll k = x * x * x;
        if(k >= n) continue;
        // k * p <= n
        ll p_max = n / k;
        p_max = min(x-1,p_max);
        ans += cnts[p_max];
    }
    cout << ans << endl;
}
