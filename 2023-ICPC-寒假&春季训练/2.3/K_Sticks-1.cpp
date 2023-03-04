//ID: LRL52  Date: 2023.2.2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
const int N = 1e3 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
int n, tcnt, a[N];

int check(int i) {
    return a[i - 2] + a[i - 1] > a[i];
}

int Solve4() {
    for(int i = 3; i <= 12; ++i) {
        if(!check(i)) continue;
        for(int j = i + 3; j <= 12; ++j) {
            if(!check(j)) continue;
            for(int k = j + 3; k <= 12; ++k) {
                if(!check(k)) continue;
                for(int l = k + 3; l <= 12; ++l) {
                    if(!check(l)) continue;
                    printf("Case #%d: %d\n", ++tcnt, 4);
                    printf("%d %d %d\n", a[i - 2], a[i - 1], a[i]);
                    printf("%d %d %d\n", a[j - 2], a[j - 1], a[j]);
                    printf("%d %d %d\n", a[k - 2], a[k - 1], a[k]);
                    printf("%d %d %d\n", a[l - 2], a[l - 1], a[l]);
                    return 1;
                }
            }
        }
    }
    return 0;
}      

int Solve3() {
    for(int i = 3; i <= 12; ++i) {
        if(!check(i)) continue;
        for(int j = i + 3; j <= 12; ++j) {
            if(!check(j)) continue;
            for(int k = j + 3; k <= 12; ++k) {
                if(!check(k)) continue;
                printf("Case #%d: %d\n", ++tcnt, 3);
                printf("%d %d %d\n", a[i - 2], a[i - 1], a[i]);
                printf("%d %d %d\n", a[j - 2], a[j - 1], a[j]);
                printf("%d %d %d\n", a[k - 2], a[k - 1], a[k]);
                return 1;
            }
        }
    }
    return 0;
} 

int Solve2() {
    for(int i = 3; i <= 12; ++i) {
        if(!check(i)) continue;
        for(int j = i + 3; j <= 12; ++j) {
            if(!check(j)) continue;
            printf("Case #%d: %d\n", ++tcnt, 2);
            printf("%d %d %d\n", a[i - 2], a[i - 1], a[i]);
            printf("%d %d %d\n", a[j - 2], a[j - 1], a[j]);
            return 1;
        }
    }
    return 0;
}

int Solve1() {
    for(int i = 3; i <= 12; ++i) {
        if(!check(i)) continue;
        printf("Case #%d: %d\n", ++tcnt, 1);
        printf("%d %d %d\n", a[i - 2], a[i - 1], a[i]);
        return 1;
    }
    return 0;
} 

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
    while(Task--) {
        rep(i, 1, 12) cin >> a[i];
        sort(a + 1, a + 12 + 1);
        if(Solve4()) continue;
        if(Solve3()) continue;
        if(Solve2()) continue;
        if(Solve1()) continue;
        printf("Case #%d: %d\n", ++tcnt, 0);
    }
	return 0;
}