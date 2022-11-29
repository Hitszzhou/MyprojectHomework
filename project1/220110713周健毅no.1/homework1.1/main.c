#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Number:220110713\n\\subject No.1- program No.1\n");
    char a;
    int b;
    short c;
    float d;
    double e;
    printf("Please input char a:");
    scanf("%c",&a);
    printf("char a=%c,size of char is %d\n",a,sizeof(char));
    printf("Please input int b:");
    scanf("%d",&b);
    printf("int b=%d,size of int is%d\n",b,sizeof(int));
    printf("Please input short c:");
    scanf("%d",&c);
    printf("short c=%d,size of short is%d\n",c,sizeof(c));
    printf("Please input float d:");
    scanf("%f",&d);
    printf("float d is %f,size of float is %d\n",d,sizeof(float));
    printf("Please input double e:");
    scanf("%lf",&e);
    printf("double e is %lf,size of double is %d\n",e,sizeof(double));


    return 0;
}
