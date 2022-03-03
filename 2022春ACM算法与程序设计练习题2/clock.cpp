#include<stdio.h>
//int main()
//{
//    int t, p, hh, mm, sh, sm, res;
//    scanf("%d", &t);
//    for (p = 1; p <= t; p++)
//    {
//        scanf("%d:%d", &hh, &mm);
//        if (hh >= 12)
//            hh = hh - 12;
//        sh = hh * 60 + mm;
//        sm = mm * 12;
//        if (sh > sm) res = sh - sm;
//        else res = sm - sh;
//        if (res >= 360) res = 720 - res;
//        if (res % 2 == 0) printf("%d\n", res / 2);
//        else printf("%d/2\n", res);
//    }
//    return 0;
//}