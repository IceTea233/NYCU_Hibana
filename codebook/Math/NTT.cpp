/* p=r*2^k+1
p                    r   k   root
998244353            119  23  3
2013265921          15  27  31
2061584302081        15  37  7
2748779069441        5    39  3
1945555039024054273 27  56  5 */

constexpr int kN = 1e5;
struct NTT {
  int n, invn, rev[kN];
  int g;
  int omega[kN], iomega[kN];
  void init(int n_, int g_) {
    this->n = n_, this->g = g_;
    invn = decltype(invn)(Inv(n));
    int k = __lg(n);
    int x =
      decltype(invn)(PowMod(g, (kMod - 1) / n));
    omega[0] = 1;
    for (int i = 1; i < n; i++)
      omega[i] = 1LL * omega[i - 1] * x % kMod;
    iomega[n - 1] =
      decltype(invn)(Inv(omega[n - 1]));
    for (int i = n - 2; i >= 0; i--)
      iomega[i] = 1LL * iomega[i + 1] * x % kMod;
    for (int i = 0; i < n; i++) {
      int t = 0;
      for (int j = 0; j < k; j++)
        if (i & (1 << j)) t |= (1 << (k - j - 1));
      rev[i] = t;
    }
  }
  void transform(vector<int> &a, int *xomega) {
    for (int i = 0; i < n; i++)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int len = 2; len <= n; len <<= 1) {
      int mid = len >> 1;
      int r = n / len;
      for (int j = 0; j < n; j += len) {
        for (int i = 0; i < mid; i++) {
          int t = 1LL * xomega[r * i] *
            a[j + mid + i] % kMod;
          a[j + mid + i] = a[j + i] - t;
          if (a[j + mid + i] < 0)
            a[j + mid + i] += kMod;
          a[j + i] += t;
          if (a[j + i] >= kMod) a[j + i] -= kMod;
        }
      }
    }
  }
  void dft(vector<int> &a) { transform(a, omega); }
  void idft(vector<int> &a) {
    transform(a, iomega);
    for (int i = 0; i < n; i++)
      a[i] = 1LL * a[i] * invn % kMod;
  }
};