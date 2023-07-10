/*** 
 * @Author: LRL52
 * @Date: 2023-05-05 21:03:25
 * @LastEditTime: 2023-05-05 21:44:48
 */
#include <bits/stdc++.h>
using namespace std;

//计算 1 ~ n 的和
int calcSum(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) res += i;
    return res;
}

//计算 1 ~ n 的和
int calcSum(int n) {
    return n * (n + 1) / 2;
}

//计算 1 ~ n的平方和
int calcSum(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) res += i * i;
    return res;
}

//计算斐波那契数列的第n项
int fib(int n) {
    if (n == 1 || n == 2) return 1;
    return fib(n - 1) + fib(n - 2);
}

//计算组合数C(n, m)
int C(int n, int m) {
    if (m == 0 || m == n) return 1;
    return C(n - 1, m - 1) + C(n - 1, m);
}

//计算卡特兰数第n项
int Catalan(int n) {
    if (n == 0) return 1;
    return Catalan(n - 1) * (4 * n - 2) / (n + 1);
}

//计算错排数第n项
int derange(int n) {
    if (n == 0) return 1;
    if (n == 1) return 0;
    return (n - 1) * (derange(n - 1) + derange(n - 2));
}

//计算最大公约数
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

//计算最小公倍数
int lcm(int a, int b) {
    return a * b / gcd(a, b);
}

//计算n的阶乘
int factorial(int n) {
    if (n == 0) return 1;
    return n * factorial(n - 1);
}

//计算x^y mod p
int qpow(int x, int y, int p) {
    int res = 1;
    while (y) {
        if (y & 1) res = res * x % p;
        x = x * x % p;
        y >>= 1;
    }
    return res;
}

//Dijkstra算法求最短路
const int N = 1e5 + 55, inf = 0x3f3f3f3f;
int n, m, et, dis[N], vis[N];
struct Edge{
    int v, w, nxt;
}e[N << 1];
int head[N];
struct Node {
    long long d; int v;
};

void Dijkstra(int start) {
    memset(dis, 0x3f, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    priority_queue<Node> q;
    q.push({dis[start] = 0, start});
    while (!q.empty()) {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt) {
            int v = e[i].v, w = e[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    }
}

//多项式板子
namespace Poly {

const int N = 1 << 18 | 55, mod = 998244353, G = 3;
using LL = long long;
int tot, bit, rev[N];

void NTT(LL *a, int sign) {
    for (int i = 0; i < tot; ++i)
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int L = 1; L < tot; L <<= 1) {
        LL w1 = qpow(G, (mod - 1) / (L << 1), mod);
        if (sign == -1) w1 = qpow(w1, mod - 2, mod);
        for (int i = 0; i < tot; i += L << 1) {
            LL wk = 1;
            for (int j = 0; j < L; ++j, wk = wk * w1 % mod) {
                int x = a[i + j], y = wk * a[i + j + L] % mod;
                a[i + j] = (x + y) % mod, a[i + j + L] = (x - y + mod) % mod;
            }
        }
    }
    if (sign == 1) return;
    int inv = qpow(tot, mod - 2, mod);
    for (int i = 0; i < tot; ++i) a[i] = a[i] * inv % mod;

}

}

//tarjan 求强联通分量
const int N = 1e5 + 55, M = 2e5 + 55;
int n, m, et, dfn[N], low[N], cnt, instk[N], stk[N], top, scc[N], scc_cnt;
struct Edge{
    int v, nxt;
}e[M];

int head[N];

void tarjan(int x) {
    dfn[x] = low[x] = ++cnt;
    stk[++top] = x, instk[x] = 1;
    for (int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (instk[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if (dfn[x] == low[x]) {
        ++scc_cnt;
        while (stk[top] != x) {
            scc[stk[top]] = scc_cnt;
            instk[stk[top]] = 0;
            --top;
        }
        scc[x] = scc_cnt;
        instk[x] = 0;
        --top;
    }
}

//Splay 模板
const int N = 1e5 + 55;
int n, m, rt, et, ch[N][2], fa[N], val[N], cnt[N], sz[N];
int stk[N], top;

void pushup(int x) {
    sz[x] = sz[ch[x][0]] + sz[ch[x][1]] + cnt[x];
}

void rotate(int x) {
    int y = fa[x], z = fa[y], k = ch[y][1] == x;
    ch[y][k] = ch[x][!k], fa[ch[x][!k]] = y;
    ch[x][!k] = y, fa[y] = x, fa[x] = z;
    if (z) ch[z][ch[z][1] == y] = x;
    pushup(y), pushup(x);
}

void splay(int x, int goal) {
    while (fa[x] != goal) {
        int y = fa[x], z = fa[y];
        if (z != goal) {
            if ((ch[y][0] == x) ^ (ch[z][0] == y)) rotate(x);
            else rotate(y);
        }
        rotate(x);
    }
    if (!goal) rt = x;
}

void insert(int x) {
    if (!rt) {
        rt = ++et;
        val[rt] = x, cnt[rt] = sz[rt] = 1;
        return;
    }
    int cur = rt, f = 0;
    while (1) {
        if (val[cur] == x) {
            ++cnt[cur], ++sz[cur];
            splay(cur, 0);
            break;
        }
        f = cur;
        cur = ch[cur][val[cur] < x];
        if (!cur) {
            cur = ++et;
            val[cur] = x, cnt[cur] = sz[cur] = 1;
            fa[cur] = f, ch[f][val[f] < x] = cur;
            splay(cur, 0);
            break;
        }
    }
}

int find(int x) {
    int cur = rt;
    while (1) {
        if (sz[ch[cur][0]] >= x && x > 0) cur = ch[cur][0];
        else if (x > sz[ch[cur][0]] + cnt[cur]) {
            x -= sz[ch[cur][0]] + cnt[cur];
            cur = ch[cur][1];
        } else {
            splay(cur, 0);
            return cur;
        }
    }
}

int pre() {
    int cur = ch[rt][0];
    while (ch[cur][1]) cur = ch[cur][1];
    return cur;
}

int nxt() {
    int cur = ch[rt][1];
    while (ch[cur][0]) cur = ch[cur][0];
    return cur;
}

void del(int x) {
    int lst = pre(), nxt = nxt();
    splay(lst, 0), splay(nxt, lst);
    int del = ch[nxt][0];
    if (cnt[del] > 1) {
        --cnt[del], --sz[del];
        splay(del, 0);
    } else {
        ch[nxt][0] = 0;
    }
}

//树状数组
const int N = 1e5 + 55;
int n, m, a[N], c[N];

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i)) c[i] += v;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += c[i];
    return res;
}

//线段树
const int N = 1e5 + 55;
int n, m, a[N];
struct Node{
    int l, r, sum, tag;
}t[N << 2];

void pushup(int p) {
    t[p].sum = t[p << 1].sum + t[p << 1 | 1].sum;
}




int main() {
    int n;
    cin >> n;
    int res = calcSum(n);
    return 0;
}