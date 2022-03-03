//这题真是趣味了，思维题
//假设目前可以表示的范围是[1，P]，再加一个数Q（Q>P)，新增的可表示的范围为[Q-P，Q+P]，并且必须满足即有Q-P=P+1；即Q=2P+1；新表示的范围即为[1，3P+1]
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	freopen("L.in", "r", stdin);
	int n; scanf("%d", &n);
	int P = 1, ans = 1;
	while (P < n) P = 3 * P + 1, ++ans;
	printf("%d\n", ans);
	return 0;
}