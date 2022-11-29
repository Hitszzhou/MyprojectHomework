#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i=0;
    for(i=1;i<=4;i++)
    {
        int j=0;
        for(j=0;j<=3-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
     }
    for(i=0;i<4;i++)
    {
        int j=0;
        for(j=0;j<=i;j++)
        {
            printf(" ");
        }

        for(j=0;j<5-2*i;j++)
        {
            printf("*");

        }
        printf("\n");
    }
    return 0;
}
