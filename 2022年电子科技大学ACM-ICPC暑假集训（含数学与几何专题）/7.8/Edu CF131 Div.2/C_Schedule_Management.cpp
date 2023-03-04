//ID: LRL52  Date: 2022.7.8
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int a[N];

int check(int T){
    int res = 0;
    rep(i, 1, n)
        if(a[i] > T)
            res += a[i] -T;
    rep(i, 1, n)
        if(a[i] < T)
            res -= min((T - a[i]) / 2, res);
    return res == 0;
}
    

int main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(m); int x, y;
        rep(i, 1, n + 1) a[i] = 0;
        rep(i, 1, m){
            rd(x);
            ++a[x];
        }
        sort(a + 1, a + n + 1);
        /*int ans = a[1];
        rep(i, 2, n) a[i] -= a[1];
        a[1] = 0;
        int p = 0, ass = 0, dcnt0 = 0, cnt0 = 0;
        rep(i, 1, n)
            if(a[i] == 0) ++cnt0;
            else break;
        while(1){
            while(p < n && a[p] <= 1) ++p;
            if(p == n && a[p] <= 2){
                ans += max(a[p], ass > 0 ? 2 : 0);
                break;
            }
            int dx = min(cnt0 - ass, a[p] - 1);
            ass += dx, a[p] -= dx;
            if(a[p] <= 1) ++dcnt0; 
            if(ass == cnt0){
                ans += 2;
                cnt0 += dcnt0;
                dcnt0 = ass = 0;
                a[p] -= min(2, a[p]);
            }
        }*/
        int l = 1, r = m * 2;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        printf("%d\n", l);
	}
	return 0;
}
