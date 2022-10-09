#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 7; // maximal length of the target string.

// Sort suffixes using radix sort. Complexity: O(n log_n)
vector<int> suffix_array(string s) {
    s = s + "$";
    int n = s.size();
    vector<int> c(n, 0); // rank of each suffixes in current iteration.
                         // represented by the index of the first character.
    vector<int> p(n, 0); // sorted permutation in every iteration.
    queue<int> keep[maxn];
 
    for (int i=0; i<n; i++)
        keep[s[i]].push(i);
    int rk = 0;
    for (int i=0, j=0; i<128; i++) { // first iteration.
        if (keep[i].size()) {
            while (keep[i].size()) {
                int x = keep[i].front();
                keep[i].pop();
                p[j++] = x;
                c[x] = rk;
            }
            rk ++;
        }
    }

    // Current length of compared segment is 2^k
    for (int k=0; (1<<k) < n; k++) {
        // Radix sort.

        // First sort. Sort based on back half.
        for (int i=0; i<n; i++)
            keep[ c[(p[i] + (1<<k)) % n] ].push(p[i]);
        for (int i=0, j=0; i<rk; i++) {
            while (keep[i].size()) {
                p[j++] = keep[i].front();
                keep[i].pop();
            }
        }

        // Second sort. Sort based on front half.
        for (int i=0; i<n; i++)
            keep[ c[ p[i] ] ].push(p[i]);
        for (int i=0, j=0; i<rk; i++) {
            while (keep[i].size()) {
                p[j++] = keep[i].front();
                keep[i].pop();
            }
        }

        vector<int> c2(n, 0); // rank of each suffixes in upcoming iteration
        int rk2 = 0;
        for (int i=0; i<n; i++) {
            int x = p[i];
            int y = p[i+1];
            c2[x] = rk2;

            if (i == n-1 // trailing "$"
            || !(c[x] == c[y] && c[(x + (1<<k)) % n] == c[(y + (1<<k)) % n])) { // unequal prefixes of suffixes
                rk2++;
            }
        }
        c = c2;
        rk = rk2;
    }
 
    return p;
}
