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
    int t; cin >> t;
    vector<ll> A(t), b(t);
    rep(i,t) cin >> A[i] >> b[i];
    rep(i,t){
        bool end = false;
        ll a =A[i];
        ll s =b[i];
        bitset<62> bit1(a*2);
        bitset<62> bit2(s);
        bitset<62> bit3(a);
        bitset<62> make(s-2*a);
        cout << "bit1: " << bit1 << endl;
        cout << "bit2: " << bit2 << endl;
        cout << "bit3: " << bit3 << endl;
        cout << "make: " << make << endl;
        if(s < a){
            // 2*andのほうがsumよりデカかったら、もう無理
            if(2*a > s) coN();
            continue;
        }
        bool carry = false;
        bool ok = true;
        rep(i,62){
            // makeが作れるかどうかを判定する
            cout << i << ":carry =  " << carry << endl;
            if(make.test(i)){
                // 1が作れるかどうか
                if(carry){
                    if(bit3.test(i)){
                        // 元データがどっちも1なら、自然に1は作れる
                        carry = true;
                    } else {
                        // 元データが0なら、0にしとけば1が作れる
                        carry = false;
                    }
                } else {
                    //  carryが立っていないとき、1が作れるか
                    if(bit3.test(i)){
                        // 元データが立っているなら、 0になっちゃうので無理
                        cout << "dame: " << i << endl;
                        ok = false;
                        break;
                    } else {
                        // 元データが立っていないなら、片方を1にすればいいのでおk
                        carry = false;
                    }

                }
            } else {
                // 0が作れるかどうか
                if(carry){
                    // carryあり.どちらか片方を1にすればよい。元からどちらも1なら無理
                    if(bit3.test(i)){
                        cout << "dame: " << i << endl;
                        ok = false;
                        break;
                    } else {
                        // どちらか片方を1にする。carryが生じる
                        carry = true;
                    }
                } else {
                    //carry無しで0を作れるか
                    // carryがないなら、bit3(元データ)が1、0どちらでもok
                    if(bit3.test(i)) carry = 1;
                    else carry = 0;
                }
            }
        }
        if(ok) coY();
        else coN();
    }
}