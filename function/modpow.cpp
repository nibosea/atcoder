ll power(ll n, ll p, ll mod) {
  ll r = 1;
  for (; p > 0; p >>= 1) {
    if (p & 1ll) r = r % mod * n % mod;
    n %= mod;
    n = n * n % mod;
  }
  return r;
}