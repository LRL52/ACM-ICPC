//ID: LRL52  Date: 2022.7.15
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 50055, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, order[N], X, start, cntN;
struct Node{
    int val, nxt, pos;
    inline bool operator<(const Node&t)const{
        return val < t.val;
    }
}a[N];

//int rnd(int x){ rand() * rand() % x + 1;}

signed main() {
	scanf("%d%d%d", &n, &start, &X);
    rep(i, 1, n) order[i] = i;
    srand(1024520);
    random_shuffle(order + 1, order + n + 1);
    //rep(i, 1, 100) printf("%d ", order[i]);
    printf("? %d\n", start); fflush(stdout); ++cntN;
    int p = 1;
    scanf("%d%d", &a[1].val, &a[1].nxt); a[1].pos = start;
    for(int i = 1; i <= min(225, n); ++i){
        int pos = order[i];
        if(pos == start) continue;
        printf("? %d\n", pos); fflush(stdout);
        ++p;
        scanf("%d%d", &a[p].val, &a[p].nxt);
        a[p].pos = pos;
        ++cntN;
    }
    sort(a + 1, a + p + 1);
    int pos = 0;
    for(int i = p; i >= 1; --i){
        if(a[i].val <= X){
            pos = a[i].pos;
            break;
        }
    }
    if(!pos){
        printf("! %d\n", a[1].val); fflush(stdout);
        return 0;
    }
    int val, nxt;
    while(1){
        printf("? %d\n", pos); fflush(stdout);
        ++cntN;
        scanf("%d%d", &val, &nxt);
        if(val >= X){
            printf("! %d\n", val); fflush(stdout);
            return 0;
        }
        if(nxt == -1){
            printf("! -1\n"); fflush(stdout);
            return 0;
        }
        pos = nxt;
        if(cntN >= 1999) assert(0);
    }
	return 0;
}