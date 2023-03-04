//ID: LRL52  Date: 2022.7.21
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
int n, K, a[N];

signed main() {
	scanf("%lld%lld", &n, &K);
    int dx = max(1LL, n / 900);
    for(int i = 1; i <= n; i += dx){
        printf("? %lld\n", i); fflush(stdout);
        scanf("%lld", &a[i]);
    }
    int val = 0x3f3f3f3f3f3f3f3f, pos = -1;
    for(int i = 1; i <= n; i += dx){
        if(a[i] > K && a[i] < val){
            val = a[i];
            pos = i;
        }
    }
    int l = 1, r = pos, x;
    while(l <= r){
        int mid = (l + r) >> 1;
        printf("? %lld\n", mid); fflush(stdout);
        scanf("%lld", &x);
        if(x <= K) l = mid + 1;
        else r = mid - 1;
    }
    if(r >= 1){
        printf("! %lld\n", r); fflush(stdout);
        return 0;
    }
    l = max(pos + 1, n - 120), r = n;
    while(l <= r){
        int mid = (l + r) >> 1;
        printf("? %lld\n", mid); fflush(stdout);
        scanf("%lld", &x);
        if(x <= K) l = mid + 1;
        else r = mid - 1;
    }
    printf("! %lld\n", r); fflush(stdout);
	return 0;
}