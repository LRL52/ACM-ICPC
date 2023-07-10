/*** 
 * @Author: LRL52
 * @Date: 2023-05-08 20:24:46
 * @LastEditTime: 2023-05-08 23:13:24
 */
/***
 * @Author: LRL52
 * @Date: 2023-05-08 20:16:30
 * @LastEditTime: 2023-05-08 20:22:41
 */
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e5 + 55, inf = 0x3f3f3f3f;
int n, m;
int a[N];

signed main()
{
#ifdef LRL52
    freopen("A.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int Task;
    cin >> Task;
    while (Task--) {
        // int n, m;
        // cin >> n >> m;
        // vector<int> a(n * m + 1);
        // for (int i = 1; i <= n * m; ++i)
        //     cin >> a[i];
        // sort(a.begin() + 1, a.end());
        // int mx = n * m;
        // // cout<<a[n*m]<<endl;
        // // cout<<(a[mx]-a[1])*(n-1)<<" "<<(a[mx]-a[2])*(m-1)<<" "<<(a[mx]-a[1])*(n*m-n-m+1)<<endl;
        // int ans1 = (a[mx] - a[1]) * (n - 1) + (a[mx] - a[2]) * (m - 1) + (a[mx] - a[1]) * (n * m - n - m + 1);
        // int ans2 = (a[mx] - a[1]) * (m - 1) + (a[mx] - a[2]) * (n - 1) + (a[mx] - a[1]) * (n * m - n - m + 1);
        // int ans3 = (a[mx] - a[1]) * (n - 1) + (a[mx - 1] - a[1]) * (m - 1) + (a[mx] - a[1]) * (n * m - n - m + 1);
        // int ans4 = (a[mx] - a[1]) * (m - 1) + (a[mx - 1] - a[1]) * (n - 1) + (a[mx] - a[1]) * (n * m - n - m + 1);
        // cout << max({ans1, ans2, ans3, ans4}) << endl;
        cin >> n >> m;
        int t = n * m;
        for (int i = 1; i <= t; ++i) cin >> a[i];
        sort(a + 1, a + t + 1);
        int d1 = a[t] - a[1], d2 = max(a[t] - a[2], a[t - 1] - a[1]);
        int l = min(n, m);
        int res = n * m - l;
        i64 ans = d1 * res + d2 * l - d2;
        cout << ans << '\n';
    }
    return 0;
}