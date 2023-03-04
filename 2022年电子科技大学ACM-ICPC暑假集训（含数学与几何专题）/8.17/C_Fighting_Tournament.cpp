//ID: LRL52  Date: 2022.8.16
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, qs;
int win[N], a[N], Ans[N]; 
struct QS{
    int i, k, id;
    inline bool operator<(const QS&t)const{
        return k < t.k;
    }
}Q[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(qs);
        rep(i, 1, n) rd(a[i]), win[i] = 0;
        rep(i, 1, qs){
            rd(Q[i].i), rd(Q[i].k);
            Q[i].id = i;
        }
        sort(Q + 1, Q + qs + 1);
        int t = a[1], per = 1, p = 0;
        for(int i = 2; i <= n; ++i){
            int round = i - 1;
            if(a[i] > t){
                t = a[i], per = i;
                win[per]++;
            } else 
                win[per]++;
            while(p < qs && Q[p + 1].k == round){
                ++p;
                Ans[Q[p].id] = win[Q[p].i];
            }
        }
        for(int i = p + 1; i <= qs; ++i){
            int u = Q[i].i;
            if(a[u] == n) Ans[Q[i].id] = win[u] + Q[i].k - (n - 1);
            else Ans[Q[i].id] = win[u];
        }
        rep(i, 1, qs) printf("%d\n", Ans[i]);
	}
	return 0;
}