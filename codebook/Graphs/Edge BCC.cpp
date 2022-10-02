stack<int> stk;
int dfs[MAX], low[MAX];
vector<int> bcc[MAX];
int bcc_cnt;

void DFS(int u, int pa) {
	dfs[u] = low[u] = ++cnt;
	stk.push(u);
	for (int v : G[u]) {
		if (v == pa) continue;
		if (!dfs[u]) {
			DFS(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] > dfs[u]) {
				bcc_cnt++;
				while (stk.top() != v) {
					bcc[bcc_cnt].push_back(stk.top());
					stk.pop();
				}
				bcc[bcc_cnt].push_back(stk.top());
				stk.pop();
			}
		} else if (dfs[v] < dfs[u]) {
			low[u] = min(low[u], dfs[v]);
		}
	}
}

// G[] : adjacency list
// bcc[i] : vertices in i-th bcc (1-indexed)
