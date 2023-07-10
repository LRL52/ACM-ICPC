/*** 
 * @Author: LRL52
 * @Date: 2023-05-19 23:31:58
 * @LastEditTime: 2023-05-19 23:47:17
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 2e5 + 55, inf = 0x3f3f3f3f, MOD = 1e9 + 7;
int n, et, is_circle, DFN, circle_cnt;
struct Edge{
    int v, nxt;
}e[N << 1];
int head[N], dfn[N], a[N];

inline void adde(int from, int to){
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

void dfs(int x) {
    dfn[x] = ++DFN;
    for (int i = head[x]; i; i = e[i].nxt) {
        int v = e[i].v;
        if (dfn[v]) {
            if(dfn[v] < dfn[x]) continue;
            is_circle = 1;
        } else {
            dfs(v);
        }
    }
}

signed main() {
#ifdef LRL52
	freopen("E.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) { 
		cin >> n; et = DFN = circle_cnt = 0;
        for (int i = 1; i <= n; ++i) head[i] = dfn[i] = a[i] = 0;
        for (int i = 1; i <= n; ++i) {
            int x; cin >> x; a[i] = x;
            if (a[x] == i) continue;
            adde(i, x), adde(x, i);
        }
        int ans1 = 0, ans2 = 0, line = 0;
        for (int i = 1; i <= n; ++i) {
            if (dfn[i]) continue;
            ++ans2;
            is_circle = 0;
            dfs(i);
            if (!is_circle) line = 1;
            else circle_cnt += 1;
        }
        ans1 = circle_cnt + line;
        printf("%d %d\n", ans1, ans2);
	}
	return 0;
}