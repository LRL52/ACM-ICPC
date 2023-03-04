//ID: LRL52  Date: 2022.8.8
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
map<int, int> H;
int MOD, a, n, q;
int s[N], d[N];

int ksm(int a, int k){
    int ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(MOD), rd(a), rd(n), rd(q);
        rep(i, 1, n){
            rd(s[i]), rd(d[i]);
        }
        int res = 1, MAXN = 200000;
        H.clear();
        H[res] = 0;
        for(int i = 1; i <= MAXN; ++i){
            res = res * a % MOD;
            if(H.find(res) == H.end())
                H[res] = i;
            else
                break;
        }
        int x;
        rep(tt, 1, q){
            rd(x);
            int ans = 0;
            rep(i, 1, n){
                if(s[i] == 0){
                    ans += (x == 0);
                } else{
                    int y = x * ksm(s[i], MOD - 2) % MOD;
                    //printf("x = %lld y = %lld\n", x, y);
                    if(H.find(y) != H.end() && H[y] <= d[i])
                        ++ans;
                }
            }
            printf("%lld\n", ans);
        }
	}
	return 0;
}