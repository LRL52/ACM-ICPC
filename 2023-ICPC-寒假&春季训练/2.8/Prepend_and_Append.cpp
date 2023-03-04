//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        string s; int n;
        cin >> n >> s;
        for(int i = 0, j = (int)s.size() - 1; ;) {
            if(j - i + 1 <= 1) {
                printf("%d\n", j - i + 1);
                break;
            }
            if(s[i] != s[j]) {
                ++i, --j;
                continue;
            } else {
                printf("%d\n", j - i + 1);
                break;
            }
        }
    }
	return 0;
}