#include<stdio.h>
int main()
{
    int year,mon,day,ret;
    int Mon[12];
      Mon[0]=31;
      Mon[1]=28;
      Mon[2]=31;
      Mon[3]=30;
      Mon[4]=31;
      Mon[5]=30;
      Mon[6]=31;
      Mon[7]=31;
      Mon[8]=30;
      Mon[9]=31;
      Mon[10]=30;
      Mon[11]=31;
      printf("请输入日期（年，月，日）\n");
    do{

            while(ret=scanf("%d,%d,%d",&year,&mon,&day)<3)//判断输入格式是否正确,不正确则提醒并重新输入
            {
                printf("输入格式错误,请重新输入:\n");
                fflush(stdin);
            }
      }while(year<0||mon>12||mon<1||day<1||day>31);//如果输入年月日不符合常规则重新输入

    if((year%4==0&&year%100!=0)||year%400==0)//判断该年是否为润年,闰年二月为29天
    {
        Mon[1]=29;
    }
    int num=0,i;
    for(i=0;i<mon-1;i++)//循环加前mon-1个月的天数
    {
        num+=Mon[i];
    }
    printf("\n%d月%d日是%d年的第%d天。",mon,day,year,num+day);
    return 0;
}
