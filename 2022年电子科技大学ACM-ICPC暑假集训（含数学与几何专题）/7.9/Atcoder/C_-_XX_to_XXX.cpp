//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
char s1[N], s2[N];

int main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	scanf("%s%s", s1 + 1, s2 + 1);
    int n = strlen(s1 + 1), m = strlen(s2 + 1);
    int p = 1, ok = 1;
    for(int i = 1; i <= n; ){
        int t = i;
        while(t < n && s1[t] == s1[t + 1]) ++t;
        int k = p;
        while(k < m && s2[k] == s2[k + 1]) ++k;
        if(s1[i] != s2[p]) ok = 0;
        int l1 = t - i + 1, l2 = k - p + 1;
        if(l1 != l2 && (l1 > l2 || (l1 < l2 && l1 == 1))) ok = 0;
        i = t + 1;
        p = k + 1;
    }
    if(p - 1 != m) ok = 0;
    ok ? puts("Yes") : puts("No");
	return 0;
}
