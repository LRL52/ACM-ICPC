//��Ӧ��������������ϵ�ԭ��
//������ֻ������ײ ��ͷ �� ���� ���Ӿ��Ͻ���һ���ģ���˸���ÿֻ���ϵ����λ�þͿ��Լ������ĳ��ʱ��һ������һֻ���ϵ���
//���ȷ������ֻ�����أ�������ײ��ͷ������ı���������ϵ����λ�ã����Ҫ���������һ����λ�ڸ��������˵�����
//�������������ֻ�������ұ���ֻ����������˼��һ�»��߿����ҵĴ����������
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;

int n, L;
struct Node {
	int p, t; char dir; //direction ���� tΪ����ʱ��
	char Name[12];
	inline bool operator<(const Node& rhs)const {
		return t < rhs.t;
	}
}a[N], b[N];

struct cmp {
	inline bool operator()(const Node& t1, const Node& t2)const {
		return t1.p < t2.p;
	}
};

int calc(const Node* t) {
	if (t->dir == 'L') return t->p;
	else return L - t->p;
}

int main() {
	freopen("A.in", "r", stdin);
	int T, cases = 0; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &L);
		for (int i = 1; i <= n; ++i) {
			scanf("%s %d %c", a[i].Name, &a[i].p, &a[i].dir);
			a[i].t = calc(&a[i]);
			b[i] = a[i];
		}
		sort(a + 1, a + n + 1);
		sort(b + 1, b + n + 1, cmp());
		int lp = 1, rp = n; //lp, rp Ϊ����ָ��
		printf("Case #%d:\n", ++cases);
		for (int i = 1; i <= n; ++i) {
			printf("%d ", a[i].t);
			if (a[i].dir == 'L') printf("%s\n", b[lp++].Name);
			else printf("%s\n", b[rp--].Name);
		}
	}	
	return 0;
}