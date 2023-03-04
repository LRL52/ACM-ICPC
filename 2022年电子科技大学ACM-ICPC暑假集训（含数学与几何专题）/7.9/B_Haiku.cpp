//ID: LRL52  Date: 2022.7.9
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
int n1, n2, n3;
char s[N];

char table[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
int check(char x){
    for(int i = 0; i < 10; ++i){
        if(x == table[i])
            return 1;
    }
    return 0;
}

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	int Task; scanf("%d", &Task);
	while(Task--){
		scanf("%d%d%d", &n1, &n2, &n3);
        int sum = 0, d = 0, ok = 1;
        rep(i, 1, n1){
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            rep(j, 1, len){
                sum += check(s[j]);
                d += s[j] == 'Y' || s[j] == 'y';
            }
        }
        ok &= (sum <= 5 && sum + d >= 5);
        sum = d = 0;
        rep(i, 1, n2){
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            rep(j, 1, len){
                sum += check(s[j]);
                d += s[j] == 'Y' || s[j] == 'y';
            }         
        }
        ok &= (sum <= 7 && sum + d >= 7);
        sum = d = 0;
        rep(i, 1, n3){
            scanf("%s", s + 1);
            int len = strlen(s + 1);
            rep(j, 1, len){
                sum += check(s[j]);
                d += s[j] == 'Y' || s[j] == 'y';
            }
        }
        ok &= (sum <= 5 && sum + d >= 5);
        ok ? puts("YES") : puts("NO");
 	}
	return 0;
}
