//ID: LRL52  Date: 2022.8.2
//bitset优化的题目
//但这题我发现bitset不支持翻转操作，以及批量填充0的操作
//算法参照cf上给的题解pdf, 由于看不懂网上的做法，自己的实现有点怪，对拍才找出错误过掉
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 50000 + 55, inf = 0x3f3f3f3f;
int n;
int sum[N];
bitset<N> f[N], ans, F, G, Ans, mask;
char s1[N], s2[N];

signed main() {
#ifdef LRL52
	freopen("J.in", "r", stdin);
    //freopen("J.out", "w", stdout);
#endif
    ios::sync_with_stdio(0); cin.tie(0), cout.tie(0);
	int Task; scanf("%d", &Task);
	while(Task--){
        #define f(x) f[x + dx]
		scanf("%d%s%s", &n, s1 + 1, s2 + 1);
        sum[0] = 0; int dx = 0;
        rep(i, 1, n){
            sum[i] = sum[i - 1] + (s1[i] == '1' ? 1 : -1);
            dx = min(dx, sum[i]);
        }
        dx = -dx;
        for(int i = 0; i <= n; ++i) f[i].reset(); 
        f(0)[0] = 1;
        F.reset(), mask.set(), Ans.set();
        rep(i, 1, n){
            if(sum[i] >= sum[i - 1]) F |= f(sum[i] - 1);
            else F &= ~f(sum[i]);
            if(s2[i] == '1') G = F;
            else G = ~F;
            mask[n - i + 1] = 0;
            //cout << "mask = " << mask << '\n';
            if(G[0] == 0) ans = G << (n - i + 1);
            else ans = mask | (G << (n - i + 1));
            f(sum[i])[i] = 1;
            Ans &= ans;
            //cout << "Res["<< i << "] = " << Res[i] << '\n';
            //cout << "ans = " << ans << '\n';
        }
        //rep(i, 1, n) Ans &= Res[i];
        for(int i = n; i >= 1; --i) cout << Ans[i];
        cout << '\n';
	}
    //cout << (double)sizeof(f) / (1 << 20) << '\n';
	return 0;
}