//实验8改错题,结构体动态申请内存
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct axy
    {
        float x, y;
    };//全局声明
int main()
{
    int i, n;

    struct axy* a;
    scanf("%d", &n);
    a = (struct axy*)malloc(n * sizeof(struct axy));
    for (i = 0; i < n; i++)
        scanf("%f%f", &a[i].x, &a[i].y);
    for (i = 0; i < n; i++)
        if (sqrt(pow(a[i].x, 2) + pow(a[i].y, 2)) <= 5)
        {
            printf("%f", a[i].x);
            printf("%f\n", a[i].y);
        }
        free(a);
    return 0;
}
