//ID: LRL52  Date: 2022.7.26
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
const int inf = 0x3f3f3f3f;
int A, B, n;
struct Node{
    int x, y;
}a[N], b[N];

struct cmp1{
    inline bool operator()(const Node&t1, const Node&t2)const{
        return t1.x < t2.x;
    }
};

struct cmp2{
    inline bool operator()(const Node&t1, const Node&t2)const{
        return t1.y < t2.y;
    }
};

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(A), rd(B);
        int u, v, w, z, y, x, e, f;
        v = x = y = e = inf;
        u = z = w = f = -inf;
        rep(i, 1, n){
            rd(a[i].x), rd(a[i].y);
            if(a[i].x == 0) y = min(y, a[i].y), u = max(u, a[i].y);
            if(a[i].x == A) e = min(e, a[i].y), z = max(z, a[i].y);
            if(a[i].y == 0) x = min(x, a[i].x), f = max(f, a[i].x);
            if(a[i].y == B) v = min(v, a[i].x), w = max(w, a[i].x);
        }
        int ans = 0;
        if(x != inf && y != inf) ans = max(ans, x * y);
        if(u != -inf && v != inf) ans = max(ans, (B - u) * v);
        if(w != -inf && z != -inf) ans = max(ans, (A - w) * (B - z));
        if(e != inf && f != -inf) ans = max(ans, (A - f) * e);
        if(y != inf && x == inf && w != -inf) ans = max(ans, y * w);
        if(x != inf && y == inf && z != -inf) ans = max(ans, z * x);
        if(u != -inf && v == inf && f != -inf) ans = max(ans, f * (B - u));
        if(v != inf && u == -inf && e != inf) ans = max(ans, v * (B - e));
        if(w != -inf && z == -inf && y != inf) ans = max(ans, (A - w) * (B - y));
        if(z != -inf && w == -inf && x != inf) ans = max(ans, (A - x) * (B - z));
        if(e != inf && f == -inf && v != inf) ans = max(ans, e * (A - v));
        if(f != -inf && e == inf && u != -inf) ans = max(ans,u * (A - f));
        //printf("y = %d x = %d\n", y, x);
        int tot = 0;
        rep(i, 1, n){
            if(a[i].y == 0 || a[i].y == B)
                b[++tot] = a[i];
        } 
        sort(b + 1, b + tot + 1, cmp1());
        int lst = b[1].x;
        if(tot > 0 && y == inf) ans = max(ans, b[1].x * B);
        rep(i, 2, tot){
            ans = max(ans, (b[i].x - lst) * B);
            lst = b[i].x;
        }
        if(tot > 0 && e == inf) ans = max(ans, (A - lst) * B);
        tot = lst = 0;
        rep(i, 1, n){
            if(a[i].x == 0 || a[i].x == A)
                b[++tot] = a[i];
        }
        sort(b + 1, b + tot + 1, cmp2());
        lst = b[1].y;
        if(tot > 0 && x == inf) ans = max(ans, b[1].y * A);
        rep(i, 2, tot){
            ans = max(ans, (b[i].y - lst) * A);
            lst = b[i].y;
        }
        if(tot > 0 && v == inf) ans = max(ans, (B - lst) * A);
        if(min(x, v) != inf){
            int L = A - min(x, v); tot = 0;
            rep(i, 1, n){
                if(a[i].x == A)
                    b[++tot] = a[i];
            }
            sort(b + 1, b + tot + 1, cmp2());
            lst = b[1].y;
            //if(tot > 0 && f == x) ans = max(ans, 
            rep(i, 2, tot){
                ans = max(ans, (b[i].y - lst) * L);
                lst = b[i].y;
            }
            //if(
        }
        if(max(w, f) != -inf){
            int L = max(w, f); tot = 0;
            rep(i, 1, n){
                if(a[i].x == 0)
                    b[++tot] = a[i];
            }
            sort(b + 1, b + tot + 1, cmp2());
            lst = b[1].y;
            rep(i, 2, tot){
                ans = max(ans, (b[i].y - lst) * L);
                lst = b[i].y;
            }
        }
        if(max(u, z) != -inf){
            int L = max(u, z); tot = 0;
            rep(i, 1, n){
                if(a[i].y == 0)
                    b[++tot] = a[i];
            }
            sort(b + 1, b + tot + 1, cmp1());
            lst = b[1].x;
            rep(i, 2, tot){
                ans = max(ans, (b[i].x - lst) * L);
                lst = b[i].x;
            }
        }
        if(min(y, e) != inf){
            int L = B - min(y, e); tot = 0;
            rep(i, 1, n){
                if(a[i].y == B)
                    b[++tot] = a[i];
            }
            sort(b + 1, b + tot + 1, cmp1());
            lst = b[1].x;
            rep(i, 2, tot){
                ans = max(ans, (b[i].x - lst) * L);
                lst = b[i].x;
            }
        }
        printf("%lld\n", ans);
	}
	return 0;
}