#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include<stdlib.h>  
#define file "temp.txt" //数据存储的文件名
struct user //用户类型定义(账号，姓名，密码，余额)  
{
	int id;
	char name[20];
	char person_password[7];
	double money;
};
void add()//添加用户资料
{
	printf("%30s\n", "***添加用户***");
	printf("---------------------------------------------\n\n");
	struct user getuser();
	int count(); //函数目的：计算文件中的记录数目以生成自动账号
	FILE *fp;
	int number;
	struct user temp;
	if ((fp = fopen(file, "ab")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	temp = getuser();             //读取用户名
	number = count();
	temp.id = number + 1;           //生成自动账号
	fwrite(&temp, sizeof(struct user), 1, fp);
	printf("添加用户成功!\n");
	fclose(fp);
}
int count() //函数目的：计算文件中的记录总数
{
	FILE *fp;
	int num;
	struct user temp;
	num = 0;
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	while (fread(&temp, sizeof(struct user), 1, fp))
	{
		num++;
	}
	fclose(fp);
	return num;
}
struct user getuser() {
	void getname(char *name);
	void getperson_password(char *person_password);
	struct user temp;
	printf("请输入用户姓名(字符数<20): ");       //读取相关开户信息 
	getname(temp.name);
	printf("请输入用户密码: ");
	getperson_password(temp.person_password);
	printf("输入开户金额:");
	do {              //判断开户金额(>=100) 
		scanf("%lf", &temp.money);
		fflush(stdin);
		if ((temp.money)<100.0)
			printf("开户金额不能小于100\n");
		else
			break;
		printf("重新输入开户金额：");
	} while (1);
	return temp;
}
void getname(char *name) //函数功能：读取用户姓名(字符数<20)  
{
	do {
		scanf("%s", name);
		fflush(stdin);
		if (strlen(name) == 0)
			printf("姓名不能为空!\n");
		else
			if (strlen(name) >= 20)
				printf("姓名不能超过20个字符!\n");
			else
				break;
		printf("重新输入姓名: ");
	} while (1); //循环以保证读入数据有效
}
void getperson_password(char *person_password) //函数功能：读取用户密码 ) 
{
	do {
		int i, mark;//mark是 
		char ch;
		for (i = 0, mark = 0;; i++) //输入有效性判断(只能是数字)
			if ((ch = getchar()) != '\n')
			{
				if (ch <= '9'&&ch >= '0')
					person_password[i] = ch;
				else
				{
					printf("密码只能是数字!\n");
					mark = 1;
					break;
				}
			}
			else
				break;
		person_password[i] = '\0';
		if (mark == 1)//输入失败 
			continue;
		if (strlen(person_password) != 6)
			printf("密码只能是6位!\n");
		else
			break;
		printf("重新输入密码: ");
	} while (1); //循环以保证读入数据有效
}
void select_id() //按照账号查询账户余额
{
	int count();
	void getperson_password(char*person_password);
	printf("%30s\n", "***按照账号查询账户余额***");
	printf("%8s %15s %6s %10s\n", "账号", "用户姓名", "密码", "存款余额");
	printf("---------------------------------------------\n\n");

	FILE * fp;
	struct user temp;
	int i, maxnum;
	char person_password[6];
	if ((fp = fopen(file, "rb")) == NULL)
	{

		printf("cannot open file!\n");
		exit(1);
	}

	maxnum = count();
	printf("输入要查询账号:"); //判断账号是否在记录中

	scanf("%d", &i);
	printf("输入账号密码:");
	scanf("%s", &person_password);
	if (i<1 || i>maxnum)
	{
		printf("你要查询的账号不存在!");
		return;
	}
	while (fread(&temp, sizeof(struct user), 1, fp))//循环读取每一条记录判断是否为要查看的记录

		if (temp.id == i&&strcmp(temp.person_password, person_password) == 0)
		{

			printf("NO.%d %15s %6s %.2f\n", temp.id, temp.name, temp.person_password, temp.money);
		}
	fclose(fp);
}
void display() //显示用户资料
{
	printf("%30s\n", "***用户资料显示**");
	printf("%8s %15s %6s %10s\n", "账号", "用户姓名", "密码", "存款余额");
	printf("---------------------------------------------\n\n");
	FILE * fp;
	struct user temp;
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	while (fread(&temp, sizeof(struct user), 1, fp))
	{
		printf("NO.%d %15s %6s %.2f\n", temp.id, temp.name, temp.person_password, temp.money);
	}
	fclose(fp);
}
void save_money() //函数功能：按账号存款
{
	printf("%30s\n", "***用户存款业务***");
	printf("---------------------------------------------\n\n");
	int count();
	void getperson_password(char *person_password);
	FILE *fp;
	int i, num, mark;
	struct user *temp;
	char person_password[6];
	num = count(); //根据记录数申请空间 
	temp = (struct user *)malloc(num * sizeof(struct user));
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (i = 0; i<num; i++) //将文件内容存入数组
		fread(&temp[i], sizeof(struct user), 1, fp);
	fclose(fp);
	printf("输入要存款账号:"); //读取存款账号
	scanf("%d", &mark);
	if (mark<1 || mark>num)
	{
		printf("你要存款账号不存在!");
		return;
	}
	printf("输入账号密码:");
	scanf("%s", &person_password);
	if ((fp = fopen(file, "wb")) == NULL)    //写方式打开文件，覆盖原文件中的内容
	{
		printf("cannot open file!\n");
		exit(1);

	}
	for (i = 0; i<num; i++)
	{
		if (temp[i].id == mark)
		{
			double money = 0;
			printf("输入要存入的金额:");
			scanf("%lf", &money);
			if (money <= 0)
			{
				printf("只能为正数!\n");
				money = 0;
			}
			temp[i].money += money; //修改该用户的信息
		}
		fwrite(&temp[i], sizeof(struct user), 1, fp);
	}
	fclose(fp);
	free(temp);
	printf("你存款业务已办妥!\n");
}
void get_money() //函数功能：用户取款
{
	printf("%30s\n", "***用户取款业务***");
	printf("---------------------------------------------\n\n");
	int count();
	void getperson_password(char *person_password);
	FILE *fp;
	int i, num, mark;
	struct user *temp;
	char person_password[6];
	num = count(); //根据记录数申请空间
	temp = (struct user *)malloc(num * sizeof(struct user));
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (i = 0; i<num; i++) //读取文件内容
		fread(&temp[i], sizeof(struct user), 1, fp);
	fclose(fp);

	printf("输入要取款账号:");
	scanf("%d", &mark);
	if (mark<1 || mark>num)
	{
		printf("你要取款账号不存在!");
		return;
	}
	printf("输入账号密码:");
	scanf("%s", &person_password);
	if ((fp = fopen(file, "wb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (i = 0; i<num; i++)  //写方式打开文件，覆盖原文件中的内容
	{
		if (temp[i].id == mark)
		{
			double money = 0;
			printf("输入要取出的金额:");
			scanf("%lf", &money);
			if (money <= 0) //判断用户余额是否足够
			{
				printf("只能为正数!\n");
				money = 0;
			}
			else
				if (money>temp[i].money)
				{
					printf("你的余额不足!\n");
					money = 0;
				}
			temp[i].money -= money;
		}
		fwrite(&temp[i], sizeof(struct user), 1, fp);
	}
	fclose(fp);
	free(temp);
	printf("你取款业务已办妥!\n");
}

void del() //销户
{
	int count();
	printf("%30s\n", "***注销账户***");
	printf("%8s %15s %15s %10s\n", "账号", "用户姓名", "密码", "存款余额");
	printf("---------------------------------------------\n\n");
	FILE * fp;
	struct user temp;
	int i, maxnum;
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	maxnum = count();
	printf("输入要销户账号:");  //判断编号是否在记录中
	scanf("%d", &i);
	if (i<1 || i>maxnum)
	{
		printf("你要注销的账号不存在!");
		return;
	}
	while (fread(&temp, sizeof(struct user), 1, fp)) //循环读取每一条记录,
		if (temp.id == i&&temp.money == 0.00)      //余额为0 
		{
			temp.id = -1;//算无效帐户
			printf("NO.%d %15s %15s %.2f\n", temp.id, temp.name, temp.person_password, temp.money);
			printf("%d\n", temp.id);
			fwrite(&temp, sizeof(struct user), 1, fp);//保存修改
			printf("账户销户成功!\n");
		}
	fclose(fp);
}
void print() //函数功能：输出界面
{
	printf("%30s\n", "***活期储蓄帐目管理系统***");
	printf("---------------------------------------------\n\n");
	printf("%8s,%-20s\n", "1", "储户开户");
	printf("%8s,%-20s\n", "2", "按照账号查询账户余额");
	printf("%8s,%-20s\n", "3", "显示用户信息");
	printf("%8s,%-20s\n", "4", "存款");
	printf("%8s,%-20s\n", "5", "取款");
	printf("%8s,%-20s\n", "6", "储户销户");
	printf("%8s,%-20s\n", "7", "退出");
	printf("\n请选择功能(1~7):");
}
int main()
{
	char choose;
	do {
		print();
		scanf(" %c", &choose); //读取功能标号，根据标号选择不同的函数
		fflush(stdin);
		system("cls");//清屏 
		switch (choose)
		{
		case '1':
			add();
			break;
		case '2':
			select_id();
			break;
		case '3':
			display();
			break;
		case '4':
			save_money();
			break;
		case '5':
			get_money();
			break;
		case '6':
			del();
			break;
		case '7':
			exit(1);
		default:
			printf("对不起，你所选择的功能不存在!\n");
		}
		getch(); //暂停功能(读取任意键继续)(conio.h)
		system("cls"); //清除屏幕显示(stdlib.h)
	} while (1);
	return 0;
}
