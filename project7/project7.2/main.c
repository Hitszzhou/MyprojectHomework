#include<stdio.h>
#include<string.h>
int main()
{
	char StringBigNum1[50], StringBigNum2[50];
	int ret,x[50]={0}, y[50]={0}, sum[50]={0};//������������,�ֱ�洢�������
	while(ret=scanf("%s%s", StringBigNum1, StringBigNum2)<2)
    {
        printf("�������,����������:\n");
        fflush(stdin);
    }
	int len1 = strlen(StringBigNum1), len2 = strlen(StringBigNum2);
	int len = len1 > len2 ? len1 : len2;//ȡ���lenΪ�͵ĳ���
	int i, j = 0, k = 0;
	for (i = len1 - 1; i >= 0; i--)
	{
		x[j] = StringBigNum1[i]-'0';//��a���������ŵ�x��
		j++;
	}
	for (i = len2 - 1; i >= 0; i--)
	{
		y[k] = StringBigNum2[i]-'0';//��b���������ŵ�y��
		k++;
	}
	int m = 0;
	for (i = 0; i < len; i++)
	{
		sum[i] = (x[i] + y[i] + m) % 10;
		m = x[i] + y[i] + m >= 10 ? 1 : 0;//���������,����mΪ��ǰ������,��10��1

	}
	if (x[i-1]+y[i-1]+m>10)
	{
		sum[i] = 1;//���������λ�����ж�,��10��1
	}
	else
		i = i - 1;
	for (; i >= 0; i--)
	{
		printf("%d", sum[i]);//��ӡ����
	}
	return 0;
}
