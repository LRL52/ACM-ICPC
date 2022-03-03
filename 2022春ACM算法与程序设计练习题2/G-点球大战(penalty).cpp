//出题人题目不讲武德，题目中的人名竟然可以是no或者good
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;
const int N = 1055;
char s[2][N], str[N];;
//const char r1[] = "no", r2[] = "good";
const char r3[] = " no good";

int main() {
	freopen("G.in", "r", stdin);
	//freopen("G.out", "w", stdout);
	int n;
	while (scanf("%d\n", &n) && n) {
		int p[2] = { 0 }, score[2] = { 0 };
		for (int i = 1; i <= n; ++i) {
			//do scanf("%s", str);
			//while (strcmp(str, r1) && strcmp(str, r2));
			fgets(str, 105, stdin);
			int len = strlen(str) - 1;
			str[len] = '\0';
			int t = i & 1; //t为1代表第1支队伍，t为0代表第2支队伍
			if (strcmp(str + len - 8 , r3) == 0) {
				//scanf("%s", str);
				s[t][++p[t]] = 'X';
			}
			else {
				s[t][++p[t]] = 'O';
				++score[t];
			}
		}
		for (int i = 1; i <= (n + 1) / 2; ++i) printf("%d ", i);
		printf("Score\n");
		if (n & 1) s[0][++p[0]] = '-';
		for (int i = 1; i <= p[1]; ++i) printf("%c ", s[1][i]);
		printf("%d\n", score[1]);
		for (int i = 1; i <= p[0]; ++i) printf("%c ", s[0][i]);
		printf("%d\n", score[0]);
	}
	//assert(n == 0);
	return 0;
}