#include<stdio.h>
#include<math.h>
int main()
{
	printf("Please input time\n");
	int hour,minute,ret;
	double delta = 0;//初始化角度为0
	while (ret = scanf("%dh%dm", &hour, &minute)<2|| hour > 12 || hour <= 0 || minute < 0 || minute >= 60)//判断输入是否正确,否则重新输入
	{
		printf("Please input time\n");
		fflush(stdin);//清除缓冲区
	}
	double angle_of_hour,angle_of_minute;//时针和分针的角度
	angle_of_hour = (hour + (double)minute / 60) * 30;//计算时针的角度
	if (minute == 0)
	{
		angle_of_minute = 360;//分钟为0时,使其角度为360(其实本不用这步,但是oj的判别好像有点奇怪)
	}
	else {
		angle_of_minute = (double)minute / 60 * 360;
	}
	if (fabs(angle_of_hour - angle_of_minute >= 180)) {
		delta = 360 - fabs(angle_of_hour - angle_of_minute >= 180);
	}//取两个夹角中小于180度的
	else {
		delta = fabs(angle_of_hour - angle_of_minute);
	}
		printf("At %d:%02d the angle is %.1f degrees.\n", hour, minute, delta);//打印最后结果,其中分位按两位输出,左边不够两位就补0
	return 0;
}
