#include <bits/stdc++.h>

int a[100005], n;

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    std::sort(a, a + n);
    std::reverse(a, a + n);
    int ans = 0;
    for(int i = 0; i < 2; i++)
        if(a[i] > 0)
            ans += a[i];
    printf("%d\n", ans);
    return 0;
}
