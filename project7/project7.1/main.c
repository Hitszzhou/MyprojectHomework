#include<stdio.h>
#define M 10
#define N 10
int main()
{
	int i,j,ret,m=0, n=0,matrix1[N][M],matrix2[M][N];
	while (ret=scanf("%d %d", &n, &m) < 2||n<1||m<1)//输入行列数,并保证按正确格式输入,否则重新输入
	{
	    printf("输入错误,请重新输入:\n");
		fflush(stdin);//清除缓冲区
	}
	while (getchar() != '\n');//全部读走留在缓冲区的'\n'
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			while (ret=scanf("%d", &matrix1[i][j]) < 1)//输入矩阵元素的值,并保证输入的为数字
			{
			    printf("该行输入有误,请重新输入:\n");
			    fflush(stdin);//清除缓冲区
			}

		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix2[i][j] = matrix1[j][i];//进行矩阵转置,把matrix1中的行列对调放在matrix2中
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix2[i][j]);//循环打印矩阵matrix2
		}
		printf("\n");
	}
}

