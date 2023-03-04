//ID: LRL52  Date: 2022.7.7
//考虑前3个点，由于总共只能画2条直线，根据抽屉原理，至少有2个点在同一条直线上
//例如假设1,2两个点共线，那么第3 ~ n个点中不在该直线上的点必然在另一条直线上，判定一下即可
//再对另外两种情况作上述操作即可
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n;
struct Node{
    int x, y;
    Node operator- (const Node&t)const{
        return (Node){x - t.x, y - t.y};
    }
}a[N];

long long cross(const Node&t1, const Node&t2){
    return 1LL * t1.x * t2.y - 1LL * t1.y * t2.x;
} 

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    rd(n);
    rep(i, 1, n) rd(a[i].x), rd(a[i].y);
    if(n <= 3){
        puts("YES");
        return 0;
    }
    for(int tt = 1; tt <= 3; ++tt){
        Node v1 = a[2] - a[1];
        int p1 = 0, p2 = 0;
        rep(i, 3, n){
            if(cross(a[i] - a[1], v1) != 0LL){
                if(p1 == 0) p1 = i;
                else{
                    p2 = i;
                    break;
                }
            }
        }
        if(p1 == 0 || p2 == 0){
            puts("YES");
            return 0;
        }
        Node v2 = a[p2] - a[p1];
        int ok = 1;
        rep(i, 3, n){
            if(cross(a[i] - a[1], v1) != 0LL && cross(a[i] - a[p1], v2) != 0LL){
                ok = 0;
                break;
            }
        }
        if(ok){
            puts("YES");
            return 0;
        }
        if(tt == 1) swap(a[2], a[3]);
        if(tt == 2) swap(a[1], a[3]);
    }
    puts("NO");
	return 0;
}
