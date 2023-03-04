//ID: LRL52  Date: 2022.7.7
//蜀黍我啊，真是没有想到还有一个操作叫做差分！！！！
//差分，差分，差分！！！
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 30055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int inf = 0x3f3f3f3f;
int n;
int a[N], b[N];
int sign[] = {-1, 1, -1, 1};

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	/*while(Task--){
        rd(n);
        rep(i, 1, n) rd(a[i]);
        int p = 0, ok = 1, flag = 1, lst = 0, minv1 = inf, minv2 = inf, maxv = -inf;
        rep(i, 2, n){
            if(a[i] < minv1){
                minv2 = minv1;
                minv1 = a[i];
            } else if(a[i] < minv2){
                minv2 = a[i];
            }
            if(a[i] > maxv) maxv = a[i];
            if(a[i] == a[i - 1]) continue;
            int now = (a[i] - a[i - 1] > 0) ? 1 : -1;
            while(p < 4 && now != sign[p]) ++p;
            if(lst != 0 && now != lst) flag = 0;
            lst = now;
            if(p >= 4){
                ok = 0;
                break;
            }
        }
        if(flag == 0 && p == 3 && minv1 + minv2 < maxv) ok = 0;
        ok ? puts("YES") : puts("NO");
	}*/
    while(Task--){
        rd(n);
        rep(i, 1, n) rd(a[i]);
        rep(i, 1, n) b[i] = a[i] - a[i - 1];
        long long s = 0;
        rep(i, 1, n)
            if(b[i] < 0)
                s += -b[i];
        if(a[1] >= s) puts("YES");
        else puts("NO");
    }
	return 0;
}
