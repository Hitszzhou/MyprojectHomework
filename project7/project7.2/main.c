#include<stdio.h>
#include<string.h>
int main()
{
	char StringBigNum1[50], StringBigNum2[50];
	int ret,x[50]={0}, y[50]={0}, sum[50]={0};//定义三个数组,分别存储加数与和
	while(ret=scanf("%s%s", StringBigNum1, StringBigNum2)<2)
    {
        printf("输入错误,请重新输入:\n");
        fflush(stdin);
    }
	int len1 = strlen(StringBigNum1), len2 = strlen(StringBigNum2);
	int len = len1 > len2 ? len1 : len2;//取最长的len为和的长度
	int i, j = 0, k = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		x[j] = StringBigNum1[i]-'0';//把a数组逆序存放到x中
		j++;
	}
	for (i = len2 - 1; i >= 0; i--)
	{
		y[k] = StringBigNum2[i]-'0';//把b数组逆序存放到y中
		k++;
	}
	int m = 0;
	for (i = 0; i < len; i++)
	{
		sum[i] = (x[i] + y[i] + m) % 10;
		m = x[i] + y[i] + m >= 10 ? 1 : 0;//两数组相加,其中m为向前进的数,满10进1

	}
	if (x[i-1]+y[i-1]+m>10)
	{
		sum[i] = 1;//单独对最高位进行判读,满10进1
	}
	else
		i = i - 1;
	for (; i >= 0; i--)
	{
		printf("%d", sum[i]);//打印大数
	}
	return 0;
}
