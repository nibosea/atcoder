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
int main()
{
	ll n, m;
	cin >> n>> m;
	ll q;
	cin >> q;
	vector<ll> A(q), B(q),C(q), D(q);
	rep(i,q){
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}
	rep(i,q){
		ll a, b, c, d;
		a = A[i], b = B[i], c = C[i], d= D[i];
		mint ans = 0;
		ll num_h = (b-a+1);
		ll num_w = (d-c+1);
		ll sum_r = (d-c+1) * (c+d) / 2;
		ans += mint(((num_h+1) / 2)) * mint(sum_r);
		if((num_h)%2==1){
			// 余った部分をdelete
			mint kou;
			bool an = 0;
			if((a+c)%2==1){
				// delete c,c+2,...,
				kou = (num_w+1) / 2; //kou := 消されるjの数
			} else {
				// delete c+1,c+3,...,
				an = 1;
				kou = (num_w) / 2;
			}
			mint del = ((kou) * mint(((c+an) + (c+an) + mint(2*(kou-1))))) / 2;
			ans -= del;
		}
		// 後は、Mが何回足されるかを考える
		mint Ms = 0;
		Ms += mint(((num_w+1)/2)) * mint((a+b-2)) * mint((num_h)) /2;
		//ans += m * ((num_w+1)/2) * (a+b-2) * (num_h) /2;
		mint start, end;
		if((num_w)%2==1){
			mint kou;
			if(((a+c)) % 2 == 1){
				start = a-1;
				kou = (num_h+1) / 2;
			} else {
				start = a;
				kou = (num_h) / 2; // huan
			}
			Ms -= (kou) * (mint(start*2) + (kou-1) * 2) / 2; 
		}
		ans += Ms * mint(m);
		cout << ans.val() << endl;
	}
}
