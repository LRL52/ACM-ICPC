#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return getchar(); }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1, cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int gcd(int a, int b) {
	return a == 0 ? b : gcd(b % a, a);
}

int main() {
	//freopen("read.in", "r", stdin);
	int T, x, y; scanf("%d", &T);
	//rd(T);
	while (T--) {
		scanf("%d%d", &x, &y);
		//rd(x), rd(y);
		printf("%d %d\n", gcd(x, y), x*y / gcd(x, y));
	}
	return 0;
}