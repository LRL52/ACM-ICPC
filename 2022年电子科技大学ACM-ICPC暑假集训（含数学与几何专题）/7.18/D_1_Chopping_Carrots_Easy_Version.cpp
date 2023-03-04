//ID: LRL52  Date: 2022.7.18
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
int n, K;
int a[N], vis[N];

int Solve(int minv){
    if(vis[minv] != -1) return vis[minv];
    int ok = 0, maxv = 0;
    if(minv == 0){
        if(a[1] / K != 0) return 0x3f3f3f3f;
        ok = 1;
        rep(i, 1, n) maxv = max(maxv, a[i] / K);
    } else{
        rep(i, 1, n){
            int p = a[i] / minv;
            p = min(p, K);
            if(p == 0) return 0x3f3f3f3f;
            if(a[i] / p == minv) ok = 1; 
            maxv = max(maxv, a[i] / p);
        }
    }
    return vis[minv] = ok ? maxv - minv : 0x3f3f3f3f;
}


signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(K);
        rep(i, 1, n) rd(a[i]);
        int up = 100000, ans = 0x3f3f3f3f;
        /*for(int minv = 0; minv <= up; ++minv){
            ans = min(ans, Solve(minv));
        }*/
        rep(i, 1, n){
            if(a[i] > a[1] / K) break;
            for(int l = 1, r; l <= a[i]; l = r + 1){
                r = min(a[i], a[i] / (a[i] / l));
                ans = min(ans, Solve(a[i] / l));
            }
        }
        printf("%d\n", ans);   
	}
	return 0;
}