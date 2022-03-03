#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100055;
int n, m;
int a[N];

int main() {
	freopen("O.in", "r", stdin);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	int h;
	for (int i = 1; i <= m; ++i) {
		scanf("%d", &h);
		int pos = lower_bound(a + 1, a + n + 1, h) - a;
		printf("%d\n", n - pos + 1);
	}
	return 0;
}