// n is prime iff miller_rabin(a, n) = false for all a
// n < 2^32 : a = 2, 7, 61
// n < 2^64 : a = 2, 325, 9375, 28178, 450775, 9780504, 1795265022

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

bool miller_rabin(ll a, ll n){
  if (n < 2) return true;
  if (n % 2 == 0) return n != 2;
  a %= n;
  if (!a) return false;

  ll u = n-1;
  int t = 0;
  while (!(u % 2)) {
    u /= 2;
    t++;
  }

  ll x = fpow(a, u, n);
  for (int i=0; i<t; i++) {
    ll nx = mult(x, x, n);
    if (nx == 1 && x != 1 && x != n-1) return true;
    x = nx;
  }
  return x != 1;
}