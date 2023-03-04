//ID: LRL52  Date: 2022.7.15
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
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
int n, a[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n) rd(a[i]);
    sort(a + 1, a + n + 1);
    long long step = 0, p = 0, cnt = 0;
    a[0] = -1;
    for(int i = 1; i <= n; ){
        int j = i;
        while(j < n && a[j + 1] == a[i]) ++j;
        int len = j - i + 1;
        if(len >= 2) ++cnt;
        if(len > 2 || (len == 2 && a[i - 1]  + 1 == a[i])){
            puts("cslnb");
            return 0;
        }
        i = j + 1;
    }
    if(cnt > 1){
        puts("cslnb");
        return 0;
    }
    rep(i, 1, n){
        if(a[i] == p){
            while(i < n && a[i + 1] == p) ++i;
        } else{
            step += a[i] - p;
        }
        p++;
    }
    //printf("%lld\n", step);
    if(step & 1) puts("sjfnb");
    else puts("cslnb");
	return 0;
}