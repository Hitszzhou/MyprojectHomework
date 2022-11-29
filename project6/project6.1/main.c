#include<stdio.h>
struct Student
{
	char Id[10];
	int math;
	int english;
	int ph;
	int Sum;
	double aver;
};//定义一个学生结构体,里面包含学生的学号与成绩
#define M 40//最多人数
int main()
{
	int SumofMath = 0, SumofEn = 0, SumofPh = 0,num, i,ret;
	struct Student S[M];
	double AverMath, AverEn, AverPh;
	printf("Input the total number of the students(n<40):\n");
	while(ret=scanf("%d", &num)<1||num<0)//让用户输入学生人数,如果输入不规范则重新输入
    {
        printf("输入错误,请重新输入:\n");
        fflush(stdin);//清除缓冲区
    }
	printf("Input student’s ID and score as: MT  EN  PH:\n");
	for (i = 0; i < num; i++)//循环输入学生的学号与成绩
	{
		while(ret=scanf("%s%d%d%d", &S[i].Id,&S[i].math,&S[i].english,&S[i].ph)<4||S[i].math<0||
        S[i].english<0||S[i].ph<0)//用户输入学号与成绩,如果输入不规范则重新输入
        {
            printf("输入有误,请重新输入:\n");
            fflush(stdin);//清除缓冲区
        }

		S[i].Sum = S[i].math + S[i].english + S[i].ph;//计算该学生的总分
		S[i].aver = (double)S[i].Sum / 3.0;//计算该同学的平均分
		//算各科的总分
		SumofMath += S[i].math;
		SumofEn += S[i].english;
		SumofPh += S[i].ph;
	}
	//计算各科的平均分
	AverMath = (double)SumofMath / num;
	AverPh = (double)SumofPh / num;
	AverEn = (double)SumofEn / num;
	printf("Counting Result:\nStudent’s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
	for (i = 0; i < num; i++)//按顺序循环分别打出各个学生的成绩
	{
		printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n", S[i].Id, S[i].math, S[i].english, S[i].ph, S[i].Sum, S[i].aver);
	}
	//打印各科总分与平均分
	printf("SumofCourse \t");
	printf("% 4d\t% 4d\t% 4d\t", SumofMath,SumofEn,SumofPh);
	printf("\nAverofCourse\t");
	printf("%4.1f\t%4.1f\t%4.1f\t",AverMath,AverEn,AverPh );
	return 0;
}
