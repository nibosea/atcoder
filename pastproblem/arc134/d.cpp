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
    int n; cin >> n;
    vector<int> a(2*n);


    rep(i,2*n) cin >> a[i];
    vector<int> b = a;
    SORT(b);
    b.erase(unique(b.begin(),b.end()),b.end());

    vector<P> p(n);
    rep(i,a.size()){
        int ans = lower_bound(b.begin(),b.end(), a[i])-b.begin();
        //cout << ans << " ";
        if(i<n){
            p[i%n].first = ans;
        } else {
            p[i%n].second = ans;
        }
    }
    //rep(i,n){
    //    printf("%d,%d\n", p[i].first, p[i].second);
    //}
    // first最小で、同じ組について、secondのほうが小さいものがあれば、secondが最も小さいものをとる。(1個でいい)
    int m = inf;
    rep(i,n){
        chmin(m,p[i].first);
    }
    //debug(m);
    int m2 = inf;
    int ind = -1;
    bool flag = false;
    rep(i,n){
        if(chmin(m2,p[i].second)){
            ind = i;
        }
    }
    if(m2<m){
        flag = true;
    }
    if(flag){
        // 1要素だけで成立する
        cout << a[ind] << " " << a[ind+n] << endl;
    } else {
        //違うかもしれないけど、first m の物の一番最初のsecondより小さいのをメモしておく
        // priority_queueでごにょごにょできないかな…
        map<int,int> mp;
        // p[i].firstを見る
        priority_queue<int, vector<int>, greater<int>> pq;
        rep(i,n){
            int num = p[i].first;
            if(mp[num] == 0){
                pq.push(num);
            }
            mp[num]++;
        }
        // pqから1個取り出して、そいつを見つけたら答えの集合に追加する
        int target = pq.top(); pq.pop();
        //debug(target);
        int target2 = -1;
        bool dekaku = false;
        vector<int> ans(0);
        int memo = -1;
        rep(i,n){
            //debug(target);
            mp[p[i].first]--;
            //debug(p[i].first);
            if(p[i].first == target){
                if(target2==-1){
                    target2 = p[i].second;
                    memo = target2;
                }
                else {
                    if(memo < p[i].second) dekaku = true;
                    memo = p[i].second;
                }
                //debug(i);
                ans.push_back(i);
            }
            while(!pq.empty() && mp[target] == 0){
                target = pq.top(); pq.pop();
            }
            if(target> target2) break;
            if(target2 != -1 && target>=target2){ // TODO: target == target2の場合がわからない
                //if(target == target2){
                    //if(!dekaku) break;
                }
            }
        }
        rep(i,ans.size()){
            cout << a[ans[i]] << " ";
        }
        rep(i,ans.size()){
            cout << a[ans[i]+n] << " ";
        }
        cout << endl;
    }
}