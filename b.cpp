#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
#define fore(i, a) for(auto &i: a)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

void coY() {cout <<"Yes"<<endl;}
void coN(){cout <<"No"<<endl;}
void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const ll MOD = 998244353;
//Write From this Line
ll n;
vector<vector<int>> s;
vector<int> p;
void input(){
    cin >> n;
    s.resize(4,vector<int>(4));
    p.resize(n);
    rep(i,4)rep(j,4) cin >> s[i][j];
    rep(i,n) cin >> p[i];
}
int main()
{
    input();
    rep(k,n){
        rep(i,4)rep(j,4) if(p[k] == s[i][j]) s[i][j] = 0;
    }
    //rep(i,4){
    //    rep(j,4){
    //        cout << s[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    int ans = 0;
    vector<int> num(0);
    rep(i,4){
        int cnt = 0;
        int sum = 0;
        rep(j,4){
            sum += s[i][j];
            if(s[i][j] != 0) cnt++;
        }
        // cnt = 1の場合がリーチ
        if(cnt == 1){
            num.push_back(sum);
            ans++;
        }
    }
    rep(j,4){
        int cnt = 0;
        int sum = 0;
        rep(i,4){
            sum += s[i][j];
            if(s[i][j] != 0) cnt++;
        }
        // cnt = 1の場合がリーチ
        if(cnt == 1){
            num.push_back(sum);
            ans++;
        }
    }
    // 縦横に関してはこれでok
    // 正斜め
    int cnt = 0;
    int sum = 0;
    rep(k,2){
        rep(i, 4) {
            sum += s[i][i];
            if (s[i][i] != 0) cnt++;
        }
        if(cnt == 1){
            ans++;
            num.push_back(sum);
        }
        rep(j,4){
            REV(s[j]);
        }
    }
    SORT(num);
    if(ans) cout << num[0] << endl;
    else cout << "no" << endl;
}