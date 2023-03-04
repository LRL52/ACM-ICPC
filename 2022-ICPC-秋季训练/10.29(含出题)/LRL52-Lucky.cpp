//ID: LRL52  Date: 2022.10.28
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6, N = MAXN + 55, MOD = 9;
int f[N], pow52[N], sum[N];

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
	f[0] = 5, f[1] = 2;
    sum[0] = ksm(f[0], 52), sum[1] = (sum[0] + ksm(f[1], 52)) % MOD; 
    pow52[0] = 1, pow52[1] = 7;
    for(int i = 2; i <=MAXN; ++i) {
        f[i] = (1LL * pow52[i - 1] * f[i - 1] % MOD + 1LL * pow52[i - 2] * f[i - 2] % MOD) % MOD;
        sum[i] = (sum[i - 1] + ksm(f[i], 52)) % MOD;
        pow52[i] = pow52[i - 1] * 52 % MOD;
    }
    int Task; cin >> Task;
    while(Task--) {
        int n; cin >> n;
        sum[n] ? puts("NO") : puts("YES");
    }
	return 0;
}
