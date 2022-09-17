#include <bits/stdc++.h>
using namespace std;
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)

template <class T> T maximize(const vector<T>& a) {
    T s = 0, t = 0;
    for (const T& x: a){
        const T u = max(s, t) + x;
        s = t;
        t = u;
    }
    return max(s, t);
}

template <class T, class F> T binary_search_lambda(T ok, T ng, const F& check){
    while (abs(ok - ng) > 1){
        const T md = (ok + ng) / 2;
        if(check(md)){
            ok = md;
        } else {
            ng = md;
        }
    }
    return ok;
}

using i64 = int64_t;

template <int n> constexpr i64 pow10 = pow10<n - 1> *10;
template <> constexpr i64 pow10<0> = 1;

int main(){
    int n; cin >> n;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    vector<i64> b(n);
    const i64 average = binary_search_lambda<i64>(0, pow10<12>+1, [&](const i64 thres){
        rep(i,n){
            b[i] = a[i] * pow10<3> - thres;
        }
        return maximize(b) >= 0;
    });
    vector<int> c(n);
    const i64 median = binary_search_lambda<int>(0, pow10<9>+1, [&](const int thres){
        rep(i,n){
            c[i] = a[i] >= thres ? 1: -1;
        }
        return maximize(c)>0;
    });
    cout << average / pow10<3> << "." << setw(3) << setfill('0') << average % pow10<3> << '\n';
    cout << median << '\n';
    return 0;
}