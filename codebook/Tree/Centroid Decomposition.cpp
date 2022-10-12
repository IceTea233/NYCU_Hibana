// This is an example showing how to use this CD template to
// solve a global k-length path counting problem on a tree.

int n, k;
vector<int> G[maxn] = {};
bool vis[maxn] = {};
int cnt[maxn] = {};
int w[maxn] = {};

// calculate the subtree weight preparing for finding the centroid later.
void build_w(int x, int p=0) {
  w[x] = 1;
  for (auto &y : G[x]) {
    if (vis[y] || y == p)
      continue;
    build_w(y, x);
    w[x] += w[y];
  }
}

// Find the centroid of a given subtree.
int centroid(int x, int p, int M) {
  for (auto &y : G[x]) {
    if (vis[y] || y == p)
      continue;
    if (w[y] > M / 2)
      return centroid(y, x, M);
  }
  return x;
}
 
int ans = 0;

// Update cnt
void dfs1(int x, int p, int dep) {
  cnt[dep] ++;
  for (auto &y : G[x]) {
    if(vis[y] || y == p)
      continue;
    dfs1(y, x, dep+1);
  }
}
// calculate number of possible endpoint based one previous cnt info.
void dfs2(int x, int p, int dep) {
  if (k - dep >= 0)
    ans += cnt[k-dep];
  for (auto &y : G[x]) {
    if (vis[y] || y == p)
      continue;
    dfs2(y, x, dep+1);
  }
}
 
void cal(int x) {
  cnt[0] = 1;
  vis[x] = true;
  for (auto &y : G[x]) {
    if (vis[y])
      continue;
    dfs2(y, x, 1); // Calculate subtree answer first.
    dfs1(y, x, 1); // Then update cnt info.
  }
}

// The main CD recursive function.
// "x" can be any node initially
void solve(int x) {
  build_w(x);
  memset(cnt, 0, sizeof(int) * (k + 1));
  int c = centroid(x, 0, w[x]);
  if (w[x] > k) {
    cal(c); // Calculate on the subtree rooted at centroid
    for (auto &y : G[c]) {
      // If a neighboring node is unvisited,
      // solve the subtree on which the neighboring node is located.
      if (!vis[y])
        solve(y);
    }
  } else {
    vis[c] = true;
  }
 
}
