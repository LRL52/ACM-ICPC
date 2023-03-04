//ID: LRL52  Date: 2022.8.12
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 5055, M = 3e6 + 55; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
const int inf = 0x3f3f3f3f;
int n, S, T, ct, K, Fee, m;
int head[N], vis[N], dis[N], cur[N], inq[N];
struct edge{
	int v, nxt, w, fee;
}e[M << 1];
deque<int> q;

inline void adde(int from, int to, int w, int fee){
	e[++ct] = (edge){to, head[from], w, fee};
	head[from] = ct;
}

int SPFA(){
	memset(dis, 0x3f, sizeof dis);
	dis[S] = 0; q.push_front(S);
	while(!q.empty()){
		int now = q.front(); q.pop_front();
		inq[now] = 0;
		for(int i = head[now]; i; i = e[i].nxt){
			int v = e[i].v;
			if(e[i].w > 0 && dis[now] + e[i].fee < dis[v]){
				dis[v] = dis[now] + e[i].fee;
				if(!inq[v]){
					inq[v] = 1;
					if(!q.empty() && dis[v] <= dis[q.front()]) q.push_front(v);
					else q.push_back(v);
				}
			}
		}
	}
	return dis[T] != inf;
}

int max_flow(int now, int flow){
	if(now == T) return flow;
	int t = flow; vis[now] = 1;
	for(int &i = cur[now]; i; i = e[i].nxt){
		int v = e[i].v;
		if(!vis[v] && e[i].w > 0 && dis[now] + e[i].fee == dis[v]){
			int dx = max_flow(v, min(flow, e[i].w));
			flow -= dx, e[i].w -= dx;
			e[i ^ 1].w += dx;
			Fee += dx * e[i].fee;
			if(flow == 0) break;
		}
	}
	vis[now] = 0;
	return t - flow;
}

void Adde(int x, int y, int z){
    adde(x, y, z, 1);
    adde(y, x, 0, -1);
}

int main(){
#ifdef LRL52
	freopen("I.in", "r", stdin);
#endif
	rd(n), rd(m), rd(K);
	int x, y, z, w; ct = 1;
    rep(i, 1, n){
        rd(z);
        rep(j, 1, z){
            rd(x);
            Adde(i, x + n, 1);
        }
    }
    S = 0, T = n + m + 2;
    rep(i, 1, n) Adde(S, i, 1);
    rep(i, n + 1, n + m) Adde(i, T, 1);
    Adde(S, n + m + 1, K);
    rep(i, 1, n) Adde(n + m + 1, i, 1);
	int Flow = 0;
	while(SPFA()){
		//注意，实际使用时可能是S循环到T，别把0号点和n+1号点漏掉了
		rep(i, S, T) cur[i] = head[i];
		Flow += max_flow(S, inf);
	}
	printf("%d\n", Flow);
	return 0;
}
