//ID: LRL52  Date: 2022.11.1
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 55, M = 2055, MOD = 1e9 + 7;
typedef long long LL;
LL ksm(LL a, LL k){
    LL ret = 1;
    while(k){
        if(k & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        k >>= 1;
    }
    return ret;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        int n; LL ans = 0;
        cin >> n;
        auto getphi = [](int n)->int {
            int ret = n;
            for(int i = 2; i * i <= n; ++i) {
                if(n % i == 0) {
                    ret = ret / i * (i - 1);
                    while(n % i == 0) n /= i;
                }
            }
            if(n > 1) ret = ret / n * (n - 1);
            return ret % MOD;
        };
        for(int i = 1; i * i <= n; ++i) {
            if(n % i == 0) {
                ans = (ans + ksm(n, i) * getphi(n / i) % MOD) % MOD;
                if(i * i != n)
                    ans = (ans + ksm(n, n/i) * getphi(i) % MOD) % MOD;
            }
        }
        auto Inv = [](LL x)->LL { return ksm(x, MOD - 2); };
        ans = ans * Inv(n) % MOD;
        printf("%lld\n", ans);
    }
	return 0;
}