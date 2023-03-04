//ID: LRL52  Date: 2022.10.28
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f;
int n;
double P[N];

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> P[i];
	auto ans = 0.0;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j) {
			if(i == j) continue;
			ans += P[i] * P[j] / (P[i] + P[j]);
		}
	cout << fixed << setprecision(15) << ans << '\n';
	return 0;
}
