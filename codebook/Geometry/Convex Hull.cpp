void find_half_convex_hull(vector<pii>& pts, vector<pii>& ret){
	int cnt = 0;
	for(pii p : pts){
			while(cnt >= 2 and ori(ret[ret.size() - 2], ret[ret.size() - 1], p) != 1){
					ret.pop_back();
			}
			ret.push_back(p);
	}
	ret.pop_back();
}

void find_convex_hull(vector<pii>& pts, vector<pii>& ret){
	sort(pts.begin(), pts.end());
	half_convex_hull(pts, ret);
	reverse(pts.begin(), pts.end());
	half_convex_hull(pts, ret);
}

// call find_convex_hull(pts, ret) to find the convex hull of pts
// result is stored in ret
