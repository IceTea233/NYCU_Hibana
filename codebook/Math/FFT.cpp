const double pi = acos(-1);
typedef complex<double> cp;
constexpr int kN = 131072;
struct FFT {
	int n, rev[kN];
	cp omega[kN], iomega[kN];
	void init(int n_) {
		this->n = n_;
		for (int i = 0; i < n_; i++) {
			omega[i] = cp(cos(2 * pi / n_ * i),
				sin(2 * pi / n_ * i));
			iomega[i] = conj(omega[i]);
		}
		int k = __lg(n_);
		for (int i = 0; i < n_; i++) {
			int t = 0;
			for (int j = 0; j < k; j++)
				if (i & (1 << j)) t |= (1 << (k - j - 1));
			rev[i] = t;
		}
	}
	void transform(vector<cp>& a, cp* xomega) {
		for (int i = 0; i < n; i++)
			if (i < rev[i]) swap(a[i], a[rev[i]]);
		for (int len = 2; len <= n; len <<= 1) {
			int mid = len >> 1;
			int r = n / len;
			for (int j = 0; j < n; j += len)
				for (int i = 0; i < mid; i++) {
					cp t = xomega[r * i] * a[j + mid + i];
					a[j + mid + i] = a[j + i] - t;
					a[j + i] += t;
				}
		}
	}
	void fft(vector<cp>& a) { transform(a, omega); }
	void ifft(vector<cp>& a) {
		transform(a, iomega);
		for (int i = 0; i < n; i++) a[i] /= n;
	}
};
