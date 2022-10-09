int dfs[MAX], low[MAX];

void DFS(int u, int pa) {
  dfs[u] = low[u] = ++cnt;
  int chd_cnt = 0;
  for (int v : G[u]) {
    if (v == pa) continue;
    if (!dfs[u]) {
      chd_cnt++;
      DFS(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] >= dfs[u] && pa != -1) {
        // u is a non-root AP
      } else if (dfs[v] < dfs[u]) {
        low[u] = min(low[u], dfs[v]);
      }
    }
  }  
  if (pa == -1 && chd_cnt > 1) {
    // the root of the tree is an AP
  }
}

// G[] : adjacency list
