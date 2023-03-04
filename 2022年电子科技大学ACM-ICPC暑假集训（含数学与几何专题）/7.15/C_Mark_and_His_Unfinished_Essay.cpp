//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long   
int n, c, qs;
int L[N], R[N], Len[N];
char s[N];
int cntN = 0;

/*char find(int k, int i){
    if(++cntN > (c + 1) * qs){
        puts("RE");
        exit(0);
    }
    printf("k = %d i = %d\n", k, i);
    if(i <= Len[0] || k == 0) return s[i];
    int j = 0;
    for(int t = 1; t <= c; ++t){
        if(i > Len[t - 1] && i <= Len[t]){
            j = t;
            break;
        }
    }
    return find(j - 1, L[j] + i - Len[j - 1] - 1);
}*/

char find(int k, int i){
    int cnt = 0;
    while(i > Len[0] && ++cnt < 50){
        int j = 0;
        for(int t = 1; t <= c; ++t){
            if(i > Len[t - 1] && i <= Len[t]){
                j = t;
                break;
            }
        }
        assert(j != 0);
        assert(L[j] + i - Len[j - 1] - 1 < i);
        i = L[j] + i - Len[j - 1] - 1;
    }
    return s[i];
}

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	int Task; scanf("%lld", &Task);
	while(Task--){
        scanf("%lld%lld%lld", &n, &c, &qs);
        scanf("%s", s + 1);
        Len[0] = n;
        rep(i, 1, c){
            scanf("%lld%lld", &L[i], &R[i]);
            Len[i] = Len[i - 1] + R[i] - L[i] + 1;
        }
        int pos;
        rep(i, 1, qs){
            scanf("%lld", &pos);
            char ans = find(c, pos);
            //printf("%c\n", ans);
            putchar(ans);
            puts("");
        }
	}
	return 0;
}