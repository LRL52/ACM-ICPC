//ID: LRL52  Date: 2023.2.6
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, K;
    cin >> n >> K;
    if(n == 1) {
        if(K == 0) {
            puts("YES");
            puts(".");
        } else
            puts("NO");
        return 0;
    }
    if(n == 2) {
        if(K == 0) {
            puts("YES");
            puts("..");
            puts("..");
        }
        else if(K == 1) {
            puts("YES");
            puts("#.");
            puts("..");
        }
        else puts("NO");
        return 0;
    }
    if(K <= n * n - n) {
        puts("YES");
        int cnt = 0;
        rep(i, 1, n) {
            rep(j, 1, n) {
                if(i == 1 && j == n) putchar('.');
                else if(i == n && j == 1) putchar('.');
                else if(i != 1 && i != n && j == i) putchar('.');
                else if(++cnt <= K) putchar('#');
                else putchar('.');
            }
            puts("");
        }
    } else 
        puts("NO"); 
	return 0;
}