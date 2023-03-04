//
// Created by onglu on 2022/4/3.
//

#include <bits/stdc++.h>

#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()

#define endl '\n'
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define Mid ((l + r) / 2)
#define int long long
using namespace std;
//const int N = 2e6 + 1009;
const int N = 2e5 + 1009;
//const int N = 2509;
//const int N = 309;
int n, m;
int f[N];
struct node {
    int x, y, w;
};
int sum;
vector<node> v, a[N], tt[N];
vector<int> t;
priority_queue<int> q;
void Insert(int x) {
    if(q.size() < m) {
        sum += x;
        q.push(-x);
    } else if(-q.top() < x) {
        sum -= -q.top();
        q.pop();
        sum += x;
        q.push(-x);
    }
}
void work() {
    int ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        t.push_back(a);
        t.push_back(b);
        v.push_back({a, b, c});
        ans += c;
    }
    std::sort(t.begin(), t.end());
    t.resize(std::unique(t.begin(), t.end()) - t.begin());
    for(int i = 0; i < v.size(); i++) {
        v[i].x = std::lower_bound(t.begin(), t.end(), v[i].x) - t.begin() + 1;
        v[i].y = std::lower_bound(t.begin(), t.end(), v[i].y) - t.begin() + 1;
        a[v[i].y].push_back({v[i].x, v[i].y, v[i].w});
    }
    for(int i = 1; i <= t.size(); i++) {
        sum = 0;
        while(q.size()) q.pop();
        for(int j = 0; j <= i; j++) {
            tt[j].clear();
        }
        for(int j = i; j > 0; j--) {
            for(auto r : a[j]) {
                tt[r.x].push_back(r);
            }
        }
        for(int j = i; j >= 1; j--) {
            for(auto r : tt[j]) {
                Insert(r.w);
            }
            f[i] = max(f[i], f[j - 1] + sum);
        }
    }
    cout << ans - f[t.size()] << endl;

}

signed main() {
#ifdef LOCAL
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.in", "r", stdin);
    freopen("C:\\Users\\onglu\\CLionProjects\\acm\\data.out", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int Case = 1;
//    cin >> Case;
    while (Case--) work();
    return 0;
}