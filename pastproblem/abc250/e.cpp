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
vector<int> to[200'005];
//Write From this Line
int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i,n) cin >> a[i];
	rep(i,n) a[i]--;
	vector<int> b(n);
	rep(i,n) cin >> b[i];
	rep(i,n) b[i]--;
	// n * n の配列が出来るんだけど、この配列、横に見ると x -> o ... o -> x っていうふうになっているから, oの区間を見つけることが出来れば
	// bの中で各数字が最初に出てくる位置を保持しておきたい
	map<int, int> mp_b;
	rep(i,n){
		mp_b[b[i]] = i + 1; // 位置を１個プラスで覚えて貰う
	}
	map<int, bool> ex;
	map<int, bool> ex_b;
	int a_syu = 0;
	int b_syu = 0;
	int mae_ok = -1; //前状態までokだったところ
	int ato_ok = -1;
	int b_ind = 0;
	vector<P> ans(n,P(-1,-1));
	rep(i,n){
		int num = a[i];
		bool hueta = false;
		if(!ex[num]){
			hueta=true;
			ex[num]=true;
		}
		// 1つ前の状態ではa,bの先頭は一致していたが、aの要素が増えたかどうかで変わる
		if(hueta){
			a_syu++;
			// aの要素が増えたなら、伸ばせるかもしれないし、伸ばせないかもしれない
			// aに5が追加されたなら、Bで5か追加されるところまで足さないといけない
			// ... 5 の中に、aに出てない要素があったらダメ
			// ... 5 の中に、aに出てる要素があっても
			// そうして、初めて５が出てくるところを見つける
			//とりあえず、numが初めて出てくる位置
			// でもこれ、構造的に、次にないならダメってなってる気がする
			// huetaのが1⃣つじゃないって可能性もあるから、
			while(true){
				if(b_ind >= n) break;
				int num_b = b[b_ind];

				// aにあって、初登場かどうか
				if(ex[num_b]){
					// aにある場合取っていい
					// bの中で初登場かどうか
					if(ex_b[num_b]){
						//2回目以降の登場
					} else {
						//初登場
						b_syu++;
						ex_b[num_b] = true;
						//これによってa,bの種類数が一致するなら,ここからokが始まる
						if(a_syu == b_syu){
							mae_ok = b_ind;
							b_ind++;
							break;
						}
					}
					b_ind++;
				} else {
					// aに無いので、取っては行けない
					break;
				}
			}
			// mae_okを見つけたので、bを伸ばせるだけ伸ばす
			if(a_syu != b_syu){
				// 見つけられなかった
				continue;
			}
			ato_ok = mae_ok;
			while(true){
				if(b_ind >= n) break;
				int num_b = b[b_ind];
				// aに登場してるならok
				if(ex[num_b]){
					b_ind++;
					ato_ok++;
				}
				else {
					// aに到着してないならダメ
					break;
				}
			}
		} else {
			// aの要素が増えていないなら、bはこれ以上長くすることが出来ない。
			ans[i] = ans[i-1];
			continue;
			// bは伸びない
		}
		// i のときは、mae_okからato_okまで行ける
		ans[i] = P(mae_ok+1,ato_ok+1);
	}
	int q;
	cin >> q;
	rep(i,q){
		int x, y;
		cin >> x>> y;
		--x;
		if(ans[x].first <= y && y <= ans[x].second) coY();
		else coN();
	}
}
