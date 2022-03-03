#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;
char s[N];

int main() {
	freopen("F.in", "r", stdin);
	int n;
	while (scanf("%d", &n) != EOF && n) {
		scanf("%s", s + 1);
		int R = 0, Y = 0;
		for (int i = 1; i <= n; ++i) {
			switch (s[i]) {
			case 'R': ++R; break;
			case 'Y': ++Y; break;
			case 'B': R == 7 ? puts("Red") : puts("Yellow"); break;
			case 'L': Y == 7 ? puts("Yellow") : puts("Red"); break;
			}
		}
	}
	return 0;
}