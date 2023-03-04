//ID: LRL52  Date: 2023.2.5
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
using namespace std;
using LL = long long;
using pii = pair<int, int>;
const int N = 1e5 + 55, M = 2e5 + 55, inf = 0x3f3f3f3f;
int n, ans;
struct Node {
    int w, i, n, type, id;
}a[N];
char Ans[M][20];
vector<int> b[10];

int Type(int w, int i, int n) {
    if(w == 1 && i == 1 && n == 1) return 0;
    if(w == 2 && i == 1 && n == 0) return 1;
    if(w == 2 && i == 0 && n == 1) return 2;
    if(w == 1 && i == 2 && n == 0) return 3;
    if(w == 0 && i == 2 && n == 1) return 4;
    if(w == 1 && i == 0 && n == 2) return 5;
    if(w == 0 && i == 1 && n == 2) return 6;
    if(w == 3 && i == 0 && n == 0) return 7;
    if(w == 0 && i == 3 && n == 0) return 8;
    if(w == 0 && i == 0 && n == 3) return 9;
    // printf("Type: %d %d %d\n", w, i, n);
    assert(0);
    return 0;
}

char select(Node &t) {
    if(t.w >= 2) return 'w';
    if(t.i >= 2) return 'i';
    if(t.n >= 2) return 'n';
    assert(0);
}

void change(vector<int> &b1, vector<int> &b2) {
    auto u = b1.back(); b1.pop_back();
    auto v = b2.back(); b2.pop_back();
    // assert(a[u].id == u && a[v].id == v);
    auto c1 = select(a[u]), c2 = select(a[v]);
    sprintf(Ans[++ans], "%d %c %d %c\n", a[u].id, c1, a[v].id, c2);
    if(c1 == 'w') --a[u].w, ++a[v].w;
    if(c1 == 'i') --a[u].i, ++a[v].i;
    if(c1 == 'n') --a[u].n, ++a[v].n;
    if(c2 == 'w') --a[v].w, ++a[u].w;
    if(c2 == 'i') --a[v].i, ++a[u].i;
    if(c2 == 'n') --a[v].n, ++a[u].n;
    // printf("%d %d %d\n", a[u].w, a[u].i, a[u].n);
    // printf("%d %d %d\n", a[v].w, a[v].i, a[v].n);
    a[u].type = Type(a[u].w, a[u].i, a[u].n);
    b[a[u].type].push_back(a[u].id);
    a[v].type = Type(a[v].w, a[v].i, a[v].n);
    b[a[v].type].push_back(a[v].id);
}   

signed main() {
#ifdef LRL52
	freopen("D.in", "r", stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int Task; cin >> Task;
	while(Task--) {
		cin >> n;
        char card[5];
        for(int i = 0; i < 10; ++i) vector<int>().swap(b[i]);
        rep(j, 1, n) {
            cin >> card;
            int w = 0, i = 0, n = 0;
            for(int k = 0; k < 3; ++k) {
                if(card[k] == 'w') ++w;
                if(card[k] == 'i') ++i;
                if(card[k] == 'n') ++n;
            }
            a[j] = { w, i, n, Type(w, i, n), j};
            b[a[j].type].push_back(j);
            
        }
        ans = 0;
        while(1) {
            int fg = 0;
            while(1) {
                int flag = 0;
                while(b[1].size() && b[6].size()) change(b[1], b[6]), flag = 1;
                while(b[2].size() && b[4].size()) change(b[2], b[4]), flag = 1;
                while(b[3].size() && b[5].size()) change(b[3], b[5]), flag = 1;
                while(b[7].size() && b[8].size()) change(b[7], b[8]), flag = 1;
                while(b[7].size() && b[9].size()) change(b[7], b[9]), flag = 1;
                while(b[8].size() && b[9].size()) change(b[8], b[9]), flag = 1;
                while(b[7].size() && b[4].size()) change(b[7], b[4]), flag = 1;
                while(b[7].size() && b[6].size()) change(b[7], b[6]), flag = 1;
                while(b[8].size() && b[2].size()) change(b[8], b[2]), flag = 1;
                while(b[8].size() && b[5].size()) change(b[8], b[5]), flag = 1;
                while(b[9].size() && b[1].size()) change(b[9], b[1]), flag = 1;
                while(b[9].size() && b[3].size()) change(b[9], b[3]), flag = 1;
                if(flag) fg = 1;
                if(!flag) break;
            }
            while(1) {
                int flag = 0;
                while(b[1].size() && b[4].size()) change(b[1], b[4]), flag = 1;
                while(b[2].size() && b[3].size()) change(b[2], b[3]), flag = 1;
                while(b[3].size() && b[6].size()) change(b[3], b[6]), flag = 1;
                while(b[4].size() && b[5].size()) change(b[4], b[5]), flag = 1;
                while(b[5].size() && b[1].size()) change(b[5], b[1]), flag = 1;
                while(b[6].size() && b[2].size()) change(b[6], b[2]), flag = 1;
                if(flag) fg = 1;
                if(!flag) break;
            }
            if(!fg) break;
        }
        printf("%d\n", ans);
        rep(j, 1, ans) printf("%s", Ans[j]);
	}
	return 0;
}