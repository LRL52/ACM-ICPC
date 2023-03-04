//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 1e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, maxa, price, W;
int sum[M];
struct Node{
    int a, b;
    inline bool operator<(const Node&t)const{
        return b < t.b;
    }
}P[N];

inline int lowbit(int x){return x & -x;}

void update(int x, int k){
    if(x <= 0) return;
    for(int i = x; i <= 100000; i += lowbit(i)) sum[i] += k;
}

int query(int x){
    if(x <= 0) return 0;
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += sum[i];
    return ret;
}

int calc(int x){
    return (query(100000) - query(x - 1)) * x;
}

int Solve(int c){
    int l = 0, r = maxa;
    while(r - l >= 25){
        int lmid = l + (r - l) / 3;
        int rmid = r - (r - l) / 3;
        if(calc(rmid) > calc(lmid)) l = lmid;
        else r = rmid;
    }
    int ret = -1;
    for(int i = min(100000LL, r + 5); i >= max(0LL, l - 5); --i){
        int res = calc(i);
        if(res > ret){
            ret = res;
            price = i;
        }
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	rd(n), rd(W); int maxb = 0;
    rep(i, 1, n){
        rd(P[i].a), rd(P[i].b);
        maxb = max(maxb, P[i].b);
    }
    sort(P + 1, P + n + 1);
    int adcnt = n, j = 0;
    for(int c = 0; c <= maxb + 1; ++c){
        while(j < n && P[j + 1].b < c){
            ++j, --adcnt;
            update(P[j].a, 1);
            maxa = max(maxa, P[j].a);
        }
        int ans = adcnt * W * c;
        ans += Solve(c);
        printf("%lld %lld\n", ans, price);
    }
	return 0;
}