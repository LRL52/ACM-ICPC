//ID: LRL52  Date: 2022.4.30
//吐了啊，最恶心的事情莫过于明明整体做法是对的，就是WA不知哪里错了
//坑点：1. 2^63 用unsigned long long 2. 1ull !!!!!!!!!!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <map>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 5e5 + 55, M = 205; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
//typedef long long LL;
typedef unsigned long long uLL;
int n, m, d, Q, cntN;
int lg[N];
uLL a[N], b[M];
bitset<63> f[N][21];
map<uLL, int> H;

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n), rd(m), rd(d), rd(Q); lg[0] = -1;
    rep(i, 1, n) rd(a[i]), lg[i] = lg[i >> 1] + 1;
    rep(i, 1, m) rd(b[i]);
    sort(b + 1, b + m + 1);
    for(int i = m; i >= 1; --i){
        uLL t = b[i] / d; int ok = 1;
        while(1){
            for(int j = 1; j < i; ++j)
                if(b[j] == t){
                    ok = 0;
                    break;
                }
            if(!ok || t == 0uLL) break;
            t /= d;
        }
        if(ok && (H.find(b[i]) == H.end())) H[b[i]] = cntN++;
    }
    rep(i, 1, n){
        uLL x = a[i];
        while(1){
            if(H.find(x) != H.end()){
                f[i][0] = 1ull << H[x]; //CSP-2019 T1 5分血的教训!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                break;
            }
            if(x == 0uLL) break;
            x /= d;
        }
    }
    for(int j = 1; j <= lg[n]; ++j){
        for(int i = 1; i + (1 << j) - 1 <= n; ++i){
            f[i][j] = f[i][j - 1] | f[i + (1 << (j - 1))][j - 1];
        }
    }
    int l, r;
    rep(i, 1, Q){
        rd(l), rd(r);
        int k = lg[r - l + 1];
        int ans = (f[l][k] | f[r - (1 << k) + 1][k]).count();
        printf("%d\n", ans);
    }
	return 0;
}