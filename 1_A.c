#include <stdio.h>

int main(void)
{
    int n, m, a;
    int x, y;
    long long ans;
    scanf("%d %d %d", &n, &m, &a);
    x = n%a == 0 ? n/a : n/a+1;
    y = m%a == 0 ? m/a : m/a+1;
    ans = (long long)x*y;
    printf("%lld\n", ans);

    return 0;
}
