//ID: LRL52  Date: 2022.7.18
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, a[N], l[N], r[N], vis[N];
char s[N];
vector<int> Ans[2];
struct Node{
    int x, y, diff;
    inline bool operator<(const Node&t)const{
        if(diff != t.diff) return diff < t.diff;
        return min(x, y) < min(t.x, t.y);
    }
};
multiset<Node> S;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    scanf("%d", &n);
    scanf("%s", s + 1);
    rep(i, 1, n) rd(a[i]);
    rep(i, 0, n + 1) l[i] = i - 1, r[i] = i + 1;
    rep(i, 2, n){
        if(s[i] != s[i - 1]){
            S.insert((Node){i - 1, i, abs(a[i] - a[i - 1])});
        }
    }
    while(!S.empty()){
        multiset<Node>::iterator it = S.begin();
        int x = it->x, y = it->y; S.erase(it);
        if(vis[x] || vis[y]) continue;
        vis[x] = vis[y] = 1;
        Ans[0].push_back(x), Ans[1].push_back(y);
        int lx = l[x], ry = r[y];
        r[lx] = r[y];
        l[ry] = l[x];
        if(lx >= 1 && ry <= n && s[lx] != s[ry]) S.insert((Node){lx, ry, abs(a[lx] - a[ry])});
    }
    printf("%u\n", Ans[0].size());
    for(int i = 0; i < Ans[0].size(); ++i){
        int x = Ans[0][i], y = Ans[1][i];
        if(x > y) swap(x, y);
        printf("%d %d\n", x, y);
    }
	return 0;
}