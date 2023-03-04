#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N = 5e3 + 5;
constexpr int M = 1e5 + 5;
constexpr int inf = 0x3f3f3f3f;
void cmin(int &x, int y) {x = x < y ? x : y;}
int n, m, T, root, va[M], vb[M];
int x[N], a[N], y[N], b[N];
ll dx(int i, int j) {return j - i;}
ll dy(int i, int j) {return vb[j] - vb[i];}
ll cr(int i, int j, int k) {
  return dx(i, j) * dy(j, k) - dy(i, j) * dx(j, k);
}
vector<int> e[M]; 
int fa[M], son[M], dep[M], sz[M];
int dn, dfn[M], rev[M], top[M];
void dfs1(int id) {
  sz[id] = 1, dep[id] = dep[fa[id]] + 1;
  for(int it : e[id]) {
    dfs1(it), sz[id] += sz[it];
    if(sz[it] > sz[son[id]]) son[id] = it;
  }
}
void dfs2(int id, int tp) {
  dfn[id] = ++dn, rev[dn] = id, top[id] = tp;
  if(son[id]) dfs2(son[id], tp);
  for(int it : e[id]) if(it != son[id]) dfs2(it, it);
}
int main() {
  #ifdef ALEX_WEI
    FILE* IN = freopen("1.in", "r", stdin);
    FILE* OUT = freopen("1.out", "w", stdout);
  #endif
  cin >> n >> m >> T;
  for(int i = 1; i <= n; i++) cin >> x[i];
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) cin >> y[i];
  for(int i = 1; i <= m; i++) cin >> b[i];
  memset(va, 0x3f, sizeof(va));
  for(int i = 1; i <= n; i++)
    for(int j = i + 1; j <= n; j++)
      cmin(va[x[j] - x[i]], a[i] + a[j]);
  memset(vb, 0x3f, sizeof(vb));
  for(int i = 1; i <= m; i++)
    for(int j = i + 1; j <= m; j++)
      cmin(vb[y[j] - y[i]], b[i] + b[j]);
  static int stc[N], tp = 0;
  for(int i = M - 1; ~i; i--) {
    if(vb[i] == inf) continue;
    while(tp > 1 && cr(i, stc[tp], stc[tp - 1]) <= 0) tp--;
    if(tp) e[stc[tp]].push_back(i), fa[i] = stc[tp];
    else root = i;
    stc[++tp] = i;
  }
  dfs1(root), dfs2(root, root);
  while(T--) {
    ll c = 0, ans = 0, pt = 0;
    cin >> c;
    auto extend = [&]() {
      pt++;
      while(pt <= root && vb[pt] == inf) pt++;
    };
    auto cost = [&](int x, int y) {
      return 1ll * x * vb[y] + 1ll * y * va[x];
    };
    auto check = [&](int x, int y) {
      if(!y) return true;
      while(y) {
        int l = dfn[top[y]], r = dfn[y];
        if(l == r || cost(x, top[y]) <= cost(x, rev[l + 1])) {
          if(cost(x, top[y]) <= c) return true;
        }
        else {
          while(l < r) {
            int m = l + r >> 1;
            if(cost(x, rev[m]) <= cost(x, rev[m + 1])) r = m;
            else l = m + 1;
          }
          return cost(x, rev[l]) <= c;
        }
        y = fa[top[y]];
      }
      return false;
    };
    for(int i = M - 1; ~i && pt <= root; i--) {
      if(va[i] == inf) continue;
      while(pt <= root && check(i, pt))
        ans = max(ans, 1ll * i * pt), extend();
    }
    cout << ans << "\n";
  }
  cerr << 1e3 * clock() / CLOCKS_PER_SEC << " ms\n";
  return 0;
}
/*
g++ std.cpp -o std -std=c++14 -O2 -DALEX_WEI
*/
