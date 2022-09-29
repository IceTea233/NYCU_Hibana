#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 5e5 + 7;
const int maxm = 30;

// count the patterns
struct AC_auto
{
  int nxt[maxn][maxm] = {};
  int fail[maxn] = {};
  vector<int> output[maxn]; // store pattern id on the node
  int cnt[maxn] = {};
  int id = 0; // simulated dynamic memory address

  int code(char c) { // encode character to numbers , 0 is reserved for "empty"
    return c - 'a' + 1;
  }
  int chd(int x, int c) { // if child doesn't exist, create one
    if (!nxt[x][c])
      nxt[x][c] = ++id;
    return nxt[x][c];
  }
  void insert(string &s, int pat_id, int cur = 0, int idx = 0) { // insert a pattern to trie
    if (idx == s.size()) {
      output[cur].push_back(pat_id); // add a tag for the pattern
      return;
    }
    insert(s, pat_id, chd(cur, code(s[idx])), idx + 1);
  }
  void build() { // build failure pointers
    queue<int> que;
    que.push(0);
    while (que.size()) {
      int goal = que.size();
      while (goal--) {
        int x = que.front();
        que.pop();
        for (int c = 1; c <= 26; c++) {
          if (nxt[x][c]) {
            int y = nxt[x][c];
            int z = fail[x];
            que.push(y);

            while (z && !nxt[z][c]) {
              z = fail[z];
            }
            if (x != z && nxt[z][c])
              fail[y] = nxt[z][c];
          }
        }
      }
    }
  }

  void scan(string &s) { // scan the trie with the base string
    int x = 0;
    for (auto &it : s) {
      while (x && !nxt[x][code(it)])
        x = fail[x];
      if (nxt[x][code(it)])
        x = nxt[x][code(it)];
      cnt[x] ++;
    }
  }

  vector<int> count(int k) { // return an array with count of inserted pattern
                             // numbered from 1 - k
    vector<int> ret(k+1, 0);
    vector<int> keep;
    queue<int> que;
    que.push(0);
    while (que.size()) { // record bfs-order series to keep[].
      int goal = que.size();
      while (goal--) {
        int x = que.front();
        keep.push_back(x);
        que.pop();
        for (int c=1; c<=26; c++) {
          if (nxt[x][c]) {
            que.push(nxt[x][c]);
          }
        }
      }
    }

    while (keep.size()) { // count from longest pattern to shortest
      int x = keep.back();
      keep.pop_back();
      for (auto it : output[x])
        ret[it] += cnt[x];
      cnt[fail[x]] += cnt[x]; // overlay the result to failure pointer
                              // (suffix pattern of current pattern)
    }
    return ret;
  }
} ac;
