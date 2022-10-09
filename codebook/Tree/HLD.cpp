int sze[MAX], mxchd[MAX], pa[MAX], dth[MAX], id[MAX], top[MAX];
int cnt;

void DFS(int u) {
  sze[u] = 1, mxchd[u] = -1;
  for (int v : G[u]) {
    if (v == pa[u]) continue;
    pa[v] = u;
    dth[v] = dth[u] + 1;
    DFS(v, u);
    sze[u] += sze[v];
    if (mxchd[u] == -1 || sze[mxchd] < sze[v])
      mxchd[u] = v;
  }
}

void build(int u, int t) {
  id[u] = ++cnt;
  top[u] = t;
  if (mxchd[u] == -1) return;
  build(mxchd[u], t);
  for (int v : G[u]) {
    if (v == pa[u] || v == mxchd[u]) continue;
    build(v, v);
  }
}

vector<pair<int, int>> qry(int a, int b) {
  vector<pair<int, int>> ret;
  int ta = top[a], tb = top[b];
  while (ta != tb) {
    if (dth[ta] < dth[tb]) swap(ta, tb), swap(a, b);
    ret.emplace_back(id[ta], id[a]);
    ta = top[a = pa[ta]];
  }
  ret.emplace_back(min(id[a], id[b]), max(id[a], id[b]));
  return ret;
}

// call DFS(root) and build(root, root) to initialize
// id[] is 1-indexed
// call qry(a, b) to split the path a -> b into segments