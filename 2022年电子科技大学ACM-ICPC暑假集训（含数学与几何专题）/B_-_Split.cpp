//ID: LRL52  Date: 2022.9.3
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e3 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
char s[N];
int a[N], b[N];
vector<int> col[15];

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	scanf("%s", s + 1);
    rep(i, 1, 10) a[i] = s[i] - '0';
    col[1].push_back(7);
    col[2].push_back(4);
    col[3].push_back(2), col[3].push_back(8);
    col[4].push_back(1), col[4].push_back(5);
    col[5].push_back(3), col[5].push_back(9);
    col[6].push_back(6);
    col[7].push_back(10);
    if(a[1]){
        puts("No");
        return 0;
    }
    rep(i, 1, 7){
        b[i] = 0;
        for(int j = 0; j < col[i].size(); ++j){
            int x = col[i][j];
            if(a[x]) b[i] = 1;
        }
    }
    int flag = -1, cnt = 0;
    rep(i, 1, 7){
        if(flag == -1){
            if(b[i] == 1) flag = 1, cnt++;
        } else {
            if(b[i] != flag) cnt++, flag = b[i];
        }
    }
    cnt >= 3 ? puts("Yes") : puts("No");
	return 0;
}