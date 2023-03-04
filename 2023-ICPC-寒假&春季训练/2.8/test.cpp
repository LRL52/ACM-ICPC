//ID: LRL52  Date: 2023.2.6
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
mt19937 rng(random_device{}());
uniform_int_distribution<int> dist(0, 2e9);

int rnd() { return dist(rng); }

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);

	vector<tuple<int, int, int> > a;
    for(int i = 0; i < 10; ++i)
        a.emplace_back(rnd(), rnd(), rnd());
    sort(a.begin(), a.end());
    for(auto &[x, y, z] : a)
        printf("%d %d %d\n", x, y, z); 
    
    vector<array<int, 3> > b;
    array<int, 3> tmp = {3, 4, 5};
    // b.push_back(tmp);
    b.push_back({3, 4, 5});

    map<pii, vector<int> > c;
    c[{1, 2}] = vector<int>(5, 1);
    auto &v = c[{1, 2}];
    for(auto &x : v) printf("%d\n", x);

    for(int i = 1; i <= 10; ++i)
        cout << i << " \n"[i == 10];
	return 0;
}