//ID: LRL52  Date: 2022.8.16
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 425, M = 5e5 + 55; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0, cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = x * 10 + (cc ^ 48); cc = gc();} x *= f;
}
const int inf = 0x3f3f3f3f;
int n, S, T, L, ct, Fee, m, SumProfit;
int head[N], vis[N], dis[N], cur[N], inq[N];
int Time[N], profit[N], Pay[N];
vector<int> Pre[N];
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

inline void Adde(int x, int y, int z){
    adde(x, y, z, 1);
    adde(y, x, 0, -1);
}

int check(int lim){
    int x, y, z, w; ct = 1;
    memset(head, 0, sizeof(head));
    S = 0, T = n + m + 1;
    rep(i, 1, n){
        if(Time[i] <= lim) Adde(S, i, Pay[i]);
        else Adde(S, i, inf);
    }
    rep(i, 1, m){
        for(int j = 0; j < Pre[i].size(); ++j){
            x = Pre[i][j];
            Adde(x, i + n, inf);
        }
    }
    rep(i, 1, m) Adde(i + n, T, profit[i]);
    int Flow = 0;
    while(SPFA()){
		//注意，实际使用时可能是S循环到T，别把0号点和n+1号点漏掉了
		rep(i, S, T) cur[i] = head[i];
		Flow += max_flow(S, 2000000000);
	}
    int res = SumProfit - Flow;
    return res;
}

int main(){
#ifdef LRL52
	freopen("A.in", "r", stdin);
#endif
    int Task; rd(Task); int casecnt = 0;
    while(Task--){
        rd(n), rd(m), rd(L);
        rep(i, 1, n){
            rd(Pay[i]), rd(Time[i]);
        }
        int x, k; SumProfit = 0;
        rep(i, 1, m){
            rd(profit[i]), rd(k);
            SumProfit += profit[i];
            vector<int>().swap(Pre[i]);
            rep(j, 1, k){
                rd(x);
                Pre[i].push_back(x);
            }
        }
        int l = 0, r = 1000000000;
        while(l <= r){
            int mid = (l + r) >> 1;
            int res = check(mid);
            if(res >= L) r = mid - 1;
            else l = mid + 1;
        }
        if(l > 1000000000){
            printf("Case #%d: impossible\n", ++casecnt);
            continue;
        }
        int res = check(l);
        printf("Case #%d: %d %d\n", ++casecnt, l, res);
    }
	return 0;
}
