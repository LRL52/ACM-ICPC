//ID: LRL52  Date: 2023.3.2
//答案要么是 nxt[n] 要么是 nxt[nxt[n]]
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s[N];
int nxt[N];

void getNext(char *s) {
    int len = strlen(s + 1);
    for(int i = 2, j = 0; i <= len; ++i) {
        while(j > 0 && s[j + 1] != s[i]) j = nxt[j];
        if(s[j + 1] == s[i]) ++j;
        nxt[i] = j;
    }
}

signed main() {
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> (s + 1);
    getNext(s);
    auto prints = [](int m) {
        for(int i = 1; i <= m; ++i) putchar(s[i]);
        puts("");
    };
    int n = strlen(s + 1);
    if(nxt[n] == 0) {
        puts("Just a legend");
        return 0;
    } else {
        int ok = 0;
        for(int i = nxt[n] + 1; i < n; ++i) {
            if(nxt[i] == nxt[n]) {
                ok = 1;
                break;
            }
        }
        if(ok) prints(nxt[n]);
        else if(nxt[nxt[n]]) prints(nxt[nxt[n]]);
        else puts("Just a legend");
    }
	return 0;
}