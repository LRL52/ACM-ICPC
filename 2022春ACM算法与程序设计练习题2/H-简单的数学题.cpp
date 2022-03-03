//根据同余，一个数除以9的余数 等于 这个数各个位的数之和除以9的余数
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;
char s[N];

int main() {
	scanf("%s", s);
	sort(s, s + strlen(s));
	puts(s);
	return 0;
}