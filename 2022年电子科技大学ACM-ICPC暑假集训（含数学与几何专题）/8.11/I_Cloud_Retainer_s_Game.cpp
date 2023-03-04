//ID: LRL52  Date: 2022.8.10
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = (1e5 + 25) * 4, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *__B = Buf, cc;
inline char gc() { return _A == __B && (__B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == __B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
//#define int long long
typedef long long LL;
LL n, m, H, bmin, bmax;
int f[N][2], vis[N][2], Nxt[N][2], Sta[N][2], B[N];
struct Node{
    int x, y, type, id;
    inline bool operator<(const Node&t)const{
        return x < t.x;
    }
}a[N];
vector<Node> line[N][2];
map<int, int> _B;

int dfs(int x, int st){
    if(vis[x][st]) return f[x][st];
    vis[x][st] = 1, f[x][st] = 0;
    int v = Nxt[x][st], nst = Sta[x][st];
    if(v) f[x][st] = max(dfs(v, nst), f[x][st]);
    if(a[x].type == 0){
        v = Nxt[x][st ^ 1], nst = Sta[x][st ^ 1];
        if(v) f[x][st] = max(dfs(v, nst), f[x][st]);
    }
    f[x][st] += (a[x].type == 1);
    //printf("f[%d][%d] = %d\n", x, st, f[x][st]);
    return f[x][st];
}

signed main() {
#ifdef LRL52
	freopen("I.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
        rd(H);
        rd(n);
        rep(i, 1, n){
            rd(a[i].x), rd(a[i].y);
            a[i].type = 0, a[i].id = i;
        }
        rd(m);
        rep(i, n + 1, n + m){
            rd(a[i].x), rd(a[i].y);
            a[i].type = 1, a[i].id = i;
        }
        a[0] = {0, 0, 1, 0};
        int un = 0;
        rep(i, 0, n + m){
            B[++un] = a[i].y - a[i].x;
            B[++un] = a[i].x + a[i].y;
        }
        sort(B + 1, B + un + 1);
        un = unique(B + 1, B + un + 1) - B - 1;
        // rep(i, 1, un){
        //     _B[i] = lower_bound(B + 1, B + un + 1, B[i]) - B;
        // }
        rep(i, 1, un){
            _B[B[i]] = i;
            //vector<Node>().swap(line[i][0]);
            //vector<Node>().swap(line[i][1]);
        }
        bmin = B[1], bmax = B[un];
        rep(i, 0, n + m){
            int id = _B[a[i].y - a[i].x];
            line[id][0].push_back(a[i]);
            id = _B[a[i].x + a[i].y];
            line[id][1].push_back(a[i]);
        }
        rep(i, 1, un){
            sort(line[i][0].begin(), line[i][0].end());
            sort(line[i][1].begin(), line[i][1].end());
        }
        rep(i, 0, n + m){
            LL b = a[i].y - a[i].x; int cnt = 1;
            Nxt[i][0] = 0;
            while(1){
                if(b < bmin || b > bmax) break;
                if(_B.find(b) != _B.end()){
                    int id = _B[b], sta = (cnt & 1) ? 0 : 1;
                    unsigned int p = upper_bound(line[id][sta].begin(), line[id][sta].end(), a[i]) - line[id][sta].begin();
                    if(p < line[id][sta].size()){
                        Nxt[i][0] = line[id][sta][p].id;
                        Sta[i][0] = sta;
                        break;
                    }
                }
                if(cnt & 1) b = 2 * H - b;
                else b = -b;
                cnt++;
            }
            Nxt[i][1] = 0, cnt = 1, b = a[i].x + a[i].y;
            if(i == 0) continue;
            while(1){
                if(b < bmin || b > bmax) break;
                if(_B.find(b) != _B.end()){
                    int id = _B[b], sta = (cnt & 1) ? 1 : 0;
                    unsigned int p = upper_bound(line[id][sta].begin(), line[id][sta].end(), a[i]) - line[id][sta].begin();
                    if(p < line[id][sta].size()){
                        Nxt[i][1] = line[id][sta][p].id;
                        Sta[i][1] = sta;
                        break;
                    }
                }
                if(cnt & 1) b = -b;
                else b = 2 * H - b;
                cnt++;
            }
        }
        // rep(i, 0, n + m){
        //     printf("Nxt[%d][0] = %d Nxt[%d][1] = %d\n", i, Nxt[i][0], i, Nxt[i][1]);
        // } 
        rep(i, 0, n + m) vis[i][0] = vis[i][1] = 0;
        dfs(0, 0);
        printf("%d\n", f[0][0] - 1);
        map<int, int>().swap(_B);
        rep(i, 1, un){
            vector<Node>().swap(line[i][0]);
            vector<Node>().swap(line[i][1]);
        }
	}
	return 0;
}