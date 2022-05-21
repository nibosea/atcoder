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
	string s;
	cin >> s;
	vector<int> ns(n);
	rep(i,n){
		if(s[i] == 'A') ns[i] = 0;
		else if(s[i] == 'R') ns[i] = 1;
		else if(s[i] == 'C') ns[i] = 2;
	}
	// A(ARC)C となっているものがあれば、A "R" C にすることが出来て、操作回数が一回増える
	// AA(ARC)CC となっていれば2回増えるかもしれないし、増えないかもしれない…　偶数奇数による
	// x個のA, ARC, y個のC となっているようなものについて、min(x,y)回操作を行える見込みがある。
	// 偶数回目に行いたいような場所と、奇数回目に行いたいようなものの数、つまり AA(ARC)CCとなっていないようなものを数える
	// で、これは島ごとに分けて考えなきゃいけなそうだから、pqueにでも突っ込んでおく
	// search A -> R -> Cの順番、
	// A..A R..R のように、Rが複数個並んでいてもしょうがない
	int search = 0;
	vector<int> vec(0);
	vector<int> cnt(3,0);
	auto sei = [&]() {
		if(cnt[1] == 0){
			// 'R'が出てこない場合は、ARCが一回も発生しないのでスルーして良い
			return 0;
		}
		if(cnt[1] >= 2) return 0;
		int x = cnt[0];
		int y = cnt[2];
		int m = min(x,y); 
		// 最大で,m回ARCを作ることが出来る
		vec.push_back(m);
		rep(i,3) cnt[i] = 0;
		return 1;
	};
	rep(i,n){
		int now = ns[i];
		if(search-1 == now || (now == 1 && search == 1) || (now == 2 && search == 0)){
			// (C->R, R->A) ,, R->R , A->C
			//  A-> C , R -> A,  R -> R , C -> Rはダメ
			rep(j,3) cnt[j] = 0;
			search = 0;
			if(now == 0) {
				cnt[now] = 1;
			}
		}
		else if(search == 2 && now == 0){
			// C -> 'A',
			// 'A'が出てきたら、それまでの精算を行う
			sei();
			search = 0;
			cnt[now]++;
		} else if(now == search){
			cnt[now]++;
		} else {
			// a->r , r->c, のパターン
			search++;
			cnt[now]++;
		}
	}
	sei();
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
			kamo++;
		}
		if(vec[i] >= 3){
			// kamoがあればたくさんシコれる
			// vec[i] -> kamo -> vec[i] -> kamo -> vec[i]という手順を踏めばいい
			// kamoの回数 だけ復活できる
			while(vec[i]>=2&& kamo){
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
				kamo++;
			}
		}
	}
	cout << ans << endl;
}
