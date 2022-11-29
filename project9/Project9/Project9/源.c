#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct People//����һ���ṹ��,�����û���id,����,����,֧������Ϣ
{
	char Id[6];
	char name[11];
	int income;
	int expense;
}P;
void menu();//��ӡ�˵�,�����û�����ѡ��
int find_by_name(char* name, P peo[]);//�������ҵ��û�
double mean_of_income(P peo[]);//����ƽ������
double mean_of_expend(P peo[]);//����ƽ��֧��
void find_morethan_perexpense(P peo[]);//�ҳ�֧������ƽ������
void input_information(P peo[]);//�����û���Ϣ
void PrintAllInformation(P peo[]);//��ӡ������Ϣ
void PrintoneInformation(P peo[], int position);//��ӡĳһ���˵���Ϣ
void sort_by_id(P peo[]);//��id�������û�
int sum_of_peo;//����һ��ȫ�ֱ���,���������û�����
void quick_sort_by_name(P peo[], int L, int R);//�ÿ�������,�����û���
void WriteToFile(P peo[]);//����Ϣ��д���ļ���
void ReadFromFile(P peo[]);//���ļ��ж�ȡ��Ϣ
int main()
{
	int input = 1, ret, position;
	char name_to_find[10];//����һ������,�������Ҫ���ҵ��û�������
	double per_income, per_expense;
	P peoplearr[10];//����һ���ṹ������,���������û�����Ϣ
	do
	{
		menu();
		while ((ret = scanf("%d", &input)) < 1 || (sum_of_peo < 1 && (input != 1&&input!=8)))//�ж������Ƿ�Ϸ�,���Ϸ��������û���������
		{
			printf("There are some erro of your choice,please choose again.\n");
			fflush(stdin);//���������,��ֹ��ѭ��
		}
		switch (input)
		{
		case 1:
			input_information(peoplearr);//¼����Ϣ
			break;
		case 2:
			quick_sort_by_name(peoplearr, 0, sum_of_peo - 1);//�����������û�
			PrintAllInformation(peoplearr);//��ӡ�����û�
			break;
		case 3:
			printf("��������Ҫ�����˵�����:\n");
			while (ret = scanf("%s", name_to_find) < 1)//�ж������Ƿ�Ϸ�
			{
				printf("��������,����������:\n");
				fflush(stdin);//���������
			}
			position = find_by_name(name_to_find, peoplearr);//���ظ����ֶ�Ӧ�����������е�λ��
			if (position == -1)//��������ֵΪ-1ʱ,˵���Ҳ���
				printf("Not Found\n");
			else
			{
				printf("ID\tUserName\tIncome\tExpenses\n");
				PrintoneInformation(peoplearr, position);
			}
			break;
		case 4:
			per_income = mean_of_income(peoplearr);
			per_expense = mean_of_expend(peoplearr);
			printf("Per capita income:\t%lf\n", per_income);
			printf("Per capita expenses:\t%lf\n", per_expense);
			break;
		case 5:
			printf("ID\tUserName\tIncome\tExpenses\n");
			find_morethan_perexpense(peoplearr);
			break;
		case 6:
			sort_by_id(peoplearr);
			PrintAllInformation(peoplearr);
			break;
		case 7:
			WriteToFile(peoplearr);
			printf("��ȡ�ɹ�\n");
			break;
		case 8:
			ReadFromFile(peoplearr);
			PrintAllInformation(peoplearr);
			break;
		case 0:
			printf("ϵͳ�˳��ɹ�\n");
			break;
		default:
			printf("�������,����������:\n");
			fflush(stdin);
			break;
		}
	} while (input);
	return 0;
}
//��������:��ӡ�˵�,���û�֪���������ִ���ĺ���
void menu()
{
	printf("1.Input record\n");
	printf("2.Sort and list records in order by user name\n");
	printf("3.Search records by user name\n");
	printf("4.Calculate and list per capita income and expenses\n");
	printf("5.List records which have more expense than per capita expenses\n");
	printf("6.List all records\n");
	printf("7.Write to file\n");
	printf("8.Read from file\n");
	printf("0.Exit\n");
	printf(" Please enter your choice:\n");
}
//��������:�����û���Ϣ ���:�ṹ������ĵ�ַ
void input_information(P peo[])
{
	int i = sum_of_peo, ret;
	printf("Please input the Id,name,income and expense of user %d\n", sum_of_peo + 1);
	while (ret = scanf("%s%s%d%d", &peo[i].Id, &peo[i].name, &peo[i].income, &peo[i].expense) < 4)
	{
		printf("There are some erro of your input,please input again\n");
		fflush(stdin);
	}
	sum_of_peo++;
}
//��������:������˳������ ���:�ṹ�����������,��˵�,�Ҷ˵�
void quick_sort_by_name(P peo[], int L, int R)
{
	P pivot;
	int left = L, right = R;
	if (left >= right)
		return;
	pivot = peo[left];
	while (left < right)
	{
		while (left < right && strcmp(peo[right].name, pivot.name) > 0)
		{
			right--;
		}
		if (left < right && strcmp(peo[right].name, pivot.name)<0)
		{
			peo[left] = peo[right];
		}
		while (left < right && strcmp(peo[left].name, pivot.name)<0)
		{
			left++;
		}
		if (left < right && strcmp(peo[left].name, pivot.name) > 0)
		{
			peo[right] = peo[left];
		}
	}
	peo[right] = pivot;
	quick_sort_by_name(peo, 0, right - 1);
	quick_sort_by_name(peo, left + 1, R);
}
//��������:�����������û� ���:�û���,�ṹ�������� ����ֵ:����ʱ���û���λ���±�,�����ڷ���-1
int find_by_name(char* name, P peo[])
{
	quick_sort_by_name(peo, 0, sum_of_peo - 1);//�Ȱ���������,�ٶ��ֲ���
	int left = 0, right = sum_of_peo - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (strcmp(name, peo[mid].name) > 0)
			left = mid + 1;
		else if (strcmp(name, peo[mid].name) < 0)
			right = mid - 1;
		else if (strcmp(name, peo[mid].name) == 0)
			return mid;
	}
	return -1;
}
//��������:��ӡ�����û�����Ϣ �������:�ṹ��������
void PrintAllInformation(P peo[])
{
	printf("ID\tUserName\tIncome\tExpenses\n");
	int i;
	for (i = 0; i < sum_of_peo; i++)
	{
		PrintoneInformation(peo, i);
	}
}
//��������:��ӡĳ���û�����Ϣ �������:�ṹ������,�û��±��λ��
void PrintoneInformation(P peo[], int position)
{
	printf("%s\t%s\t\t%d\t%d\n", peo[position].Id, peo[position].name, peo[position].income, peo[position].expense);
}
//��������:���������û���ƽ��֧�� ������ڲ���:�ṹ��������
double mean_of_expend(P peo[])
{
	double sum_of_expense = 0;
	int i;
	for (i = 0; i < sum_of_peo; i++)
	{
		sum_of_expense += peo[i].expense;
	}
	return sum_of_expense / sum_of_peo;
}
//��������:�����û���ƽ������ ������ڲ���:�ṹ�������� ����ƽ�������ֵ
double mean_of_income(P peo[])
{
	double sum_of_income = 0;
	int i;
	for (i = 0; i < sum_of_peo; i++)
	{
		sum_of_income += peo[i].income;
	}
	return sum_of_income / sum_of_peo;
}
//��������:��ӡ�ҵ����д���ƽ��������û�����Ϣ
void find_morethan_perexpense(P peo[])
{
	int i, j = 0;
	double perexpense = mean_of_expend(peo);
	for (i = 0; i < sum_of_peo; i++)
	{
		if (peo[i].expense > perexpense)
			PrintoneInformation(peo, i);
	}

}
//��������:��ѧ�Ž���ѡ������
//�����ӿ�:�ṹ�������ַ
//��������Ϊvoid
void sort_by_id(P peo[])
{
	int i, j, k;
	P temp;
	int n = sum_of_peo;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(peo[j].Id, peo[k].Id) < 0)
			{
				k = j;
			}
			if (k != i)
			{
				temp = peo[i];
				peo[i] = peo[k];
				peo[k] = temp;
			}
		}
	}
}
//��������:�ѽṹ�������е�����д���ļ��б�������
//�����ӿڲ���:�ṹ������ĵ�ַ
//��������Ϊvoid
void WriteToFile(P peo[])
{
	FILE* fp = fopen("system.txt","w");
	if (fp == NULL)
	{
		printf("Fail to open system.txt\n");
		return ;
	}
	fprintf(fp, "%d\n", sum_of_peo);
	int i = 0;
	for(i=0;i<sum_of_peo;i++)
	{
		fprintf(fp, "%s\t%s\t\t%d\t%d\n",
			peo[i].Id, peo[i].name, peo[i].income, peo[i].expense);
	}
	fclose(fp);
	fp = NULL;
	return;
} 
//��������:���ļ��ж�ȡ��Ϣ�ŵ��ṹ��������
//�����ӿڲ���:�ṹ������ĵ�ַ
//������������:void
void ReadFromFile(P peo[])
{
	FILE*pf=fopen("system.txt", "r");
	if (pf == NULL)
	{
		printf("fail to open the file\n");
		return;
	}
	int i = 0;
	fscanf(pf, "%d\n", &sum_of_peo);
	for (i = 0; i < sum_of_peo; i++)
	{
		fscanf(pf, "%s%s%d%d", &peo[i].Id, &peo[i].name, &peo[i].income, &peo[i].expense);
	}
	fclose(pf);
	pf = NULL;
	return;
}




