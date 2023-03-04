//ID: LRL52  Date: 2022.11.13
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e5 + 55;
using LL = long long;
const int MOD = 998244353, G = 3, Gi = 332748118;
namespace Poly {
    int tot, bit, rev[N << 2]; //注意这里

    LL ksm(LL a, LL k) {
        LL ret = 1;
        while(k) {
            if(k & 1) ret = ret * a % MOD;
            a = a * a % MOD;
            k >>= 1;
        }
        return ret;
    }
    LL Inv(LL x) { return ksm(x, MOD - 2); }

    void NTT(vector<LL> &a, int sign) {
        for(int i = 0; i < tot; ++i)
            if(i < rev[i])
                swap(a[i], a[rev[i]]);
        for(int L = 1; L < tot; L <<= 1) {
            LL w1 = ksm(sign == 1 ? G : Gi, (MOD - 1) / (L << 1));
            for(int i = 0; i < tot; i += L << 1) {
                int wk = 1;
                for(int j = 0; j < L; ++j, wk = wk * w1 % MOD) {
                    int x = a[i + j], y = wk * a[i + j + L] % MOD;
                    a[i + j] = (x + y) % MOD, a[i + j + L] = (x - y + MOD) % MOD;
                }
            }
        }
        if(sign == 1) return;
        int inv = ksm(tot, MOD - 2);
        for(int i = 0; i < tot; ++i) a[i] = a[i] * inv % MOD;
    }

    void PolyMul(vector<LL> &a, vector<LL> &b, int n) {
        static vector<LL> c; c.resize(N << 2);
        tot = 1, bit = 0;
        while(tot < (n << 1)) ++bit, tot <<= 1;
        for(int i = 0; i < tot; ++i) rev[i] = (rev[i >> 1] >> 1) | (i & 1) << (bit - 1);
        for(int i = 0; i < n; ++i) c[i] = b[i];
        for(int i = n; i < tot; ++i) c[i] = a[i] = 0;
        NTT(a, 1); NTT(c, 1);
        for(int i = 0; i < tot; ++i) a[i] = a[i] * c[i] % MOD;
        NTT(a, -1);
    }
}
using Poly::ksm;
using Poly::Inv;
int n, m, K;
LL S[N], sum[N << 2];
int inv[N], fact[N], factinv[N];
void Prework(int n) {
    fact[0] = fact[1] = inv[1] = factinv[0] = factinv[1] = 1;
    rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    rep(i, 2, n) inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
    rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m) {
    if(m > n || n < 0 || m < 0) return 0;
    return 1LL * fact[n] * factinv[n - m] % MOD * factinv[m] % MOD;
}

/*LL* Solve(int l, int r, int rt) {
    if(l == r) {
        sum[rt] = S[l];
        LL *a = new LL [S[l] + 5];
        for(int i = 0; i < S[l] + 5; ++i) a[i] = 0;
        for(int i = 1; i <= S[l]; ++i)
            a[i] = C(S[l], i);
        return a;
    }
    int mid = (l + r) >> 1;
    LL *a = Solve(l, mid, rt << 1), *b = Solve(mid + 1, r, rt << 1 | 1);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    LL *c = new LL [(sum[rt] << 2) + 5], *d = new LL [(sum[rt] << 2) + 5];
    for(int i = 0; i <= sum[rt << 1]; ++i) c[i] = a[i];
    for(int i = 0; i <= sum[rt << 1 | 1]; ++i) d[i] = b[i];
    Poly::PolyMul(c, d, sum[rt] + 1);
    delete [] a;
    delete [] b;
    delete [] d;
    return c;
}*/

void Solve(int l, int r, int rt, vector<LL>& a) {
    if(l == r) {
        sum[rt] = S[l];
        //LL *a = new LL [S[l] + 5];
        a.resize(S[l] + 5);
        for(int i = 0; i < S[l] + 5; ++i) a[i] = 0;
        for(int i = 1; i <= S[l]; ++i)
            a[i] = C(S[l], i);
        //return a;
        return;
    }
    int mid = (l + r) >> 1;
    //LL *a = Solve(l, mid, rt << 1), *b = Solve(mid + 1, r, rt << 1 | 1);
    vector<LL> b;
    Solve(l, mid, rt << 1, a); Solve(mid + 1, r, rt << 1 | 1, b);
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    //LL *c = new LL [(sum[rt] << 2) + 5], *d = new LL [(sum[rt] << 2) + 5];
    //for(int i = 0; i <= sum[rt << 1]; ++i) c[i] = a[i];
    ///for(int i = 0; i <= sum[rt << 1 | 1]; ++i) d[i] = b[i];
    a.resize((sum[rt] << 2) + 5); 
    b.resize((sum[rt] << 2) + 5);
    Poly::PolyMul(a, b, sum[rt] + 1);
    // delete [] a;
    // delete [] b;
    // delete [] d;
    //return c;
}


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    Prework(N - 55);
	cin >> n >> m >> K;
    rep(i, 1, m) cin >> S[i];
    //LL *Ans = Solve(1, m, 1);
    vector<LL> Ans;
    Solve(1, m, 1, Ans);
    printf("%lld\n", Ans[K]);
	return 0;
} 
    