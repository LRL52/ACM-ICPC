//ID: LRL52  Date: 2022.7.5
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
typedef long long LL;
const LL M = 1LL << 40;
LL S[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	S[0] = 1611516670;
    int n = 1000;
    printf("%lld\n", S[0] & 1);
    for(int i = 1; i < n; ++i){
        S[i] = (S[i - 1] + (S[i - 1] >> 20) + 12345LL) % M;
        printf("%lld\n", S[i] & 1);
    }
	return 0;
}
