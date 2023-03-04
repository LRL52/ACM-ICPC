//ID: LRL52  Date: 2022.7.11
//后来知道这题是个加法器原理
//a + b = (a | b) + (a & b)
//ai + bi = ti + t_{i+1}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int a[N], b[N], t[N], unable[N][4];

int dfs(int i){
    if(i == n + 1) return 1;
    for(int k = 0; k <= 3; ++k){
        if(unable[i][k]) continue;
        if((k & t[i - 1]) == b[i - 1] && (k | t[i - 1]) == a[i - 1]){
            t[i] = k;
            if(dfs(i + 1)) return 1;
            else unable[i][k] = 1;
        }
    }
    return 0;
}
            

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	rd(n);
    rep(i, 1, n - 1) rd(a[i]);
    rep(i, 1, n - 1) rd(b[i]);
    rep(i, 0, 3){
        t[1] = i;
        if(dfs(2)){
            puts("YES");
            rep(j, 1, n) printf("%d ", t[j]);
            return 0;
        }
    }
    puts("NO");
	return 0;
}
