#include<stdio.h>
#define M 10
#define N 10
int main()
{
	int i,j,ret,m=0, n=0,matrix1[N][M],matrix2[M][N];
	while (ret=scanf("%d %d", &n, &m) < 2||n<1||m<1)//����������,����֤����ȷ��ʽ����,������������
	{
	    printf("�������,����������:\n");
		fflush(stdin);//���������
	}
	while (getchar() != '\n');//ȫ���������ڻ�������'\n'
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			while (ret=scanf("%d", &matrix1[i][j]) < 1)//�������Ԫ�ص�ֵ,����֤�����Ϊ����
			{
			    printf("������������,����������:\n");
			    fflush(stdin);//���������
			}

		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			matrix2[i][j] = matrix1[j][i];//���о���ת��,��matrix1�е����жԵ�����matrix2��
		}
	}
	for (i = 0; i < m; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", matrix2[i][j]);//ѭ����ӡ����matrix2
		}
		printf("\n");
	}
}

