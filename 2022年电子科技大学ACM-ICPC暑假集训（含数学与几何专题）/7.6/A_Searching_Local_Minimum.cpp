//ID: LRL52  Date: 2022.7.6
//第一次做交互题
//二分维护答案区间，即a[l - 1] > a[l] && a[r] < a[r + 1]
//注意快读就别用了，然后每次输出都要fflush(stdout)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
int n;

int main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	//rd(n);
    scanf("%d", &n);
    int l = 1, r = n, x, y;
    while(l < r){
        int mid = (l + r) >> 1;
        //printf("? %d\n? %d\n", mid, mid + 1);
        printf("? %d\n", mid);
        fflush(stdout);
        scanf("%d", &x);
        printf("? %d\n", mid + 1);
        fflush(stdout);
        scanf("%d", &y);
        if(x < y) r = mid;
        else l = mid + 1;
    }
    printf("! %d\n", l);
    fflush(stdout); //注意最后输出答案了以后也要fflush(stdout)
	return 0;
}
