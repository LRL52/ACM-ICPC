//ID: LRL52  Date: 2022.11.13
//结论是正图和反图的数字之和是相等的，所以答案要么为A的正图，要么为A的反图
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
const int N = 1e3 + 55;
int n, m;
char s1[N][N], s2[N][N];

void printans() {
    rep(i, 1, n) puts(s1[i] + 1);
    exit(0);
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
    rep(i, 1, n) cin >> (s1[i] + 1);
    rep(i, 1, n) cin >> (s2[i] + 1);
    //尝试把B变成A
    int cnt = 0;
    rep(i, 1, n)
        rep(j, 1, m)
            cnt += s1[i][j] != s2[i][j];
    if(cnt <= n * m / 2) printans();
    cnt = 0;
    rep(i, 1, n)
        rep(j, 1, m) {
            if(s1[i][j] == 'X') s1[i][j] = '.';
            else s1[i][j] = 'X';
            cnt += s1[i][j] != s2[i][j];
        }
    assert(cnt <= n * m / 2);
    printans();
	return 0;
} 
    