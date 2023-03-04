//ID: LRL52  Date: 2022.10.30
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 1e6;
vector<int> U, V, W;

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
    int n = 100, k = 1e6;
    for(int i = 1; i + 3 <= n; i += 3) {
        // U.push_back(i), V.push_back(i + 1), W.push_back(inf - i * 1000);
        U.push_back(i), V.push_back(i + 1), W.push_back(k);
        U.push_back(i), V.push_back(i + 2), W.push_back(1);
        U.push_back(i + 1), V.push_back(i + 2), W.push_back(1);
        U.push_back(i + 1), V.push_back(i + 3), W.push_back(1);
        U.push_back(i + 2), V.push_back(i + 3), W.push_back(max(1, k / 2 - 1));
        k = max(1, k / 2);
        //if(i + 4 <= n) U.push_back(i + 3), V.push_back(i + 4), W.push_back(1);
    }
    printf("%d %lu\n", n, U.size());
    for(size_t i = 0; i < U.size(); ++i) {
        printf("%d %d %d\n", U[i], V[i], W[i]);
    } 
	return 0;
}
