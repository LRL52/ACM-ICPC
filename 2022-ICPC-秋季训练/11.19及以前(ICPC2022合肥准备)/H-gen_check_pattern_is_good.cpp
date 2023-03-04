//ID: LRL52  Date: 2022.11.14
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f;


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    srand(time(NULL));
    freopen("H.in", "w", stdout);
	int T = 1000;
    printf("%d\n", T);
    rep(tt, 1, T) {
        int n = 100, m = 100;
        printf("%d %d\n", n, m);
        rep(i, 1, n) {
            rep(j, 1, m) {
                int x = rand() % 3;
                if(x == 0) putchar('?');
                else if(x == 1) putchar('B');
                else putchar('W');
            }
            puts("");
        }
    }
	return 0;
} 
    