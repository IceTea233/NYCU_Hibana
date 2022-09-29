#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 7;
const int bits = 25;

vector<int> G[maxn];
int in[maxn] = {};
int anc[maxn][bits] = {};

int id = 0;
void build(int x, int p) { // 0 is the fake parent of root
  in[x] = ++id;
  anc[x][0] = p;
  for (int i = 0; anc[x][i]; i++)
    anc[x][i + 1] = anc[anc[x][i]][i];
  for (auto &y : G[x]) {
    if (y == p)
      continue;
    build(y, x);
  }
}

int lca(int a, int b) {
  if (a == b)
    return a;
  if (in[a] > in[b])
    swap(a, b);
  for (int i = bits - 1; i >= 0; i--) {
    if (in[a] < in[anc[b][i]])
      b = anc[b][i];
  }
  return anc[b][0];
}
