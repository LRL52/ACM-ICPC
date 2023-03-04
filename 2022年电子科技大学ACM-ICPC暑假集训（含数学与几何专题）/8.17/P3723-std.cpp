#include <algorithm>
#include <complex>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long ll;
typedef complex<double> cex;

const int N = 1e6 + 10;
const double PI = acos(-1);

int n, m, a[N], b[N];
ll ans, t, res[N], mx;

int r[N];
void fft(cex *c, int lim, int type)  {
	for(int i = 1; i < lim; i ++)
		if(i < r[i]) swap(c[i], c[r[i]]);
	for(int n = 1; n < lim; n <<= 1) {
		cex x(cos(PI / n), type * sin(PI / n));
		for(int i = 0; i < lim; i += (n << 1)) {
			cex y(1, 0);
			for(int k = 0; k < n; k ++, y *= x) {
				cex p = c[i + k], q = y * c[i + k + n];
				c[i + k] = p + q; c[i + k + n] = p - q;
			}
		}
	}
}

void _transform(int *a, int *b, int n, int m, ll *ans) {
	static cex f[N], g[N];
	int lim = 1, l = 0;
	for(int i = 1; i <= n; i ++) f[i].real(a[i]);
	for(int i = 1; i <= m; i ++) g[i].real(b[i]);
	for(n += m; lim <= n + m; lim <<= 1) l ++;
	for(int i = 1; i < lim; i ++)
		r[i] = (r[i >> 1] >> 1) | ((i & 1) << (l - 1));
	fft(f, lim, 1), fft(g, lim, 1);
	for(int i = 0; i < lim; i ++) f[i] *= g[i];
	fft(f, lim, -1);
	for(int i = 1; i <= n; i ++)
		ans[i] = (ll)(0.5 + f[i].real() / lim);
}

int main() {
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
	for(int i = 1; i <= n; i ++) scanf("%d", &b[i]);
	for(int i = 1; i <= n; i ++) {
		ans += a[i] * a[i] + b[i] * b[i]; t += b[i] - a[i];
	}
    printf("t = %d n = %d\n", t, n);
	int c1 = floor(t * 1.0 / n), c2 = ceil(t * 1.0 / n);
    printf("c1, c2 = %d, %d\n", c1, c2);
	ans += min(n * c1 * c1 - 2 * c1 * t, n * c2 * c2 - 2 * c2 * t);
	printf("ans = %d\n", ans);
	for(int i = 1; i <= n; i ++) b[i + n] = b[i];
	reverse(a + 1, a + n + 1);
	_transform(a, b, n, n << 1, res);
	ll tmp = 0;
	for(int i = 0; i <= n; i ++)
		tmp = max(tmp, res[i + n + 1]);
	ans -= (tmp << 1);
	printf("%lld\n", ans);
	return 0;
}