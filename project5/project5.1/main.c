// code here
#include<stdio.h>
//函数功能:(冒泡排序)把数组中的数从小到大排好
void Bubble_sort(int randarr[], int n)
{

	int i = 0;
	int tmp = 0;
	for (i = 0; i < n-1; i++)//外层循环,循环n-1次,把每次循环的最大数放到每次循环的末尾
	{
		int j = 0;
		for (j = 0; j < n - i-1; j++)
		{
			if (randarr[j] > randarr[j + 1])//如果前面的数比后面的数大,则交换两数
			{
				tmp = randarr[j];
				randarr[j] = randarr[j + 1];
				randarr[j + 1] = tmp;
			}
		}
	}
}
int main()
{
    unsigned int n;
	int randarr[1000],flag[1000]={0}, temp,i,sum_of_num=0,ret;
	while((ret=scanf("%d", &n)<1))//判断输入是否符合格式,如果不符合就重新输入
    {
        printf("输入错误,请重新输入:\n");//提醒用户重新输入
        fflush(stdin);//清除缓冲区
    }
	for (i = 0; i < n; i++)
	{
		while((ret=scanf("%d ", &temp))<1)
        {
            printf("输入错误,请重新输入:\n");
            fflush(stdin);//清除缓冲区
        }
		if (flag[temp] == 0)//如果这个位置上还没有数,即说明前面未出现重复的数字,则将该数存入数组
		{
			randarr[sum_of_num] = temp;
			sum_of_num++;
			flag[temp] = 1;//把flag数组中该位置的数字由0置为1,表明已经出现过该数字
		}

	}
	Bubble_sort(randarr, sum_of_num);//把randarr的数组进行排序
	printf("%d\n", sum_of_num);
	for (i = 0; i <sum_of_num; i++)
	{
		printf("%d ", randarr[i]);
	}
	return 0;
}
