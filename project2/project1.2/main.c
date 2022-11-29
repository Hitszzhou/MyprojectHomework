#include<stdio.h>
int main()
{
	int nur1, dnm1, nur2, dnm2,ret;
	while(ret=scanf("%d/%d,%d/%d", &nur1, &dnm1,&nur2,&dnm2)<4)
    {
        printf("输入错误,请重新输入:\n");
        fflush(stdin);
    }
	if ((float)nur1 / dnm1 > (float)nur2 / dnm2)
	{
		printf("%d/%d > %d/%d", nur1,  dnm1,nur2, dnm2);
	}
	if ((float)nur1 /  dnm1 == (float)nur2 / dnm2)
	{
		printf("%d/%d = %d/%d", nur1,  dnm1, nur2, dnm2);
	}
	if ((float)nur1 /  dnm1 < (float)nur2 / dnm2)
	{
		printf("%d/%d < %d/%d", nur1, dnm1, nur2, dnm2);
	}
	return 0;
}
