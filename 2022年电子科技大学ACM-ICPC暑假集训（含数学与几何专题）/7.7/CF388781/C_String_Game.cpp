//ID: LRL52  Date: 2022.7.7
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 200055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, a[N], take[N];
char s1[N], s2[N];

int check(int K){
    int p = 0;
    rep(i, 1, n){
        if(p < m && take[i] > K && s1[i] == s2[p + 1])
            ++p;
    }
    return p == m;
}

int main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	scanf("%s%s", s1 + 1, s2 + 1);
    n = strlen(s1 + 1), m = strlen(s2 + 1);
    rep(i, 1, n) scanf("%d", &a[i]), take[a[i]] = i;
    int l = 1, r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) l = mid + 1;
        else r = mid - 1;
    }
    printf("%d\n", r);
	return 0;
}
