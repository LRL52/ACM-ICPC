//ID: LRL52  Date: 2022.7.8
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, K;
int a[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(K);
        rep(i, 1, n) a[i] = i;
        int cnt = 0;
        for(int i = 2; i < n && cnt < K; i += 2){
            swap(a[i], a[i + 1]);
            ++cnt;
            if(cnt == K) break;
        }
        if(cnt < K) puts("-1");
        else{
            rep(i, 1, n) printf("%d ", a[i]);
            putchar('\n');
        }
	}
	return 0;
}
