#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	freopen("J.in", "r", stdin);
	int T, n, K; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &K);
		if (n == 1 || (n > 2 && K == 1)) puts("0");
		else if (K > n - 1) printf("%d\n", n * (n - 1) / 2);
		else printf("%d\n", n * K / 2);
	}
	return 0;
}