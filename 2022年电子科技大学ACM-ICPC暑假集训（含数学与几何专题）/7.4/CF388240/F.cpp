//ID: LRL52  Date: 2022.7.4
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055;
int n, m;
int a[N][N];
char s[N];

int check(int i, int sign){ //0代表行, 1代表列
    int ok = 1;
    if(sign == 0){
        rep(k, 1, m)
            if(a[i][k] == 0){
                ok = 0;
                break;
            }
    } else {
        rep(k, 1, n)
            if(a[k][i] == 0){
                ok = 0;
                break;
            }
    }
    return ok;
}

int main() {
#ifdef LRL52
	freopen("F.in", "r", stdin);
#endif
	int T; scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &m); int ok = 0, OK = 1;
        rep(i, 1, n){
            scanf("%s", s + 1);
            rep(j, 1, m){
                a[i][j] = (s[j] == 'A');
                ok |= a[i][j];
                if(a[i][j] == 0) OK = 0;
            }
        }
        if(!ok){
            puts("MORTAL");
            continue;
        }
        if(OK){
            puts("0");
            continue;
        }
        int flag = 0;
        flag |= check(1, 0); //0代表行, 1代表列
        flag |= check(1, 1);
        flag |= check(n, 0);
        flag |= check(m, 1);
        if(flag){
            puts("1");
            continue;
        }
        flag |= a[1][1] | a[1][m] | a[n][1] | a[n][m];
        rep(i, 1, n) flag |= check(i, 0);
        rep(i, 1, m) flag |= check(i, 1);
        if(flag){
            puts("2");
            continue;
        }
        rep(i, 1, n) flag |= a[i][1] | a[i][m];
        rep(i, 1, m) flag |= a[1][i] | a[n][i];
        if(flag){
            puts("3");
            continue;
        }
        puts("4");
    }
	return 0;
}