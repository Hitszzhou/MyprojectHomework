#include<stdio.h>
#include<math.h>
//��������:�ж�һ�������Ƿ�Ϊ����,��:����1,��:����0
//�����������:Ҫ�жϵ�����
int IsPrime(int x)
{
	int flag = 1,i;
	for (i = 2; i <= sqrt(x); i++)//�Դ�2������x������Ϊ����,�ж�x�Ƿ�Ϊ����
	{
		if (x % i == 0)//���������i,��������
		{
			flag = 0;
			break;
		}
	}
	if (x == 1)
		flag = 0;
	return flag;
}
int main()
{
	int N, M,i,ret, x = 0;//N����ÿ��������ĸ���,M��������
	int SumofPrime[9] = { 0 };
	while((ret=scanf("%d", &M))<1)//������Ե�����,�����ʽ����ʱ��������
    {
        printf("�������,����������:\n");
        fflush(stdin);
    }
	for (i = 0; i < M; i++)
	{
		while((ret=scanf("%d", &N))<1)//�������������ĸ���,�������ʱ��������
        {
            printf("�������,����������:\n");
            fflush(stdin);
        }
		for (int j = 0; j < N; j++)//��forѭ����ʵ��һ����������
		{
			while((ret=scanf("%d", &x))<1)//�ж������Ƿ���ȷ
            {
                printf("�������,����������:\n");
                fflush(stdin);
            }
			if (IsPrime(x))
			{
				SumofPrime[i] += x;
			}
		}

	}
	for (i = 0; i < M; i++)
	{
		printf("%d\n", SumofPrime[i]);
	}
	return 0;
}
