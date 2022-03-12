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

void coY() {cout <<"Takahashi"<<endl;}
void coN(){cout <<"Aoki"<<endl;}
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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    // 高橋君目線で考えると、A以上B以下の数字の中でxを選ぶ。、x+C～x+Dが全て素数じゃないとき、勝てる
    // 2~200が素数かどうかのフィールドを持てばいい
    vector<bool> p(1000,true);
    p[0] = false;
    p[1] = false;
    For(i,1,1000){
        if(p[i]){
            int j = i + i;
            while(j < 1000){
                p[j] = false;
                j+=i;
            }
        }
    }
    for(int x = a; x <= b; x++){
        bool flag = true;
        for(int y = c; y<=d; y++){
            if(p[x+y]==true){
                //青木が勝てちゃう
                flag = false;
                break;
            }
        }
        if(flag){
            coY();
            return 0;
        }
    }
    coN();
}