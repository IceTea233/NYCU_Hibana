#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e2 + 7;
const int maxm = 1e3 + 7;
const int INF = 1e18; // Notice: 1e9 might not be large enough

struct dinic {
  int n, m; // num of vertex, num of edges
  int s, t; // source and toward
  vector<int> G[maxn]; // Graph
  int cap[maxn][maxn]; // capacity
  int flow[maxn][maxn];
  int lev[maxn]; // shortest distance from source
  bool vis[maxn];

  dinic(int _n, int _m) { // initialize
    n = _n;
    m = _m;
    memset(cap, -1, sizeof(cap)); // -1 means no edge
    memset(flow, 0, sizeof(flow));
    for (int i=0; i<=n; i++) {
      G[i].clear();
    }
  }

  void add_edge(int u, int v, int c) { // directed
    if (cap[u][v] == -1) {
      G[u].push_back(v);
      cap[u][v] = 0;
    }
    if (cap[v][u] == -1) {
      G[v].push_back(u);
      cap[v][u] = 0;
    }
    cap[u][v] += c;
  }

  int bfs() {
    memset(lev, 0, sizeof(lev));
    queue<int> que;
    lev[s] = 1;
    que.push(s);
    while (!que.empty()) {
      int x = que.front();
      que.pop();
      for (auto y : G[x]) {
        if (!lev[y] && cap[x][y] > flow[x][y]) { // touch if capacity is not filled
          lev[y] = lev[x] + 1;
          que.push(y);
        }
      }
    }
    return lev[t];
  }

  int dfs(int x, int mf) {
    int f = mf;
    if (x == t)
      return mf;
    for (auto y : G[x]) {
      if (lev[y] == lev[x] + 1 && cap[x][y] > flow[x][y]) {
        int t = dfs(y, min(f, cap[x][y] - flow[x][y]));
        flow[x][y] += t;
        flow[y][x] -= t;
        f -= t;
      }
      if (f == 0)
        break;
    }
    return mf - f;
  }

  int max_flow(int _s, int _t) {
    s = _s;
    t = _t;
    int ret = 0;

    while (bfs()) {
      int add;
      while (add = dfs(s, INF)) {
        ret += add;
      }
    }
    return ret;
  }
};
