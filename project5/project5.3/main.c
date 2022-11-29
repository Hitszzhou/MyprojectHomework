// code here
#include<stdio.h>
void Bubble_sort(int randarr[], int n);//ð������
double Mean(int arr[], int n);//��ƽ����
double Median(int arr[], int n);//����λ��
int Mode(int arr[], int n);//������
int main()
{
	int n,ret,feedback[40];//��feedback���������淴�����

	while(ret=scanf("%d", &n)<1||n<1)
    {
        printf("�������,����������:\n");
        fflush(stdin);
    }
	int i = 0;
	for (i = 0; i < n; i++)
	{
		while(ret=scanf("%d", &feedback[i])<1||feedback[i]<1||feedback[i]>10)
        {
            printf("�������,����������:\n");
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
//��������:�����鰴��С�����˳����������
void Bubble_sort(int feedback[], int n)//ð������
{

	int i ,j;
	int tmp = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (feedback[j] > feedback[j + 1])//���ǰ��������ں����������������
			{
				tmp = feedback[j];
				feedback[j] = feedback[j + 1];
				feedback[j + 1] = tmp;
			}
		}
	}
}
//��������:����һ����������������ƽ����
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
//����λ��
double Median(int arr[], int n)
{
	Bubble_sort(arr, n);
	if (n % 2 == 1)//����ܵĸ���Ϊ����,�����м����Ϊ��λ��
	{
		return arr[(n + 1) / 2-1]*1.0;
	}
	else
	{
		return (arr[n / 2-1] + arr[n / 2])*1.0 / 2;//����ܵĸ���Ϊż��,��ȡ�м�������ƽ������Ϊ��λ��
	}
}
int Mode(int arr[], int n)//������
{
	int i = 0;
	int count[11] = { 0 };
	for (i = 0; i < n; i++)
	{
		count[arr[i]]++;//�Ѹ�λ�õ�count���飫1,��ʾarr[i]������ĸ�����1
	}
	int max =0;//��count�е��������λ��,��ʶ���λ��Ϊ0,��0��Ϊ����
	for (i = 0; i <= 10; i++)
	{
		if (count[i] > count[max])//����и����ͬ��,��ı�max
			max = i;
	}
	return max;
}
