//ID: LRL52  Date: 2022.7.20
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
int n, a[N], b[N];
char s[N];

int check(int i, int j){
    if(i == 1 || i == 2) return j == 3 || j == 4;
    return j == 1 || j == 2;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%d", &n);
        rep(i, 1, n){
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            a[i] = s[len] - '0';
        }
        rep(i, 1, n){
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            b[i] = s[len] - '0';
        }
        int ok = 1;
        rep(i, 1, n){
            if(check(a[i], b[i]) == 0){
                ok = 0;
                break;
            }
        }
        if(a[n] != 3 && a[n] != 4) ok = 0;
        ok ? puts("YES") : puts("NO");
	}
	return 0;
}