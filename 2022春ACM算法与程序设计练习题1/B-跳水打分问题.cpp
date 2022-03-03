#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main() {
	int T, n; scanf("%d", &T);
	while (T--) {
		double sum = 0.0, x, min_x, max_x;
		scanf("%d%lf", &n, &min_x); sum = max_x = min_x;
		for (int i = 2; i <= n; ++i)
			scanf("%lf", &x), sum += x, max_x = max(x, max_x), min_x = min(x, min_x);
		printf("%.2lf\n", (sum - max_x - min_x) / (n-2));
	}
	return 0;
}