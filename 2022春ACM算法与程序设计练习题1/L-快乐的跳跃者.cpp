#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 305;
int a[N], vis[N];

int main() {
	freopen("L.in", "r", stdin);
	int T, n; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		memset(vis, 0, sizeof vis);
		for (int i = 1; i < n; ++i) {
			int idx = labs(a[i] - a[i + 1]);
			if (idx < n) vis[idx] = 1;
		}
		int ok = 1;
		for (int i = 1; i < n; ++i)
			if (vis[i] == 0) {
				ok = 0;
				break;
			}
		ok ? puts("Jolly") : puts("Not jolly");
	}
	return 0;
}