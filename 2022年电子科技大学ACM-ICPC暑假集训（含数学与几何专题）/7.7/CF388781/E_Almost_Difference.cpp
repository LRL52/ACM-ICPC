//ID: LRL52  Date: 2022.7.7
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 200055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n;
int sum[N], Cnt[N];
struct Node{
    int x, id;
    inline bool operator<(const Node&t)const{
        return x < t.x;
    }
}a[N];

inline int lowbit(int x){return x & -x;}

void update1(int x, int k){
    for(int i = x; i <= n; i += lowbit(i))
        sum[i] += k;
}

void update2(int x, int k){
    for(int i = x; i <= n; i += lowbit(i))
        Cnt[i] += k;
}

int query1(int x){
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += sum[i];
    return ret;
}

int query2(int x){
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += Cnt[i];
    return ret;
}

void print(__int128_t x){
    if(x < 0){
        putchar('-');
        x = -x;
    }
    if(x > 9) print(x / 10);
    putchar(x % 10 + '0');
}

signed main() {
#ifdef LRL52
	freopen("E.in", "r", stdin);
    //freopen("E.out", "w", stdout);
#endif
	rd(n);
    rep(i, 1, n) rd(a[i].x), a[i].id = i, update1(i, a[i].x), update2(i, 1);
    sort(a + 1, a + n + 1);
    //int ans = 0; 
    int p = 1;
    __int128_t ans = 0;
    rep(i, 1, n){
        while(p < n && a[p].x - a[i].x <= 1){
            update1(a[p].id, -a[p].x);
            update2(a[p].id, -1);
            ++p;
        }
        if(a[p].x - a[i].x > 1){
            //ans += sum[n] - sum[p - 1] - a[i] * (n - p + 1);
            int s = query1(n) - query1(a[i].id), cnt = query2(n) - query2(a[i].id);
            ans += s - (__int128_t)cnt * a[i].x;
            s = query1(a[i].id - 1), cnt = query2(a[i].id - 1);
            ans += (__int128_t)cnt * a[i].x - s;
        }
    }
    //printf("%llu\n", ans);
    //printf("%lld\n", LONG_LONG_MAX);
    print(ans);
	return 0;
}
