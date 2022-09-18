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
void coN(){cout <<-1<<endl;}
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
vector<ll> pos[300'005];
vector<ll> n_pos[300'005];

//Write From this Line
int main()
{
	ll n, k;
	cin >> n>> k;
	vector<ll> first(n+1,-1);
	vector<ll> last(n+1,-1);
	vector<int> nidotuke(n+1,0);
	For(i,1,n+1){
		// i が使えるようになる場所、使えなくなる場所を格納する
		ll fi = i - k;
		// iのk個前の値は？
		if(fi >= 1){
			n_pos[1].push_back(i);
			ll ato = i + k;
			if(ato <= n) {
				n_pos[ato].push_back(i);
			}
		}
		else {
			ll ato = i + k;
			if(ato <= n) {
				n_pos[ato].push_back(i);
			}
		}
		// 使えなくなるところ
		ll la = i - k;
		if(la >= 1){
			pos[la].push_back(i);
			nidotuke[i]++;
			la = i + k;
			if(la <= n){
				pos[n].push_back(i);
				nidotuke[i]++;
			}
		} else {
			la = i + k; // i + k以降なら使えるよ
			if(la <= n) {
				pos[n].push_back(i);
				nidotuke[i]++;
			}
		}
	}
	// 最初と最後は出したけど、iの最後の位置ではなく、位置hogeに対して最後の出現の数字を求めたい
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	vector<bool> used(n+1,false);
	vector<bool> can_use(n+1,false);
	vector<ll> ans(n,-1);
	For(i,1,n+1){
		for(auto x:n_pos[i]){
			if(used[x]) continue;
			if(!used[x]){
				pq.push(x);
				can_use[x] = true;
			}
		}
		// ここで使えなくなる数字を見てみる
		ll next = 0;
		for(auto ng: pos[i]){
			// ngがここでしか使えないなら、使わないといけない
			//cout << "使わないと！！: " << ng << endl;
			if(used[ng]) continue;//既に使っていれば問題ない
			if(2==nidotuke[ng]){
				// 2度漬ok商品だったら、後に回しても良い
				ll tp = inf;
				while(!pq.empty()){
					tp=pq.top();
					if(!can_use[tp] || used[tp]){
						pq.pop();
						continue;
					} else {
						break;
					}
				}
				if(tp < ng){
					// tpにしたほうがお得だから、使わないという選択肢を取ればいい
					nidotuke[ng]--;
					can_use[ng] = false;
					//一旦使えなくなる
					break;
				}
			}
			if(can_use[ng]){
				// ここで使わなきゃ
				ans[i] = ng;
				used[ng] = true;
				can_use[ng] = false;
				next ++;
			} else {
				coN();
				return 0; 
				// 使えないならだめ。GG
			}
		}
		if(next >= 2){
			coN();
			return 0;
		}
		if(next == 1) continue;
		// 何も処理していないので、最低を使ってやればいい
		while(true){
			if(pq.empty()){
				coN();
				return 0;
			}
			ll tp = pq.top();
			if(!can_use[tp]){
				pq.pop();
				continue;
			}
			pq.pop();
			if(used[tp]) continue;
			if(!used[tp]){
				used[tp] = true;
				can_use[tp] = false;
				ans[i] = tp;
				break;
			}
		}
	}
	For(i,1,n+1){
		ll diff = abs(ans[i] - i);
		if(diff < k){
			coN();
			return 0;
		}
	}
	For(i,1,n+1){
		cout << ans[i] << " ";
	}
	cout << endl;
}
