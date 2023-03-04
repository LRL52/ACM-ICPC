//ID: LRL52  Date: 2022.7.12
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1055, M = 2055; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int a[N][N], vis[N][N];
struct Node{
    int i, j, val;
    inline bool operator<(const Node&t)const{
        return val < t.val;
    }
}Q[N * N];
priority_queue<Node> q;
struct cmp{
    inline bool operator()(const Node&t1, const Node&t2)const{
        return t1.val > t2.val;
    }
};

int check(int x, int i, int j){
    return x != a[i - 1][j] && x != a[i][j - 1] && x != a[i + 1][j] && x != a[i][j + 1];
}

int judge(int i, int j){
    return !(vis[i - 1][j] && vis[i][j - 1] && vis[i + 1][j] && vis[i][j + 1]);
}

int dfs(int p){
    if(p == n * m + 1) return 1;
    Node now = Q[p];
    int i = now.i, j = now.j;
    vis[i][j] = 1;
    if(judge(i, j) || check(a[i][j], i, j)){
        if(dfs(p + 1)) return 1;
    }
    if(judge(i, j) || check(a[i][j] + 1, i, j)){
        a[i][j]++;
        if(dfs(p + 1)) return 1;
        a[i][j]--;
    }
    vis[i][j] = 0;
    return 0;
}

int main() {
#ifdef LRL52
	freopen("B.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
		rd(n), rd(m); int p = 0;
        rep(i, 1, n)
            rep(j, 1, m){
                rd(a[i][j]);
                //q.push((Node){i, j, a[i][j]});
                Q[++p] = (Node){i, j, a[i][j]};
                vis[i][j] = 0;
            }
        sort(Q + 1, Q + p + 1, cmp());
        rep(i, 0, n + 1) vis[i][0] = vis[i][m + 1] = 1;
        rep(i, 0, m + 1) vis[0][i] = vis[n + 1][i] = 1;
        /*rep(i, 1, n){
            rep(j, 1, m){
                if(a[i][j] == a[i - 1][j] || a[i][j] == a[i][j - 1]){
                    ++a[i][j];
                }
            }
        }*/
        /*while(!q.empty()){
            Node qu = q.top(); q.pop();
            int i = qu.i, j = qu.j;
            if(a[i][j] + 1 != a[i - 1][j] && 
               a[i][j] + 1 != a[i][j - 1] &&
               a[i][j] + 1 != a[i][j + 1] &&
               a[i][j] + 1 != a[i + 1][j]   ){
                   ++a[i][j];
               }
        }*/
        dfs(1);
        rep(i, 1, n){
            rep(j, 1, m)
                printf("%d ", a[i][j]);
            putchar('\n');
        }
	}
	return 0;
}
