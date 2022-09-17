#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

using ll = long long;
typedef pair<ll,ll> P;
#define SORT(a) sort((a).begin(),(a).end())
#define REV(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(ll i = (a) ; i < (b) ; ++i)
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

const ll dy[] = {0,0,1,-1};
const ll dx[] = {1,-1,0,0};
const ll mod = 1e9+7;
const ll MOD = 998244353;
using mint = modint998244353;
const double PI=3.14159265358979323846;
const ll inf = 1001001001;
const ll INF = 9'000'000'000'000'000'000;

vector<ll> to[200'005];
//Write From this Line
int main() {
	int h, w;
	cin >> h>> w;
	vector A(h,vector<int>(w));
	rep(i,h)rep(j,w) cin >> A[i][j];
	int h2, w2;
	cin >> h2>> w2;
	vector B(h2,vector<int>(w2));
	rep(i,h2)rep(j,w2) cin >> B[i][j];
	// 行列の削除を好きなだけ行う
	// h - h2 行 Del , w-w2 列 Del
	//削除する行や列を全探索すればいいBit全探索
	for(int i = 0; i < (1 << (h)); i++){
		bitset<10> tmp(i);
		int cnt = tmp.count();
		if(cnt != (h-h2)) continue;
		for(int j = 0; j < (1 <<(w)); j++){
			bitset<10> tmp2(j);
			cnt = tmp2.count();
			if(cnt != (w-w2)) continue;
			//cnt が消す行のかず
			// true?
			int i1 = 0;
			int i2 = 0;
			bool flag = true;
			rep(x,h){
				if(tmp.test(x)) continue;
				rep(y,w){
					if(tmp2.test(y)) continue;
					if(A[x][y] == B[i1][i2]){
						// ok
						i2++;
						if(i2 >= w2){
							i2 = 0;
							++i1;
						}
					} else {
						// dame
						flag = false;
						break;
					}
				}
				if(!flag) break;
			}
			if(flag){
				coY();
				return 0;
			}
		}
	}
	coN();
}
