//ID: LRL52  Date: 2022.7.11
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
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
int n, m, K;
int fa[N], Size[N], gov[N], ecnt[N], vis[N];
vector<int> S;

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	rd(n), rd(m), rd(K); int x, y;
    rep(i, 1, n) fa[i] = i, Size[i] = 1;
    rep(i, 1, K) rd(x), gov[x] = 1;
    rep(i, 1, m){
        rd(x), rd(y);
        int f1 = find(x), f2 = find(y);
        if(f1 != f2){
            fa[f1] = f2;
            gov[f2] |= gov[f1];
            Size[f2] += Size[f1];
            ecnt[f2] += ecnt[f1] + 1;
        } else
            ecnt[f1]++;
    }
    int ans = 0, maxs = 0;
    rep(i, 1, n){
        int f1 = find(i);
        if(vis[f1]) continue;
        vis[f1] = 1;
        ans += Size[f1] * (Size[f1] - 1) / 2 - ecnt[f1];
        if(gov[f1]) maxs = max(maxs, Size[f1]);
        else S.push_back(Size[f1]);
    }
    for(int i = 0; i < S.size(); ++i){
        ans += maxs * S[i];
        maxs += S[i];
    }
    printf("%d\n", ans);
	return 0;
}
