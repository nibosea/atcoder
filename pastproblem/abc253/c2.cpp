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
// https://atcoder.jp/contests/abc253/submissions/32071960
template<class T> class MapMultiSet {
    using i64 = long long;
    std::map<T, i64> mp;
public:
    bool add(T x) { mp[x] += 1; return true; }
    bool add(T x, i64 c) { mp[x] += c; return true; }
    bool remove(T x) {
        if (mp.find(x) == mp.end()) return false;
        if (mp[x] == 1) { mp.erase(x); return true; }
        mp[x] -= 1;
        return true;
    }
    bool remove(T x, i64 c) {
        if (mp.find(x) == mp.end()) return false;
        if (mp[x] <= c) { mp.erase(x); return true; }
        mp[x] -= c;
        return true;
    }
    T min() {
        assert(!mp.empty());
        return get<0>(*mp.begin());
    }
    T max() {
        assert(!mp.empty());
        return get<0>(*prev(mp.end()));
    }
    int size() {
        return mp.size();
    }
    i64 count(T x) {
        if (mp.find(x) == mp.end()) return 0;
        return mp[x];
    }
    bool empty() { return mp.empty(); }
    bool not_empty() { return !mp.empty(); }
    bool contains(T x) { return mp.find(x) != mp.end(); }
};
int main()
{
    int q;
    cin >> q;
    MapMultiSet<int> ms;
    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int x;
            cin >> x;
            ms.add(x);
        }
        if(t == 2){
            int x, c;
            cin >> x>> c;
            ms.remove(x,c);
        }
        if(t == 3){
            cout << ms.max() - ms.min() << endl;
        }
    }
}
