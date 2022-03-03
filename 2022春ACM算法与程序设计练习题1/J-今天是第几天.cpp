#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int D[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int check(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int main() {
	freopen("J.in", "r", stdin);
	int T, year, month, day; scanf("%d", &T);
	while (T--){
		scanf("%d%d%d", &year, &month, &day);
		if (check(year)) D[2] = 29;
		else D[2] = 28;
		int ans = 0;
		for (int i = 1; i < month; ++i) ans += D[i];
		ans += day;
		printf("%d\n", ans);
	}
	return 0;
}