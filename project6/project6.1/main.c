#include<stdio.h>
struct Student
{
	char Id[10];
	int math;
	int english;
	int ph;
	int Sum;
	double aver;
};//����һ��ѧ���ṹ��,�������ѧ����ѧ����ɼ�
#define M 40//�������
int main()
{
	int SumofMath = 0, SumofEn = 0, SumofPh = 0,num, i,ret;
	struct Student S[M];
	double AverMath, AverEn, AverPh;
	printf("Input the total number of the students(n<40):\n");
	while(ret=scanf("%d", &num)<1||num<0)//���û�����ѧ������,������벻�淶����������
    {
        printf("�������,����������:\n");
        fflush(stdin);//���������
    }
	printf("Input student��s ID and score as: MT  EN  PH:\n");
	for (i = 0; i < num; i++)//ѭ������ѧ����ѧ����ɼ�
	{
		while(ret=scanf("%s%d%d%d", &S[i].Id,&S[i].math,&S[i].english,&S[i].ph)<4||S[i].math<0||
        S[i].english<0||S[i].ph<0)//�û�����ѧ����ɼ�,������벻�淶����������
        {
            printf("��������,����������:\n");
            fflush(stdin);//���������
        }

		S[i].Sum = S[i].math + S[i].english + S[i].ph;//�����ѧ�����ܷ�
		S[i].aver = (double)S[i].Sum / 3.0;//�����ͬѧ��ƽ����
		//����Ƶ��ܷ�
		SumofMath += S[i].math;
		SumofEn += S[i].english;
		SumofPh += S[i].ph;
	}
	//������Ƶ�ƽ����
	AverMath = (double)SumofMath / num;
	AverPh = (double)SumofPh / num;
	AverEn = (double)SumofEn / num;
	printf("Counting Result:\nStudent��s ID\t  MT \t  EN \t  PH \t SUM \t AVER\n");
	for (i = 0; i < num; i++)//��˳��ѭ���ֱ�������ѧ���ĳɼ�
	{
		printf("%12s\t%4d\t%4d\t%4d\t%4d\t%5.1f\n", S[i].Id, S[i].math, S[i].english, S[i].ph, S[i].Sum, S[i].aver);
	}
	//��ӡ�����ܷ���ƽ����
	printf("SumofCourse \t");
	printf("% 4d\t% 4d\t% 4d\t", SumofMath,SumofEn,SumofPh);
	printf("\nAverofCourse\t");
	printf("%4.1f\t%4.1f\t%4.1f\t",AverMath,AverEn,AverPh );
	return 0;
}
