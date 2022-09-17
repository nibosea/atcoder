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
    string s; cin >> s;
    vector<int> cnum(26,0);
    rep(i,n){
        char c = s[i]; 
        cnum[c-'a']++;
    }
    rep(i,26){
        //cout << cnum[i] << " " ;
    }
    int left = 0; int right = n-1; // left,rightはまだ考慮の予知がある
    while(left < right){
        //debug(left);
        char cl = s[left];
        int nl = cl - 'a';
        // nlよりも小さい添え字のcr, nrがあるかを探せばいい
        bool flag = false;
        int target = -1;
        rep(i,nl){
            if(cnum[i]>0) {
                flag=true;
                target=i;
                break;
            }
        }
        cnum[nl]--;//変えるやつがあるにせよ無いせよ、leftはもう使えない
        if(flag){
            // 変えるべき対象がある
            while(s[right]-'a'!=target){
                int rnum = s[right]-'a';
                cnum[rnum]--;
                right--;
            }
            // 変えるやつが見つかった
            cnum[s[right]-'a']--;
            swap(s[left],s[right]);
            right--;
        } else {
            //変えるべき対象がない
        }
        left++;
    }
    cout << s << endl;
}