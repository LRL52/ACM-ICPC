//判断能否被11整除的方法：每一位正负交替求和，再判断能否被11整除
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;
char s[N];

int main() {
	freopen("K.in", "r", stdin);
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%s", s + 1);
		int len = strlen(s + 1);
		int s3 = 0, s11 = 0;
		for (int i = 1; i <= len; ++i) {
			int dig = s[i] - '0';
			s3 += dig, s11 += (i & 1) ? dig : -dig;
		}
		s3 % 3 ? printf("No ") : printf("Yes ");
		s11 % 11 ? printf("No\n") : printf("Yes\n");
	}
	return 0;
}