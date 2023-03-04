//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };
int n;
char s[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	map<char, int> H{ {'U', 0}, {'R', 1}, {'D', 2}, {'L', 3} };
    int Task; cin >> Task;
    while(Task--) {
        cin >> n >> (s + 1);
        int x = 0, y = 0, ok = 0;
        for(int i = 1; i <= n; ++i) {
            int k = H[s[i]];
            x += dx[k], y += dy[k];
            if(x == 1 && y == 1) ok = 1;
        }
        ok ? puts("YES") : puts("NO");
    }
	return 0;
}