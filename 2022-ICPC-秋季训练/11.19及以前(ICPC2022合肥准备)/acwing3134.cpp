//ID: LRL52  Date: 2022.10.31
//Burnside引理 + 矩阵快速幂优化DP
#include <bits/stdc++.h>
using namespace std;
const int M = 12, inf = 0x3f3f3f3f, MOD = 9973;
using LL = long long;
struct Mat {
    int c, r, a[M][M];
    Mat() {
        c = r = 0;
        memset(a, 0, sizeof(a));
    }
    Mat(int k) : c(k), r(k) {
        memset(a, 0, sizeof(a));
        for(int i = 0; i < k; ++i) a[i][i] = 1;
    }
    Mat operator*(const Mat& t) const {
        Mat ret; ret.c = c, ret.r = t.r;
        for(int i = 0; i < c; ++i)
            for(int j = 0; j < t.r; ++j)
                for(int k = 0; k < r; ++k)
                    ret.a[i][j] = (ret.a[i][j] + 1LL * a[i][k] * t.a[k][j] % MOD) % MOD;
        return ret;
    }
    friend Mat operator^(Mat A, LL k) {
        Mat ret(A.c);
        while(k) {
            if(k & 1) ret = ret * A;
            A = A * A;
            k >>= 1;
        }
        return ret;
    }
};

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
        int n, m, K, x, y;
        cin >> n >> m >> K;
        Mat tr;
        tr.c = tr.r = m;
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < m; ++j)
                tr.a[i][j] = 1;
        for(int i = 1; i <= K; ++i) {
            cin >> x >> y; --x, --y;
            tr.a[x][y] = tr.a[y][x] = 0;
        }
        LL ans = 0;
        auto getsum = [](const Mat &A)->LL {
            LL ret = 0;
            for(int i = 0; i < A.c; ++i) ret = (ret + A.a[i][i]) % MOD;
            return ret;
        };
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
                ans = (ans + getsum(tr^i) * getphi(n / i) % MOD) % MOD;
                if(i * i != n)
                    ans = (ans + getsum(tr^(n/i)) * getphi(i) % MOD) % MOD;
            }   
        }
        auto Inv = [](LL x)->LL { return ksm(x, MOD - 2); };
        ans = ans * Inv(n) % MOD;
        printf("%lld\n", ans);
    }
	return 0;
}
  