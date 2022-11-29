#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct People
{
	char Id[6];
	char name[11];
	int income;
	int expense;
}P;
void menu();
void sort_by_reverse_name(P peo[]);
int find_by_name(char* name, P peo[]);
double mean_of_income(P peo[]);
double mean_of_expend(P peo[]);
void find_morethan_perexpense(P peo[]);
void input_information(P peo[10]);
void PrintAllInformation(P peo[]);
void PrintoneInformation(P peo[], int position);
void sort_by_id(P peo[]);
void WritetoFile(P peo[]);
void Loadsystem(P* peo);
int sum_of_peo;
void quick_sort_by_reverse_name(P peo[],int L,int R);
int main()
{
	int input=1,ret,position;
	char name_to_find[10];
	double per_income, per_expense;
	P peoplearr[10];
	do
	{
		menu();
		while (ret = scanf("%d", &input) < 1||(sum_of_peo<1&&(input!=7&&input!=1)))
		{
			printf("There are some erro of your choice,please choose again.\n");
			fflush(stdin);
		}
		switch (input)
		{
		case 1:
			input_information(peoplearr);//录入信息
			break;
		case 2:
			quick_sort_by_reverse_name(peoplearr,0,sum_of_peo);
			PrintAllInformation(peoplearr);
			break;
		case 3:
			printf("请输入你要查找人的姓名:\n");
			while (ret = scanf("%s", name_to_find) < 1)
			{
				printf("输入有误,请重新输入:\n");
				fflush(stdin);//清除缓冲区
			}
			position=find_by_name(name_to_find, peoplearr);
			if (position == -1)
				printf("Not Found\n");
			else
			{
				printf("ID\tUserName\tIncome\tExpenses\n");
				PrintoneInformation(peoplearr, position);
			}
			break;
		case 4:
			per_income=mean_of_income(peoplearr);
			per_expense=mean_of_expend(peoplearr);
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
            WritetoFile(peoplearr);
            break;
		case 0:
			WritetoFile(peoplearr);//在退出前把信息保存到文件中
			printf("系统退出成功\n");
			break;
		default:
			printf("输入错误,请重新输入:\n");
			fflush(stdin);
			break;
		}
	} while (input);
	return 0;
}
void menu()
{
	printf("1.Input record\n");
	printf("2.Sort and list records in reverse order by user name\n");
	printf("3.Search records by user name\n");
	printf("4.Calculate and list per capita income and expenses\n");
	printf("5.List records which have more expense than per capita expenses\n");
	printf("6.List all records\n");
	printf("7.Load system\n");
	printf("0.Exit\n");
	printf(" Please enter your choice:\n");
}
void input_information(P peo[10])
{
	int i = sum_of_peo,ret;
	printf("Please input the Id,name,income and expense of user %d\n", sum_of_peo+1);
	while (ret = scanf("%s%s%d%d", &peo[i].Id, &peo[i].name, &peo[i].income, &peo[i].expense) < 4)
	{
		printf("There are some erro of your input,please input again\n");
		fflush(stdin);
	}
	sum_of_peo++;
}
void quick_sort_by_reverse_name(P peo[],int L,int R)
{
    int left=L,right=R;
    if (left>=right)
        return;
    P pivot;
    pivot=peo[left];
    while(left<right)
    {
        while(left<right&&strcmp(peo[right].name,pivot.name)<0)
        {
            right--;
        }
        if(left<right&&strcmp(peo[right].name,pivot.name)>0)
        {
            peo[left]=peo[right];
        }
        while(left<right&&strcmp(peo[left].name,pivot.name)>0)
        {
            left++;
        }
        if(left<right&&strcmp(peo[left].name,pivot.name)<0)
        {
            peo[right]=peo[left];
        }
    }
    peo[right]=pivot;
    quick_sort_by_reverse_name(peo,0,right-1);
    quick_sort_by_reverse_name(peo,left+1,R);
}
int find_by_name(char* name, P peo[])
{
	quick_sort_by_reverse_name(peo,0,sum_of_peo);//先把名字逆序排序,再二分查找
	int left = 0, right = sum_of_peo - 1,mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (strcmp(name, peo[mid].name) < 0)
			left = mid + 1;
		else if (strcmp(name, peo[mid].name) > 0)
			right = mid - 1;
		else if (strcmp(name, peo[mid].name) == 0)
			return mid;
	}
	return -1;
}
void PrintAllInformation(P peo[])
{
	printf("ID\tUserName\tIncome\tExpenses\n");
	int i;
	for (i = 0; i < sum_of_peo; i++)
	{
		printf("%s\t%s\t\t%d\t%d\n", peo[i].Id, peo[i].name, peo[i].income, peo[i].expense);
	}
}
void PrintoneInformation(P peo[], int position)
{
	printf("%s\t%s\t\t%d\t%d\n", peo[position].Id, peo[position].name, peo[position].income, peo[position].expense);
}
double mean_of_expend(P peo[])
{
	double sum_of_expense=0;
	int i;
	for (i = 0; i < sum_of_peo; i++)
	{
		sum_of_expense += peo[i].expense;
	}
	return sum_of_expense / sum_of_peo;
}
double mean_of_income(P peo[])
{
	double sum_of_income=0;
	int i;
	for (i = 0; i < sum_of_peo; i++)
	{
		sum_of_income += peo[i].income;
	}
	return sum_of_income / sum_of_peo;
}
void find_morethan_perexpense(P peo[])
{
	int i,j=0;
	double perexpense = mean_of_expend(peo);
	for (i = 0; i < sum_of_peo; i++)
	{
		if (peo[i].expense > perexpense)
		printf("%s\t%s\t\t%d\t%d\n", peo[i].Id, peo[i].name, peo[i].income, peo[i].expense);
	}

}
void sort_by_id(P peo[])
{
	int i, j;
	P temp;
	for (i = 0; i < sum_of_peo - 1; i++)
	{
		for (j = 0; j < sum_of_peo - 1 - i; j++)
		{
			if (strcmp(peo[j].Id, peo[j + 1].Id) < 0)
			{
				temp=peo[j];
				peo[j]= peo[j + 1];
				peo[j + 1]= temp;
			}
		}
	}
}
//void WritetoFile(P peo[])
//{
//	FILE* fp= fopen("system.dat", "w");
//	int i;
//	if (fp  == NULL)
//	{
//		printf("Failure to open system.dat!\n");
//		exit(0);
//	}
//	//写文件
//	for (i = 0; i < sum_of_peo; i++)
//	{
//		fprintf(fp, "%s\t%s\t\t%d\t%d\n", peo[i].Id, peo[i].name, peo[i].income, peo[i].expense);
//	}
//	fclose(fp);
//	fp = NULL;
//}
