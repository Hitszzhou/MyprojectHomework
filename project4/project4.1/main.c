#include<stdio.h>
//打印月历表
int Isleap(int year);
int DayofMon(int Lp, int mon);
int WeekofFirst(int year, int mon,int Lp);
int main()
{
	int year, mon,ret;
	while(ret=scanf("%d %d", &year, &mon)<2||year<1900||mon>12||mon<1)//判断输入是否合法,不合法则重新输入
    {
        printf("输入错误,请重新输入:\n");
        fflush(stdin);//清除缓冲区
    }
	int Lp=Isleap(year);//判断某年是否为闰年,是返回1不是返回0
	int day=DayofMon(Lp, mon);
	int Wef=WeekofFirst(year, mon,Lp);//计算某年某月的第一天的星期
	int i;
	printf("Sun\tMon\tTue\tWed\tThu\tFri\tSat\n");
	if (Wef == 7)//如果天数星期为7则置为0
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
//函数功能:判断一年是否为闰年,是:返回1,否:返回0
int Isleap(int year)
{
	if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
		return 1;
	else
		return 0;
}
//函数功能:计算一个月的天数
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
//函数功能:计算某年某月的第一天为星期几
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
	}//计算和1900年1月1日的天数差
	return difday % 7+1;//返回值为星期几

}
