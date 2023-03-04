//ID: LRL52  Date: 2022.10.31
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f;
typedef long long LL;
LL ksm(LL a, LL k){
    LL ret = 1;
    while(k){
        if(k & 1) ret = ret * a;
        a = a * a;
        k >>= 1;
    }
    return ret;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, m;
    while(1) {
        cin >> m >> n;
        if(n == 0 && m == 0) break;
        long long ans = 0; 
        for(int i = 0; i < n; ++i)
            ans += ksm(m, gcd(n, i));
        if(n & 1)
            ans += n * ksm(m, (n + 1) / 2);
        else
            ans += n / 2 * (ksm(m, n / 2 + 1) + ksm(m, n / 2));
        printf("%lld\n", ans / 2 / n);
    }
	return 0;
}
  