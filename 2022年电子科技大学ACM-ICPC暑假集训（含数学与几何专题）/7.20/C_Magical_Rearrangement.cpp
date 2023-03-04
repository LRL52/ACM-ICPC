//ID: LRL52  Date: 2022.7.20
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
const int N = 2e5 + 55, M = 2055, inf = 0x3f3f3f3f; char Buf[1 << 21], *_A = Buf, *_B = Buf, cc;
inline char gc() { return _A == _B && (_B = (_A = Buf) + fread(Buf, 1, 1 << 21, stdin), _A == _B) ? EOF : *_A++; }
template<class T>inline void rd(T& x) {
	int f = 1; x = 0, cc = gc(); while (cc < '0' || cc > '9') { if (cc == '-') f = -1; cc = gc(); }
	while (cc >= '0' && cc <= '9') { x = x * 10 + (cc ^ 48); cc = gc(); } x *= f;
}
int Ans[N], ins[N], a[N];
vector<int> f;

signed main() {
#ifdef LRL52
	freopen("C.in", "r", stdin);
#endif
	int Task; rd(Task);
	while(Task--){
        int sum = 0;
		rep(i, 0, 9) rd(a[i]), sum += a[i];
        //rep(i, 0, sum + 5) ins[i] = -1;
        int p = 0, lst = -1;
        rep(i, 1, 9){
            if(a[i] != 0){
                lst = i; a[i]--;
                Ans[++p] = i;
                break;
            }
        }
        if(lst == -1){
            if(a[0] == 1) puts("0");
            else puts("-1");
            continue;
        }
        while(1){
            int flag = 0, x = 0;
            rep(i, 0, 9){
                if(a[i] > 0 && i != lst){
                    flag = 1, a[i]--, x = i;
                    break;
                }
            }
            if(!flag) break;
            Ans[++p] = x;
            lst = x;
        }
        int num = -1;
        rep(i, 0, 9){
            if(a[i] > 0){
                num = i;
                break;
            }
        }
        rep(i, 1, p) ins[i] = -1;
        int ok = 1; f.clear();
        if(num != -1){
            int pos = -1;
            for(int i = p; i >= 1; --i){
                if(Ans[i] != num) f.push_back(Ans[i]);
                if(Ans[i] != num && Ans[i - 1] != num){
                    ins[i] = num;
                    a[num]--;
                    if(a[num] == 0){
                        pos = i, p = i - 1;
                        break;
                    }
                }
            }
            if(pos == -1) ok = 0;
            else sort(f.begin(), f.end());
        }
        if(ok == 0) puts("-1");
        else{
            rep(i, 1, p){
                printf("%d", Ans[i]);
            }
            int first = 1;
            for(int i = 0; i < f.size(); ++i){
                if(first) printf("%d", num), first = 0;
                printf("%d%d", f[i], num);
            }
            puts("");
        }
	}
	return 0;
}