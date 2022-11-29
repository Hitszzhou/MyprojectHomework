#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    int i=0;
    char arr[10];//定义一个数组,其最大长度为10
    int num[10];
    scanf("%s",arr);
    while(arr[i]!='\0')//当数组内容不为'\0'时,说明该字符串还未结束,循环继续
    {
        while(!isdigit(arr[i]))//判断是否为数字,不是则使下标++,到下一位
        {
            i++;
        }
        while(isdigit(arr[i]))//如果是数字,则打印,并指向下一位
        {
            printf("%c",arr[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
