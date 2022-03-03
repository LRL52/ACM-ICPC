#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 500000 * 2 + 5555;
int Num0[N];


int main() {
	freopen("N.in", "r", stdin);
	int *Num = &Num0[500000 + 2555]; //根据内存分配原理使用负数下标
	int T, m, n; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m); int x;
		memset(Num0, 0, sizeof Num0);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &x);
			++Num[x];
		}
		for (int i = 500000; i >= -500000; --i) {
			while (m > 0 && Num[i] > 0) {
				printf("%d ", i);
				--m, --Num[i];
			}
			if (!m) break;
		}
		putchar('\n');
	}
	return 0;
}