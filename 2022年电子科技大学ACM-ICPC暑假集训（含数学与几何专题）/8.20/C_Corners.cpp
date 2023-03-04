//ID: LRL52  Date: 2022.8.16
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
char s[N][N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%d%d", &n, &m);
        rep(i, 1, n) scanf("%s", s[i] + 1);
        int one = 0, two = 0, ans = 0;
        rep(i, 1, n){
            rep(j, 1, m){
                ans += s[i][j] == '1';
                if(s[i][j] == '0') one = 1;
                if(j < m && s[i][j] == '0' && s[i][j + 1] == '0') two = 1;
                if(i < n && s[i][j] == '0' && s[i + 1][j] == '0') two = 1;
                if(s[i][j] == '1'){
                    int u = (i > 1) ? s[i - 1][j] - '0' : 1;
                    int d = (i < n) ? s[i + 1][j] - '0' : 1;
                    int l = (j > 1) ? s[i][j - 1] - '0' : 1;
                    int r = (j < m) ? s[i][j + 1] - '0' : 1;
                    if(u == 0 && r == 0) two = 1;
                    if(u == 0 && l == 0) two = 1;
                    if(r == 0 && d == 0) two = 1;
                    if(l == 0 && d == 0) two = 1;
                }
            }
        }
        if(two) printf("%d\n", ans);
        else if(one) printf("%d\n", ans - 1);
        else printf("%d\n", ans - 2);
	}
	return 0;
}