//不难推出式子: F(a) = (2n-1)a1 + (2n-3)a2 +...+ 3an-1 + an
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;

int main() {
	freopen("M.in", "r", stdin);
	int T, n; LL F; scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &F);
		LL sum = 0;
		for (int i = 1, j = n; i <= n; ++i, --j) {
			sum += 1LL * (2 * j - 1) * i;
		}
		if (sum > F) puts("-1");
		else {
			for (int i = 1; i < n; ++i) printf("%d ", i);
			printf("%lld\n", (LL)n + F - sum);
		}
	}
	return 0;
}