//ID: LRL52  Date: 2023.2.8
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e6 + 55, M = 2e3 + 55, inf = 0x3f3f3f3f;
char s1[N], s2[N];
int _sum[N];
int *sum = _sum + 5;

int change(pair<char, char> &t, char c) {
    auto [x, y] = t;
    if(c == x) return 1;
    if(c == y) return -1;
    return 0;
}

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task, tcnt = 0; cin >> Task;
	while(Task--) {
        cin >> (s1 + 1) >> (s2 + 1);
        vector<pair<char, char> > a;
        int n = strlen(s1 + 1);
        rep(i, 1, n)
            if(s1[i] != s2[i])
                a.emplace_back(s1[i], s2[i]);
        sum[-1] = 0;
        for(size_t i = 0; i < a.size(); ++i) {
            sum[i] = sum[i - 1];
            auto [x, y] = a[i];
            if(x == 'a') sum[i]++;
            else if(y == 'a') --sum[i];
        }
        int pos = 0;
        vector<char> Ans;
        for(int i = (int)a.size() - 1; i >= -1; --i) {
            if(abs(sum[i]) > (int)a.size() - 1 - i) continue;
            pos = i; int delta = sum[i];
            for(int j = 0; j <= i; ++j) Ans.push_back('a');
            for(int j = i + 1; j < a.size(); ++j) {
                auto [x, y] = a[j];
                for(int k = 0; k < 26; ++k) {
                    if(int t = delta + change(a[j], 'a' + k); abs(t) <= (int)a.size() - 1 - j) {
                        delta = t;
                        Ans.push_back('a' + k);
                        break;
                    }
                }
                // if(int t = delta + change(a[j], 'a'); abs(t) <= (int)a.size() - 1 - j) {
                //     delta = t;
                //     Ans.push_back('a');
                // } else 
                // if(int t = delta + change(a[j], min(x, y)); abs(t) <= (int)a.size() - 1 - j) {
                //     delta = t;
                //     Ans.push_back(min(x, y));
                // } else {
                //     delta += change(a[j], max(x, y));
                //     Ans.push_back(max(x, y));
                // }
            }
            break;
        } 
        printf("Case %d: ", ++tcnt);
        for(int i = 1, j = 0; i <= n; ++i) {
            if(s1[i] == s2[i]) putchar('a');
            else putchar(Ans[j++]);
        }
        puts("");
	}
	return 0;
}