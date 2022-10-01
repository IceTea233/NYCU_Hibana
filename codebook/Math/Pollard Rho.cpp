#define ll long long

ll mult(ll a, ll b, ll m){
	if(b == 0) return 0;
	if(b % 2) return (a + mult(a, b - 1)) % m;
	int tmp = mult(a, b / 2, m);
	return (tmp + tmp) % m;
}

ll fpow(ll a, ll b, ll m){
	if(b == 0) return 1;
	if(b % 2) return mult(a, fpow(a, b - 1)) % m;
	int tmp = fpow(a, b / 2, m);
	return mult(tmp, tmp) % m;
}

// random number generator
ll f(Int x, Int m) {
	return (mult(x, x, m)+1) % m;
}

// returns a divisor d of n
// if d == n, try changing xj or f
ll pollard_rho(Int n) {
	if (n%2 == 0) return 2;

	ll xi, xj;
	int i = 1, j = 1;
	xi = xj = 2;

	while (true) {
		j++;
		xj = f(xj, n);
		int d = __gcd(abs(xi - xj), n);
		if (d != 1) return d;

		if (j == i*2) {
			i *= 2;
			xi = xj;
		}
	}
}
