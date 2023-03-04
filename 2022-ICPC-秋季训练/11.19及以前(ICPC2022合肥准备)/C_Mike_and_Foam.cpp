//ID: LRL52  Date: 2022.11.6
//容斥原理基本应用，容斥每个质因子，Cnt[i]表示含有因子i的数的个数
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 2e5 + 55, M = 5e5 + 55;
int n, qs, Pcnt, vis[M], a[N], vm[M], prime[M], d[M], Cnt[M];
vector<int> p[M];

void Euler(int up) {
    vm[1] = 1;
    for(int i = 2; i <= up; ++i) {
        if(!vm[i]) prime[++Pcnt] = i, vm[i] = i;
        for(int j = 1; prime[j] <= up / i; ++j) {
            vm[i * prime[j]] = prime[j];
            if(i % prime[j] == 0) break;
        }
    }
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	Euler(M - 55);
    rep(i, 1, Pcnt) {
        for(int j = prime[i]; j <= M - 55; j += prime[i]) {
            p[j].emplace_back(prime[i]);
        }
    }
    cin >> n >> qs;
    rep(i, 1, n) cin >> a[i];
    long long ans = 0;
    while(qs--) {
        int idx, x;
        cin >> idx; x = a[idx];
        if(!vis[idx]) {
            vis[idx] = 1;
            for(int s = 0; s < (1 << p[x].size()); ++s) {
                int sign = 0, d = 1;
                for(size_t i = 0; i < p[x].size(); ++i) {
                    if((s >> i) & 1) {
                        sign++;
                        d *= p[x][i];
                    }
                }
                sign = (sign & 1) ? -1 : 1;
                ans += sign * Cnt[d];
                ++Cnt[d];
            }
        } else {
            vis[idx] = 0;
            for(int s = 0; s < (1 << p[x].size()); ++s) {
                int sign = 0, d = 1;
                for(size_t i = 0; i < p[x].size(); ++i) {
                    if((s >> i) & 1) {
                        sign++;
                        d *= p[x][i];
                    }
                }
                sign = (sign & 1) ? -1 : 1;
                --Cnt[d];
                ans -= sign * Cnt[d];
                
            }
        }
        printf("%lld\n", ans);
    }       
	return 0;
} 
    