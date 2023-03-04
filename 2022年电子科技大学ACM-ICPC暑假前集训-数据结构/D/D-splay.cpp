#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 55, M = 2055; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0; cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = (x << 3) + (x << 1) + (cc ^ 48); cc = gc();} x *= f;
}
const int inf = 0x3f3f3f3f;
int n;
struct Splay{
	#define ls ch[cur][0]
	#define rs ch[cur][1]
	int ch[N][2], size[N], par[N], val[N], cnt[N];
	int root, cntN;
	inline int chk(int x){return ch[par[x]][1] == x;}
	void pushup(int cur){size[cur] = size[ls] + size[rs] + cnt[cur];}
	void rotate(int x){
		int y = par[x], z = par[y], k = chk(x), w = ch[x][k ^ 1];
		ch[y][k] = w, par[w] = y;
		ch[z][chk(y)] = x, par[x] = z;
		ch[x][k ^ 1] = y, par[y] = x;
		pushup(y), pushup(x);
	}
	void splay(int x, int goal = 0){
		while(par[x] != goal){
			int y = par[x], z = par[y];
			if(z != goal){
				if(chk(x) == chk(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		if(!goal) root = x;
	}
	void find(int x){
		int cur = root;
		while(val[cur] != x && ch[cur][x > val[cur]]) cur = ch[cur][x > val[cur]];
		splay(cur);
	}
	void insert(int x){
		int cur = root, p = 0;
		while(val[cur] != x && cur) p = cur, cur = ch[cur][x > val[cur]];
		if(cur) ++cnt[cur];
		else{
			cur = ++cntN;
			if(p) ch[p][x > val[p]] = cur;
			par[cur] = p, val[cur] = x;
			size[cur] = cnt[cur] = 1;
		}
		splay(cur);
	}
	int pre(int x){
		find(x); if(val[root] < x) return root;
		int cur = ch[root][0]; 
		while(rs) cur = rs; return cur;
	}
	int suc(int x){
		find(x); if(val[root] > x) return root;
		int cur = ch[root][1]; 
		while(ls) cur = ls; return cur;
	}
	void remove(int x){
		int prex = pre(x), sucx = suc(x);
		splay(prex); splay(sucx, prex);
		int cur = ch[sucx][0];
		if(cnt[cur] > 1){
			--cnt[cur]; splay(cur);
		} else {
			ch[sucx][0] = 0; splay(sucx);
		}
	}
	int kth(int k){
		++k; int cur = root;
		while(1){
			if(size[ls] >= k) cur = ls;
			else if(size[ls] + cnt[cur] >= k) return cur;
			else k -= size[ls] + cnt[cur], cur = rs;
		}
	}
	int rank(int x){
		find(x); return size[ch[root][0]];
	}
}s;

int main(){
	rd(n); int op, x;
	s.insert(-inf); s.insert(inf);
	rep(i, 1, n){
		rd(op), rd(x);
		if(op == 1) s.insert(x);
		else if(op == 2) s.remove(x);
		else if(op == 3) printf("%d\n", s.rank(x));
		else if(op == 4) printf("%d\n", s.val[s.kth(x)]);
		else if(op == 5){
			int ans =  s.val[s.pre(x)];
			if(ans != -inf) printf("%d\n", ans); 
			else puts("NOT FOUND");
		}
		else{
			int ans =  s.val[s.suc(x)];
			if(ans != inf) printf("%d\n", ans);
			else puts("NOT FOUND");
		}
	}
	return 0;
}
