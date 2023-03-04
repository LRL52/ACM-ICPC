//ID: LRL52  Date: 2022.7.12
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
char s[N];
int a[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%d", &n);
        rep(i, 1, n) scanf("%d", &a[i]);
        rep(i, 1, n){
            scanf("%d%s", &m, s + 1);
            for(int j = m; j >= 1; --j){
                if(s[j] == 'U') a[i] = (a[i] - 1 + 10) % 10;
                else a[i] = (a[i] + 1) % 10;
            }
        }
        rep(i, 1, n) printf("%d ", a[i]);
        putchar('\n');
	}
	return 0;
}
