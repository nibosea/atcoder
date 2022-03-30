#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using ll = long long;
typedef pair<int,int> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define Per(i, a, b)    for(int i = (a) ; i>=(b);--i)
#define per(i, n)       Per(i,n,0)
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
vector<int> to[200500];
int main()
{
	int n;	
	cin >> n;	
	vector<P> p(n+1);
	rep(i,n) cin >> p[i].first >> p[i].second;
	int M = 0;
	rep(i,n){
		chmax(M,p[i].first+p[i].second);
	}
	p[n] = P(M,0);
	SORT(p);

	// 含まれている日数だけで見てやる良さそう♡
	vector<int> ans(n+1,0);
	// INF日に開始した人を0人追加しておく
	int days = 0; //処理し終わった日付
	int human = 0;

	priority_queue<int, vector<int>, greater<int>> pq;
	rep(i,n+1){
		auto [day,num] = p[i]; //今の日にち、何日後までサービスをするのか
		pq.push(day);// day-1日目まで処理しないといけない
		// day-1日目までを処理する
		// day以下は取り除かないといけない
		ll next_human = human;
		while(!pq.empty() && pq.top() <= day) {
			ll now = pq.top(); pq.pop();
			next_human--;
			while(!pq.empty()&&pq.top()==now){
				pq.pop();
				next_human--;
			}
			// 前回の日にちから、now-1日まではhuman人
			ll cnt = now-1 - days + 1;
			ans[human] += cnt;
			human = next_human;
			if(now==day) human++;
			days=now;
		}
		human++;
		pq.push(day+num);
	}
	rep(i,n){
		cout << ans[i+1] << " ";
	}
	cout << endl;
}
