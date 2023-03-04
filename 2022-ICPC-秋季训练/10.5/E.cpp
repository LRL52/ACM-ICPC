    //ID: LRL52  Date: 2022.10.4
    #include <bits/stdc++.h>
    #define rep(i, a, b) for(int i = (a); i <= (b); ++i)
    #define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
    using namespace std;
    const int N = 1e5 + 55, inf = 0x3f3f3f3f;
    char s[N], t[N];
    int Nxt[N][102], Pos[155];

    signed main() {
    #ifdef LRL52
        freopen("E.in", "r", stdin);
    #endif
        int Task; scanf("%d", &Task);
        while(Task--) {
            scanf("%s%s", s + 1, t + 1);
            int n = strlen(s + 1), m = strlen(t + 1);
            rep(i, 0, 128) Pos[i] = n + 1;
            rep(i, 1, m) Nxt[n + 1][i] = n + 1;
            for(int i = n; i >= 1; --i) {
                Pos[s[i]] = i;
                for(int j = 1; j <= m; ++j)
                    Nxt[i][j] = Pos[t[j]];
            }
            int ans = inf, st = 0, ed = 0;
            for(int i = 1; i <= n; ++i) {
                int now = i;
                for(int j = 1; j <= m; ++j) {
                    if(now > n) break;
                    if(j != 1 && now == Nxt[now][j]) now = Nxt[now + 1][j];
                    else now = Nxt[now][j];
                }
                if(now <= n && now - i + 1 < ans) {
                    ans = now - i + 1;
                    st = i, ed = now;
                }
            }
            for(int i = st; i <= ed; ++i) putchar(s[i]);
            puts("");
        }
        return 0;
    }