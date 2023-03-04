//ID: LRL52  Date: 2023.2.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;


int Solve(vector<int> &a, int n, int K) {
    if(K <= 0) return 0;
    if(n == 1) {
        return a[1] + 1 <= K;
    }
    int mid = (1 + n) / 2;
    vector<pii> b(n + 1);
    for(int i = 1; i <= mid; ++i) b[i] = { a[i] + i, i };
    for(int i = mid + 1; i <= n; ++i) b[i] = { a[i] + n + 1 - i, i };
    sort(b.begin() + 1, b.begin() + n + 1);
    int ok = 0, ans = 0; LL sum = 0;
    for(int i = 1; i <= n; ++i) {
        auto [w, p] = b[i];
        if(sum + w <= K) {
            sum += w, ++ans;
            if(p <= mid) ok = 1;
        } else 
            break;
    }
    if(ok) return ans;
    if(ans == 0) return 0;
    vector<int> a2(mid + 1);
    for(int i = 1; i <= mid; ++i)
        a2[i] = a[i];
    int res1 = Solve(a2, mid, K);
    a2.resize(n - mid + 1);
    for(int i = 1; i <= n - mid; ++i)
        a2[i] = a[mid + i];
    int res2 = Solve(a2, n - mid, K - mid);
    return max(res1, res2);
}

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n, K, Task; cin >> Task;
    while(Task--) {
        cin >> n >> K;
        vector<int> a(n + 1);
        rep(i, 1, n) cin >> a[i];
        int ans = Solve(a, n, K);
        cout << ans << '\n';
    }
	return 0;
}