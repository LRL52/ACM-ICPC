#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e6 + 5;
int n, p[N], f[N], buc[N];
vector<int> e[N];
void dfs(int id) {
  f[id] = 1;
  for(int it : e[id]) dfs(it), f[id] = max(f[id], f[it] + 1);
  buc[f[id]]++;
}
void solve() {
  cin >> n;
  for(int i = 1; i <= n; i++) e[i].clear(), buc[i] = 0;
  for(int i = 2; i <= n; i++) scanf("%d", &p[i]), e[p[i]].push_back(i);
  dfs(1);
  int ans = N;
  for(int i = 1; i <= n; i++) ans = min(ans, i + buc[i] - 1);
  cout << ans << "\n";
}
int main() {
  #ifdef ALEX_WEI
    freopen("0.in", "r", stdin);
    freopen("0.out", "w", stdout);
  #endif
  int T;
  cin >> T;
  while(T--) solve();
  return 0;
}
