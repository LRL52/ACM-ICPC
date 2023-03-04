//ID: LRL52  Date: 2022.11.12
//思维题，据说可以证明客人和饭的匹配不会相交
//枚举第1个客人匹配哪个饭，然后分4种情况：1.只顺时针2.只逆时针3.先顺后逆4.先逆后顺
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 5e5 + 55;
long long n, K, a[N], b[N], c[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        cin >> n >> K;
        rep(i, 1, K) cin >> a[i];
        rep(i, 1, K) cin >> b[i];
        sort(a + 1, a + K + 1);
        sort(b + 1, b + K + 1);
        long long ans = 1e10;
        for(int i = 0; i < K; ++i) {
            for(int j = 1; j <= K; ++j) {
                int pos = (j + i > K) ? j + i - K : j + i;  
                c[j] = (a[pos] >= b[j]) ? a[pos] - b[j] : n - (b[j] - a[pos]);
            }
            sort(c + 1, c + K + 1);
            ans = min(ans, min(c[K], n - c[1]));
            for(int j = 1; j < K; ++j) {
                ans = min(ans, c[j] * 2LL + (n - c[j + 1]));
                ans = min(ans, (n - c[j + 1]) * 2LL + c[j]);
            }
        }
        printf("%lld\n", ans);
    }
	return 0;
} 
    