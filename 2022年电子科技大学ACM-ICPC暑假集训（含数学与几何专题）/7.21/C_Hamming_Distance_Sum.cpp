//ID: LRL52  Date: 2022.7.21
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 200000 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
int n, sum0[N], sum1[N], m;
char a[N], b[N];

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	scanf("%s%s", a + 1, b + 1);
    int n = strlen(a + 1), m = strlen(b + 1);
    rep(i, 1, n){
        sum0[i] = sum0[i - 1] + (a[i] == '0');
        sum1[i] = sum1[i - 1] + (a[i] == '1');
    }
    /*int ans = 0;
    rep(i, 1, n){
        if(b[i] == '0') ans += sum1[i];
        else ans += sum0[i];
    }
    rep(i, n + 1, m - n){
        if(b[i] == '0') ans += sum1[n];
        else ans += sum0[n];
    }
    rep(i, max(n + 1, m - n + 1), m){
        if(b[i] == '0') ans += sum1[n] - sum1[n - (m - i + 1)];
        else ans += sum0[n] - sum0[n - (m - i + 1)];
    }*/
    int ans = 0;
    rep(i, 1, m){
        int r = min(i, n), l = max(0LL, n - (m - i + 1));
        if(b[i] == '0') ans += sum1[r] - sum1[l];
        else ans += sum0[r] - sum0[l];
    }
    printf("%lld\n", ans);
	return 0;
}