#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define dwn(i, a, b) for(int i = (a); i >= (b); --i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
#include<bits/stdc++.h>
using namespace std;
const int N = 500055, M = 2055; char ss[1<<21], *A = ss, *B = ss, ch;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1<<21, stdin), A == B) ? EOF : *A++;}
template<class T>void rd(T &x){
	int f = 1; x = 0; ch = gc(); while(ch < '0' || ch > '9'){if(ch == '-') f = -1; ch = gc();}
	while(ch >= '0' && ch <= '9'){x = x * 10 + (ch ^ 48); ch = gc();} x *= f;
}
#define int long long
int ct = 0, head[N], ans = 0, n, s;
struct edge{
	int v, nxt, w;
}e[N*2];

inline void adde(int from, int to, int w){
	e[++ct].v = to;
	e[ct].nxt = head[from];
	e[ct].w = w;
	head[from] = ct;
}

int dfs(int x, int far){
	int child = 0, now = 0;
	ee(i, x){
		int v = e[i].v, w = e[i].w;
		if(v == far) continue;
		int vnow = dfs(v, x);
		if(vnow + w > now){
			ans += child * (vnow + w - now);
			now = vnow + w;
		}else if(vnow + w < now){
			ans += now - (vnow + w);
		}
		++child;
	}
	//printf("%lld = %lld\n", x, now);
	return now;
}

#undef int
int main()
{
#define int long long
	freopen("X.in", "r", stdin);
	rd(n), rd(s); int x, y, z;
	rep(i, 1, n-1){
		rd(x), rd(y) ,rd(z);
		adde(x, y, z);
		adde(y, x, z);
	}
	dfs(s, 0);
	printf("%lld\n", ans);
	return 0;
}