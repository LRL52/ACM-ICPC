//ID: LRL52  Date: 2022.7.18
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, a[N], Ans[N];

int Nxt(int i){return (i + 1) % n;}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        for(int i = 0; i < n; ++i) rd(a[i]);
        int p = 0;
        while(p < n - 1 && a[p + 1] == a[p]) ++p;
        if(p == n - 1){
            printf("1\n");
            for(int i = 0; i < n; ++i) printf("1 ");
            puts("");
            continue;
        }
        int st = -1;
        for(int i = 0; i < n; ++i){
            if(a[i] == a[(i + n - 1) % n]){
                st = i;
                break;
            }
        }
        int col = (st == -1 && (n&1) ) ? 3 : 2;
        st = st != -1 ? st : 0;
        int first = 1, now = 1;
        for(int i = st, j; first || i != st; i = Nxt(i)){
            first = 0;
            j = i, Ans[i] = now;
            while(Nxt(j) != st && a[Nxt(j)] == a[i]){
                j = Nxt(j);
                Ans[j] = now;
            }
            now = 3 - now;
        }
        printf("%d\n", col);
        for(int i = 0; i < n - 1; ++i) printf("%d ", Ans[i]);
        col == 3 ? printf("3\n") : printf("%d\n", Ans[n - 1]);
	}
	return 0;
}