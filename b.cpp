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
ll t;
ll n;
vector<P> p;
void input(){
    cin >> n;
    p.resize(n);
    rep(i,n){
        cin >> p[i].first >> p[i].second;
    }
}
int main()
{
    cin >> t;
    while(t--){
        input();
        map<int,int> L, R;
        rep(i,n){
            L[p[i].first] ++;
            R[p[i].first] ++;
        }
        queue<int> ql, qr;
        for(auto x:L) ql.push(x.first);
        for(auto x:R) qr.push(x.first);
        for(auto x:L){
            //printf("(L, num) = (%d,%d)\n",x.first,x.second);
        }
        int have = 0;
        int pre = 0;
        int sum = 0;
        int nes = 0;; // 捨てるべき個数の合計
        bool flag = true;
        while(!qr.empty()){
            while(!ql.empty() && qr.front() >= ql.front()){
                //持てるだけ持つ。
                have += L[ql.front()]; ql.pop();
            }
            //debug(have);
            int end = qr.front(); // endで捨て処理をおこなう。
            qr.pop();
            // end-pre個捨てることが出来る
            nes += R[end];
            int sute = min(have, end-pre);
            have -= sute;
            sum += sute; // 捨てた個数の合計
            pre = end;
            if(nes > sum) flag = false;
        }
        if(flag) coY();
        else coN();
    }
}