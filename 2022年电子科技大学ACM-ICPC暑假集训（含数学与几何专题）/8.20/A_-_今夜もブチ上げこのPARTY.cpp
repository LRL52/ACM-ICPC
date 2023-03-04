//ID: LRL52  Date: 2022.8.20
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++i)
#define ee(i, a) for(int i = head[a]; i; i = e[i].nxt)
using namespace std;
#define double long double
const double eps = 1e-6;
double Ans, L1, L2;
struct Node{
    double x, y;
    Node operator-(const Node&t)const{
        return {x - t.x, y - t.y};
    }
    Node operator+(const Node&t)const{
        return {x + t.x, y + t.y};
    }
    Node operator*(const double&k)const{
        return {x * k, y * k};
    }
}a, b, c, d, e1, e2;
int flag;

double len2(const Node&t){
    return t.x * t.x + t.y * t.y;
}

double calc(double t){
    t = sqrt(t);
    Node f1 = a + e1 * t;
    Node f2 = c + e2 * t;
    if(t > L2) f2 = d;
    else if(flag) f2 = c;
    double ret = len2(f1 - f2);
    Ans = min(Ans, ret);
    return ret;
}

signed main() {
#ifdef LRL52
	freopen("A2.in", "r", stdin);
#endif
    clock_t start = clock();
	scanf("%Lf%Lf%Lf%Lf%Lf%Lf%Lf%Lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y, &d.x, &d.y);
    e1 = b - a, e2 = d - c;
    Ans = min(len2(a - c), len2(b - d));
    L1 = sqrt(len2(e1)), L2 = sqrt(len2(e2));
    if(L1 < L2){
        swap(L1, L2);
        swap(a, c); swap(b, d);
        swap(e1, e2);
    }
    //double L = max(L1, L2);
    if(L1 < eps){
        printf("%.12Lf\n", sqrt(Ans));
        return 0;
    }
    e1.x /= L1, e1.y /= L1;
    if(L2 >= eps) e2.x /= L2, e2.y /= L2;
    else flag = 1;
    double l = 0.0F, r = len2(b - a);
    while(r - l > eps){
        double lmid = l + (r - l) / 3.0F;
        double rmid = r - (r - l) / 3.0F;
        double res1 = calc(lmid), res2 = calc(rmid);
        //if(abs(res1 - res2) < eps) l = lmid;
        if(res1 < res2) r = rmid;
        else l = lmid;
        if((double)(clock() - start) / CLOCKS_PER_SEC > 0.96F) break;
    }
    /*l = 0.0F, r = len2(b - a);
    while(r - l > eps){
        double lmid = l + (r - l) / 3.0F;
        double rmid = r - (r - l) / 3.0F;
        double res1 = calc(lmid), res2 = calc(rmid);
        if(abs(res1 - res2) < eps) r = rmid;
        else if(res1 > res2) l = lmid;
        else r = rmid;
        if((double)(clock() - start) / CLOCKS_PER_SEC > 0.96F) break;
    }*/
    printf("%.12Lf\n", sqrt(Ans));
	return 0;
}