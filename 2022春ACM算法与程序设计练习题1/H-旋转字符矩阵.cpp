#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105;
char a[N][N];

int main() {
	freopen("H.in", "r", stdin);
	int T, n; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%s", a[i] + 1);
		for (int j = 1; j <= n; ++j) {
			for (int i = n; i >= 1; --i)
				putchar(a[i][j]);
			putchar('\n');
		}
		putchar('\n');
	}
	return 0;
}