//ID: LRL52  Date: 2022.7.18
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 105, M = 1e7+55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m, belong[N], W[N], mp[N][N], Ans[N];
long long del[M];
struct Node{
    long long sta; int rmb;
    inline bool operator<(const Node&t)const{
        return sta < t.sta;
    }
};
set<Node> s[N];

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	rd(n); rd(m);
    for(int i = 1; i <= n; ++i) rd(belong[i]);
    for(int i = 1; i <= n; ++i) rd(W[i]);
    int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        mp[x][y] = 1;
    }
    set<Node>::iterator it, it2;
    s[1].insert((Node){1LL << (belong[1]-1), W[belong[1]]});
    Ans[1] = W[belong[1]];
    for(int now = 1; now <= n; ++now){
        for(int nxt = now + 1; nxt <= n; ++nxt){
            if(mp[now][nxt] == 0) continue;
            for(it = s[now].begin(); it != s[now].end(); it++){
                long long sta = it->sta; int rmb = it->rmb;
                long long nsta; int nrmb;
                if((sta >> (belong[nxt]-1))&1){
                    nsta = sta;
                    nrmb = rmb;
                } else{
                    nsta = sta | (1LL << (belong[nxt]-1));
                    nrmb = rmb + W[belong[nxt]];
                }
                int p = 0, ok = 1;
                for(it2 = s[nxt].begin(); it2 != s[nxt].end(); it2++){
                    long long sta2 = it2->sta;
                    if((nsta | sta2) == sta2){
                        ok = 0; break;
                    }
                    if((nsta | sta2) == nsta){
                        del[++p] = sta2;
                    }
                }
                rep(i, 1, p) s[nxt].erase((Node){del[i], 0});
                if(ok) s[nxt].insert((Node){nsta, nrmb});
                Ans[nxt] = max(Ans[nxt], nrmb);
            }
        }
    }
    rep(i, 1, n) printf("%d\n", Ans[i]);
	return 0;
}