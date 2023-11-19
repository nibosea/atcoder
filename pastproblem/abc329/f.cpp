#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
int main()
{
  int n, q;
  cin >> n >> q;
  vector<unordered_set<int>> s(n);
  rep(i,n) {
    int c; cin >> c;
    s[i].insert(c);
  }

rep(qi,q) {
    int a, b;
    cin >> a >> b;
    --a; --b;
    if (s[a].size() > s[b].size()) swap(s[a],s[b]);
    s[b].merge(s[a]);
    s[a] = {};
    cout << s[b].size() << '\n';
  }
  return 0;
}