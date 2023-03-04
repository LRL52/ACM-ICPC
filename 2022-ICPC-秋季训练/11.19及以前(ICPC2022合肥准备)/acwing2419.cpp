//ID: LRL52  Date: 2022.11.4
//每个结点在序列中出现的次数是其度数减-1（没有出现的就是叶结点）
//在构造完 Prufer 序列后原树中会剩下两个结点，其中一个一定是编号最大的点n
//把n号结点当作根，转化为有根树，这样第n号结点在Prefur序列构造中都不可能被选上(因为编号最大)
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55;
int n, m, fa[N], deg[N], prufer[N];

void TreeToPrufer() {
    for(int i = 1; i < n; ++i) {
        cin >> fa[i];
        deg[fa[i]]++; //deg实际上是儿子的数量
    }
    //j是当前编号最小的叶节点
    for(int i = 1, j = 1; i <= n - 2; ++j) {
        while(deg[j] > 0) ++j;
        prufer[i++] = fa[j];
        while(i <= n - 2 && --deg[prufer[i - 1]] == 0 && prufer[i - 1] < j) 
            prufer[i] = fa[prufer[i - 1]], ++i;
    }
    for(int i = 1; i <= n - 2; ++i) printf("%d ", prufer[i]);
}

//代码就是上面的代码反转一下
void PruferToTree() {
    for(int i = 1; i <= n - 2; ++i) {
        cin >> prufer[i];
        deg[prufer[i]]++;
    }
    prufer[n - 1] = n; //补充1个，prufer序列长度变为n-1，便于后续还原n-1边
    for(int i = 1, j = 1; i < n; ++j) {
        while(deg[j] > 0) ++j;
        fa[j] = prufer[i++];
        while(i <= n - 1 && --deg[prufer[i - 1]] == 0 && prufer[i - 1] < j)
            fa[prufer[i - 1]] = prufer[i], ++i;
    }
    for(int i = 1; i <= n - 1; ++i) printf("%d ", fa[i]);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
    if(m == 1) TreeToPrufer();
    else PruferToTree();
	return 0;
} 
    