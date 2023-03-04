#include <bits/stdc++.h>
typedef long long LL;
const int MOD = 998244353;

int power(int x, int t) {
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1ULL * ret * x % MOD;
		x = 1ULL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int rt[1100005];
void dft(int arr[], int l, int dir) {
	int rev = 0;
	for(int i = 0; i < (1 << l); i++) {
		if(i < rev) std::swap(arr[i], arr[rev]);
		for(int j = l - 1; j >= 0; j--) {
			rev ^= 1 << j;
			if(rev >> j & 1) break;
		}
	}
	for(int d = 2; d <= (1 << l); d <<= 1)
		for(int i = 0; i < (1 << l); i += d)
			for(int j = i; j < i + (d >> 1); j++) {
				int ev = arr[j], od = 1ULL * arr[j + (d >> 1)] * rt[(j ^ i) | d] % MOD;
				arr[j] = ev + od - (ev + od >= MOD ? MOD : 0);
				arr[j + (d >> 1)] = ev - od + (ev < od ? MOD : 0);
			}
	if(dir < 0) {
		std::reverse(arr + 1, arr + (1 << l));
		int inv = power((MOD + 1) / 2, l);
		for(int i = 0; i < (1 << l); i++)
			arr[i] = 1ULL * arr[i] * inv % MOD;
	}
}

int n, t, q, m, ca[550005];

void init() {
	for(int i = 1; i <= 19; i++) {
		int pr = power(3, (MOD - 1) >> i), cr = 1;
		for(int j = 0; j < (1 << i); j++) {
			rt[j | 1 << i] = cr;
			cr = 1ULL * cr * pr % MOD;
		}
	}
	
	ca[0] = 1;
	int len = 0;
	while(t >> len)
		len++;
	for(int i = len - 1; i >= 0; i--) {
		int cl = std::min(len - i, 19);
		dft(ca, cl, 1);
		for(int j = 0; j < (1 << cl); j++)
			ca[j] = 1ULL * ca[j] * ca[j] % MOD;
		if(t >> i & 1)
			for(int j = 0; j < (1 << cl); j++)
				ca[j] = 1ULL * ca[j] * (1 + rt[j | 1 << cl]) % MOD;
		dft(ca, cl, -1);
		for(int j = m; j < (1 << cl); j++) {
			ca[j - m] = (ca[j - m] + ca[j]) % MOD;
			ca[j] = 0;
		}
	}
}

int query4(int dx, int dy) {
	int ndx = ((dx + dy + t) / 2 % m + m) % m, ndy = ((dx - dy + t) / 2 % m + m) % m;
	return (1ULL * ca[ndx] * ca[ndy] + 1ULL * ca[(ndx + n) % m] * ca[(ndy + n) % m]) % MOD;
}

void query() {
	int xa, ya, xb, yb;
	scanf("%d%d%d%d", &xa, &ya, &xb, &yb);
	xa++;
	ya++;
	xb++;
	yb++;
	if((xa ^ ya ^ xb ^ yb ^ t) & 1) {
		printf("0\n");
		return;
	}
	int ans = query4(xb - xa, yb - ya);
	ans = (ans + query4(m - xb - xa, m - yb - ya)) % MOD;
	ans = (ans + MOD - query4(m - xb - xa, yb - ya)) % MOD;
	ans = (ans + MOD - query4(xb - xa, m - yb - ya)) % MOD;
	printf("%d\n", ans);
}

int main() {
	scanf("%d%d%d", &n, &t, &q);
	n += 2;
	m = n * 2;
	init();
	for(int i = 0; i < q; i++)
		query();
	return 0;
}

