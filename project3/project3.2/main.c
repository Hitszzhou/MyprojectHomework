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
      printf("���������ڣ��꣬�£��գ�\n");
    do{

            while(ret=scanf("%d,%d,%d",&year,&mon,&day)<3)//�ж������ʽ�Ƿ���ȷ,����ȷ�����Ѳ���������
            {
                printf("�����ʽ����,����������:\n");
                fflush(stdin);
            }
      }while(year<0||mon>12||mon<1||day<1||day>31);//������������ղ����ϳ�������������

    if((year%4==0&&year%100!=0)||year%400==0)//�жϸ����Ƿ�Ϊ����,�������Ϊ29��
    {
        Mon[1]=29;
    }
    int num=0,i;
    for(i=0;i<mon-1;i++)//ѭ����ǰmon-1���µ�����
    {
        num+=Mon[i];
    }
    printf("\n%d��%d����%d��ĵ�%d�졣",mon,day,year,num+day);
    return 0;
}
