//��������Ȥζ�ˣ�˼ά��
//����Ŀǰ���Ա�ʾ�ķ�Χ��[1��P]���ټ�һ����Q��Q>P)�������Ŀɱ�ʾ�ķ�ΧΪ[Q-P��Q+P]�����ұ������㼴��Q-P=P+1����Q=2P+1���±�ʾ�ķ�Χ��Ϊ[1��3P+1]
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