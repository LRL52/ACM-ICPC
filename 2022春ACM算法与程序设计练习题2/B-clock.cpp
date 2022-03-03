#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;


int main() {
	int T, hh, mm; scanf("%d", &T);
	while (T--) {
		scanf("%d:%d", &hh, &mm);
		if (hh >= 12) hh -= 12;
		double hh_deg = hh * 30.0 + mm / 2.0;
		double mm_deg = mm * 6.0;
		double ans = fabs(hh_deg - mm_deg);
		if (ans > 180.0) ans = 360.0 - ans; //题目没说角度要<=180°吧
		if (ans - floor(ans) > 0.1) {
			int res = int(ans * 2.0 + 0.5);
			printf("%d/2\n", res);
		}
		else {
			printf("%d\n", int(ans + 0.5));
		}
	}
	return 0;
}