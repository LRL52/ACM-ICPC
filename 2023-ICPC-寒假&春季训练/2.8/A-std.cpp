#include<bits/stdc++.h>
using namespace std;
int read () {
    int num = 0; char c = ' '; int flag = 1;
    for (;c > '9' || c < '0'; c = getchar ())
        if (c == '-')
            flag = 0;
    for (;c >= '0' && c <= '9'; num = (num << 3) + (num << 1) + c - 48, c = getchar ());
    return flag ? num : - num;
}
typedef long long ll;
const int maxn = 100200;
ll a[maxn], b[maxn];
int n, m; ll x[maxn], y[maxn];
void init () {
	n = read (), m = read ();
	for (int i = 1;i <= n;i ++)
		x[i] = a[i] = read ();
	for (int i = 1;i <= m;i ++)
		y[i] = b[i] = read ();
}
int la[maxn], lb[maxn];
void mergea () {
	for (int i = 1;i <= n;i ++)
		la[i] = 1;
	int k = n; bool flag = 1;
	while (flag) {
		flag = 0; k = n;
		for (int i = n - 1;i >= 1;i --)
			if (a[i]) {
				if (1ll * a[k] * la[i] > 1ll * a[i] * la[k]) {
					a[k] += a[i]; a[i] = 0;
					la[k] += la[i]; la[i] = 0;
					flag = 1;
				}
				else k = i;
			}
	}
}
void mergeb () {
	for (int i = 1;i <= m;i ++)
		lb[i] = 1;
	int k = m; bool flag = 1;
	while (flag) {
		flag = 0; k = m;
		for (int i = m - 1;i >= 1;i --)
			if (b[i]) {
				if (1ll * b[k] * lb[i] > 1ll * b[i] * lb[k]) {
					b[k] += b[i]; b[i] = 0;
					lb[k] += lb[i]; lb[i] = 0;
					flag = 1;
				}
				else k = i;
			}
	}
}
ll blocka[maxn], blockb[maxn], topa, topb;
void prework () {
	topa = topb = 0;
	int t = 0;
	for (int i = 1;i <= n;i ++) {
		t ++;
		if (a[i]) blocka[++ topa] = t, t = 0;
	}
	t = 0;
	for (int i = 1;i <= m;i ++) {
		t ++;
		if (b[i]) blockb[++ topb] = t, t = 0;
	}
	for (int i = 1;i <= n;i ++)
		a[i] = x[i];
	for (int i = 1;i <= m;i ++)
		b[i] = y[i];
	for (int i = 1;i <= n;i ++)
		x[i] += x[i - 1];
	for (int i = 1;i <= m;i ++)
		y[i] += y[i - 1];
}
long long ans;
void work () {
	int i, j, k, l;
	i = j = k = l = 1;
	ans = 0; int s = 1;
	while (k <= topa || l <= topb) {
		long long sum1, sum2;
		sum1 = 1ll * (x[i + blocka[k] - 1] - x[i - 1]) * blockb[l];
		sum2 = 1ll * (y[j + blockb[l] - 1] - y[j - 1]) * blocka[k];
		if (l > topb) {
			for (int u = 1;u <= blocka[k];u ++) {
				ans += 1ll * a[i ++] * s ++;
			}
			k ++;	
		}
		else if (k > topa) {
			for (int u = 1;u <= blockb[l];u ++) {
				ans += 1ll * b[j ++] * s ++;
			}
			l ++;
		}
		else {
			if (sum1 > sum2) {
				for (int u = 1;u <= blocka[k];u ++) {
					ans += 1ll * a[i ++] * s ++;
				}
				k ++;
			}
			else {
				for (int u = 1;u <= blockb[l];u ++) {
					ans += 1ll * b[j ++] * s ++;
				}
				l ++;
			}
		}
	}
}
int main () {
	int T = read ();
	for (int caseT = 1;caseT <= T;caseT ++) {
		init ();
		mergea ();
		mergeb ();
		prework ();
		work ();
		printf ("Case %d: %lld\n", caseT, ans);
	}
	return 0;
}
