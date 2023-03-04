//ID: LRL52  Date: 2022.7.7
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e6 + 55;
char s[N];

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%s", s + 1);
        int n = strlen(s + 1);
        int L = 0, R = 0, U = 0, D = 0;
        rep(i, 1, n){
            L += s[i] == 'L';
            R += s[i] == 'R';
            U += s[i] == 'U';
            D += s[i] == 'D';
        }
        L = R = min(L, R);
        U = D = min(U, D);
        if(L == 0) U = D = min(U, 1);
        if(U == 0) L = R = min(L, 1);
        printf("%d\n", L + R + U + D);
        rep(i, 1, U) putchar('U');
        rep(i, 1, R) putchar('R');
        rep(i, 1, D) putchar('D');
        rep(i, 1, L) putchar('L');
        putchar('\n');
	}
	return 0;
}
