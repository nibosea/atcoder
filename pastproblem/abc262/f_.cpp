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
	vector<int> a(n);
	rep(i,n) cin >> a[i];
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
	int m = a[0];
	int index = 0;
	for(int i = 1; i <= k; i++){
		if(m < a[n-i]) continue; // どうせ小さくならないのでやるまでもない
		if(chmin(m,a[n-i])){
			index = i;
		}
	}
	vector<int> kari(0);
	if(index > 0){
		for(int i = n-index; i < n; i++){
			kari.push_back(a[i]);
		}
	}
	vector<int> kari2(0);
	// いるものだけ使う kari2は、好きなものを消していい
	deque<int> deq;
	deq.push_front(kari[0]);
	deq.push_back(inf);
	For(i,1,kari.size()){
		while(!deq.empty()){
			if(deq.back() > kari[i]){
				deq.pop_back();
			} else break;
		}
		deq.push_back(kari[i]);
	}
	if(deq.back() == inf) deq.pop_back();
	vector<int> kori(0);
	for(int i = 0; i < (n-index); i++){
		kori.push_back(a[i]);
	}
	// koriからdel個まで消していい
	int del = k - index;
	deque<int> deq2;
	deq2.push_back(inf);
	del++;
	For(i,0,kori.size()){
		while(!deq2.empty()){
			if(del<=0)break;
			if(deq2.back() > kori[i]){
				deq2.pop_back();
				del--;
			} else {
				break;
			}
		}
		deq2.push_back(kori[i]);
	}
	if(!deq2.empty()){
		if(deq2.front() == inf) deq2.pop_front();
	}
	while(!deq.empty()){
		if(!deq2.empty()){
			if(deq.front() > deq2.front()) {
				deq.pop_front();
				continue;
			}
		}
		cout << deq.front() <<  " ";
		deq.pop_front();
	}
	while(!deq2.empty()){
		cout << deq2.front() <<  " ";
		deq2.pop_front();
	}
	cout << endl;
}
