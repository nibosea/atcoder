#include <bits/stdc++.h>

using namespace std;

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
int main()
{
    ll n, q;
    cin >> n>> q;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    SORT(a);
    vector<P> x(q+1);
    rep(i,q) {
        cin >> x[i].first;
        x[i].second = i+1;
    }
    x[q] = P(0,0);// 空のクエリを埋めておこう
    SORT(x);
    ll sum = 0;
    rep(i,n) sum += a[i];
    vector<ll> ans(n+1);
    ans[0] = sum;

    ll memo = 0;
    ll dou = 0;
    ll andou = n;
    ll b_obj = 0;
    rep(i,q+1){
        // 全ての要素をobjにする
        ll obj = x[i].first;
        // まず、dou個は一気にobjまであげる
        sum += (obj - b_obj) * dou;
        // memo番目まずの数は同一視
        for(ll j = memo; j < n; j++){
            // a[j] <= objなら、objにして同一視する
            if(a[j] <= obj){
                // b_obj <= a[j] <= objみたいなとき、注意
                // 一度a[j]にしてから、
                sum -= a[j] - b_obj;
                sum += obj-a[j];
                dou++;
                andou--;
                memo++;
                a[j]=obj;
                // この時コストは…近づくだけ
            } else {
                break;
            }
        }
        sum -= (obj-b_obj) * andou;
        ll query = x[i].second;
        ans[x[i].second] = sum;
     b_obj = obj;
    }
    For(i,1,q+1){
        cout << ans[i] << endl;
    }
}
