//ID: LRL52  Date: 2022.7.29
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
char s1[N], s2[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%d%d", &n, &m);
        scanf("%s%s", s1 + 1, s2 + 1);
        int ok = 1;
        for(int i = 1; i < m; ++i){
            if(s1[n - i + 1] != s2[m - i + 1]){
                ok = 0;
                break;
            }
        }
        int flag = 0;
        rep(i, 1, n - m + 1){
            if(s1[i] == s2[1]){
                flag = 1;
                break;
            }
        }
        ok && flag ? puts("YES") : puts("NO");
	}
	return 0;
}