// insert line, point query max. of lines
// note that m, k of nodes are NOT initialized

struct segment {
  double m, k;
  double val(double x) {
    return m * x + k;
  }
}tr[MAXC * 4];

void insert(int lb, int rb, int idx, segment seg) {
  if (lb == rb) {
    if(seg.val(lb) > tr[idx].val(lb))
      tr[idx] = seg;
     return;
   }
   int mid = (lb + rb) / 2;
   if (tr[idx].m > seg.m)
     swap(tr[idx],seg);
   if (tr[idx].val(mid) < seg.val(mid)) {
     swap(tr[idx],seg);
     insert(lb, mid, idx * 2, seg);
   }
   else
     insert(mid + 1, rb, idx * 2 + 1, seg);
}

double query(int lb, int rb, int idx, int x) {
  if (lb == rb) return tr[idx].val(x);
  int mid = (lb + rb) / 2;
  if (x <= mid)
    return max(query(lb, mid, idx * 2, x), tr[idx].val(x));
  return max(query(mid + 1, rb, idx * 2 + 1, x), tr[idx].val(x));
}

// for [1, n]:
// call insert(1, n, 1, seg) to insert a line seg
// call query(1, n, 1, x) to query max. of lines at point x
