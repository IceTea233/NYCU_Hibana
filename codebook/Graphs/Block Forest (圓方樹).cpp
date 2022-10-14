#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 7;

// "Centroid" nodes would be numbered after original nodes.
// Note: Here we define a "component" to be a graph that can not be "disconnected"
// by remove a nodes. So, a pair of connected nodes is also a component.
// Properties of Block Forest:
//  1. Every "circle" is NOT connected to another one.
//  2. Every "circle" in the same component connect to the same "square"
//  3. Every "circle" connect to at most 1 "square"
//  4. Every "square" connect to another "square" if the component they
//      represents are adjacent in the original graph.
vector<int> G[maxn]; // Given Graph
vector<int> G2[maxn]; // Block Forest Graph
vector<int> in; // time stamp for dfs
vector<int> low; // tarjan low value
vector<int> stk; // dfs recorder

int n, m; // the # of nodes and edges of the given graph
int id1; // maximal id of original nodes
int id2; // maximal id of "centroid" nodes
 
void reset() {
    for (int i=1; i<=n*2; i++) {
        G[i].clear();
        G2[i].clear();
    }
    in.assign(n + 1, 0);
    low.assign(n + 1, 0);
    id1 = 0;
    id2 = n;
    stk.clear();
}
 
// Add a "square" in G2 connected to node set "g".
void addSquare(int x, vector<int> g) {
    id2 ++;
    for (auto & it : g) {
        G2[id2].push_back(it);
        G2[it].push_back(id2);
    }
}

// Use tarjan-like dfs to build a block forest.
void dfs(int x, int p) {
    in[x] = ++id1;
    low[x] = id1;
    stk.push_back(x);
    for (auto y : G[x]) {
        if (y == p)
            continue;
        
        if (in[y]) {
            low[x] = min(low[x], in[y]);
            continue;
        }
 
        dfs(y, x);
        low[x] = min(low[x], low[y]);
 
        if (in[x] == low[y]) {
            // x is an AP and a component is found!
            // Flush the component nodes and add a square.
            vector<int> buff;
            while (stk.back() != x) {
                buff.push_back(stk.back());
                stk.pop_back();
            }
            buff.push_back(x);
            addSquare(x, buff);
        }
    }
    
    // A bridge is between x and y, forming a special case of component.
    if (low[x] == in[x]) {
        vector<int> buff({p, x});
        stk.pop_back();
        if (p != -1) {
            addSquare(p, buff);
        }
    }
}
