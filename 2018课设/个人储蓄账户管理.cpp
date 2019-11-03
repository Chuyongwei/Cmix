#include<stdio.h> 
#include<string.h> 
#include<conio.h> 
#include<stdlib.h>  
#define file "temp.txt" //���ݴ洢���ļ���
struct user //�û����Ͷ���(�˺ţ����������룬���)  
{
	int id;
	char name[20];
	char person_password[7];
	double money;
};
void add()//����û�����
{
	printf("%30s\n", "***����û�***");
	printf("---------------------------------------------\n\n");
	struct user getuser();
	int count(); //����Ŀ�ģ������ļ��еļ�¼��Ŀ�������Զ��˺�
	FILE *fp;
	int number;
	struct user temp;
	if ((fp = fopen(file, "ab")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	temp = getuser();             //��ȡ�û���
	number = count();
	temp.id = number + 1;           //�����Զ��˺�
	fwrite(&temp, sizeof(struct user), 1, fp);
	printf("����û��ɹ�!\n");
	fclose(fp);
}
int count() //����Ŀ�ģ������ļ��еļ�¼����
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
	printf("�������û�����(�ַ���<20): ");       //��ȡ��ؿ�����Ϣ 
	getname(temp.name);
	printf("�������û�����: ");
	getperson_password(temp.person_password);
	printf("���뿪�����:");
	do {              //�жϿ������(>=100) 
		scanf("%lf", &temp.money);
		fflush(stdin);
		if ((temp.money)<100.0)
			printf("��������С��100\n");
		else
			break;
		printf("�������뿪����");
	} while (1);
	return temp;
}
void getname(char *name) //�������ܣ���ȡ�û�����(�ַ���<20)  
{
	do {
		scanf("%s", name);
		fflush(stdin);
		if (strlen(name) == 0)
			printf("��������Ϊ��!\n");
		else
			if (strlen(name) >= 20)
				printf("�������ܳ���20���ַ�!\n");
			else
				break;
		printf("������������: ");
	} while (1); //ѭ���Ա�֤����������Ч
}
void getperson_password(char *person_password) //�������ܣ���ȡ�û����� ) 
{
	do {
		int i, mark;//mark�� 
		char ch;
		for (i = 0, mark = 0;; i++) //������Ч���ж�(ֻ��������)
			if ((ch = getchar()) != '\n')
			{
				if (ch <= '9'&&ch >= '0')
					person_password[i] = ch;
				else
				{
					printf("����ֻ��������!\n");
					mark = 1;
					break;
				}
			}
			else
				break;
		person_password[i] = '\0';
		if (mark == 1)//����ʧ�� 
			continue;
		if (strlen(person_password) != 6)
			printf("����ֻ����6λ!\n");
		else
			break;
		printf("������������: ");
	} while (1); //ѭ���Ա�֤����������Ч
}
void select_id() //�����˺Ų�ѯ�˻����
{
	int count();
	void getperson_password(char*person_password);
	printf("%30s\n", "***�����˺Ų�ѯ�˻����***");
	printf("%8s %15s %6s %10s\n", "�˺�", "�û�����", "����", "������");
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
	printf("����Ҫ��ѯ�˺�:"); //�ж��˺��Ƿ��ڼ�¼��

	scanf("%d", &i);
	printf("�����˺�����:");
	scanf("%s", &person_password);
	if (i<1 || i>maxnum)
	{
		printf("��Ҫ��ѯ���˺Ų�����!");
		return;
	}
	while (fread(&temp, sizeof(struct user), 1, fp))//ѭ����ȡÿһ����¼�ж��Ƿ�ΪҪ�鿴�ļ�¼

		if (temp.id == i&&strcmp(temp.person_password, person_password) == 0)
		{

			printf("NO.%d %15s %6s %.2f\n", temp.id, temp.name, temp.person_password, temp.money);
		}
	fclose(fp);
}
void display() //��ʾ�û�����
{
	printf("%30s\n", "***�û�������ʾ**");
	printf("%8s %15s %6s %10s\n", "�˺�", "�û�����", "����", "������");
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
void save_money() //�������ܣ����˺Ŵ��
{
	printf("%30s\n", "***�û����ҵ��***");
	printf("---------------------------------------------\n\n");
	int count();
	void getperson_password(char *person_password);
	FILE *fp;
	int i, num, mark;
	struct user *temp;
	char person_password[6];
	num = count(); //���ݼ�¼������ռ� 
	temp = (struct user *)malloc(num * sizeof(struct user));
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (i = 0; i<num; i++) //���ļ����ݴ�������
		fread(&temp[i], sizeof(struct user), 1, fp);
	fclose(fp);
	printf("����Ҫ����˺�:"); //��ȡ����˺�
	scanf("%d", &mark);
	if (mark<1 || mark>num)
	{
		printf("��Ҫ����˺Ų�����!");
		return;
	}
	printf("�����˺�����:");
	scanf("%s", &person_password);
	if ((fp = fopen(file, "wb")) == NULL)    //д��ʽ���ļ�������ԭ�ļ��е�����
	{
		printf("cannot open file!\n");
		exit(1);

	}
	for (i = 0; i<num; i++)
	{
		if (temp[i].id == mark)
		{
			double money = 0;
			printf("����Ҫ����Ľ��:");
			scanf("%lf", &money);
			if (money <= 0)
			{
				printf("ֻ��Ϊ����!\n");
				money = 0;
			}
			temp[i].money += money; //�޸ĸ��û�����Ϣ
		}
		fwrite(&temp[i], sizeof(struct user), 1, fp);
	}
	fclose(fp);
	free(temp);
	printf("����ҵ���Ѱ���!\n");
}
void get_money() //�������ܣ��û�ȡ��
{
	printf("%30s\n", "***�û�ȡ��ҵ��***");
	printf("---------------------------------------------\n\n");
	int count();
	void getperson_password(char *person_password);
	FILE *fp;
	int i, num, mark;
	struct user *temp;
	char person_password[6];
	num = count(); //���ݼ�¼������ռ�
	temp = (struct user *)malloc(num * sizeof(struct user));
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (i = 0; i<num; i++) //��ȡ�ļ�����
		fread(&temp[i], sizeof(struct user), 1, fp);
	fclose(fp);

	printf("����Ҫȡ���˺�:");
	scanf("%d", &mark);
	if (mark<1 || mark>num)
	{
		printf("��Ҫȡ���˺Ų�����!");
		return;
	}
	printf("�����˺�����:");
	scanf("%s", &person_password);
	if ((fp = fopen(file, "wb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (i = 0; i<num; i++)  //д��ʽ���ļ�������ԭ�ļ��е�����
	{
		if (temp[i].id == mark)
		{
			double money = 0;
			printf("����Ҫȡ���Ľ��:");
			scanf("%lf", &money);
			if (money <= 0) //�ж��û�����Ƿ��㹻
			{
				printf("ֻ��Ϊ����!\n");
				money = 0;
			}
			else
				if (money>temp[i].money)
				{
					printf("�������!\n");
					money = 0;
				}
			temp[i].money -= money;
		}
		fwrite(&temp[i], sizeof(struct user), 1, fp);
	}
	fclose(fp);
	free(temp);
	printf("��ȡ��ҵ���Ѱ���!\n");
}

void del() //����
{
	int count();
	printf("%30s\n", "***ע���˻�***");
	printf("%8s %15s %15s %10s\n", "�˺�", "�û�����", "����", "������");
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
	printf("����Ҫ�����˺�:");  //�жϱ���Ƿ��ڼ�¼��
	scanf("%d", &i);
	if (i<1 || i>maxnum)
	{
		printf("��Ҫע�����˺Ų�����!");
		return;
	}
	while (fread(&temp, sizeof(struct user), 1, fp)) //ѭ����ȡÿһ����¼,
		if (temp.id == i&&temp.money == 0.00)      //���Ϊ0 
		{
			temp.id = -1;//����Ч�ʻ�
			printf("NO.%d %15s %15s %.2f\n", temp.id, temp.name, temp.person_password, temp.money);
			printf("%d\n", temp.id);
			fwrite(&temp, sizeof(struct user), 1, fp);//�����޸�
			printf("�˻������ɹ�!\n");
		}
	fclose(fp);
}
void print() //�������ܣ��������
{
	printf("%30s\n", "***���ڴ�����Ŀ����ϵͳ***");
	printf("---------------------------------------------\n\n");
	printf("%8s,%-20s\n", "1", "��������");
	printf("%8s,%-20s\n", "2", "�����˺Ų�ѯ�˻����");
	printf("%8s,%-20s\n", "3", "��ʾ�û���Ϣ");
	printf("%8s,%-20s\n", "4", "���");
	printf("%8s,%-20s\n", "5", "ȡ��");
	printf("%8s,%-20s\n", "6", "��������");
	printf("%8s,%-20s\n", "7", "�˳�");
	printf("\n��ѡ����(1~7):");
}
int main()
{
	char choose;
	do {
		print();
		scanf(" %c", &choose); //��ȡ���ܱ�ţ����ݱ��ѡ��ͬ�ĺ���
		fflush(stdin);
		system("cls");//���� 
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
			printf("�Բ�������ѡ��Ĺ��ܲ�����!\n");
		}
		getch(); //��ͣ����(��ȡ���������)(conio.h)
		system("cls"); //�����Ļ��ʾ(stdlib.h)
	} while (1);
	return 0;
}
