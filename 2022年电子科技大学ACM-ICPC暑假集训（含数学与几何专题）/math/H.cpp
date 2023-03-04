//ID: LRL52  Date: 2022.7.6
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 1e9 + 7;
pair<int, int> nextPair(int &x) {
    int a, b;
    x ^= x << 13; x ^= x >> 17; x ^= x << 5; x %= 10000000; a = x;
    x ^= x << 13; x ^= x >> 17; x ^= x << 5; x %= 10000000; b = x;
    b = max(b, 1); a = max(a % b, 1);
    return make_pair(a, b);
}

int ksm(int a, int k){
    int ret = 1;
    while(k){
        if(k & 1) ret = 1LL * ret * a % MOD;
        a = 1LL * a * a % MOD;
        k >>= 1;
    }
    return ret;
}

int Inv(int x){
    return ksm(x, MOD - 2);
}

int main() {
#ifdef LRL52
	freopen("H.in", "r", stdin);
#endif
	int n, x, ans = 0;
    rd(n), rd(x);
    rep(i, 1, n){
        pair<int, int> pii = nextPair(x);
        int res = 1LL * pii.second * Inv(pii.first) % MOD; 
        ans = (ans + res) % MOD;
    }
    printf("%d\n", ans);
	return 0;
}
