//ID: LRL52  Date: 2022.8.16
//建KMP树 + 双指针 + 手写栈模拟DFS题解：https://www.cnblogs.com/Orzjh/p/16519740.html 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
const int MOD = 998244353;
int K, Nxt[N];
char b[N];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%s%d", b + 1, &K);
        int m = strlen(b + 1);
        for(int i = 2, j = 0; i <= m; ++i){
            while(j > 0 && b[j + 1] != b[i]) j = Nxt[j];
            if(b[j + 1] == b[i]) ++j;
            Nxt[i] = j;
        }
        long long ans = 1; int cnt = 0;
        rep(i, 1, m){
            int res = (i % K == 0);
            for(int j = Nxt[i]; j; j = Nxt[j]){
                if(j < i - j + 1) break;
                int t = j - (i - j + 1) + 1;
                if(t % K == 0) ++res;
                if(++cnt >= 10000000) break;
            }
            //printf("%d ", res);
            ans = ans * (res + 1) % MOD;
        }
        //puts("");
        printf("%lld\n", ans);
	}
	return 0;
}
