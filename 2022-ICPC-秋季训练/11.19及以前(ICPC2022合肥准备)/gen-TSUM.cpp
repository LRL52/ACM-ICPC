//ID: LRL52  Date: 2022.11.4
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f;


signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n = 40000;
    printf("%d\n", n);
    rep(i, 1, n) {
        long long x = rand() * rand() % 20000;
        if(i & 1) printf("%d\n", x);
        else printf("%d\n", -x);
    }
	return 0;
} 
    