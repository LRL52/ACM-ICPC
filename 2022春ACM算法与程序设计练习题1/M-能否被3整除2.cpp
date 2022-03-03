#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MOD = 3;
typedef long long LL;
struct Mat {
	int c, r, a[2][2];
	Mat() {
		c = r = 0;
		memset(a, 0, sizeof a);
	}
	Mat(int x) {
		c = r = x; memset(a, 0, sizeof a);
		for (int i = 0; i < c; ++i)
			a[i][i] = 1;
	}
	inline Mat operator*(const Mat& t)const {
		Mat ret; ret.c = c, ret.r = t.r;
		for (int i = 0; i < c; ++i)
			for (int j = 0; j < t.r; ++j)
				for (int k = 0; k < r; ++k)
					ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * t.a[k][j] % MOD) % MOD;
		return ret;
	}
	friend Mat operator^(Mat A, LL k) {
		Mat ret(A.c);
		while (k) {
			if (k & 1) ret = ret * A;
			A = A * A;
			k >>= 1;
		}
		return ret;
	}
}F_n, G, F_1;
const int _G[2][2] = {
	{1, 1},
	{1, 0},
};

int main() {
	freopen("M.in", "r", stdin);
	int T, a, b, m, n; scanf("%d", &T);
	G.c = G.r = 2;
	memcpy(G.a, _G, sizeof _G);
	while (T--) {
		scanf("%d%d%d", &a, &b, &m);
		F_1.c = 2, F_1.r = 1;
		F_1.a[0][0] = b, F_1.a[1][0] = a;
		while (m--) {
			scanf("%d", &n);
			if (n >= 1) F_n = (G ^ (n - 1)) * F_1; //ºËÐÄÊ½×Ó
			else F_n.a[0][0] = a;
			F_n.a[0][0] % 3 ? puts("No") : puts("Yes");
		}
		putchar('\n');
	}
	return 0;
}