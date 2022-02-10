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
int n;
int a[20][20];
vector<P> vec;
bool used[20];
int calc(){
    if(vec.size() == n){
        int ret = 0;
        for(auto p:vec) ret ^= (a[p.first][p.second]);
        return ret;
    }
    int l;
    for(int i = 1; i <= 2*n;i++){
        if(!used[i]){
            l = i;
            break;
        }
    }
    used[l] = true;

    int ret = 0;
    for(int i = 1; i <= 2*n; i++){
        if(!used[i]){
            vec.push_back({l,i}), used[i] = true;
            ret = max(ret, calc());
            vec.pop_back(), used[i] = false;
        }
    }
    used[l] = false;
    return ret;
}
int main()
{
    cin >> n;
    For(i,1,2*n){
        For(j,i+1,2*n+1){
            cin >> a[i][j];
        }
    }
    // 2*n-1 * 2*(n-1)-1 * ... * 1 を実現したい
    // イメージとしてはDFS? 
    cout << calc() << endl;
}