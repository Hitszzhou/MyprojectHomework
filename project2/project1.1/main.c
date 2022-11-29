#include <stdio.h>
#include<math.h>
//函数功能:计算函数的面积并返回,函数参数入口:三角形的三边
float Square(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    float s = sqrt(p*(p - a)*(p - b)*(p - c));
    return s;
}
int ret;
int main()
{
    float a, b, c;//a,b,c指三角形的三边
    while(ret=scanf("%f %f %f", &a, &b, &c)<3)//判断输入是否符合格式,不符合就重新输入
    {
        printf("输入格式错误,请重新输入:\n");
        fflush(stdin);

    }
    if ((a + b > c) && (a + c > b) && (c + b > a))//判断是否为三角形
    {
    if (a == b && a == c)//三边相等
    {
        printf("等边三角形\n");//等边三角形
        printf("S=%.2f\n", Square(a, b, c));
    }
    else if (fabs(a* a + b * b- c * c )<=1e-2|| fabs(a * a + c * c- b * b)<=1e-2||fabs( c * c + b * b -a * a)<=1e-2)//直角三角形
    {
        if (a != b && a != c && b != c)
        {
            printf("直角三角形\n");
            printf("S=%.2f\n", Square(a, b, c));
        }
        else if (a == b || a == c || b == c)
        {
            printf("等腰直角三角形\n");
            printf("S=%.2f\n", Square(a, b, c));
        }
    }
    else if ((a==b && a != c) || (a == c && a != b) || (b == c && b != a)) //等腰三角形
    {
        printf("等腰三角形\n");
        printf("S=%.2f\n", Square(a, b, c));
    }
    else//一般三角形
    {
        printf("一般三角形\n");
        printf("S=%.2f\n", Square(a, b, c));
    }
    }
    else
    {
        printf("不是三角形\n");
    }
    return 0;
}
