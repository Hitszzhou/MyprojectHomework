// code here
#include<stdio.h>
#include<stdlib.h>
//��������:����pell�����е�ĳһ��
long long Pell(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	else
		return 2 * Pell(n - 1) + Pell(n - 2);
}
//��������:����һ����ģ��32767���ֵ
int ModeofBigNum(long long num)
{
	return num % 32767;
}
int main()
{
	int i,mode,ret;
	unsigned int num_of_group;
	int *arr=(int *)malloc(num_of_group*sizeof(int));//����һ������,���ڴ�������casȷ��
	while(ret=scanf("%u", &num_of_group)<1)
    {
        printf("�������,����������:\n");//�ж������Ƿ�淶,������������
        fflush(stdin);//���������
    }
	for (i = 0; i < num_of_group; i++)//forѭ���������������
	{
		while(ret=scanf("%d", &arr[i])<1)
        {
            printf("�������,����������:\n");//ͬ��:�ж������Ƿ�淶
            fflush(stdin);//���������
        }
	}
	for (i = 0; i < num_of_group; i++)
	{
		mode= ModeofBigNum(Pell(arr[i]));
		printf("%d\n", mode);
	}
	return 0;
}
