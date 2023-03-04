//ID: LRL52  Date: 2022.10.7
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e4 + 55; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
using LL = long long;
const LL LIMIT = 1e9 * (1LL << 20);
int n, K;
int Cnt[N], b[N], _b[N], a[N];

int check(LL r) {
    for(int i = 0; i < 50; ++i) Cnt[i] = b[i] = 0;
    rep(i, 1, n) {
        __int128_t t = (__int128_t)a[i] * r;
        if(t >= LIMIT) return 0;
        for(int k = 0; k < 50; ++k) {
            if(t >> k & 1)
                ++Cnt[k];
        }
    }
    for(int i = 0; i < K; ++i) b[i] = _b[i];
    LL need = 0;
    for(int i = 0; i < 50; ++i) {
        if(b[i] > Cnt[i]) {
            auto d = min(need, b[i] - Cnt[i]);
            need -= d, b[i] -= d;
            auto db = (b[i] - Cnt[i]) / 2;
            b[i] -= db * 2;
            b[i + 1] += db;
        } else
            need += Cnt[i] - b[i];
    }
    return need == 0;
    // LL res = 0;
    // for(int i = 49; i >= 0; --i) {
    //     if(b[i] > Cnt[i]) res += b[i] - Cnt[i];
    //     else if(b[i] < Cnt[i]) {
    //         auto d = Cnt[i] - b[i];
    //         if(res >= d) res -= d;
    //         else return 0;
    //     }
    // }
    // return 1;
}

signed main() {
#ifdef LRL52
	freopen("B.in", "w", stdout);
#endif
	int Task; rd(Task);
    while(Task--) {
        rd(n), rd(K);
        rep(i, 1, n) rd(a[i]);
        sort(a + 1, a + n + 1);
        for(int i = 0; i < K; ++i) rd(_b[i]);
        LL l = 0, r = (1LL << 20) * 1e9;
        while(l <= r) {
            LL mid = (l + r) >> 1;
            if(check(mid)) l = mid + 1;
            else r = mid - 1;
        }
        printf("%lld\n", r);
    }
	return 0;
}