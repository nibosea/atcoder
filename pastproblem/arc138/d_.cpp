#include <iostream>
#include <vector>
using namespace std;

// a の i ビット目と j ビット目を swap する
void swa(int &a, int i, int j) {
    if ( (a & (1<<i)) && !(a & (1<<j)) ) a += -(1<<i) + (1<<j);
    else if ( !(a & (1<<i)) && (a & (1<<j)) ) a += (1<<i) - (1<<j);
}

// 0, 1, ..., n-1 ビット目を動かして、a を b にする
vector<int> solve(int n, int a, int b) {
    if (n == 1) return {a, b};
    
    // a^b の最高位が 1 でないときは 1 を見つけて swap する
    int exchange = n-1;
    int c = a^b;
    if (!(c & (1<<(n-1)))) {
        for (int d = 0; d < n-1; ++d) if (c & (1<<d)) exchange = d;
    }
    swa(a, n-1, exchange), swa(b, n-1, exchange);

    // 前半戦: テキトーに最後尾のビットを入れ替えておく
    int na = a & ~(1<<(n-1));
    auto zenhan = solve(n-1, na, na^1);

    // 後半戦
    int nb = b & ~(1<<(n-1));
    auto kouhan = solve(n-1, na^1, nb);

    // マージする
    vector<int> res;
    if (a & (1<<(n-1))) {
        for (auto v : zenhan) res.push_back(v ^ (1<<(n-1)));
        for (auto v : kouhan) res.push_back(v);
    }
    else {
        for (auto v : zenhan) res.push_back(v);
        for (auto v : kouhan) res.push_back(v ^ (1<<(n-1)));
    }

    // 最後に swap して戻す
    for (auto &v : res) swa(v, n-1, exchange);
    return res;
}

int main() {
    int N, A, B; cin >> N >> A >> B;
    int C = A ^ B;
    int bitcount = 0;
    for (int i = 0; i < N; ++i) if (C & (1<<i)) ++bitcount;
    if (bitcount % 2 == 0) {
        cout << "NO" << endl;
        return 0;
    }
    auto res = solve(N, A, B);
    cout << "YES" << endl;
    for (auto v : res) cout << v << " ";
    cout << endl;
}
