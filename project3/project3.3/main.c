#include<stdio.h>
#include<math.h>
int main()
{
	printf("Please input time\n");
	int hour,minute,ret;
	double delta = 0;//��ʼ���Ƕ�Ϊ0
	while (ret = scanf("%dh%dm", &hour, &minute)<2|| hour > 12 || hour <= 0 || minute < 0 || minute >= 60)//�ж������Ƿ���ȷ,������������
	{
		printf("Please input time\n");
		fflush(stdin);//���������
	}
	double angle_of_hour,angle_of_minute;//ʱ��ͷ���ĽǶ�
	angle_of_hour = (hour + (double)minute / 60) * 30;//����ʱ��ĽǶ�
	if (minute == 0)
	{
		angle_of_minute = 360;//����Ϊ0ʱ,ʹ��Ƕ�Ϊ360(��ʵ�������ⲽ,����oj���б�����е����)
	}
	else {
		angle_of_minute = (double)minute / 60 * 360;
	}
	if (fabs(angle_of_hour - angle_of_minute >= 180)) {
		delta = 360 - fabs(angle_of_hour - angle_of_minute >= 180);
	}//ȡ�����н���С��180�ȵ�
	else {
		delta = fabs(angle_of_hour - angle_of_minute);
	}
		printf("At %d:%02d the angle is %.1f degrees.\n", hour, minute, delta);//��ӡ�����,���з�λ����λ���,��߲�����λ�Ͳ�0
	return 0;
}
