//ID: LRL52  Date: 2022.7.27
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
int A[N][N];
const int D[] = {1, 10, 100, 1000, 10000};

int getres(int num){
    int a = num / 1000 % 10, b = num / 100 % 10;
    int c = num / 10 % 10, d = num % 10;
    int res = 0;
    res = A[res][a];
    res = A[res][b];
    res = A[res][c];
    res = A[res][d];
    return res;
}

int getres2(int num, int type = 0, int k = 0, int v = 0){
    int a = num / 10000 % 10, b = num / 1000 % 10;
    int c = num / 100 % 10, d = num / 10 % 10, e = num % 10;
    if(type == -1){
        if(k == 0) e = v;
        if(k == 1) d = v;
        if(k == 2) c = v;
        if(k == 3) b = v;
        if(k == 4) a = v;
    }
    if(type == 1){
        if(a == b) return -1;
        swap(a, b);
    }
    if(type == 2){
        if(b == c) return -1;
        swap(b, c);
    }
    if(type == 3){
        if(c == d) return -1;
        swap(c, d);
    }
    if(type == 4){
        if(d == e) return -1;
        swap(d, e);
    }
    int res = 0;
    res = A[res][a];
    res = A[res][b];
    res = A[res][c];
    res = A[res][d];
    res = A[res][e];
    return res;
}

signed main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	for(int i = 0; i <= 9; ++i)
        for(int j = 0; j <= 9; ++j)
            rd(A[i][j]);
    int ans = 0;
    for(int num = 0; num <= 9999; ++num){
        int res = getres(num);
        //if(num == 2016) printf("res = %d\n", res);
        int err = 0;
        /*for(int k = 0; k < 4; ++k){
            for(int t = 0; t < 9; ++t){
                int v = num / D[k] % 10;
                if(v == t) continue;
                int res2 = getres(num, -1, k, t);
                if(res2 == res) err = 1;
            }
        }
        for(int k = 1; k <= 3; ++k){
            int res2 = getres(num, k);
            if(res2 == res) err = 1;
        }
        int d = num % 10;
        int res2 = getres(num / 10 * 10 + res);
        if(res2 == d) err = 1;
        ans += err;*/
        int ssn = num * 10 + res;
        for(int k = 0; k < 5; ++k){
            for(int t = 0; t <= 9; ++t){
                int v = ssn / D[k] % 10;
                if(v == t) continue;
                int res2 = getres2(ssn, -1, k, t);
                if(res2 == 0) err = 1;
            }
        }
        for(int k = 1; k <= 4; ++k){
            int res2 = getres2(ssn, k);
            if(res2 == 0) err = 1;
        }
        ans += err;
    }
    printf("%d\n", ans);
	return 0;
}