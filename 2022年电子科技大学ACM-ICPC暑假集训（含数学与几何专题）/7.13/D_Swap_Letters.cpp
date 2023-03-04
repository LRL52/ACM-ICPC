//ID: LRL52  Datep: 2022.7.13
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
vector<int> v1, v2;
vector<pair<int, int> > Ans;
int n;
char s1[N], s2[N];

int main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	scanf("%d", &n);
    scanf("%s%s", s1 + 1, s2 + 1);
    rep(i, 1, n){
        if(s1[i] == s2[i]) continue;
        if(s1[i] == 'a' && s2[i] == 'b') v1.push_back(i);
        if(s1[i] == 'b' && s2[i] == 'a') v2.push_back(i);
    }
    if((v1.size() + v2.size()) % 2){
        puts("-1");
        return 0;
    }
    for(int i = 0; i + 1 < v1.size(); i += 2){
        //printf("%d %d\n", v1[i + 1], v1[i]);
        Ans.push_back(make_pair(v1[i + 1], v1[i]));
    }
    for(int i = 0; i + 1 < v2.size(); i += 2){
        //printf("%d %d\n", v2[i + 1], v2[i]);
        Ans.push_back(make_pair(v2[i + 1], v2[i]));
    }
    if(v1.size() % 2){
        int x = v1[v1.size() - 1], y = v2[v2.size() - 1];
        if(x > y) swap(x, y);
        //printf("%d %d\n", y, y);
        //printf("%d %d\n", y, x);
        Ans.push_back(make_pair(y, y));
        Ans.push_back(make_pair(y, x));
    }
    printf("%u\n", Ans.size());
    for(int i = 0; i < Ans.size(); ++i)
        printf("%d %d\n", Ans[i].first, Ans[i].second);
	return 0;
}
