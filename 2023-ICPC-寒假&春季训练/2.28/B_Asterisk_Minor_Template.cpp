//ID: LRL52  Date: 2023.2.28
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s[N], t[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
        cin >> (s + 1) >> (t + 1);
        int n = strlen(s + 1), m = strlen(t + 1);
        if(s[1] == t[1]) {
            printf("YES\n");
            printf("%c*\n", s[1]);
        }
        else if(s[n] == t[m]) {
            printf("YES\n");
            printf("*%c\n", s[n]);
        } else {
            int ok = 0;
            char c1, c2;
            for(int i = 1; i < n; ++i) {
                for(int j = 1; j < m; ++j) {
                    if(s[i] == t[j] && s[i + 1] == t[j + 1]) {
                        ok = 1;
                        c1 = s[i], c2 = s[i + 1];
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) {
                printf("YES\n");
                printf("*%c%c*\n", c1,c2);
            } else 
                printf("NO\n");
        }

	}
	return 0;
}