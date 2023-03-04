//ID: LRL52  Date: 2022.8.10
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
struct Node{
    int d, x, ans;
    inline bool operator<(const Node&t)const{
        return ans > t.ans;
    }
};
priority_queue<Node> q;
vector<int> p, c;
map<long long, int> dis;

void Divide(int n){
    vector<int>().swap(p);
    vector<int>().swap(c);
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0){
            p.push_back(i);
            c.push_back(0);
            while(n % i == 0) n /= i, c[c.size() - 1]++;
        }
    }
    if(n > 1) p.push_back(n), c.push_back(1);
}

signed main() {
#ifdef LRL52
	freopen("J.out", "r", stdin);
#endif
	int Task; rd(Task);
    int a, b; const long long base = 1e9;
	while(Task--){
        rd(a), rd(b);
        if(a > b) swap(a, b);
        int D = b - a;
        if(D == 0) D = a;
        Divide(D);
        q.push({D, a, 0});
        int ans = inf;
        dis.clear();
        dis[D * base + a] = 0;
        while(!q.empty()){
            Node qu = q.top(); q.pop();
            int d = qu.d, x = qu.x;
            if(x == 1){
                ans = min(ans, qu.ans);
                continue;
            }
            if(qu.ans >= ans) continue;
            if(dis[d * base + x] != qu.ans) continue;
            for(int i = 0; i < p.size(); ++i){
                int t = p[i];
                if(d % t == 0){
                    int r = x % t;
                    if(x - r >= 1){
                        int nd = d / t, nx = (x - r) / t, nans = qu.ans + r + 1;
                        long long ns = nd * base + nx;
                        if(qu.ans + r + 1 < ans && (dis.find(ns) == dis.end() || nans < dis[ns])){
                            dis[ns] = nans;
                            q.push({nd, nx, nans});
                        }
                    }
                    if(r != 0){
                        r = t - r;
                        int nd = d / t, nx = (x + r) / t, nans = qu.ans + r + 1;
                        long long ns = nd * base + nx;
                        if(qu.ans + r + 1 < ans && (dis.find(ns) == dis.end() || nans < dis[ns])){
                            dis[ns] = nans;
                            q.push({nd, nx, nans});
                        }
                    }
                }
            }
            int nd = d, nx = 1, nans = qu.ans + x - 1;
            long long ns = nd * base + nx;
            if(nans < ans && (dis.find(ns) == dis.end() || nans < dis[ns])){
                dis[nx] = nans;
                q.push({nd, nx, nans});
            }
        }
        printf("%d\n", ans);
	}
	return 0;
}