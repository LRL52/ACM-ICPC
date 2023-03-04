// ID: LRL52  Date: 2022.6.7
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 55;
struct Edge{
	int v, nxt;
}e[N];
char s[N * 10];
int n, size[N];
struct Ac{
	int tr[N][27], tot, len, p, nxt[N];
	int head[N], ct, match[N], size[N];
	Edge e[N];
	queue<int> q;
	void adde(int from, int to){
		e[++ct].v = to;
		e[ct].nxt = head[from];
		head[from] = ct;
	}
	void insert(int id, const char *t){
		p = 0, len = strlen(t + 1);
		rep(i, 1, len){
			int &x = tr[p][t[i] - 'a'];
			if(!x) x = ++tot;
			p = x;
		}
		match[id] = p;
	}
	void build(){
		rep(i, 0, 25) if(tr[0][i]) q.push(tr[0][i]);
		while(!q.empty()){
			int now = q.front(); q.pop();
			rep(i, 0, 25){
				int &v = tr[now][i];
				if(v){
					nxt[v] = tr[nxt[now]][i];
					q.push(v);
				}
				else v = tr[nxt[now]][i];
			}
		}
		rep(i, 1, tot) adde(nxt[i], i);
	}
	void insert_text(const char *t){
		p = 0, len = strlen(t + 1);
		rep(i, 1, len){
			p = tr[p][t[i] - 'a'];
			++size[p];
		}
	}
	void dfs(int x){
		ee(i, x){
			int v = e[i].v;
			dfs(v);
			size[x] += size[v];
		}
	}
	int getans(int i){return size[match[i]];}
}ac;

int main(){
#ifdef LRL52
	freopen("W.in", "r", stdin);
#endif
    scanf("%d", &n);
	rep(i, 1, n){
		scanf("%s", s + 1);
		ac.insert(i, s);
	}
	ac.build();
	scanf("%s", s + 1);
	ac.insert_text(s);
	ac.dfs(0);
	rep(i, 1, n) printf("%d\n", ac.getans(i));
	return 0;
}