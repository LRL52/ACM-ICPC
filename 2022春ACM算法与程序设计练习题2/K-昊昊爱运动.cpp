//����Ӧ����Ī�Ӱɣ���������Ī��զд�ˣ��������Ҹ�ģ����ӶȲ��Ǻ���ȷ�����ɹ���Ŀ
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 2055, M = 1e6 + 55;
int n, m, Q;
int a[N], col[N], Ans[M];
struct Node {
	int l, r, id;
	inline bool operator<(const Node& rhs)const {
		if (l != rhs.l) return l < rhs.l;
		else return r < rhs.r;
	}
}qs[M];

int main() {
	freopen("K.in", "r", stdin);
	//rd(n), rd(m);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &a[i]); // rd(a[i]);
	scanf("%d", &Q); // rd(Q);
	for (int i = 1; i <= Q; ++i) /*rd(qs[i].l), rd(qs[i].r)*/scanf("%d%d", &qs[i].l, &qs[i].r), qs[i].id = i;
	sort(qs + 1, qs + Q + 1);
	int l = 1, r = 0, ans = 0;
	for (int i = 1; i <= Q; ++i) {
		while (l < qs[i].l && l < n) --col[a[l++]] == 0 ? --ans : 0; //:�����0û���κκ����
		while (r > qs[i].r && r > 1) --col[a[r--]] == 0 ? --ans : 0;
		while (r < qs[i].r && r < n) ++col[a[++r]] == 1 ? ++ans : 0;
		Ans[qs[i].id] = ans;
	}
	for (int i = 1; i <= Q; ++i) printf("%d\n", Ans[i]);
	return 0;
}