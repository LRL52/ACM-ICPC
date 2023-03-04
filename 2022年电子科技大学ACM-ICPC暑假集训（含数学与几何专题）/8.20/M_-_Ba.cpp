//ID: LRL52  Date: 2022.8.20
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
char s[N], s2[N];
int n, Pos[35], Nxt[N][27];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%s", s + 1);
    int L = strlen(s + 1);
    for(int i = L; i >= 1; --i){
        for(int k = 0; k < 26; ++k)
            Nxt[i][k] = Pos[k];
        Pos[s[i] - 'a'] = i;
    }
    scanf("%d", &n);
    rep(i, 1, n){
        scanf("%s", s2 + 1);
        int len = strlen(s2 + 1);
        int p = Pos[s2[1] - 'a'], j;
        if(p == 0){
            puts("IMPOSSIBLE");
            continue;
        }
        for(j = 2; j <= len; ++j){
            p = Nxt[p][s2[j] - 'a'];
            if(!p) break;
        }
        --j;
        for(int k = 1; k <= j; ++k) putchar(s2[k]);
        puts("");
    }
	return 0;
}