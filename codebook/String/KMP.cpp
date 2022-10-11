const int maxn = 1e6 + 7;
 
int fail[maxn] = {};

// build failure function
// p: pattern; m: length of pattern
void build_fail(string &p, int m) {
    fail[1] = 0;
    for (int i=1, j=0; i<m; i++) {
        while (j && p[i+1] != p[j+1]) {
            j = fail[j];
        }
        if (p[i+1] == p[j+1])
            fail[i+1] = ++j;
        else
            fail[i+1] = j;
    }
}

void count() {
    int ans = 0;
    for (int i=0, j=0; i<n; i++) {
        while (j && (j == n || s[i+1] != p[j+1])) {
            j = fail[j];
        }
        if (s[i+1] == p[j+1]) {
            j++;
        }
        if (j == m)
            ans++; // A pattern is matched.
    }
    return count;
}