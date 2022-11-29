#include<stdio.h>
#include<math.h>
//函数功能:判断一个输入是否为素数,是:返回1,否:返回0
//函数参数入口:要判断的数字
int IsPrime(int x)
{
	int flag = 1,i;
	for (i = 2; i <= sqrt(x); i++)//以从2到根号x的数作为除数,判断x是否为素数
	{
		if (x % i == 0)//如果可整除i,则不是素数
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
	int N, M,i,ret, x = 0;//N代表每组测试数的个数,M代表组数
	int SumofPrime[9] = { 0 };
	while((ret=scanf("%d", &M))<1)//输入测试的组数,输入格式错误时重新输入
    {
        printf("输入错误,请重新输入:\n");
        fflush(stdin);
    }
	for (i = 0; i < M; i++)
	{
		while((ret=scanf("%d", &N))<1)//输入改组测试数的个数,输入错误时重新输入
        {
            printf("输入错误,请重新输入:\n");
            fflush(stdin);
        }
		for (int j = 0; j < N; j++)//用for循环来实现一组数的输入
		{
			while((ret=scanf("%d", &x))<1)//判断输入是否正确
            {
                printf("输入错误,请重新输入:\n");
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
