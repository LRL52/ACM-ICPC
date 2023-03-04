//ID: LRL52  Date: 2022.4.27
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 55; char ss[1 << 21], *A = ss, *B = ss, cc;
inline char gc(){return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++;}
template<class T>inline void rd(T &x){
	int f = 1; x = 0; cc = gc(); while(cc < '0' || cc > '9'){if(cc == '-') f = -1; cc = gc();}
	while(cc >= '0' && cc <= '9'){x = (x << 3) + (x << 1) + (cc ^ 48); cc = gc();} x *= f;
}
const int inf = 0x3f3f3f3f;
int n, m;
struct Splay{
	#define ls ch[cur][0]
	#define rs ch[cur][1]
	int ch[N][2], size[N], par[N], val[N];
	int root, cntN;
	inline int chk(int x){return ch[par[x]][1] == x;}
	void pushup(int cur){size[cur] = size[ls] + size[rs] + 1;}
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
    void init(){
        root = 1, cntN = 2;
        ch[root][1] = 2, par[2] = 1;
        val[1] = -inf, val[2] = inf;
        size[1] = 2, size[2] = 1;
    }
   	int kth(int k){ //这里第k小没有--k，没有除去首尾的边界点
		int cur = root;
		while(1){
			if(size[ls] >= k) cur = ls;
			else if(size[ls] + 1 >= k) return cur;
			else k -= size[ls] + 1, cur = rs;
		}
	}     
	void insert(int k, int x){ //第k个位置前插入x
        k = min(k + 1, size[root]);
        int prex = kth(k - 1), sucx = kth(k);
        splay(prex); splay(sucx, prex);
        int cur = ++cntN;
        val[cur] = x, par[cur] = sucx, size[cur] = 1;
        ch[sucx][0] = cur;
		splay(cur);
	}
}s;

int main(){
#ifdef LRL52
	freopen("O.in", "r", stdin);
#endif
	s.init();
    rd(n), rd(m); int op, pos, x;
    rep(i, 1, n){
        rd(x);
        s.insert(i, x);
    }
    rep(i, 1, m){
        rd(op);
        if(op == 1){
            rd(x), rd(pos);
            s.insert(pos, x);
        } else
        if(op == 2){
            rd(pos);
            printf("%d\n", s.val[s.kth(pos + 1)]);
        }
    }
	return 0;
}