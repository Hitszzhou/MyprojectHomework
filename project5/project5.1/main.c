// code here
#include<stdio.h>
//��������:(ð������)�������е�����С�����ź�
void Bubble_sort(int randarr[], int n)
{

	int i = 0;
	int tmp = 0;
	for (i = 0; i < n-1; i++)//���ѭ��,ѭ��n-1��,��ÿ��ѭ����������ŵ�ÿ��ѭ����ĩβ
	{
		int j = 0;
		for (j = 0; j < n - i-1; j++)
		{
			if (randarr[j] > randarr[j + 1])//���ǰ������Ⱥ��������,�򽻻�����
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
	while((ret=scanf("%d", &n)<1))//�ж������Ƿ���ϸ�ʽ,��������Ͼ���������
    {
        printf("�������,����������:\n");//�����û���������
        fflush(stdin);//���������
    }
	for (i = 0; i < n; i++)
	{
		while((ret=scanf("%d ", &temp))<1)
        {
            printf("�������,����������:\n");
            fflush(stdin);//���������
        }
		if (flag[temp] == 0)//������λ���ϻ�û����,��˵��ǰ��δ�����ظ�������,�򽫸�����������
		{
			randarr[sum_of_num] = temp;
			sum_of_num++;
			flag[temp] = 1;//��flag�����и�λ�õ�������0��Ϊ1,�����Ѿ����ֹ�������
		}

	}
	Bubble_sort(randarr, sum_of_num);//��randarr�������������
	printf("%d\n", sum_of_num);
	for (i = 0; i <sum_of_num; i++)
	{
		printf("%d ", randarr[i]);
	}
	return 0;
}
