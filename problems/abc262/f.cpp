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
const ll INF = 9'000'000'000'000'000'000;
vector<int> to[200'005];
//Write From this Line
int main()
{
	int n, k;
	cin >> n>> k;
	vector<int> a(2*n);
	rep(i,n) cin >> a[i];
	rep(i,n){
		a[n+i] = a[i];
	}
	if(k == 0){
		rep(i,n){
			cout << a[i] << " ";
		}
		cout << endl;
		return 0;
	}
	if(k==n-1){
		cout << 1 << endl;
		return 0;
	}
	// rotateする位置を全探索出来ないだろうか
	// 先頭の最小文字
	int m = a[0];
	int index = 0;
	for(int i = 1; i <= k; i++){
		if(m < a[n-i]) continue; // どうせ小さくならないのでやるまでもない
		if(chmin(m,a[n-i])){
			index = i;
		}
		// a[i]を先頭にもってくる
		// debug(a[n-i]);
		int left = k -i;
		//debug(left);
		// left回だけ他のやつ殺したりして遊ぶことが出来る
	}
	debug(m);
	debug(index);
	// mを先頭にもってくるのが偉い
	// それ以降、Rotateは行わなくていい。
	vector<int> kari(n);
	int start = n-index;
	if(start == n) start = 0;
	rep(i,n){
		kari[i]= a[start++];
	}
	for(auto x: kari){
		cout << x << " ";
	}
	cout << endl;
	int del = k - index;
	//  消せたはずの過去は何個？
	int kako = index - 1;
	debug(del);
	map<int, bool> mp; //消したものをメモる用
	// kariを最適化する
	vector<int> kari2(0);
	int M = inf;
	int charge = 0;
	deque<int> deq;
	deq.push_front(kari[0]);
	deq.push_back(inf);
	int last = 0;
	For(i,1,n){
		debug(i);
		if(chmin(M,kari[i])){
			debug(kari[i]);
			if(del >= charge){
				del -= charge;
				// kari[i]を使う(暫定)
				deq.pop_back();
				deq.push_back(kari[i]);
				last = i;
				charge = 1;
			} else {
				// 消すことが出来ない；；
				deq.push_back(kari[i]);
				last = i;
			}
		}
	}
	For(i,last+1,n){
		deq.push_back(kari[i]);
	}
	puts("nya");
	while(!deq.empty()){
		cout << deq.front() <<  " ";
		deq.pop_front();
	}
	cout << endl;
}
