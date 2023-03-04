//ID: LRL52  Date: 2022.8.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 1e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
unsigned long long k1 , k2;
unsigned long long xorShift128Plus () {
    unsigned long long k3 = k1 , k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26) ;
    return k2 + k4;
}
int n, m, fa[N];
struct Edge{
    int u, v;
    unsigned long long w;
    inline bool operator<(const Edge&t)const{
        return w < t.w;
    }
}E[M << 1];

void gen () {
    scanf ("%d%d%llu%llu", &n, &m, &k1 , &k2);
    for (int i = 1; i <= m; ++i) {
        E[i].u = xorShift128Plus () % n + 1;
        E[i].v = xorShift128Plus () % n + 1;
        E[i].w = xorShift128Plus () ;
    }
}
const int MOD = 1e9 + 7;
int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    int task; scanf("%d", &task); 
    while(task--){
        gen();
        sort(E + 1, E + m + 1);
        long long ans = 0; int cnt = 0;
        rep(i, 1, n) fa[i] = i;
        rep(i, 1, m){
            int u = E[i].u, v = E[i].v;
            int f1 = find(u), f2 = find(v);
            if(f1 != f2){
                fa[f1] = f2;
                ans += E[i].w % MOD;
                ans %= MOD;
                if(++cnt == n - 1) break;
            }
        }
        if(cnt < n - 1) ans = 0;
        printf("%lld\n", ans);
    }
	return 0;
}