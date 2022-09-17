#include <bits/stdc++.h>

using namespace std;
using ll = long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)

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
	int n, k; 
	cin >> n>> k; 
	vector<P> a(k);
	vector<P> b(n-k);
	rep(i,k) {
		int x;
		cin >> x;
		a[i] = P(x,i);
	}
	For(i,k,n){
		int x;
		cin >> x;
		b[i-k] = P(x,i);
	}
	SORT(a);
	REV(a);
	SORT(b);
	// aの大きいものから考える
	REV(b);
	puts("配列 a");
	for(auto x: a){
		cout << x.first << " ";
	}
	cout << endl;
	puts("配列 b");
	for(auto x: b){
		cout << x.first << " ";
	}
	cout << endl;
	
	priority_queue<int, vector<int>, greater<int>> pq; // ヒープ
	int ans = inf;
	int L = 0; // bのどこまで見たかっていうindex
	rep(i,k){
		// aの各添字iについて、どこと交換するのがベストかを求める
		int num = a[i].first;

		// bのなかから、numよりも大きいものだけをpushする
		while(L < n-k && b[L].first > num){
			pq.push(b[L].second);
			L++;
		}
		if(pq.empty()){
			continue;
		}
		int next = pq.top();
		int mae = a[i].second;
		// mae nextを交換
		// 各iについて、最適な位置との交換するときの手数でansを更新する
		chmin(ans, next-mae);
	}
	if(ans == inf) cout << -1 << endl;
	else cout << ans << endl;
}
