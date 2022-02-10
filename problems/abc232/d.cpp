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
int main()
{
    int h,w;
    cin >>h>>w;
    vector<string> field(h);
    rep(i,h) cin>>field[i];

    vector<vector<int>> cost(h,vector<int>(w,-1));
    cost[0][0] = 1;
    queue<P> q;
    q.push(P(0,0));

    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front(); q.pop();
        //printf("x,y: %d, %d\n", x, y);
        rep(i,4){
            int nx, ny;
            int d = dx[i] + dy[i];
            if(d <= 0) continue;
            nx = x + dx[i]; 
            ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if(field[nx][ny] == '#') continue;
            if(cost[nx][ny]!=-1) continue;
            cost[nx][ny] = cost[x][y] + 1;
            q.push(P(nx,ny));
        }
    }
    int ans = 1;
    rep(i,h){
        rep(j,w){
            chmax(ans,cost[i][j]);
        }
        //cout << endl;
    }
    cout << ans << endl;
}