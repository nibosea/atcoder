#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
int main(){
    int n, m, k;
    cin >> n>> m>> k;
    vector<vector<long long>> dp(n,vector<long long> (m, 0));
    for(int i = 0; i<m; i++){
        dp[0][i] = 1;
    }
    for(int i = 0; i < n - 1; i++){
        vector<long long> s(m+1);
        s[0] = 0;
        for(int j = 0; j < m; j++){
            s[j+1] = s[j] + dp[i][j];
            s[j+1] %= mod;
        }
    }
}
