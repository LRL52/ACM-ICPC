//ID: LRL52  Date: 2022.5.10
//单调队列优化DP
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 50055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int inf = 0x3f3f3f3f;
int n, T;
int price[N], D[N], q[N];
long long f[N];

int check(int K){ //最多可以做K个站
    f[1] = 0;
    int head = 1, tail = 0;
    rep(i, 1, n){
        while(head <= tail && i - q[head] > K) ++head;
        if(head <= tail){
            int j = q[head];
            f[i] = f[j] + i - j + D[j];
        }
        while(head <= tail && f[q[tail]] - q[tail] + D[q[tail]] >= f[i] - i + D[i]) --tail;
        q[++tail] = i;
    }
    return f[n] <= T;
}

int main() {
#ifdef LRL52
	freopen("V.in", "r", stdin);
#endif
    rd(n), rd(T);
    rep(i, 1, n - 1) rd(price[i]);
    rep(i, 2, n - 1) rd(D[i]);
    int l = 1, r = n - 1;
    while(l <= r){
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    int ans = inf;
    rep(i, l, n - 1) ans = min(ans, price[i]);
    printf("%d\n", ans);
	return 0;
}