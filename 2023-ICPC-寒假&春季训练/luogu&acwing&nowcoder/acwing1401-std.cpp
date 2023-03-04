#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

#define x first
#define y second

using namespace std;

typedef pair<double, double> PDD;
const int N = 10010;

int n;
PDD q[N];
int stk[N];
bool used[N];

double get_dist(PDD a, PDD b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

PDD operator-(PDD a, PDD b)
{
    return {a.x - b.x, a.y - b.y};
}

double cross(PDD a, PDD b)
{
    return a.x * b.y - a.y * b.x;
}

double area(PDD a, PDD b, PDD c)
{
    return cross(b - a, c - a);
}

double andrew()
{
    sort(q, q + n);
    int top = 0;
    for (int i = 0; i < n; i ++ )
    {
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
        {
            // 凸包边界上的点即使被从栈中删掉，也不能删掉used上的标记
            if (area(q[stk[top - 1]], q[stk[top]], q[i]) < 0)
                used[stk[top -- ]] = false;
            else top -- ;
        }
        stk[ ++ top] = i;
        used[i] = true;
    }
    used[0] = false;
    for (int i = n - 1; i >= 0; i -- )
    {
        if (used[i]) continue;
        while (top >= 2 && area(q[stk[top - 1]], q[stk[top]], q[i]) <= 0)
            top -- ;
        stk[ ++ top] = i;
    }

    double res = 0;
    for (int i = 2; i <= top; i ++ )
        res += get_dist(q[stk[i - 1]], q[stk[i]]);
    return res;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i ++ ) scanf("%lf%lf", &q[i].x, &q[i].y);
    double res = andrew();
    printf("%.2lf\n", res);

    return 0;
}