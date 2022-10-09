int dfs[MAX], low[MAX];

void DFS(int u, int pa) {
  dfs[u] = low[u] = ++cnt;
  for (int v : G[u]) {
    if (v == pa) continue;
    if (!dfs[u]) {
      DFS(v, u);
      low[u] = min(low[u], low[v]);
      if (low[v] > dfs[u]) {
        // Edge(u, v) is a bridge.
      }
    } else if (dfs[v] < dfs[u]) {
      low[u] = min(low[u], dfs[v]);
    }
  }
}

// G[] : adjacency list
