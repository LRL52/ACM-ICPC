//ID: LRL52  Date: 2022.11.1
//CDQ分治
#include <bits/stdc++.h>
using namespace std;
const int N = 5 * (1e5 + 55);
using LL = long long;
int n, m;
struct Node {
    int x, y, w, type, id; //(x, y)的权值为w，type=0表示点，type=1/-1表示询问(带符号), id表示询问编号
    LL ans;
    inline bool operator<(const Node &t) const {
        if(x != t.x) return x < t.x;
        if(y != t.y) return y < t.y;
        return abs(type) < abs(t.type); 
    }
}a[N], q[N];
LL Ans[N];

void CDQ(int l, int r) {
    if(l >= r) return;
    int mid = (l + r) >> 1;
    CDQ(l, mid), CDQ(mid + 1, r);
    int i = l, j = mid + 1, k = l; LL sum = 0LL;
    while(i <= mid && j <= r) {
        if(a[i].y <= a[j].y) sum += !a[i].type * a[i].w, q[k++] = a[i++];
        else a[j].ans += sum, q[k++] = a[j++];
    }
    while(i <= mid) sum += !a[i].type * a[i].w, q[k++] = a[i++];
    while(j <= r) a[j].ans += sum, q[k++] = a[j++];
    for(int i = l; i <= r; ++i) a[i] = q[i];
}

signed main() {
    //freopen("acwing2847.in", "r", stdin);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m; int x, y, w;
    for(int i = 1; i <= n; ++i) {
        cin >> x >> y >> w;
        a[i] = (Node){x, y, w, 0, i, 0};
    }
    int p = n;
    for(int i = 1; i <= m; ++i) {
        int X1, X2, Y1, Y2;
        cin >> X1 >> Y1 >> X2 >> Y2;
        a[++p] = (Node){X2, Y2, 0, 1, i, 0};
        a[++p] = (Node){X1 - 1, Y2, 0, -1, i, 0};
        a[++p] = (Node){X2, Y1 - 1, 0, -1, i, 0};
        a[++p] = (Node){X1 - 1, Y1 - 1, 0, 1, i, 0};
    }
    sort(a + 1, a + p + 1);
    CDQ(1, p);
    for(int i = 1; i <= p; ++i)
        if(a[i].type)
            Ans[a[i].id] += a[i].type * a[i].ans;
    for(int i = 1; i <= m; ++i) printf("%lld\n", Ans[i]);
	return 0;
} 
    