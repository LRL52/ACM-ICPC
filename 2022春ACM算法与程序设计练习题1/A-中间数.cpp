#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	freopen("A.in", "r", stdin);
	int T, x, y, z; //rd(T);
	scanf("%d", &T);
	while (T--) {
		//rd(x), rd(y), rd(z);
		scanf("%d%d%d", &x, &y, &z);
		if (x > y) swap(x, y);
		if (y > z) swap(y, z);
		if (x > y) swap(x, y);
		if (x == y) printf("%d\n", z);
		else printf("%d\n", y);
	}
	return 0;
}