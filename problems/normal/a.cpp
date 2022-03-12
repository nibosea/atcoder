#include <bits/stdc++.h>

using namespace std;
// 計算時間を考慮し，答えが1~10の8乗の範囲にあるとする
const int MAX_N = 1e8;
//Write From this Line
int main()
{
    int n; cin >> n;
    // エラトステネスの篩
    vector<bool> is_prime(MAX_N,true);
    for(int i = 0; i <= 1; i++){
        is_prime[i] = false;
    }
    int cnt = 0;
    for(int i = 2; i < MAX_N; i++){
        if(is_prime[i]){
            cnt++;
            if(cnt == n){
                // n番目の素数が見つかったので出力する
                cout << i << endl;
                return 0;
            }
            for(int j = i; j < MAX_N; j += i){
                is_prime[j] = false;
            }
        }
    }
    // n番目の素数がMAX_Nまでに無ければ何も出力されずにプログラムは終了する
}