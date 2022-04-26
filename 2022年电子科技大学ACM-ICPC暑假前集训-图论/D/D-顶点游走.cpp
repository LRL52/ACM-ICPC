//ID: LRL52  Date: 2022.4.18
//一次AC, Nice，就是细节想了很久
//感谢zhongzh的n连自环的妙计，然后也不需要二分，其实答案只可能在产生新的可走道路后再走n次以内
//就是数据给的很绕，d还不是严格递增的
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 185, M = 4e4 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int a[N][N]; //矩阵运算的辅助数组
int n, m, C;
int mp[N][N], c[M], d[M], X[M], Y[M];

typedef long long LL;
struct Mat {
	int c, r;
	bitset<N> row[N], col[N];
	Mat() {
		c = r = 0;
		for (int i = 0; i < N; ++i) {
			row[i].reset();
			col[i].reset();
		}
	}
	Mat(int x) {
		c = r = x;
		for (int i = 0; i < N; ++i) {
			row[i].reset();
			col[i].reset();
			row[i][i] = col[i][i] = 1;
		}
	}
	inline Mat operator*(const Mat& t)const {
		Mat ret; ret.c = c, ret.r = t.r;
		for (int i = 0; i < c; ++i)
			for (int j = 0; j < t.r; ++j)
				a[i][j] = (row[i] & t.col[j]).any();
		for (int i = 0; i < c; ++i)
			for (int j = 0; j < t.r; ++j) {
				ret.row[i][j] = a[i][j];
				ret.col[j][i] = a[i][j];
			}
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
}F, H;

Mat f(int t) { //f(t)函数处理出t时刻能走的边的邻接矩阵
	Mat ret;
	ret.c = ret.r = n;
	rep(i, 1, n) {
		rep(j, 1, n) {
			if (mp[i][j] <= t) {
				ret.row[i - 1][j - 1] = 1; //注意矩阵是0下标
				ret.col[j - 1][i - 1] = 1;
			}
		}
	}
	return ret;
}
 

int main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	rd(n), rd(m), rd(C);
	rep(i, 1, m) {
		rd(X[i]), rd(Y[i]), rd(c[i]);
	}
	rep(i, 1, C) rd(d[i]);
	memset(mp, 0x3f, sizeof mp);
	rep(i, 1, m) {
		int u = X[i], v = Y[i];
		mp[u][v] = min(mp[u][v], d[c[i]]);
	}
	mp[n][n] = 0;
	C = unique(d + 1, d + C + 1) - d - 1;
	F.c = 1, F.r = n;
	F.row[0][0] = 1, F.col[0][0] = 1;
	if (d[1]) {
		puts("Impossible");
		return 0;
	}
	rep(i, 1, C) {
		int t = d[i] + 1, up = (i == C ? t + n : min(t + n, d[i + 1]));
		H = f(d[i]);
		for (int j = t; j <= up; ++j) {
			F = F * H;
			if (F.row[0][n - 1]) {
				printf("%d\n", j);
				return 0;
			}
		}
		if (i < C && up < d[i + 1]) {
			F = F * (H ^ (d[i + 1] - up));
		}
	}
	puts("Impossible");
	return 0;
}