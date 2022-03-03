#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 25;
int a[N][N];

int main() {
	freopen("G.in", "r", stdin);
	int T, n; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		memset(a, 0, sizeof a);
		int x = 0, y = n, num = 0, end = n * n;
		while (1) {
			while (x < n && a[x + 1][y] == 0 && num < end) a[++x][y] = ++num;
			while (y > 1 && a[x][y - 1] == 0 && num < end) a[x][--y] = ++num;
			while (x > 1 && a[x - 1][y] == 0 && num < end) a[--x][y] = ++num;
			while (y < n && a[x][y + 1] == 0 && num < end) a[x][++y] = ++num;
			if (num == end) break;
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j)
				printf("%4d", a[i][j]);
			putchar('\n');
		}
	}
	return 0;
}