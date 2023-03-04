//ID: LRL52  Date: 2022.7.11
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = (1e5 + 55) * 4; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
    int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
    while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int inf = 0x3f3f3f3f;
int n, L, a[N], b[N], sum[N];

int main() {
#ifdef LRL52
    freopen("E.in", "r", stdin);
#endif
    rd(n), rd(L);
    rep(i, 1, n - 1) rd(a[i]), sum[i] = sum[i - 1] + a[i];
    /*rep(i, n, n + L) a[i] = inf;
    rep(i, 1, L) b[i] = a[i];
    int p = 0;
    for(int i = 1; i + L < n; i += L){
        int res = 0;
        for(int j = i + L - 1; j >= i; --j){
            //int cnt = min(a[j + L], b[j] + res)
            if(b[j] + res <= a[j + L]){
                b[j + L] = b[j] + res;
                res = 0;
            } else{
                b[j + L] = a[j + L];
                res = b[j] + res - a[j + L];
            }
        }
        p = i + L;
    }
    int ans = 0;
    //rep(i, n, n + L - 1) ans += b[i];
    //for(int i = n + L - 1; i >= max(1, n - L); --i) ans += b[i];
    rep(i, p, p + L - 1) ans += b[i];
    printf("%d\n", ans); */
    int ans = inf;
    for(int i = L; i < n; ++i)
        ans = min(ans, sum[i] - sum[i - L]);
    printf("%d\n", ans);
    return 0;
}
