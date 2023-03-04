#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int N = 300000;
const double PI = acos(-1);

struct Complex
{
    double x, y;
    Complex operator+ (const Complex& t) const
    {
        return {x + t.x, y + t.y};
    }
    Complex operator- (const Complex& t) const
    {
        return {x - t.x, y - t.y};
    }
    Complex operator* (const Complex& t) const
    {
        return {x * t.x - y * t.y, x * t.y + y * t.x};
    }
}a[N], b[N];
char s1[N], s2[N];
int res[N];
int rev[N], bit, tot;

void fft(Complex a[], int inv)
{
    for (int i = 0; i < tot; i ++ )
        if (i < rev[i])
            swap(a[i], a[rev[i]]);
    for (int mid = 1; mid < tot; mid *= 2)
    {
        auto w1 = Complex({cos(PI / mid), inv * sin(PI / mid)});
        for (int i = 0; i < tot; i += mid * 2)
        {
            auto wk = Complex({1, 0});
            for (int j = 0; j < mid; j ++, wk = wk * w1)
            {
                auto x = a[i + j], y = wk * a[i + j + mid];
                a[i + j] = x + y, a[i + j + mid] = x - y;
            }
        }
    }
}

int main()
{
    scanf("%s%s", s1, s2);
    int n = strlen(s1) - 1, m = strlen(s2) - 1;
    for (int i = 0; i <= n; i ++ ) a[i].x = s1[n - i] - '0';
    for (int i = 0; i <= m; i ++ ) b[i].x = s2[m - i] - '0';
    while ((1 << bit) < n + m + 1) bit ++ ;
    tot = 1 << bit;
    for (int i = 0; i < tot; i ++ )
        rev[i] = ((rev[i >> 1] >> 1)) | ((i & 1) << (bit - 1));
    fft(a, 1), fft(b, 1);
    for (int i = 0; i < tot; i ++ ) a[i] = a[i] * b[i];
    fft(a, -1);

    int k = 0;
    for (int i = 0, t = 0; i < tot || t; i ++ )
    {
        t += a[i].x / tot + 0.5;
        res[k ++ ] = t % 10;
        t /= 10;
    }

    while (k > 1 && !res[k - 1]) k -- ;
    for (int i = k - 1; i >= 0; i -- ) printf("%d", res[i]);

    return 0;
}