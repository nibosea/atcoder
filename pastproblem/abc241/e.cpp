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
#define Per(i, a, b)    for(int i = (a) ; i>=(b);--i)
#define per(i, n)       Per(i,0,n)
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
ll N, K;
ll A[200009];
ll LastTime[200009];
ll LastCand[200009];
int main()
{
	cin >> N >> K;
	rep(i,N) cin >> A[i];

	ll CurrentTime = 0;
	ll CurrentCand = 0;
	rep(i,N) LastTime[i] = -1;
	rep(i,N) LastCand[i] = -1;
	ll u1 = 0, u2 = 0;
	ll CycleCand = 0;
	while(1){
		if(CurrentTime == K) {
			cout << CurrentCand << endl;
			return 0;
		}
		// 周期性が見つかった
		if(LastTime[CurrentCand%N] != -1){
			u1 = LastTime[CurrentCand%N];
			u2 = CurrentTime;
			CycleCand = CurrentCand - LastCand[CurrentCand%N];
			break;
		}
		LastTime[CurrentCand%N] = CurrentTime;
		LastCand[CurrentCand%N] = CurrentCand;
		CurrentTime++;
		CurrentCand += A[CurrentCand % N];
	}
	ll MaxCycles = (K-u2) / (u2-u1);
	ll FinalTime = u2 + MaxCycles * (u2-u1);
	ll FinalCand = CurrentCand + MaxCycles* CycleCand;
	ll period = u2 - u1;
	debug(period);
	ll period_num = CycleCand;
	debug(period_num);
	debug(FinalTime);


	debug(FinalCand);
	while(FinalTime<K){
		FinalTime += 1;
		debug(A[FinalCand%N]);
		FinalCand += A[FinalCand%N];
	}
	cout << FinalCand << endl;
}
