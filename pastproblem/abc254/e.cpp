#include <bits/stdc++.h>

using namespace std;

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


const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const int mod = 1e9+7;
const int MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
vector<int> to[160'005];
int ans[200000][4];
//Write From this Line
int main()
{
    int n, m;
    cin >> n>> m;
    rep(i,m){
        int a, b;
        scanf("%d %d", &a, &b);
        --a, --b;
        to[a].push_back(b);
        to[b].push_back(a);
    }
    // 各頂点から距離３までを幅有線探索
    int q;
    cin >> q;
    vector<bool> mp(n,false);
    vector<int> qx(q), qk(q);
    rep(nn,q){
        int x, k;
        cin >> x>> k;
        --x;
        qx[nn] = x;
        qk[nn] = k;
        mp[x] = true;
    }
    rep(i,n){
        //頂点iから幅有線探索
        if(!mp[i])continue;
        vector<int> dist(n,-1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        ans[i][0] += i + 1;
        while(!q.empty()){
            int v = q.front(); q.pop();
            if(dist[v] >= 3) break;
            for(auto nv: to[v]){
                if(dist[nv] != -1) continue;
                dist[nv] = dist[v] + 1;
                ans[i][dist[nv]] += nv + 1;
                if(dist[nv] < 3)q.push(nv);
            }
        }
        For(j,1,4){
            ans[i][j] = ans[i][j-1] + ans[i][j];
        }
    }
    rep(nn,q){
        int x, k;
        x = qx[nn];
        k = qk[nn];
        cout <<ans[x][k] << '\n';
    }
}
