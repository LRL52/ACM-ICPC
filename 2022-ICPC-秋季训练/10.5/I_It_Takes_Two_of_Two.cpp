//ID: LRL52  Date: 2022.10.4
//i题调了1年qaq
//29行处，max(k-4, 0)，不是max(k-2,，0)，因为这个调了一晚上，还手算n=4的样例
//f[i][j][k]表示还有i个节点的度为1或2，j个节点的度为1，k个节点的度为1且连接度为1的点
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 255, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int vis[N][N][N];
double f[N][N][N];

double F(int i, int j, int k) {
    // printf("f[%d][%d][%d]\n", i, j, k);
    if(vis[i][j][k]) return f[i][j][k];
    vis[i][j][k] = 1, f[i][j][k] = 0.0;
    double &ret = f[i][j][k];
    //int tot = 0;
    if(i <= 1 || (i == 2 && j == 2 && k == 2)) return ret = 0.0;
    // if(i > 2 && j > 2) ret += j * (j - 2) * (F(i-2, j-2) + 1);
    // if(j > 1) ret += j;
    if(j >= 2) {
        if(k > 2) ret += k * (k - 2) * (F(i-2, j-2, max(k-4, 0)) + 1)/*, tot += k * (k - 2)*/;
        if(j - k - 1 > 0) ret += (j - k) * (j - k - 1) * (F(i-2, j-2, k) + 1)/*, tot += (j - k) * (j - k - 1) */;
        if(j > k && k > 0) ret += 2 * k * (j - k) * (F(i-2, j-2, max(k-2,0)) + 1)/*, tot += 2 * k * (j - k)*/;
    }
    if(k > 0) ret += k/*, tot += k*/;
    if(i - j >= 2) ret += (i - j) * (i - j - 1) * (F(i, j+2, k+2) + 1)/*, tot += (i - j) * (i - j - 1)*/;
    if(i - j >= 1 && j > 0) {
        ret += 2 * k * (i - j) * (F(i-1, j, max(k-2,0)) + 1)/*, tot += 2 * k * (i - j)*/;
        ret += 2 * (j - k) * (i - j) * (F(i-1, j, k) + 1)/*, tot += 2 * (j - k) * (i - j)*/;
    }
    ret += i + n * n - i * i/*, tot += i + n * n - i * i*/;
    // assert(tot == n * n);
    double i2 = i * i;
    // ret /= i2;
    double t = i;
    if(k > 0) t += k;
    ret /= (i2 - t);
    // printf("%.3lf\n", i2 - t);
    // assert(ret > 1e-6);
    //printf("f[%d][%d][%d] = %.3lf\n", i, j, k, ret);
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("I.in", "r", stdin);
#endif
    rd(n);
    double ans = F(n, 0, 0);
    printf("%.9lf\n", ans);
	return 0;
}