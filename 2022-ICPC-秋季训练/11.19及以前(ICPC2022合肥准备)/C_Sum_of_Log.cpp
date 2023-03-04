//ID: LRL52  Date: 2022.11.13
//有点技巧的数位DP，枚举最高位1的位置，把时间复杂度降到一个log
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 35, MOD = 1e9 + 7;
int n, m, Num1[N], Num2[N];
LL f[N][2][2];

int div(int x, int* Num) {
    // memset(Num, 0, sizeof(Num)); //传递的指针不能清空
    int ret = 0;
    while(x) {
        Num[++ret] = x % 2;
        x /= 2;
    }
    return ret;
}

LL dfs(int pos, int lim1, int lim2) {
    auto &ans = f[pos][lim1][lim2];
    if(ans != -1) return ans;
    if(pos == 0) return ans = 1;
    ans = 0;
    int up1 = (lim1 ? Num1[pos] : 1), up2 = (lim2 ? Num2[pos] : 1);
    for(int i = 0; i <= up1; ++i)
        for(int j = 0; j <= up2; ++j) {
            if(i & j) continue;
            ans += dfs(pos - 1, i == up1 && lim1, j == up2 && lim2);
            ans %= MOD;
        }
    return ans;
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        cin >> n >> m;
        memset(f, -1, sizeof(f));
        memset(Num1, 0, sizeof(Num1));
        memset(Num2, 0, sizeof(Num2));
        int len1 = div(n, Num1), len2 = div(m, Num2);
        long long ans = 0;
        for(int i = max(len1, len2); i >= 1; --i) {
            long long res = 0;
            if(i <= len1)
                (res += dfs(i - 1, i == len1, i > len2)) %= MOD;
            if(i <= len2)
                (res += dfs(i - 1, i > len1, i == len2)) %= MOD;
            (ans += res * i % MOD) %= MOD;
        }
        printf("%lld\n", ans);
    }       
	return 0;
}  