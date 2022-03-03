//O(Tklogn)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;
int sta[N];

int main() {
	freopen("F.in", "r", stdin);
	int T, n, K; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &K);
		memset(sta, 0, sizeof sta);
		for (int i = 1; i <= K; ++i) {
			for (int j = i; j <= n; j += i) {
				sta[j] ^= 1;
			}
		}
		for (int i = 1; i <= n; ++i)
			if (sta[i])
				printf("%d ", i);
		putchar('\n');
	}
	return 0;
}