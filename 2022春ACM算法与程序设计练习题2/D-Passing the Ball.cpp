#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 105;
//unsigned int f[N][N]; //unsiged int不能表示-1，算了还是long long吧
typedef long long LL;
LL f[N][N];
int n;

LL F(int id, int m) {
	if (f[id][m] != -1) return f[id][m];
	if (m == 0) return 0;
	f[id][m] = 0;
	for (int i = 1; i <= n; ++i) {
		if (i == id) continue;
		f[id][m] += F(i, m - 1);
	}
	return f[id][m];
}

int main() {
	freopen("D.in", "r", stdin);
	memset(f, -1, sizeof f);
	f[1][0] = 1; int m;
	scanf("%d%d", &n, &m);
	printf("%lld\n", F(1, m));
	return 0;
}