//ID: LRL52  Date: 2022.5.18 ~ 5.19
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int X[N], Y[N], X0[N], Y0[N];
struct Node{
    int x, y, val, ok;
    inline bool operator<(const Node&t)const{
        return val < t.val;
    }
}a[N * N];
struct cmp{
    inline bool operator()(const Node&t1, const Node&t2)const{
        if(t1.x != t2.x) return t1.x < t2.x;
        return t1.y < t2.y;
    }
};

inline int dist(int x, int y, int u, int v){
    return abs(x - u) + abs(y - v);
}

inline void update(int k, int x, int y){
    if(dist(x, y, X0[k], Y0[k]) < dist(X[k], Y[k], X0[k], Y0[k])){
        X[k] = x, Y[k] = y;
    }
}

int main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
    rd(n), rd(m); int cnt = 0;
    rep(i, 1, n){
        rep(j, 1, n){
            ++cnt;
            rd(a[cnt].val);
            a[cnt].x = i, a[cnt].y = j;
        }
    }
    sort(a + 1, a + cnt + 1);
    a[cnt].ok = 1; int ans = 1;
    X0[0] = 1, Y0[0] = 1, X[0] = a[cnt].x, Y[0] = a[cnt].y;
    X0[1] = 1, Y0[1] = n, X[1] = a[cnt].x, Y[1] = a[cnt].y;
    X0[2] = n, Y0[2] = 1, X[2] = a[cnt].x, Y[2] = a[cnt].y;
    X0[3] = n, Y0[3] = n, X[3] = a[cnt].x, Y[3] = a[cnt].y;
    for(int i = cnt - 1; i >= 1; --i){
        a[i].ok = 1;
        for(int k = 0; k < 4; ++k){
            if(dist(a[i].x, a[i].y, X[k], Y[k]) > m){
                a[i].ok = 0;
                break;
            }
        }
        if(a[i].ok){
            ++ans;
            for(int k = 0; k < 4; ++k){
                update(k, a[i].x, a[i].y);
            }
        }
    }
    sort(a + 1, a + cnt + 1, cmp());
    printf("%d\n", ans);
    rep(i, 1, cnt)
        if(a[i].ok)
            printf("%d %d\n", a[i].x, a[i].y);
	return 0;
}