#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 55;
char s[N];

void step(int& x, int& y, char op) {
	switch (op) {
	case 'U': ++y; break;
	case 'D': --y; break;
	case 'L': --x; break;
	case 'R': ++x; break;
	}
}

int dist(int a, int b, int c, int d) {
	return abs(a - c) + abs(b - d);
}

int main() {
	freopen("I.in", "r", stdin);
	int T, n, X, Y; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%s", &X, &Y, &n, s + 1);
		int x = 0, y = 0, ok = 0;
		if (x == X && y == Y) { //注意起点和终点重合的情况
			puts("0");
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			int tx = x, ty = y;
			step(tx, ty, s[i]);
			if (dist(tx, ty, X, Y) < dist(x, y, X, Y)) {
				x = tx, y = ty;
				if (x == X && y == Y) {
					printf("%d\n", i);
					ok = 1; break;
				}
			}
		}
		if (!ok) puts("-1");
	}
	return 0;
}