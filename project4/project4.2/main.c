// code here
#include<stdio.h>
#include<stdlib.h>
//函数功能:计算pell函数中的某一项
long long Pell(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	else
		return 2 * Pell(n - 1) + Pell(n - 2);
}
//函数功能:计算一个数模上32767后的值
int ModeofBigNum(long long num)
{
	return num % 32767;
}
int main()
{
	int i,mode,ret;
	unsigned int num_of_group;
	int *arr=(int *)malloc(num_of_group*sizeof(int));//定义一个数组,其内存由组数cas确定
	while(ret=scanf("%u", &num_of_group)<1)
    {
        printf("输入错误,请重新输入:\n");//判断输入是否规范,否则重新输入
        fflush(stdin);//清除缓冲区
    }
	for (i = 0; i < num_of_group; i++)//for循环来输入各组数据
	{
		while(ret=scanf("%d", &arr[i])<1)
        {
            printf("输入错误,请重新输入:\n");//同上:判断输入是否规范
            fflush(stdin);//清除缓冲区
        }
	}
	for (i = 0; i < num_of_group; i++)
	{
		mode= ModeofBigNum(Pell(arr[i]));
		printf("%d\n", mode);
	}
	return 0;
}
