//ID: LRL52  Date: 2022.11.1 ~ 11.2
//CDQ分治，下标排序，元素的值归并，时间戳用树状数组维护
//时间戳从n ~ 1编号，时间戳越大表示越早被删除
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55;
struct Node {
    int val, t, res; //t是时间戳，越早被删除的元素时间戳越大，便于转化为偏序问题
}a[N], q[N];
int n, m, c[N], Pos[N];
long long Ans[N];

inline int lowbit(int x) { return x & -x; }

void update(int x, int y) {
    for(int i = x; i <= n; i += lowbit(i)) c[i] += y;
}

int query(int x) {
    int ret = 0;
    for(int i = x; i; i -= lowbit(i)) ret += c[i];
    return ret;
}

void CDQ(int l, int r) {
    if(l >= r) return;
    int mid = (l + r) >> 1;
    CDQ(l, mid), CDQ(mid + 1, r);
    int i = mid, j = r;
    while(i >= l && j > mid) {
        if(a[i].val > a[j].val) update(a[i].t, 1), --i;
        else a[j].res += query(a[j].t - 1), --j;
    }
    while(i >= l) update(a[i].t, 1), --i;
    while(j > mid) a[j].res += query(a[j].t - 1), --j;
    for(int k = l; k <= mid; ++k) update(a[k].t, -1);

    i = mid + 1, j = l; //j在[l, mid], i在[mid+1, r], 计算右半区间对左半区间的贡献
    while(j <= mid && i <= r) {
        if(a[i].val < a[j].val) update(a[i].t, 1), ++i;
        else a[j].res += query(a[j].t - 1), ++j;
    }
    while(i <= r) update(a[i].t, 1), ++i;
    while(j <= mid) a[j].res += query(a[j].t - 1), ++j;
    for(int k = mid + 1; k <= r; ++k) update(a[k].t, -1);

    i = l, j = mid + 1; int k = l; //下面才是真正的归并排序
    while(i <= mid && j <= r) {
        if(a[i].val <= a[j].val) q[k++] = a[i++];
        else q[k++] = a[j++];
    }
    while(i <= mid) q[k++] = a[i++];
    while(j <= r) q[k++] = a[j++];
    for(k = l; k <= r; ++k) a[k] = q[k];
}

signed main() {
    //freopen("acwing2819.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; int x;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].val;
        Pos[a[i].val] = i;
    }
    for(int i = 0, j = n; i < m; ++i) {
        cin >> x;
        a[Pos[x]].t = j--;
        Pos[x] = -1;
    }
    for(int i = 1, j = n - m; i <= n; ++i)
        if(Pos[i] != -1) 
            a[Pos[i]].t = j--, Pos[i] = -1;
    CDQ(1, n);
    for(int i = 1; i <= n; ++i) Ans[a[i].t] = a[i].res;
    for(int i = 2; i <= n; ++i) Ans[i] += Ans[i - 1];
    for(int i = n; i >= n - m + 1; --i) printf("%lld\n", Ans[i]);
	return 0;
} 
    