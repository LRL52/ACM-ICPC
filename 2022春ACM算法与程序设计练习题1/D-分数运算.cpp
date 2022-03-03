#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1055, M = 2055;
typedef long long LL;

LL gcd(LL a, LL b) {
	return a == 0 ? b : gcd(b % a, a);
}

int main() {
	freopen("D.in", "r", stdin);
	int T; scanf("%d", &T);
	LL a, b, c, d, x, y; char op; //ans = x / y
	while (T--) {
		scanf("%lld%lld%lld%lld %c", &a, &b, &c, &d, &op);
		if (op == '+') {
			x = a * d + b * c;
			y = b * d;
		}
		else if (op == '-') {
			x = a * d - b * c;
			y = b * d;
		}
		else if (op == '*') {
			x = a * c;
			y = b * d;
		}
		else if (op == '/') {
			x = a * d;
			y = b * c;
		}
		LL _d = gcd(llabs(x), y);
		x /= _d, y /= _d;
		if(y > 1) printf("%lld/%lld%c%lld/%lld=%lld/%lld\n", a, b, op, c, d, x, y);
		else printf("%lld/%lld%c%lld/%lld=%lld\n", a, b, op, c, d, x);
	}
	return 0;
}