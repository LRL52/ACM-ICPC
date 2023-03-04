//ID: LRL52  Date: 2022.11.1
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55, M = 2e5 + 55;
int n, m, Ans[N], c[M];;
struct Node {
    int a, b, c, cnt, res;
    inline bool operator<(const Node& t) const {
        if(a != t.a) return a < t.a;
        if(b != t.b) return b < t.b;
        return c < t.c;
    }
    inline bool operator==(const Node& t) const {
        return a == t.a && b == t.b && c == t.c;
    }
}a[N], q[N];


inline int lowbit(int x) { return x & -x; }

void update(int x, int y) {
    for(int i = x; i <= m; i += lowbit(i)) c[i] += y;
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
    int i = l, j = mid + 1, k = l;
    while(i <= mid && j <= r) {
        if(a[i].b <= a[j].b) update(a[i].c, a[i].cnt), q[k++] = a[i++];
        else a[j].res += query(a[j].c), q[k++] = a[j++];
    }
    while(i <= mid) update(a[i].c, a[i].cnt), q[k++] = a[i++];
    while(j <= r) a[j].res += query(a[j].c), q[k++] = a[j++];
    for(int i = l; i <= mid; ++i) update(a[i].c, -a[i].cnt);
    for(int i = l; i <= r; ++i) a[i] = q[i];
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; int x, y, z;
    for(int i = 1; i <= n; ++i) {
        cin >> x >> y >> z;
        a[i] = (Node){x, y, z, 1, 0};
    }
    sort(a + 1, a + n + 1);
    int p = 1;
    for(int i = 2; i <= n; ++i) {
        if(a[i] == a[p]) a[p].cnt++;
        else a[++p] = a[i];
    }
    CDQ(1, p);
    for(int i = 1; i <= p; ++i)
        Ans[a[i].res + a[i].cnt - 1] += a[i].cnt;
    for(int i = 0; i < n; ++i) printf("%d\n", Ans[i]);
	return 0;
} 
    