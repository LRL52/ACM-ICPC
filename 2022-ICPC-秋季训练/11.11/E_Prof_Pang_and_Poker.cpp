#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e5 + 55;
int n, m;
int a[N], b[N];

int getcard() {
    static char s[5];
    cin >> s;
    if(s[0] == 'T') return 10;
    else if(s[0] == 'J') return 11;
    else if(s[0] == 'Q') return 12;
    else if(s[0] == 'K') return 13;
    else if(s[0] == 'A') return 14;
    else return s[0] - '0';
}

signed main(){
    //freopen("E.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int Task; cin >> Task;
    while(Task--) {
        cin >> n >> m;
        int A0_max = -1, A1_max = -1, B0_max = -1, B1_max = -1;
        int A0 = 0, B0 = 0, A1 = 0, B1 = 0;
        int X;
        rep(i, 1, n) a[i] = getcard();
        rep(i, 1, m) b[i] = getcard();
        X = getcard();
        rep(i, 1, n) {
            int y = a[i];
            if(y < X) ++A0, A0_max = max(A0_max, y);
            else ++A1, A1_max = max(A1_max, y);
        }
        rep(i, 1, m) {
            int y = b[i];
            if(y < X) ++B0, B0_max = max(B0_max, y);
            else ++B1, B1_max = max(B1_max, y);
        }
        int ok = 0;
        if(A0 == 1 && A1 == 0) ok = 0;
        else if(A0 == 0) ok = 0;
        else if(A0 >= 1) {
            if(B0 >= 2) ok = 1;
            else if(B0 == 0) ok = 0;
            else if(B0 == 1) {
                if(A0_max < B0_max) ok = 0;
                else {
                    if(B1 == 0) ok = 1;
                    else if(B1 > 0 && A1 == 0) ok = 0;
                    else if(A1_max > B1_max) {
                        if(A0 == 1 || A0 + A1 <= 3) ok = 0;
                        else ok = 1;
                    }
                    else ok = 0;
                }
            }
        }
        ok ? puts("Pang") : puts("Shou");
    }
    return 0;
}