//ID: LRL52  Date: 2022.7.5
//推性质 + DP
//DP时序列左右端点边界需要注意
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e3 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int a[N], f[N], fre[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
		rep(i, 1, n) rd(a[i]);
		f[0] = 0;
		rep(i, 1, n + 1){ //添加第n + 1个数，并认为它和最终序列中的数相等
			f[i] = 0; int maxfre = 0;
			rep(j, 0, n) fre[j] = 0;
			for(int j = i - 1; j >= 0; --j){
				int len = i - 1 - (j + 1) + 1; // 考虑i-1 ~ j+1 这一段是否能被完全删除
				if(len % 2 == 0 && maxfre <= len / 2 && (j == 0 || ((i == n + 1 || a[j] == a[i]) && f[j] > 0))) //j=0表示能完全删除1~i-1,留下i
					f[i] = max(f[i], f[j] + 1);
				maxfre = max(maxfre, ++fre[a[j]]);
			}
		}
		printf("%d\n", f[n + 1] - 1);
	}
	return 0;
}
