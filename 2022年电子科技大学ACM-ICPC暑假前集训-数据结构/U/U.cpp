//ID: LRL52  Date: 2022.5.6 ~ 5.7
//fw实锤了，借llf佬代码对拍了几次终于把错全部找完了
//坑点：1.解密[l, r]时注意可能爆int 2. 询问查询边角时要查询l - 1 和 L[q] - 1 3.中间块是 p + 1 <= q - 1 !!!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
//#include <assert.h>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 12055, M = 125; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
//#define int long long
int n, m, tot;
int sum[N], rt[N], f[M][M], L[N], R[N], pos[N], tr[35 * N][2], latest[35 * N];

void insert(int i, int k, int old, int now){
    if(k < 0) return void(latest[now] = i);
    int bit = sum[i] >> k & 1;
    tr[now][bit] = ++tot, tr[now][bit ^ 1] = tr[old][bit ^ 1];
    //assert(tot < N * 35);
    insert(i, k - 1, tr[old][bit], tr[now][bit]);
    latest[now] = max(latest[tr[now][0]], latest[tr[now][1]]);
}

int query(int x, int k, int l, int now){
	//cerr << "x = " << x << " k = " << k << " l = " << l << " now = " << now << '\n';
    if(k < 0) return x ^ sum[latest[now]];
    int bit = x >> k & 1;
    if(latest[tr[now][bit ^ 1]] >= l) return query(x, k - 1, l, tr[now][bit ^ 1]);
    else return query(x, k - 1, l, tr[now][bit]);
}

int Query(int l, int r){
    int p = pos[l], q = pos[r], ret = 0;
    if(p == q){
        rep(i, l - 1, r) ret = max(ret, query(sum[i], 30, l - 1, rt[r]));
    } else{
        rep(i, l - 1, R[p]) ret = max(ret, query(sum[i], 30, l - 1, rt[r]));
        rep(i, L[q] - 1, r) ret = max(ret, query(sum[i], 30, l - 1, rt[r]));
        if(p + 1 <= q - 1) ret = max(ret, f[p + 1][q - 1]);
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("U.in", "r", stdin);
    freopen("U.out", "w", stdout);
#endif
    rd(n), rd(m);
    rt[0] = ++tot; latest[0] = -1;
    memset(latest, -1, sizeof latest);
    insert(0, 30, 0, rt[0]);
    rep(i, 1, n){
        rd(sum[i]), sum[i] = sum[i] ^ sum[i - 1];
        rt[i] = ++tot;
        insert(i, 30, rt[i - 1], rt[i]);
    }
    int S = sqrt(n), T = n / S;
    //assert(S <= 120 && T <= 120);
    rep(i, 1, T){
        L[i] = (i - 1) * S + 1;
        R[i] = i * S;
    }
    //assert(R[T] <= n);
    if(R[T] < n) ++T, L[T] = R[T - 1] + 1, R[T] = n;
    rep(i, 1, T)
        rep(j, L[i], R[i])
            pos[j] = i;
    rep(i, 1, T){
        int res = 0, l = L[i] - 1;
        rep(j, i, T){
            int r = R[j];
            rep(k, L[j], R[j]){
                res = max(res, query(sum[k], 30, l, rt[r]));
            }
            f[i][j] = res;
        }
    }
    int lastans = 0, l, r, x, y;
    rep(i, 1, m){
        rd(l), rd(r);
        x = ((long long)l + lastans) % n + 1;
        y = ((long long)r + lastans) % n + 1;
        int ans = Query(min(x, y), max(x, y));
        printf("%lld\n", ans);
        lastans = ans;
    }
	return 0;
}
