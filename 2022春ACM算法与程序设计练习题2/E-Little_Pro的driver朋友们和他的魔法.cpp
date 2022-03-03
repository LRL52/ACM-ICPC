#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100055;
int n;
char s[N];

int main() {
	scanf("%d%s", &n, s + 1);
	//下面这个算法有点问题，不能证明是正确的
	/*int one = 0, zero = 0, s1 = 0, s0 = 0; //s1表示连续1的段需要的交换次数, s0同理
	for (int i = 1; i <= n; ++i) {
		int t = 0;
		if (s[i] == '0') {
			++zero, ++t;
			while (i < n && s[i + 1] == '0') ++i, ++zero, ++t;
			s0 += t >> 1;
		}
		else {
			++one, ++t;
			while (i < n && s[i + 1] == '1') ++i, ++one, ++t;
			s1 += t >> 1;
		}
	}
	int ans = (n / 2) - min(one, zero); //需要把0变1 或者 1变0 的次数
	if (one == zero) ans += max(s0, s1);
	else if (one < zero) ans += max(s1, s0 - ans);
	else ans += max(s0, s1 - ans);
	printf("%d\n", ans);*/

	//只要首位确定了，最终答案就定了，即010101... 或 101010...
	//遍历字符串，分奇偶位找到不符合期望答案的数字，取max即是答案的一种情况（不想细说，还是容易得到的）
	//odd_0 奇数位为0的个数 odd_1 even_0 even_1 同理
	int odd_0 = 0, odd_1 = 0, even_0 = 0, even_1 = 0;
	for(int i = 1; i <= n; ++i)
		if (i % 2) s[i] == '0' ? ++odd_0 : ++odd_1;
		else s[i] == '0' ? ++even_0 : ++even_1;
	printf("%d\n", min(max(odd_0, even_1), max(odd_1, even_0)));
	return 0;
}