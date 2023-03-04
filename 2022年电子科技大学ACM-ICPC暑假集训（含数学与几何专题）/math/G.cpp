//ID: LRL52  Date: 2022.7.21
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n;
struct Node{
    int x, y;
    Node operator+(const Node&t)const{
        return (Node){x + t.x, y + t.y};
    }
    Node operator-(const Node&t)const{
        return (Node){x - t.x, y - t.y};
    }
    int operator^(const Node&t)const{
        return x * t.y - y * t.x;
    }
    int operator*(const Node&t)const{
        return x * t.x + y * t.y;
    }
}a[N], b[N], O;

inline int quad(const Node&t){
    if(t.y > 0) return 4;
    if(t.y < 0) return 1;
    if(t.x < 0) return 5;
    if(t.x > 0) return 3;
    return 2;
}

struct cmp{
    inline bool operator()(const Node&t1, const Node&t2)const{
        int qa = quad(t1-O), qb = quad(t2-O);
        if(qa != qb) return qa < qb;
        int res = (t1-O)^(t2-O);
        return res > 0;
    }
};

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
    freopen("G.out", "w", stdout);
#endif
	rd(n);
    rep(i, 1, n) rd(a[i].x), rd(a[i].y);
    int res = 0; //钝角三角形 + 直角三角形 + 三点共线的数量
    rep(i, 1, n){
        int p = 0;
        rep(j, 1, n){
            if(j == i) continue;
            b[++p] = a[j];
        }
        O = a[i];
        sort(b + 1, b + p + 1, cmp());
        int l = 1, r = 1, r2 = 0, first = 1;
        //if(i == 3){
        //    puts("qaq");
        //}
        int t = 0;
        for(; l <= p; ++l){
            while(r < p && (b[r] - O) * (b[l] - O) > 0){
                int ok = ((b[r+1] - O) * (b[l] - O) <= 0) ||
                         (((b[r+1] - O) ^ (b[l] - O)) <= 0);
                if(!ok) break;
                ++r;
            }
            //if(first) r2 = r, first = 0;
            r2 = max(r2, r);
            while(r2 < p && (b[r2 + 1] - O) * (b[l] - O) <= 0) ++r2;
            if((b[r] - O) * (b[l] - O) <= 0 && (b[r2] - O) * (b[l] - O) <= 0){
                res += r2 - r + 1;
                t += r2 - r + 1;
            }
        }
        //printf("t = %d\n", t);
    }
    int ans = n * (n - 1) * (n - 2) / 6 - res;
    printf("%lld\n", ans);
	return 0;
}