    //ID: LRL52  Date: 2022.7.12
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <algorithm>
    #define rep(i, a, b) for(int i = (a); i <= (b); ++i)
    #define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
    using namespace std;
    const int N = 2e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
    inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
    template<class T>inline void rd(T& x) {
        int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
        while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
    }
    #define int long long
    int n;
    int a[N];

    signed main() {
    #ifdef LRL52
        freopen("A.in", "r", stdin);
    #endif
        //int Task; rd(Task);
        //while(Task--){
        rd(n);
        rep(i, 1, 2 * n) rd(a[i]);
        sort(a + 1, a + 2 * n + 1);
        int ans = 0;
        for(int i = 1, j = 2 * n; i <= n; ++i, --j)
            ans = max(ans, a[i] * a[j]);
        printf("%lld\n", ans);
        //}
        return 0;
    }
