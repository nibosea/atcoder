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
ll used[1'000'000'5];
ll cnt_digits(ll x){
    ll ret = 0;
    while(x>0){
        ret++;
        x/=10;
    }
    return ret;
}

ll rotate(ll x){
    string ret_s = "";
    string s = to_string(x);
    ll n = s.size();
    // 123 -> 312
    ret_s.push_back(s[n-1]);
    rep(i,n-1){
        ret_s.push_back(s[i]);
    }
    ll ret = stoi(ret_s);
    return ret;
}
int main()
{
    ll a, n;
    cin >> a >> n;
    queue<ll> q;
    map<ll, ll> cost;
    ll tar_digits = cnt_digits(n);
    auto add = [&] (ll x, ll y){
        // xがunusedかつ、桁数okならコストyで突っ込む
        if(cnt_digits(x) > tar_digits) return;
        if(used[x]) return;
        cost[x]=y;
        used[x]=true;
        q.push(x);
    };
    add(1,0);
    while(!q.empty()){
        ll v = q.front(); q.pop();
        ll nv = v * a;
        add(nv, cost[v]+1);
        if(v % 10 == 0) continue; // 10で割り切れるときはrotate 無理 120 -> 012(x)
        nv = rotate(v);
        add(nv,cost[v]+1);
    }
    cout << cost[n] << endl;
    //cout << (cost[n]? cost[n]:-1) << endl;
}