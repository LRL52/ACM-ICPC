//ID: LRL52  Date: 2023.2.8
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
const int N = 1e5 + 55;
int a[N], b[N];
i64 sum1[N], sum2[N];

// vector<pair<i64, vector<int> > >& split(int *c, i64 *sum, int n) {
//     auto _ret = new vector<pair<i64, vector<int> > >;
//     auto &ret = *_ret;
//     int last = n, size = 1; i64 s = 0;
//     for(int i = n - 1; i >= 1; --i) {
//         // (sum[last] - sum[i]) / (last - i) >= s / size && sum[i] / i >= (sum[last] - sum[i]) / (last - i)
//         if((sum[last] - sum[i]) * size >= s * (last - i) && sum[i] * (last - i) >= (sum[last] - sum[i]) * i) {
//             vector<int> num;
//             for(int j = i + 1; j <= last; ++j) num.push_back(c[j]);
//             ret.emplace_back(sum[last] - sum[i], num);
//             last = i, size = num.size(), s = sum[last] - sum[i];
//         }
//     }
//     vector<int> num;
//     for(int j = 1; j <= last; ++j) num.push_back(c[j]);
//     ret.emplace_back(sum[last], num);
//     reverse(ret.begin(), ret.end());
//     return ret;
// }

vector<pair<i64, vector<int> > >& split(int *c, i64 *sum, int n) {
    auto _ret = new vector<pair<i64, vector<int> > >;
    auto &ret = *_ret;
    for(int i = 1; i <= n; ++i) ret.emplace_back(c[i], vector<int>{c[i]});
    while(1) {
        int flag = 0;
        vector<pair<i64, vector<int> > > res;
        vector<int> num(ret.back().second); i64 s = ret.back().first;
        for(int i = (int)ret.size() - 2; i >= 0; --i) {
            auto &[t, v] = ret[i];
            if(t * num.size() < s * v.size()) {
                for(auto x : v) num.push_back(x);
                s += t;
                flag = 1;
            } else {
                res.emplace_back(s, num);
                num = v, s = t;
            }
        }
        res.emplace_back(s, num);
        reverse(res.begin(), res.end());
        ret = res;
        if(!flag) break;
    }
    for(auto &[t, v] : ret) reverse(v.begin(), v.end()); 
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task, tcnt = 0; cin >> Task;
	while(Task--) {
        int n, m;
		cin >> n >> m;
        rep(i, 1, n) cin >> a[i], sum1[i] = sum1[i - 1] + a[i];
        rep(i, 1, m) cin >> b[i], sum2[i] = sum2[i - 1] + b[i];
        auto &v1 = split(a, sum1, n);
        auto &v2 = split(b, sum2, m);
        vector<vector<int> > Ans;
        int p1 = 0, p2 = 0;
        while(p1 < v1.size() && p2 < v2.size()) {
            auto &[s1, b1] = v1[p1]; //b1 -> block1
            auto &[s2, b2] = v2[p2];
            if(s1 * b2.size() > s2 * b1.size()) Ans.push_back(b1), ++p1;
            else Ans.push_back(b2), ++p2;
        }
        while(p1 < v1.size()) Ans.push_back(v1[p1++].second);
        while(p2 < v2.size()) Ans.push_back(v2[p2++].second);
        i64 ans = 0, idx = 0;
        for(auto &v : Ans)
            for(auto x : v)
                ans += (++idx) * x;
        printf("Case %d: %lld\n", ++tcnt, ans);
	}
	return 0;
}