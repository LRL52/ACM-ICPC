//ID: LRL52  Date: 2022.7.20
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

int getlen(int K){
    if(K == 0) return 1;
    if(K == 1) return 2;
    if(K == 2) return 3;
    int ret = 1;
    for(int i = K - 1; i >= 2; --i){
        ret += i * (1LL << (i-1));
    }
    ret += 2;
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		int len; rd(len);
        /*if(X == 1){
            puts("0");
            continue;
        }
        int k = 0;
        while((1 << (k+1)) - 1 <= X) ++k;
        if((1 << (k)) - 1 == X) --k;
        printf("%d\n", k);*/
        int l = 0, r = 40;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(getlen(mid) > len) r = mid - 1;
            else l = mid + 1;
        }
        printf("%lld\n", r);
	}
	return 0;
}