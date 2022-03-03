//Լɪ������
//��mֻ���ӵı��Ϊ0 ~ m-1, ��f(m, n)��ʾmֻ����ÿ�α�����n���ʣ�µĺ��ӱ��
//�����������Եõ�����ʽ��f(m, n) = [f(m-1, n) + n] mod m�� ��ֵf(1, n) = 0
//���մ�Ϊf(m, n) + 1��ʱ�临�Ӷ�O(T*m)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;
int f[N];

int main() {
	freopen("I.in", "r", stdin);
	int T, n, m; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &m, &n);
		f[1] = 0;
		for (int i = 2; i <= m; ++i)
			f[i] = (f[i - 1] + n) % i;
		printf("%d\n", f[m] + 1);
	}
	return 0;
}