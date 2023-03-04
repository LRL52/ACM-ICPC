//ID: LRL52  Date: 2022.8.12
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, K, q[N], a[N];
char s1[N], s2[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%d%d", &n, &K);
    scanf("%s%s", s1 + 1, s2 + 1);
    int l = 1, r = 0, OK = 1;
    rep(i, 1, n){
        while(l <= r && q[l] + K - 1 < i) ++l;
        //int res = (r - l + 1 + s1[i] - '0') & 1;
        int res = s1[i] - '0';
        if(l <= r) res = a[q[r]];
        int c = s2[i] - '0';
        if(res != c){
            if(i + K - 1 <= n) q[++r] = i, a[i] = c;
            else{
                OK = 0;
                break;
            }
        }
    }
    OK ? puts("Yes") : puts("No");
	return 0;
}