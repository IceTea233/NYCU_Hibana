// Given a suffix array, generate its LCP array
// (The length of longest common prefix between each 
// adjacent suffix in the suffix array.)
vector<int> kasai(string &s, vector<int> &sa) {
    int n = s.size();
    vector<int> rank(n+1, 0);
    vector<int> lcp(n+1, 0);
    for (int i=0; i<n+1; i++)
        rank[sa[i]] = i;
    for (int i=0, k=0; i<n; i++, k ? k-- : 0) {
        int j = sa[rank[i] - 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[rank[i]] = k;
    }
 
    return lcp;
}