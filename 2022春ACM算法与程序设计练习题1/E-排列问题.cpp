#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055, M = 2055;
char a[N], b[N];
int cnt[12];

int main() {
	freopen("E.in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s%s", a, b);
		memset(cnt, 0, sizeof cnt);
		int len = strlen(a);
		for (int i = 0; i < len; ++i)
			++cnt[a[i] - '0'];
		len = strlen(b);
		for (int i = 0; i < len; ++i)
			--cnt[b[i] - '0'];
		int ok = 1;
		for (int i = 1; i < 10; ++i)
			if (cnt[i]) {
				ok = 0;
				break;
			}
		if (ok) puts("Yes");
		else puts("No");
	}
	return 0;
}