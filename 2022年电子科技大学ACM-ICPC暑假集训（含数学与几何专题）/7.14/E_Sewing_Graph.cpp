    //ID: LRL52  Date: 2022.7.13
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <algorithm>
    #define rep(i, a, b) for(int i = (a); i <= (b); ++i)
    #define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
    using namespace std;
    const int N = 1055, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
    inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
    template<class T>inline void rd(T& x) {
        int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
        while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
    }
    int n;
    struct Node{
        int x, y, id;
        inline bool operator<(const Node&t)const{
            if(x != t.x) return x < t.x;
            return y < t.y;
        }
    }a[N];

    signed main() {
    #ifdef LRL52
        freopen("A.in", "r", stdin);
    #endif
        rd(n); int x, y;
        rep(i, 1, n){
            rd(a[i].x), rd(a[i].y);
            a[i].id = i;
        }
        sort(a + 1, a + n + 1);
        printf("%d\n", 2 * n - 1);
        //rep(i, 1, n - 1) printf("%d %d ", a[i + 1].id, a[i].id);
        //printf("%d\n", a[n].id);
        rep(i, 1, n) printf("%d ", a[i].id);
        for(int i = n - 1; i >= 1; --i) printf("%d ", a[i].id);
        return 0;
    }