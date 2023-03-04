//ID: LRL52  Date: 2022.8.2
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
int n, a[N], select[N], X[N], Y[N];

long long Solve(){
    long long ret = 0;
    rep(i, 1, 3) if(select[i]) ret += a[i];
    rep(i, 1, n - 3){
        int x = X[i], y = Y[i];
        if(select[x] || select[y]) select[i + 3] = 0;
        else select[i + 3] = 1, ret += a[i + 3];
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n) rd(a[i]);
        rep(i, 1, n - 3){
            rd(X[i]), rd(Y[i]);
        }
        long long ans = 0;
        rep(i, 1, n) select[i] = 0;
        select[1] = 1, select[2] = select[3] = 0;
        ans = max(ans, Solve());
        rep(i, 1, n) select[i] = 0;
        select[2] = 1, select[1] = select[3] = 0;
        ans = max(ans, Solve());
        rep(i, 1, n) select[i] = 0;
        select[3] = 1, select[1] = select[2] = 0;
        ans = max(ans, Solve()); 
        printf("%lld\n", ans);
	}
	return 0;
}