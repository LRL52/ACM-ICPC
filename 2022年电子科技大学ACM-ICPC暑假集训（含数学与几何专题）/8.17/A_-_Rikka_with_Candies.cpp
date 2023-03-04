//ID: LRL52  Date: 2022.8.15
//#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 50000 + 5, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	x = 0, cc = gc(); while (cc < '0' || cc > '9') cc = gc();
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); }
}
//#define int unsigned short
bitset<N> A, B, T;
int n, m, qs;
int b[N], Ans[N];
struct Qs{
    int k, id;
    inline bool operator<(const Qs&t)const{
        return k < t.k;
    }
}Q[N];

signed main() {
#ifdef LRL52
	freopen("tmp.txt", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(m), rd(qs);
        A.reset(); int x, maxa = 0;
        rep(i, 1, n){
            rd(x);
            A[x] = 1;
            maxa = max(maxa, x);
        }
        rep(i, 1, m) rd(b[i]);
        sort(b + 1, b + m + 1);
        const int MAXN = maxa; //记着改
        /*B[m + 1].reset();
        for(int i = m; i >= 1; --i){
            B[i] = B[i + 1];
            for(int j = 0; j <= MAXN; j += b[i]){
                B[i][j].flip();
            }
        }*/
        rep(i, 1, qs){
            int k; rd(k);
            Q[i].k = k;
            Q[i].id = i;
            //int idx = upper_bound(b + 1, b + m + 1, k) - b;
            //Ans = (B[idx] << k) & A;
            //int ans = Ans.count() & 1;
            //printf("%d\n", ans);
        }
        sort(Q + 1, Q + qs + 1);
        B.reset(); int p = m + 1;
        for(int i = qs; i >= 1; --i){
            //printf("i = %d\n", i);
            int k = Q[i].k;
            while(p > 1 && b[p - 1] > k){
                --p;
                for(int j = 0; j <= MAXN; j += b[p]){
                    B[j].flip();
                }
            }
            T = (B << k) & A;
            int ans = T.count() & 1;
            Ans[Q[i].id] = ans;
        }
        rep(i, 1, qs){
            putchar('0' + Ans[i]);
            putchar('\n');
        }
	}
    //printf("%.3lf M\n", (double)sizeof(B) / (1 << 20));
	return 0;
}