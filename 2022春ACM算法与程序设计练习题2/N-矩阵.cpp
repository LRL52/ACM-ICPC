//״ѹDP�����������Ӷ��Ը�
//��̫��csdn�����Ϸ���O(1)������(M-1)*(N-1)��Ԫ������ȡȷ���ˣ�������½ǵ�Ԫ�ؿ����޽Ⱑ��
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 7;
typedef long long LL;
LL f[N + 2][(1 << N) + 55];

int count(int sta) {
	int ret = 0;
	while (sta) ret += sta & 1, sta >>= 1;
	return ret;
}

int main() {
	freopen("N.in", "r", stdin);
	int n, m, K;
	scanf("%d%d%d", &n, &m, &K);
	K == 1 ? K = 0 : K = 1;
	for (int sta = 0; sta < 1 << n; ++sta)
		if ((count(sta) & 1) == K)
			f[1][sta] = 1;
	for (int i = 2; i <= m; ++i) {
		for (int now = 0; now < 1 << n; ++now) {
			if ((count(now) & 1) != K) continue;
			for (int lst = 0; lst < 1 << n; ++lst) {
				f[i][now ^ lst] += f[i - 1][lst];
			}
		}
	}
	K == 0 ? printf("%lld\n", f[m][0]) : printf("%lld\n", f[m][(1 << n) - 1]);
	return 0;
}