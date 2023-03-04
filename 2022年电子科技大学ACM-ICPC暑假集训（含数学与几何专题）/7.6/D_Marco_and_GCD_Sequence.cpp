//ID: LRL52  Date: 2022.7.6
//鼠鼠我啊想了很久都没构造出来
//不过思路大体是正确的，就是把考虑直接把给的数列当作答案
//但是可能会产生新的gcd，我开始直接认为这是没有解的，后来我找了很久才找出一个反例
//例如8 2 12，生产的S序列是2, 8, 12，按照题意计算会多出一个4，而4不在原序列
//原来只需要在每两个数中间插入一个d就行了，d = gcd(a1, a2, ..., an)，而这样构造就可以避免上述情况
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 4055, M = 1e6 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
int a[N], Ans[N], use[M], H[M];
vector<int> q1, q2;

int gcd(int a, int b){return a == 0 ? b : gcd(b % a, a);}

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    rd(n);
    rep(i, 1, n) rd(a[i]), H[a[i]] = 1;
    /*rep(i, 1, n){
        int d = 1;
        rep(j, i, n){
            if(j == i) d = a[j];
            else d = gcd(d, a[j]);
            if(H[d] == 0){
                puts("-1");
                return 0;
            }
        }
    }*/
    /*for(int i = n; i >= 1; --i) q1.push_back(a[i]);
    int p = 0;
    while(q1.size() > 0){
        q2.clear();
        for(int i = 0; i < q1.size(); ++i){
            int x = q1[i];
            if(use[x]) continue;
            int d = x, ok = 1;
            for(int j = p; j >= 1; --j){
                d = gcd(d, Ans[j]);
                if(H[d]){
                    use[d] = 1;
                } else{
                    ok = 0;
                    break;
                }
            }
            if(ok) Ans[++p] = x, use[x] = 1;
            else q2.push_back(x);
        }
        if(q1.size() == q2.size()){
            puts("-1");
            return 0;
        }
        q1.clear();
        for(int i = 0; i < q2.size(); ++i) q1.push_back(q2[i]);
    }
    printf("%d\n", p);
    rep(i, 1, p) printf("%d ", Ans[i]);*/
    int d = a[1];
    rep(i, 2, n) d = gcd(d, a[i]);
    if(d != a[1]){
        puts("-1");
        return 0;
    }
    else{
        printf("%d\n", 2 * n);
        rep(i, 1, n){
            printf("%d %d ", a[i], d);
        }
    }
	return 0;
}
