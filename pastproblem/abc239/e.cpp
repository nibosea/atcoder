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
vector<int> to[200005];
vector<vector<int>> ans(200005,vector<int>(25,-1));

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    rep(i,n) cin >> x[i];
    rep(i,n){
        int a, b;
        cin >> a >> b;
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }

    queue<P> que;
    que.push(P(0,-1));
    vector<int> d(n,0);
    vector<int> p(n,-1);
    // 深さを求める
    while(!que.empty()){
        int v, parent;
        tie(v,parent)=que.front();
        que.pop();
        for(auto nv: to[v]){
            if(nv == parent) continue;
            d[nv] = d[v
            que.push(P(nv,v));
        }
    }
    // 深さが深い物から問題を解く
    // 全ての頂点について、1番大きいものから20番目に大きいもの持つくらいならいけるんじゃね？
    vector<priority_queue<int, vector<int>, greater<int>>> vq(200005);
    //vector<priority_queue<int,greater<int>,vector<int>>> vq(2000005);
    que.push(P(0,-1));
    auto bfs = [&](int v,int mae){
        // vの大きい方から20番目までを求めるために
        priority_queue<int, vector<int>, greater<int>> nowq;
        for(auto nv: to[v]){
            if(nv == mae) continue;
            vector<int> ret = bfs(nv,v);
            rep(i,ret.size()){
                nowq.push(ret[i]);
            }
        }
        // 大きい方から20個までを返す
        vector<int> kaesu(0);
        int cnt = 0;
        while(!nowq.empty()){
            kaesu.push_back(nowq.top());
            nowq.pop();
            cnt++;
            if(cnt >= 20)break;
        }
        return kaesu;
    }; 
    // 0 を解く
    bfs(0,-1);
}