//ID: LRL52  Date: 2022.8.10
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1055, M = 1e6 + 55; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
const int inf = 0x3f3f3f3f;
int n, ct, S, T, Fee, K, m;
int head[N], vis[N], dis[N], cur[N], inq[N];
int St[N], End[N], type[N], W[N];
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

inline void Adde(int x, int y, int z, int w){
    adde(x, y, z, -w);
    adde(y, x, 0, w);
}

int main(){
#ifdef LRL52
	freopen("L.in", "r", stdin);
#endif
	int x, y, z, w, dw;
    int task; rd(task);
    while(task--){
        rd(n), rd(m), rd(K), rd(dw);
        rep(i, 1, m) rd(St[i]), rd(End[i]), rd(W[i]), rd(type[i]);
        memset(head, 0, sizeof(head));
        ct = 1;
        rep(i, 1, m){
            rep(j, 1, m){
                if(End[i] <= St[j]){
                    Adde(i + m, j, inf, (type[i] == type[j]) * (-dw));
                }
            }
        }
        rep(i, 1, m) Adde(i, i + m, 1, W[i]);
        rep(i, 1, m){
            Adde(2 * m + 1, i, inf, 0);
            Adde(i + m, 2 * m + 2, inf, 0);
        }
        Adde(0, 2 * m + 1, K, 0);
        S = 0, T = 2 * m + 2;
        int Flow = 0; Fee = 0;
        while(SPFA()){
            //注意，实际使用时可能是S循环到T，别把0号点和n+1号点漏掉了
            rep(i, S, T) cur[i] = head[i];
            Flow += max_flow(S, inf);
        }
        printf("%d\n", -Fee);
    }
	//printf("%d %d\n", Flow, Fee);
	return 0;
}
