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
#define per(i, n)       Per(i,0,n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"-1"<<endl;}
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
class UnionFind {
public:
    // 親の番号を格納する。親だった場合は-(その集合のサイズ)
    vector<int> Parent;

    UnionFind(int N) {
        Parent = vector<int>(N, -1);
    }

    // Aがどのグループに属しているか調べる
    int root(int A) {
        if (Parent[A] < 0) return A;
        return Parent[A] = root(Parent[A]);
    }

    // 自分のいるグループの頂点数を調べる
    int size(int A) {
        return -Parent[root(A)];//親をとってきたい]
    }

    // AとBをくっ付ける
    bool connect(int A, int B) {
        // AとBを直接つなぐのではなく、root(A)にroot(B)をくっつける
        A = root(A);
        B = root(B);
        if (A == B) {
            //すでにくっついてるからくっ付けない
            return false;
        }

        // 大きい方(A)に小さいほう(B)をくっ付ける
        // 大小が逆だったらひっくり返す
        if (size(A) < size(B)) {
            swap(A, B);
        }

        // Aのサイズを更新する
        Parent[A] += Parent[B];
        // Bの親をAに変更する
        Parent[B] = A;

        return true;
    }
};
vector<int> to[200005];
int main() {
    int n,m; cin >> n >> m;
    vector<int> d(n);
    rep(i,n) cin>> d[i];
    dsu dsu(n);
    rep(i,m){
        int x,y; cin>>x>>y;
        x--;y--;
        d[x]--;d[y]--;
        dsu.merge(x,y);
    }
    vector<vector<int>> temp(n);
    rep(i,n){
        if(d[i]<0){
            cout << -1 << endl;
            return 0;
        }
        rep(j,d[i])temp[dsu.leader(i)].push_back(i);
    }
    vector<vector<int>> c2;
    vector<int>c1;
    rep(i,n){
        if(temp[i].size()==1)c1.push_back(temp[i][0]);
        else if(temp[i].size()>1)c2.push_back(temp[i]);
    }
    vector<P>ans;
    for(auto v:c2){
        rep(i,v.size()-1){
            if(c1.empty()){
                cout << -1 << endl;
                return 0;
            }
            dsu.merge(v[i],c1.back());
            ans.push_back({v[i],c1.back()});
            c1.pop_back();
        }
        c1.push_back(v.back());
    }
    if(c1.size()!=2){
        cout << -1;return 0;
    }
    dsu.merge(c1[0],c1[1]);
    ans.push_back({c1[0],c1[1]});

    if(dsu.size(0)!=n){
        cout << -1; return 0;
    }
    for(auto[p,q]:ans){
        cout << p+1 << " " << q+1 << endl;
    }
}