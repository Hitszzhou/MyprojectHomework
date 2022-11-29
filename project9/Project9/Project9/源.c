#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct People//定义一个结构体,包含用户的id,姓名,收入,支出的信息
{
	char Id[6];
	char name[11];
	int income;
	int expense;
}P;
void menu();//打印菜单,提醒用户进行选择
int find_by_name(char* name, P peo[]);//按名字找到用户
double mean_of_income(P peo[]);//计算平均收入
double mean_of_expend(P peo[]);//计算平均支出
void find_morethan_perexpense(P peo[]);//找出支出大于平均的人
void input_information(P peo[]);//输入用户信息
void PrintAllInformation(P peo[]);//打印所有信息
void PrintoneInformation(P peo[], int position);//打印某一个人的信息
void sort_by_id(P peo[]);//按id来排序用户
int sum_of_peo;//定义一个全局变量,代表所有用户人数
void quick_sort_by_name(P peo[], int L, int R);//用快速排序,排序用户名
void WriteToFile(P peo[]);//将信息读写到文件中
void ReadFromFile(P peo[]);//从文件中读取信息
int main()
{
	int input = 1, ret, position;
	char name_to_find[10];//定义一个数组,用来存放要查找的用户的名字
	double per_income, per_expense;
	P peoplearr[10];//定义一个结构体数组,储存所有用户的信息
	do
	{
		menu();
		while ((ret = scanf("%d", &input)) < 1 || (sum_of_peo < 1 && (input != 1&&input!=8)))//判断输入是否合法,不合法则提醒用户重新输入
		{
			printf("There are some erro of your choice,please choose again.\n");
			fflush(stdin);//清除缓冲区,防止死循环
		}
		switch (input)
		{
		case 1:
			input_information(peoplearr);//录入信息
			break;
		case 2:
			quick_sort_by_name(peoplearr, 0, sum_of_peo - 1);//按姓名排序用户
			PrintAllInformation(peoplearr);//打印所有用户
			break;
		case 3:
			printf("请输入你要查找人的姓名:\n");
			while (ret = scanf("%s", name_to_find) < 1)//判断输入是否合法
			{
				printf("输入有误,请重新输入:\n");
				fflush(stdin);//清除缓冲区
			}
			position = find_by_name(name_to_find, peoplearr);//返回该名字对应的人在数组中的位置
			if (position == -1)//函数返回值为-1时,说明找不到
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
			printf("读取成功\n");
			break;
		case 8:
			ReadFromFile(peoplearr);
			PrintAllInformation(peoplearr);
			break;
		case 0:
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
//函数功能:打印菜单,让用户知道各个数字代表的含义
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
//函数功能:输入用户信息 入口:结构体数组的地址
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
//函数功能:按名字顺序排序 入口:结构体数组的名字,左端点,右端点
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
//函数功能:按名字搜索用户 入口:用户名,结构体数组名 返回值:存在时该用户的位置下标,不存在返回-1
int find_by_name(char* name, P peo[])
{
	quick_sort_by_name(peo, 0, sum_of_peo - 1);//先把名字排序,再二分查找
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
//函数功能:打印所有用户的信息 函数入口:结构体数组名
void PrintAllInformation(P peo[])
{
	printf("ID\tUserName\tIncome\tExpenses\n");
	int i;
	for (i = 0; i < sum_of_peo; i++)
	{
		PrintoneInformation(peo, i);
	}
}
//函数功能:打印某个用户的信息 函数入口:结构体数组,用户下标的位置
void PrintoneInformation(P peo[], int position)
{
	printf("%s\t%s\t\t%d\t%d\n", peo[position].Id, peo[position].name, peo[position].income, peo[position].expense);
}
//函数功能:计算所有用户的平均支出 函数入口参数:结构体数组名
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
//函数功能:计算用户的平均收入 函数入口参数:结构体数组名 返回平均收入的值
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
//函数功能:打印找到所有大于平均收入的用户的信息
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
//函数功能:按学号进行选择排序
//参数接口:结构体数组地址
//返回类型为void
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
//函数功能:把结构体数组中的内容写到文件中保存起来
//函数接口参数:结构体数组的地址
//返回类型为void
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
//函数功能:从文件中读取信息放到结构体数组中
//函数接口参数:结构体数组的地址
//函数返回类型:void
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




