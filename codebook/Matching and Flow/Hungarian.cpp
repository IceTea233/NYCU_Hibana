#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 7;

struct Hungarian {
  int x_sz, y_sz;
  vector<int> Gx[maxn]; // list of y-node connected to each x-node (1-based)
  int mx[maxn];
  int my[maxn];
  bool vy[maxn];

  void init(int n, int m) {
    x_sz = n;
    y_sz = m;
    memset(mx, 0, sizeof(int) * (x_sz + 1));
    memset(my, 0, sizeof(int) * (y_sz + 1));
    for (int i=1; i<=x_sz; i++) {
      Gx[i].clear();
    }
  }
  void connect(int x, int y) {
    Gx[x].push_back(y);
  }
  bool dfs(int x) {
    for (auto y : Gx[x]) {
      if (vy[y])
        continue;
      vy[y] = 1;
      if (!my[y] || dfs(my[y])) {
        mx[x] = y;
        my[y] = x;
        return true;
      }
    }
    return false;
  }
  vector<pair<int,int>> match() {
    vector<pair<int,int>> ans;
    for (int i=1; i<=x_sz; i++) {
      if (!mx[i]) {
        memset(vy, 0, sizeof(bool) * (y_sz + 1));
        dfs(i);
      }
    }

    for (int i=1; i<=x_sz; i++) {
      if (mx[i]) {
        ans.push_back({i, mx[i]});
      }
    }
    return ans;
  }
} match;
