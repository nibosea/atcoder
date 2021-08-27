#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
using P = pair<int,int>;

void solve() {
  int n;
  cin >> n;
  vector<P> p(n);
  rep(i,n) cin >> p[i].first >> p[i].second;
  sort(p.begin(), p.end());
  priority_queue<int, vector<int>, greater<int>> q;
  int x = 1;
  const int INF = 1001001001;
  p.emplace_back(INF, INF);
  for (auto [l, r) : p) {
    while (x < l && q.size()) {
      if (q.top() < x) {
        cout << "No" << endl;
        return;
      }
      q.pop();
      ++x;
    }
    x = l;
    q.push(r);
  }
  cout << "Yes" << endl;
}

int main() {
  int T;
  cin >> T;
  rep(ti,T) solve();
  return 0;
}