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
#define int long long
int n, vis[N], a[N], b[N], order[N], Ans[N];

int Solve(){
    rep(i, 1, n) vis[i] = 0;
    int ret = 0;
    rep(i, 1, n){
        int t = order[i];
        int d = inf, idx = 0;
        rep(j, 1, n){
            if(vis[j]) continue;
            if(abs(a[j] - b[t]) < d){
                d = abs(a[j] - b[t]);
                idx = j;
            }
        }
        ret += d;
        vis[idx] = 1;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
    freopen("F-std.out", "w", stdout);
#endif
    rd(n);
    rep(i, 1, n) rd(a[i]);
    rep(i, 1, n) rd(b[i]);
    rep(i, 1, n) order[i] = i;
    int ans = 1e18;
    do{
        int res = Solve();
        if(res < ans){
            ans = res;
            rep(i, 1, n) Ans[i] = order[i];
        }
    }while(next_permutation(order + 1, order + n + 1));
    printf("%lld\n", ans);
    rep(i, 1, n) printf("%lld ", Ans[i]);
	return 0;
}