//ID: LRL52  Date: 2023.2.12
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s[N];
// int f[N];

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> (s + 1);
    int n = strlen(s + 1);
    i64 sum = 0, one = 0;
    for(int i = 1; i <= n; ++i) {
        if(s[i] == '0') sum += one;
        else one++;
    }
    // f[0] = 0, f[1] = 1;
    // for(int i = 2; i <= 1000; ++i) {
    //     if(f[i - 2] == 0 || f[i - 1] == 0) f[i] = 1;
    //     printf("f[%d] = %d\n", i, f[i]);
    // }
    if(sum % 3 == 0) puts("Bob");
    else puts("Alice");
	return 0;
}