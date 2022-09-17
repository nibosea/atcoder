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
bool mysort(string x, string y){
    if(x.size() == y.size()){
        // size一緒なら普通に比較
        return x > y;
    }
    return x.size() > y.size();
}
int main()
{
    ll n;
    cin >> n;
    vector<ll> cost(10);
    rep(i,9) cin >> cost[i+1];
    // 最大回数を考える
    vector<ll> maxes(10,0);
    rep(i,9){
        maxes[i+1] = n / cost[i+1];
    }
    vector<string> ans(0);
    For(i,1,10){
        //操作iを出来るだけすることを考える
        // 操作の振り替えが出来るかもしれない
        ll left = n % cost[i];
        ll huri = i;
        ll kai = 0;
        For(j,i+1,10){
            // 振り替える対象は、自身より大きい物を考えればいい
            // 何回振り替えれる？
            ll diff = cost[j] - cost[i];
            if(diff <= 0) continue;
            ll tinpo = left / diff;
            // tinpo回振り替えれる
            huri = j;
            kai = tinpo;
        }
        // maxes[i]回、10倍を行う。huriを１回、残りはiをmaxes[i]-1回
        string tmp = "";
        char c = char('0'+huri);
        char c2 = char('0'+i);
        rep(ti,kai){
            tmp += c;
        }
        rep(ti,maxes[i]-kai){
            tmp += c2;
        }
        ans.push_back(tmp);
    }
    // sortの仕方が違う
    sort(ans.begin(),ans.end(),mysort);
    cout << ans[0] << endl;
}
