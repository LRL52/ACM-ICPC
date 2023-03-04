//ID: LRL52  Date: 2022.7.8
//这是用并查集 + set的版本
//只考虑原图的0边，维护出所有这些0边添加后的连通块数量
//从1~n考虑每个点，对于每个点考虑它的所有出边所在的连通块，如果该连通块被遍历的次数 < 它的size，则该点能和它相连，并合并该连通块到该点
//为了避免上述操作将时间复杂度退化至O(n^2)，需要一个set和queue辅助一下(可能也有其它办法吧)
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 1e5 + 55, M = 1e5 + 55; char ss[1 << 21], * A = ss, * B = ss, cc;
inline char gc() { return A == B && (B = (A = ss) + fread(ss, 1, 1 << 21, stdin), A == B) ? EOF : *A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int n, m;
int head[N], vis[N], Count[N], fa[N], Size[N];
struct Edge{
    int v, nxt;
}e[M << 1];
set<int> s;
queue<int> q;

inline void adde(int from, int to){
    static int et = 0;
    e[++et] = (Edge){to, head[from]};
    head[from] = et;
}

int find(int x){return fa[x] == x ? x : fa[x] = find(fa[x]);}

int main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
    rd(n), rd(m); int x, y;
    rep(i, 1, m){
        rd(x), rd(y);
        adde(x, y), adde(y, x);
    }
    int cntN = 1; fa[1] = Size[1] = 1;
    s.insert(1);
    rep(i, 2, n){
        fa[i] = i, Size[i] = 1;
        ee(j, i){
            int v = e[j].v;
            int f1 = find(v);
            if(vis[f1] != i) vis[f1] = i, Count[f1] = 0;
            if(++Count[f1] == Size[f1]){
                set<int>::iterator it = s.lower_bound(f1);
                s.erase(it);
                q.push(f1);
            }
        }
        ++cntN;
        if(s.size() > 0){
            //int f1 = *s.begin();
            //fa[i] = f1, ++Size[f1];
            for(set<int>::iterator it = s.begin(); it != s.end(); it++){
                int f1 = *it;
                fa[f1] = i, Size[i] += Size[f1];
                --cntN;
            }
            s.clear();
        }
        s.insert(i);
        while(!q.empty()){
            int f1 = q.front(); q.pop();
            s.insert(f1);
        }
        /*int ok = 0;
        ee(j, i){
            int v = e[j].v;
            int f1 = find(v);
            if(Count[f1] < Size[f1]){
                fa[i] = f1;
                ++Size[f1];
                ok = 1;
                break;
            }
        }
        if(!ok) ++cntN;*/
    }
    printf("%d\n", cntN - 1);
	return 0;
}
