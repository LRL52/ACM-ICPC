#include <bits/stdc++.h>

#ifdef LOCAL_DEFINE
#include <dbg.h>
#else
#define dbg(...)
#endif

using namespace std;
using ll = long long;
using pii = pair<int, int>;

mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

void Main(int Case) {
    int n = 12;
    vector<int> a(n);
    for (int &i : a) cin >> i;
    sort(a.begin(), a.end());
    vector<array<int, 3>> ans, Ans;
    vector<int> r;

    for(int times = 1; times <= 3000; ++times) {
        ans.clear(); r.clear();
        for (int i = 0; i < n; i++) {
            if (r.size() < 2)
                r.push_back(a[i]);
            else {
                vector<pii> S;
                for(int j = (int)r.size() - 1; j >= 0; --j) {
                    int k = lower_bound(r.begin(), r.end(), a[i] - r[j] + 1) - r.begin();
                    if(k >= j) break;
                    S.emplace_back(k, j);
                }
                int p1 = -1, p2 = -1;
                for(auto [k, j] : S) {
                    if(p1 == -1 && p2 == -1) p1 = k, p2 = j;
                    else if(r[k] + r[j] < r[p1] + r[p2]) p1 = k, p2 = j;
                    else if(r[k] + r[j] == r[p1] + r[p2] && r[j] < r[p2]) {
                        if(times == 1) p1 = k, p2 = j;
                        else if(times == 2) continue;
                        else if(rnd() % 3) p1 = k, p2 = j;
                    }
                }
                if(p1 == -1 || p2 == -1) r.push_back(a[i]);
                else {
                    array<int, 3> tmp = {r[p1], r[p2], a[i]};
                    ans.push_back(tmp);
                    r.erase(lower_bound(r.begin(), r.end(), r[p1]));
                    r.erase(lower_bound(r.begin(), r.end(), r[p2]));
                }
            }
        }
        if(ans.size() > Ans.size()) Ans = ans;
        if(Ans.size() == 4) break;
    }
    ans = Ans;
    cout << "Case #" << Case << ": " << ans.size() << endl;
    for (auto x : ans) {
        for (int i = 0; i < 2; i++) {
            cout << x[i] << " ";
        }
        cout << x[2] << endl;
    }
}

signed main() {
#ifdef LRL52
	freopen("K.in", "r", stdin);
#endif
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int o_o;
    cin >> o_o;
    for (int i = 1; i <= o_o; i++) {
        Main(i);
    }
    return 0;
}