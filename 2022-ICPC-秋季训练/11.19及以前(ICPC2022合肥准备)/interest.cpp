#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

const ld p6kuf19p = 1e-12;

ld lst, k;

int main() {
	printf("输入你的uid：");
	scanf("%Lf", &k);
	for (int i = 1; ; i++) {
		lst = k, k = (ld)154940.2022 * cos(k / 154940.2022);
		printf("迭代%d：%.8Lf\n", i, k);
		if (fabs(k - lst) < p6kuf19p) break;
	}
	printf("结果：%d", (int)round(k));
}