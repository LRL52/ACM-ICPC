//ID: LRL52  Date: 2022.8.10
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, Pcnt;
int a[N], st[N], prime[N], Ans[N];
vector<int> d[N], p[N], c[N];
set<int> s[N];

void Euler(int n){
    for(int i = 2; i <= n; ++i){
        if(!st[i]) st[i] = 1, prime[++Pcnt] = i;
        for(int j = 1; prime[j] <= n / i; ++j){
            st[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

void dfs(int n, int i, int now){
    if(i >= (int)p[n].size()){
        d[n].push_back(now);
        return;
    }
    int x = 1;
    for(int j = 0; j <= c[n][i]; ++j){
        dfs(n, i + 1, now * x);
        x *= p[n][i];
    }
}

void init_d(int MAXN){
    for(int t = 1; t <= MAXN; ++t){
        int n = t;
        for(int i = 1; prime[i] * prime[i] <= n; ++i){
            if(n % prime[i] == 0){
                p[t].push_back(prime[i]), c[t].push_back(0);
                while(n % prime[i] == 0) c[t][c[t].size()-1]++, n /= prime[i];
            }
        }
        if(n > 1) p[t].push_back(n), c[t].push_back(1);
        dfs(t, 0, 1);
        sort(d[t].begin(), d[t].end(), greater<int>());
    }
    //for(int i = 0; i < d[256].size(); ++i) printf("%d ", d[256][i]);
    //puts("");
}

struct Edge{
    int v, nxt;
}e[N << 1];
int head[N];

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs_tree(int x, int far){
    //s[x].insert(a[x]);
    for(int i = 0; i < d[a[x]].size(); ++i)
        s[x].insert(d[a[x]][i]);
    ee(i, x){
        int v = e[i].v;
        if(v == far) continue;
        dfs_tree(v, x);
        for(set<int>::reverse_iterator it = s[v].rbegin(); it != s[v].rend(); it++){
            int t = *it;
            //printf("x = %d t = %d\n", x, t);
            if(t <= Ans[x]) break;
            if(s[x].find(t) != s[x].end()){
                Ans[x] = max(Ans[x], t);
                break;
            }
            /*for(int j = 0; j < d[t].size(); ++j){
                int _d = d[t][j];
                if(s[x].find(_d) != s[x].end()){
                    Ans[x] = max(Ans[x], _d);
                    break;
                }
            }*/
        }
        if(s[v].size() > s[x].size()) swap(s[x], s[v]);
        if(s[x].size() >= 100000) continue;
        for(set<int>::iterator it = s[v].begin(); it != s[v].end(); it++){
            int t = *it;
            s[x].insert(t);
        }
        set<int>().swap(s[v]);
    }
}

signed main() {
#ifdef LRL52
	freopen("temp.in", "r", stdin);
    freopen("temp.out", "w", stdout);
#endif
    Euler(100000); //记着改
    init_d(100000);
    rd(n); int x, y;
    rep(i, 2, n){
        rd(x);
        adde(i, x), adde(x, i);
    }
    rep(i, 1, n) rd(a[i]);
    dfs_tree(1, -1);
    rep(i, 1, n){
        if(Ans[i] == 0) puts("-1");
        else printf("%d\n", Ans[i]);
    }
	return 0;
}