// code here
#include<stdio.h>
void Bubble_sort(int randarr[], int n);//冒泡排序
double Mean(int arr[], int n);//求平均数
double Median(int arr[], int n);//求中位数
int Mode(int arr[], int n);//求众数
int main()
{
	int n,ret,feedback[40];//用feedback数组来储存反馈意见

	while(ret=scanf("%d", &n)<1||n<1)
    {
        printf("输入错误,请重新输入:\n");
        fflush(stdin);
    }
	int i = 0;
	for (i = 0; i < n; i++)
	{
		while(ret=scanf("%d", &feedback[i])<1||feedback[i]<1||feedback[i]>10)
        {
            printf("输入错误,请重新输入:\n");
            fflush(stdin);
        }
	}
	double mean=Mean(feedback,n);
	double median= Median(feedback,n);
	int mode = Mode(feedback,n);
	printf("Mean=%d\n", (int)mean);
	printf("Median=%d\n", (int)median);
	printf("Mode=%d\n", mode);
	return 0;
}
//函数功能:把数组按从小到大的顺序重新排序
void Bubble_sort(int feedback[], int n)//冒泡排序
{

	int i ,j;
	int tmp = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (feedback[j] > feedback[j + 1])//如果前面的数大于后面的数则两数交换
			{
				tmp = feedback[j];
				feedback[j] = feedback[j + 1];
				feedback[j + 1] = tmp;
			}
		}
	}
}
//函数功能:计算一个数组中所有数的平均数
double Mean(int arr[], int n)
{
	int i = 0;
	double sum = 0;
	for (i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum * 1.0 / n;
}
//求中位数
double Median(int arr[], int n)
{
	Bubble_sort(arr, n);
	if (n % 2 == 1)//如果总的个数为奇数,则正中间的数为中位数
	{
		return arr[(n + 1) / 2-1]*1.0;
	}
	else
	{
		return (arr[n / 2-1] + arr[n / 2])*1.0 / 2;//如果总的个数为偶数,则取中间两数的平均数作为中位数
	}
}
int Mode(int arr[], int n)//求众数
{
	int i = 0;
	int count[11] = { 0 };
	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;//把该位置的count数组＋1,表示arr[i]这个数的个数加1
	}
	int max =0;//找count中的最大数的位置,初识最大位置为0,即0分为众数
	for (i = 0; i <= 10; i++)
	{
		if (count[i] > count[max])//如果有更多的同数,则改变max
			max = i;
	}
	return max;
}
