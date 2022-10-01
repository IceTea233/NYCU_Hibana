// point assign, range max

const int inf = numeric_limits<int>::max();
struct Node {
	Node *lc, *rc;
	int mx;
	void pull() { mx = max(lc->mx, rc->mx); }
} *root = nullptr;

Node *build(int arr[], int l, int r) {
	Node *res = new Node();
	if (l == r) {
		res->lc = res->rc = nullptr;
		res->mx = arr[l];
	} else {
		int m = (l + r) / 2;
		res->lc = build(arr, l, m);
		res->rc = build(arr, m + 1, r);
		res->pull();
	}
	return res;
}

int query(Node *nd, int ql, int qr, int l, int r) {
	if (r < ql || l > qr)
	return -inf;
	if (ql <= l && r <= qr)
	return nd->mx;
	int m = (l + r) / 2;
	return max(query(nd->lc, ql, qr, l, m), query(nd->rc, ql, qr, m
֒→ + 1, r));
}

int modify(Node *nd, int val, int p, int l, int r) {
	if (l == r) {
		nd->mx = val;
		return;
	}
	int m = (l + r) / 2;
	if (p <= m)
		modify(nd->lc, val, p, l, m);
	else
		modify(nd->rc, val, p, m + 1, r);
	nd->pull(); // IMPORTANT!!
}

// call root = build(a, 1, n) to initialize
// call query(root, ql, qr, 1, n) to query
// call modify(root, val, p, 1, n) to modify