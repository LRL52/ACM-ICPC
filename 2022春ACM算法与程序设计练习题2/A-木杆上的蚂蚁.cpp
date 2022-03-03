//这应该是刘汝佳蓝书上的原题
//首先两只蚂蚁相撞 掉头 和 穿过 从视觉上讲是一样的，因此根据每只蚂蚁的起点位置就可以计算出在某个时刻一定会有一只蚂蚁掉落
//如何确定是哪只蚂蚁呢？蚂蚁相撞掉头并不会改变杆子上蚂蚁的相对位置，因此要掉落的蚂蚁一定是位于杆子最两端的蚂蚁
//到底是最左边那只还是最右边那只，聪明的你思考一下或者看看我的代码就明白了
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055;

int n, L;
struct Node {
	int p, t; char dir; //direction 方向 t为掉下时间
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
		int lp = 1, rp = n; //lp, rp 为左右指针
		printf("Case #%d:\n", ++cases);
		for (int i = 1; i <= n; ++i) {
			printf("%d ", a[i].t);
			if (a[i].dir == 'L') printf("%s\n", b[lp++].Name);
			else printf("%s\n", b[rp--].Name);
		}
	}	
	return 0;
}