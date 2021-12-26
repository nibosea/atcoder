#include <atcoder/modint>
#include <bits/stdc++.h>

using namespace std;
using mint = atcoder::modint998244353;

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for(auto &v:a){
        cin >> v;
        --v;
    }

    vector dp(n+1, vector(1<<d + d + 1, mint(0)));
    dp[0][(1<<d+1)-1] = 1;
    for (int i = 0; i < n; i++){
        for (int set = 1; set < (1 << d + d + 1); set += 2){
            const int newSet = set >> 1;
            
        }
    }
}
