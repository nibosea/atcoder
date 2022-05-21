#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using ll = long long;
typedef pair<int,int> P;
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

void mswap(ll &a, ll &b){ if(a >= b) swap(a,b); }
void rswap(ll &a, ll &b){ if(a <= b) swap(a,b); }

const int dy[] = {0,0,1,-1};
const int dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
const double PI=3.14159265358979323846;
const int inf = 1001001001;
const ll INF = 1'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	int n;
	cin >> n;
	vector<int> vec(n);
	rep(i,n) cin >> vec[i];
	SORT(vec);
	if(vec.size() == 0){
		cout << 0 << endl;
		return 0;
	}
	// vec[i] == 2でかつ奇数回目で回ってきたら、自己オナニーで完結
	int ans = 0;
	int kamo = 0;
	rep(i,vec.size()){
		if(vec[i] == 1){
			ans++;
			kamo++;
		} 	
		if(vec[i] == 2){
			ans += 2;
		}
		if(vec[i] >= 3){
			// kamoがあればたくさんシコれる
			// vec[i] -> kamo -> vec[i] -> kamo -> vec[i]という手順を踏めばいい
			// kamoの回数 だけ復活できる
			while(vec[i] && kamo){
				vec[i]--;
				kamo--;
				ans++;
			}
			// 今、気持ちよく終わってるんだけど、vec[i]が残っていたら,一発抜ける
			if(vec[i]==1){
				ans++;
				kamo++;
			} else if (vec[i] >= 2){
				ans+=2;
			}
		}
	}
	cout << ans << endl;
}
