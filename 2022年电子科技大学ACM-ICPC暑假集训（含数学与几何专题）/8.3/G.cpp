//ID: LRL52  Date: 2022.8.1
#include <bits/stdc++.h>
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
int sum[N << 2][31], tag[N << 2][31], c[N], mp[N];
int MOD, n, a[N], Cnt[N];

int ksm(int a, int k){
    int ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

#define lson l, mid, rt << 1
#define rson mid + 1, r, rt << 1 | 1
#define ls (rt << 1)
#define rs (rt << 1 | 1)
inline void pushup(int l, int r, int rt){
    for(int i = 0; i < MOD; ++i){
        sum[rt][i] = sum[ls][i] + sum[rs][i];
    }
}

inline void pushdown(int l, int r, int rt){
    if(tag[rt][0] == -1) return;
    if(tag[ls][0] != -1)
        for(int i = 0; i < MOD; ++i) tag[ls][i] = tag[rt][tag[ls][i]];
    else
        for(int i = 0; i < MOD; ++i) tag[ls][i] = tag[rt][i];
    for(int i = 0; i < MOD; ++i) c[i] = sum[ls][i], sum[ls][i] = 0;
    for(int i = 0; i < MOD; ++i) sum[ls][tag[rt][i]] += c[i];
    if(tag[rs][0] != -1)
        for(int i = 0; i < MOD; ++i) tag[rs][i] = tag[rt][tag[rs][i]];
    else
        for(int i = 0; i < MOD; ++i) tag[rs][i] = tag[rt][i];
    for(int i = 0; i < MOD; ++i) c[i] = sum[rs][i], sum[rs][i] = 0;
    for(int i = 0; i < MOD; ++i) sum[rs][tag[rt][i]] += c[i];
    tag[rt][0] = -1;
}

void buildtree(int l, int r, int rt){
    if(l == r){
        sum[rt][a[l]] = 1;
        return;
    }
    tag[rt][0] = -1;
    int mid = (l + r) >> 1;
    buildtree(lson);
    buildtree(rson);
    pushup(l, r, rt);
}

void update(int x, int y, int l, int r, int rt){
    if(x <= l && r <= y){
        if(tag[rt][0] == -1) 
            for(int i = 0; i < MOD; ++i) tag[rt][i] = mp[i];
        else{
            for(int i = 0; i < MOD; ++i) tag[rt][i] = mp[tag[rt][i]];
        }
        for(int i = 0; i < MOD; ++i) c[i] = sum[rt][i], sum[rt][i] = 0;
        for(int i = 0; i < MOD; ++i) sum[rt][mp[i]] += c[i];
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(l, r, rt);
    if(x <= mid) update(x, y, lson);
    if(y >  mid) update(x, y, rson);
    pushup(l, r, rt);
}        

void query(int x, int y, int l, int r, int rt){
    if(x <= l && r <= y){
        for(int i = 0; i < MOD; ++i) Cnt[i] += sum[rt][i];
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(l, r, rt);
    if(x <= mid) query(x, y, lson);
    if(y >  mid) query(x, y, rson);
    pushup(l, r, rt);
}


signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	rd(n), rd(MOD);
    rep(i, 1, n) rd(a[i]), a[i] %= MOD;
    buildtree(1, n, 1);
    int qs, op, l, r, k; rd(qs);
    rep(tt, 1, qs){
        rd(op), rd(l), rd(r), rd(k);
        if(op == 1){
            for(int i = 0; i < MOD; ++i) mp[i] = (i + k) % MOD;
            update(l, r, 1, n, 1);
        } else
        if(op == 2){
            for(int i = 0; i < MOD; ++i) mp[i] = i * k % MOD;
            update(l, r, 1, n, 1);
        } else 
        if(op == 3){
            for(int i = 0; i < MOD; ++i) mp[i] = ksm(i, k);
            update(l, r, 1, n, 1);
        } else
        if(op == 4){
            for(int i = 0; i < MOD; ++i) mp[i] = ksm(i, k), Cnt[i] = 0;
            query(l, r, 1, n, 1);
            int ans = 0;
            for(int i = 0; i < MOD; ++i)
                ans = (ans + Cnt[i] * mp[i] % MOD) % MOD;
            printf("%lld\n", ans);
        } else
        if(op == 5){
            for(int i = 0; i < MOD; ++i) Cnt[i] = 0;
            query(l, r, 1, n, 1);
            int ans = 1;
            for(int i = 0; i < MOD; ++i)
                ans = ans * ksm(i, Cnt[i]) % MOD;
            printf("%lld\n", ans);
        }
        //for(int i = 0; i < MOD; ++i) printf("%lld ", sum[1][i]);
        //puts("");
    }
	return 0;
}