## 题目

[传送门](https://atcoder.jp/contests/abc266/tasks/abc266_g)

给你 $4$ 个整数 $R, G, B, K$，求满足下列条件的字符串数量：

- 字符串仅由 `R`,`G`,`B` 构成，且`R`,`G`,`B`的个数**恰好**分别有 $R, G, B$ 个
- `RG` 子串的个数**恰好**有 $K$ 个

$ 1 \le R, G, B \le 10^6 $
$ 0 \le K \le \min (R, G) $



## 题解

首先将 $K$ 个 `RG` 捆绑在一起，视 `RG` 为新字符 `K` ，令 $R = R - K, G = G - K$ ，原题意转化为用 `R`, `G`, `B`, `K` 组成字符串，且不含任何子串 `RG`

### 方法一（容斥原理）：

回想下容斥原理的证明（也是我的理解），每一个统计对象有很多个“特征”，最后我们要不重不漏的计算出统计对象的总个数，假设一个统计对象有 $K$ 个“特征”，

![image-20220902203902779](https://images.lrl52.top/Aug/image-20220902203902779.png)

那么恰好这个对象会被统计 $2^K$ 次，一些为正，一些为负，即：
$$
\begin{aligned}
\text{Res} &=  \binom{K}{1} - \binom{K}{2} + \binom{K}{3} - \binom{K}{4} + \cdots + (-1)^{K+1} \binom{K}{K} \\
&= -\sum_{i=1}^K (-1)^i \binom{K}{i} \\
&= -[\sum_{i=0}^K (-1)^i \binom{K}{i} - 1] \\
&= -[(1-1)^K - 1] \\
&= 1
\end{aligned}
$$
故每个统计对象恰好被统计了 $1$ 次。

回到本题，例如 `***RG**RG**RG*****`（`*`代表其它字符），其实就包含 $3$ 个“特征”，因此在统计含有至少 $1$ 个 `RG` 的数量是会被计算 $\binom{3}{1}$ 次，统计含有至少 $2$ 个 `RG` 的数量是会被计算 $\binom{3}{2}$ 次，统计含有至少 $3$ 个 `RG` 的数量是会被计算 $\binom{3}{3}$ 次，最后经过正负号交题的容斥就恰好仅仅被计算 $1$ 次，

我们可以用组合数算出**至少含有 $i$ 个 `RG` 的数量**，容斥即可（实际上容斥算出的是含有 `RG` 的字符串总数，我们 用总方案数 - 含有 `RG` 的方案数 就可以得到最终答案，实际计算时让`i=0`开始循环，可以和容斥原理完美结合）
$$
\text{Ans} = \sum_{i=0}^{\min (R,G)} (-1)^i \frac{(R-i+G-i+B+K+i)!}{(R-i)!(G-i)!B!K!i!}
$$
 ==注：实际我们每次统计的至少含有 $i$ 个 `RG` 的数量有重复计算的，不然我们直接用至少含有$i$ 个 `RG` 的数量 - $i+1$ 个 `RG` 的数量就得到了恰好含有 $i$ 个 `RG` 的数量==

```cpp
//ID: LRL52  Date: 2022.9.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 3e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int R, G, B, K;

const int MOD = 998244353;
int inv[N], fact[N], factinv[N];
void Prework(int n){
    fact[0] = fact[1] = inv[1] = factinv[0] = factinv[1] = 1;
    rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
    rep(i, 2, n) inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
    rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
}

int C(int n, int m){
    if(m > n || n < 0 || m < 0) return 0;
    return 1LL * fact[n] * factinv[n - m] % MOD * factinv[m] % MOD;
}

signed main() {
#ifdef LRL52
	freopen("G.in", "r", stdin);
#endif
    rd(R), rd(G), rd(B), rd(K);
    R -= K, G -= K;
    Prework(R + G + B + K);
    long long ans = 1LL * fact[R + G + B + K] * factinv[R] % MOD * \
                    factinv[G] % MOD * factinv[B] % MOD * factinv[K] % MOD;
    for (int i = 1; i <= min(R, G); ++i) {
        int sign = (i & 1) ? (MOD - 1) : 1;
        ans += 1LL * sign * fact[R - i + G - i + B + K + i] % MOD * factinv[R - i] % MOD * \
               factinv[G - i] % MOD * factinv[B] % MOD * factinv[i] % MOD * factinv[K] % MOD;
        ans %= MOD;
    }
    printf("%lld\n", ans);
	return 0;
}
```



### 方法二（组合数插空法）：

具体见[这篇题解](https://atcoder.jp/contests/abc266/editorial/4721)

![image-20220902211154661](https://images.lrl52.top/Aug/image-20220902211154661.png)

### 方法三（二项式反演）：

**用二项式反演来思考是最自然，最简单的！**

首先设“**钦定** $k$ 个 `RG` ”的方案是数为 $f_k$
$$
\large f_k = \dfrac{n!}{k!(R-k)!(G-k)!B!}
$$
其中 $n = R + G + B - k$

然后设“**恰好**有 $k$ 个 `RG`”的方案数为 $g_k$，$f_k$ 与 $g_k$ 有如下优美的关系：
$$
\large f_k = \sum_{i=k}^{\infty} \binom{i}{k} g_i
$$
根据二项式反演有：
$$
\large f_k = \sum_{i=k}^{\infty} \binom{i}{k} g_i \iff g_k = \sum_{i=k}^{\infty} (-1)^{i-k} \binom{i}{k} f_i
$$
令 $k = K$ ，直接计算 $g_k$ 即可，实际计算中不用计算到无穷，取上限 `up = min{R, G}`

 ```cpp
 //ID: LRL52  Date: 2022.9.15
 //二项式反演直接秒掉，比用容斥简单多了
 #include <bits/stdc++.h>
 #define rep(i, a, b) for(int i = (a); i <= (b); ++i)
 #define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
 using namespace std;
 const int N = 3e6 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
 inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
 template<class T>inline void rd(T& x) {
 	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
 	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
 }
 int R, G, B, K;
 const int MOD = 998244353;
 int inv[N], fact[N], factinv[N];
 void Prework(int n){
     fact[0] = fact[1] = inv[1] = factinv[0] = factinv[1] = 1;
     rep(i, 2, n) fact[i] = 1LL * fact[i - 1] * i % MOD;
     rep(i, 2, n) inv[i] = 1LL * (MOD - MOD/i) * inv[MOD % i] % MOD;
     rep(i, 2, n) factinv[i] = 1LL * factinv[i - 1] * inv[i] % MOD;
 }
 
 int C(int n, int m){
     if(m > n || n < 0 || m < 0) return 0;
     return 1LL * fact[n] * factinv[n - m] % MOD * factinv[m] % MOD;
 }
 
 signed main() {
 #ifdef LRL52
 	freopen("A.in", "r", stdin);
 #endif
 	rd(R), rd(G), rd(B), rd(K);
     int up = min(R, G);
     Prework(R + G + B);
     long long ans = 0;
     for(int i = K; i <= up; ++i){
         int res = 1LL * C(i, K) * fact[R + G + B - i] % MOD * factinv[i] % MOD * \
                   factinv[R - i] % MOD * factinv[G - i] % MOD * factinv[B] % MOD;
         if((i - K) & 1) ans = (ans - res + MOD) % MOD;
         else ans = (ans + res) % MOD;
     }
     printf("%lld\n", ans);
 	return 0;
 }
 ```
