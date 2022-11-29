#include<stdio.h>
//��ӡ������
int Isleap(int year);
int DayofMon(int Lp, int mon);
int WeekofFirst(int year, int mon,int Lp);
int main()
{
	int year, mon,ret;
	while(ret=scanf("%d %d", &year, &mon)<2||year<1900||mon>12||mon<1)//�ж������Ƿ�Ϸ�,���Ϸ�����������
    {
        printf("�������,����������:\n");
        fflush(stdin);//���������
    }
	int Lp=Isleap(year);//�ж�ĳ���Ƿ�Ϊ����,�Ƿ���1���Ƿ���0
	int day=DayofMon(Lp, mon);
	int Wef=WeekofFirst(year, mon,Lp);//����ĳ��ĳ�µĵ�һ�������
	int i;
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	if (Wef == 7)//�����������Ϊ7����Ϊ0
	{
		Wef = 0;
	}

		for (i=0; i <Wef; i++)
		{
			printf("\t");
		}
		int j = Wef;
	for (i = 1; i <=day; i++)
	{
		printf("%d\t", i);
		j++;
		if (j == 7)
		{
			printf("\n");
			j = 0;
		}

	}
	return 0;
}
//��������:�ж�һ���Ƿ�Ϊ����,��:����1,��:����0
int Isleap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	else
		return 0;
}
//��������:����һ���µ�����
int DayofMon(int Lp, int mon)
{
	if (mon == 1 || mon == 3 || mon == 5 || mon == 7 || mon == 8 || mon == 10 || mon == 12)
		return 31;
	if (Lp == 1 && mon == 2)
		return 29;
	if (Lp == 0 && mon == 2)
		return 28;
	if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
		return 30;
}
//��������:����ĳ��ĳ�µĵ�һ��Ϊ���ڼ�
int WeekofFirst(int year, int mon,int Lp)
{
	int difday = 0;
	int i = 1;
	for (i = 1900; i < year; i++)
	{
		if (Isleap(i) == 1)
		{
			difday += 366;
		}
		else
			difday += 365;
	}

	for (i = 1; i <mon; i++)
	{
		difday += DayofMon(Lp, i);
	}//�����1900��1��1�յ�������
	return difday % 7+1;//����ֵΪ���ڼ�

}
