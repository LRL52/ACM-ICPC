//ID: LRL52  Date: 2022.6.7
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <assert.h>
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
typedef unsigned int uint;
int S;
uint a[N];
struct Number{
    int pos; uint val;
    inline bool operator<(const Number&t)const{
        return val%7 > t.val%7;
    }
}b[N][N];

int dfs(int dep, int sum, int maxdep){
    if(dep > maxdep){
        if(sum >= S) return 1;
        else return 0;
    }
    rep(i, 1, dep) b[dep][i] = {i, a[i]};
    sort(b[dep] + 1, b[dep] + dep + 1);
    rep(i, 1, dep){
        uint x = b[dep][i].val; int pos = b[dep][i].pos;
        if(sum + (int)(x%7) + 6 * (maxdep - dep) < S) return 0;
        a[pos] = 213346089u * x + 870413u;
        a[dep + 1] = 166042049u * x + 598777u;
        if(dfs(dep + 1, sum + (int)(x%7), maxdep)) return 1;
        a[pos] = x;
    }
    return 0;
}

int main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	uint seed;
    rd(seed), rd(S);
    a[1] = seed;
    for(int depth = 1; ; depth++){
        if(dfs(1, 0, depth)){
            printf("%d\n", depth);
            return 0;
        }
        assert(a[1] == seed);
    }
	return 0;
}