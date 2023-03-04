//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
#define int long long
vector<int> s1, s2, res;

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int a, b, K;
    rd(a), rd(b), rd(K);
    while(a){
        s1.push_back(a % K);
        a /= K;
    }
    while(b){
        s2.push_back(b % K);
        b /= K;
    }
    if(s1.size() < s2.size()) swap(s1, s2);
    int ans = 0, carry = 0;
    for(int i = 0; i < min(s1.size(), s2.size()); ++i){
        int t = carry + s1[i] + s2[i];
        res.push_back(t % K);
        if(t >= K){
            //++ans;
            ans += t / K;
        }
        carry = t / K;
    }
    for(int i = s2.size(); i < s1.size(); ++i){
        int t = carry + s1[i];
        res.push_back(t % K);
        if(t >= K){
            //++ans;
            ans += t / K;
        }
        carry = t / K;
    }
    while(carry){
        res.push_back(carry % K);
        ans += carry / K;
        carry /= K;
    }
    printf("%d\n", ans);
	return 0;
}
