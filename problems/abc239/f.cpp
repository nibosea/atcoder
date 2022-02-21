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
int main()
{
    int n, m;
    cin >> n >> m;
    vector<ll> d(n);
    ll sum = 0;
    rep(i,n){
        cin >> d[i];
        sum += d[i];
    }
    UnionFind uni(n);
    bool hasLoop = false;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        --a, --b;
        if(uni.root(a) == uni.root(b)){
            hasLoop=true;
        }
        uni.connect(a,b);
        to[a].push_back(b);
        to[b].push_back(a);
        d[a]--;
        d[b]--;
        if(d[a] < 0 || d[b] < 0){
            coN();
            return 0;
        }
    }
    if(sum != 2*(n-1)){
        coN(); //n-1本の辺という条件から、各が、di本のとつながってるようなのは無理
        return 0;
    }
    if(hasLoop){
        coN();
        return 0; //Loopあったら無理
    }
    //rep(i,n){
    //    cout << d[i] << " ";
    //}
    //cout << endl;
    // 0と違う島にいる。繋げないといけない者たち
    priority_queue<P> pq;
    // 0島にいて、つなげるために使えるやつたち
    queue<P> islands;

    For(i,1,n){
        //0と同じ島にいるやつ、いないやつを見つける 
        if(uni.root(0) == uni.root(i)){
            // 同じグループにいる
            if(d[i] >= 1){
                // 他の島とつなげるときに使える
                islands.push(P(i,d[i]));
            } 
        } else {
            // 別グループにいるから、つなげないといけない物たち
            if(d[i] >= 1){
                pq.push(P(d[i],i));
            }
        }
    }
    vector<P> ans(0);
    vector<int> cnt(n,0);
    while(!pq.empty()){
        int v, cost;
        tie(cost,v) = pq.top(); pq.pop();
        //vと0島を連結にする
        //何らかの原因で、すでに連結になったかもしれない
        if(uni.root(v) == uni.root(0)){
            //vは、使えるものとしてislandsに入れる

            //islands.push(P(v,d[v])); d[v]は更新してないから自己る
            islands.push(P(v,cost));
            continue;
        }
        // まだつながっていないなら、つなげる
        int nv, cost2;
        if(islands.empty()){
            coN();
            return 0;
        }
        tie(nv,cost2) = islands.front(); islands.pop();
        uni.connect(v,nv);
        cnt[v]++;
        cnt[nv]++;
        ans.push_back(P(v,nv));
        cost--;
        if(cost>=1){
            islands.push(P(v,cost));
        }
        cost2--;
        if(cost2>=1){
            islands.push(P(nv,cost2));
        }
    }
    rep(i,n){
        if(uni.root(i) == uni.root(0)){
            continue;
        } else {
            coN();
            return 0;
        }
    }
    rep(i,n){
        if(cnt[i] != d[i]){
            coN();
            return 0;
        }
    }
    rep(i,n-m-1){
        cout << ans[i].first+1 << " " << 1+ans[i].second << endl;
    }
}