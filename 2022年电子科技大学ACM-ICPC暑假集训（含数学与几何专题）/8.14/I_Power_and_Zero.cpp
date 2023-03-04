//ID: LRL52  Date: 2022.8.13
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
#define int long long
int n, lim;
int Cnt[N], a[N], b[N];

int check(int K){
    for(int k = 0; k <= lim; ++k) b[k] = Cnt[k];
    b[lim + 1] = 0;
    if(b[0] > K) return 0;
    int t = (K - b[0]) / 2;
    b[0] += t * 2, b[1] -= t; 
    for(int k = 1; k <= lim; ++k){
        if(b[k] > b[k - 1]) return 0;
        t = (b[k - 1] - b[k]) / 2;
        b[k] += t * 2, b[k + 1] -= t;
    }
    if(b[lim + 1] > 0) return 0;
    return 1;
} 

signed main() {
#ifdef LRL52
	freopen("tmp.txt", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n);
        rep(i, 1, n) rd(a[i]);
        for(int k = 0; k < 31; ++k){
            Cnt[k] = 0;
            rep(i, 1, n)
                if(a[i] >> k & 1)
                    ++Cnt[k];
        }
        for(int k = 30; k >= 0; --k){
            if(Cnt[k] > 0){
                lim = k;
                break;
            }
        }
        int l = 1, r = 1e9;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        printf("%lld\n", l);
	}
	return 0;
}