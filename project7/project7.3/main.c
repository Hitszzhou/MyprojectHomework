#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
int main()
{
    int i=0;
    char arr[10];//����һ������,����󳤶�Ϊ10
    int num[10];
    scanf("%s",arr);
    while(arr[i]!='\0')//���������ݲ�Ϊ'\0'ʱ,˵�����ַ�����δ����,ѭ������
    {
        while(!isdigit(arr[i]))//�ж��Ƿ�Ϊ����,������ʹ�±�++,����һλ
        {
            i++;
        }
        while(isdigit(arr[i]))//���������,���ӡ,��ָ����һλ
        {
            printf("%c",arr[i]);
            i++;
        }
        printf("\n");
    }
    return 0;
}
