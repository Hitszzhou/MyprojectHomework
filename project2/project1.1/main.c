#include <stdio.h>
#include<math.h>
//��������:���㺯�������������,�����������:�����ε�����
float Square(float a, float b, float c)
{
    float p = (a + b + c) / 2;
    float s = sqrt(p*(p - a)*(p - b)*(p - c));
    return s;
}
int ret;
int main()
{
    float a, b, c;//a,b,cָ�����ε�����
    while(ret=scanf("%f %f %f", &a, &b, &c)<3)//�ж������Ƿ���ϸ�ʽ,�����Ͼ���������
    {
        printf("�����ʽ����,����������:\n");
        fflush(stdin);

    }
    if ((a + b > c) && (a + c > b) && (c + b > a))//�ж��Ƿ�Ϊ������
    {
    if (a == b && a == c)//�������
    {
        printf("�ȱ�������\n");//�ȱ�������
        printf("S=%.2f\n", Square(a, b, c));
    }
    else if (fabs(a* a + b * b- c * c )<=1e-2|| fabs(a * a + c * c- b * b)<=1e-2||fabs( c * c + b * b -a * a)<=1e-2)//ֱ��������
    {
        if (a != b && a != c && b != c)
        {
            printf("ֱ��������\n");
            printf("S=%.2f\n", Square(a, b, c));
        }
        else if (a == b || a == c || b == c)
        {
            printf("����ֱ��������\n");
            printf("S=%.2f\n", Square(a, b, c));
        }
    }
    else if ((a==b && a != c) || (a == c && a != b) || (b == c && b != a)) //����������
    {
        printf("����������\n");
        printf("S=%.2f\n", Square(a, b, c));
    }
    else//һ��������
    {
        printf("һ��������\n");
        printf("S=%.2f\n", Square(a, b, c));
    }
    }
    else
    {
        printf("����������\n");
    }
    return 0;
}
