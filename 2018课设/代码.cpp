#include<stdio.h>
#include<math.h>
#include<conio.h> 
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define file "erhuo.txt"
#define file2 "JiLu.txt"
typedef int Status;
/*��1��ʵ�ִ�������������ʱ��Ҫ��д�Ǽǿ�����¼������Ϣ�������������˺ţ��������ÿ������Ϊ0��
��2��ʵ�ִ�����������Ҫ���ҵ��������˻���Ϣ��Ȼ����ɾ����
��3����ĳ�˻�����Ҫ�ҵ��˻���Ϣ��Ȼ���޸��˻�����ԭ�������?+?�������
��4����ĳ�˻�ȡ���Ҫ�ҵ��˻���Ϣ��Ȼ���޸��˻�����ԭ�������???ȡ������
��5��������ʾ�����˻���Ϣ�������˺Ŷ������˻���Ϣ����
��6����ѯĳ�˻����ҵ�Ҫ���ҵ��˻���Ȼ����ʾ�˻���
��7����ѯĳ�˻����׼�¼���ҵ�Ҫ��ѯ���˻���Ȼ����ʾ���˻��Ľ��׼�¼��
��8�������˻����佻����Ϣ�洢���ļ�����������ʱ���ļ��ж��롣*/
typedef struct user {//�û�
	int ID;
	char name[21];
	double money;
	char password[7];
}user;
typedef struct //��¼
{
	int hour, mid, sec;//ʱ�� 
	int year, month, days;//���� 
	int ID;
	int fun;
	double wec;
	double money;
}score;
void print()
{
	printf("��ѡ������ҵ��\n");
	printf("%8s%34s", "��1������", "��5����ѯ�˻����\n\n");
	printf("%8s%42s", "��2������", "��6��������ʾ�����˻���Ϣ\n\n");
	printf("%8s%34s", "��3�����", "��7����ѯ���׼�¼\n\n");
	printf("%8s%30s", "��4��ȡ��", "��8���޸�����\n\n");
	printf("%8s","��9���˳�ϵͳ\n\n"); 
	printf("�������֣�1~8��");
}

void local(score &temp2)
{
	struct tm *d;
	time_t t;
	time(&t);
	d = localtime(&t);
	temp2.days = d->tm_mday;
	temp2.hour = d->tm_hour;
	temp2.mid = d->tm_min;
	temp2.sec = d->tm_sec;
	temp2.year = d->tm_year + 1900;
	temp2.month = d->tm_mon + 1;
	return;
}

score score2(user temp, int n, double wec)
{//��¼�ļ� 
	score temp2;
	local(temp2);
	temp2.fun = n;
	temp2.ID = temp.ID;
	temp2.money = temp.money;
	temp2.wec = wec;
	return temp2;
}

void add()
{//���� 
	Status couts();
	int mun, i;
	FILE *fd;
	struct user temp;
	score temp2;

	//�����
	if ((fd = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!");
		exit(1);
	}
	mun = 0;
	while (fread(&temp, sizeof(struct user), 1, fd))
	{
		mun++;
	}

	temp.ID = mun + 1;
	fclose(fd);

	//�������� 
	printf("%30s\n", "***plase add user***");
	printf("*************************************\n");
	printf("Please enter name:  ");
	do {
		scanf("%s", temp.name);
		fflush(stdin);
		if (strlen(temp.name) <= 20)
			break;
		else
			printf("Don't char length more than 20!");
	} while (1);

	//�������� 
	int mark = 0;
	printf("Please enter password:");
	while (1)
	{
		gets(temp.password);
		fflush(stdin);
		for (i = 0; i<7;)
		{
			if (temp.password[i] <'0' || temp.password[i]>'9')
			{

				break;
			}
			else i++;
		}
		if (i != 6 || strlen(temp.password) != 6)
		{
			if (i != 6)
				printf("password must number!");
			if (strlen(temp.password) != 6)
				printf("password must 6!");
		}
		else break;
	}
	//�洢���
	printf("�������");
	scanf("%lf", &temp.money);

	//�����ļ� 
	if ((fd = fopen(file, "ab")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	else
	{
		fwrite(&temp, sizeof(user), 1, fd);
		printf("Creat user succeal!");
	}
	fclose(fd);
	//��¼�����ļ�
	temp2 = score2(temp, 0, temp.money);
	if ((fd = fopen("JiLu.txt", "ab")) == NULL)
	{
		printf("cannot open file2!\n");
		exit(1);
	}
	else {
		fwrite(&temp2, sizeof(score), 1, fd);
	}
	fclose(fd);
}

int cout() //����Ŀ�ģ������ļ��еļ�¼����
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



void select()//���˺Ų�ѯ�˻���� 
{
	int i, maxmun;
	char pass[6];
	user temp;
	FILE *fd;
	printf("%30s\n", "***�����˺Ų�ѯ�˻����***");
	printf("*************************************\n");
	printf("����Ҫ��ѯ���˻�");
	scanf("%d", &i);
	printf("��������");
	scanf("%s", &pass);
	fflush(stdin);
	if ((fd = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	maxmun = cout();
	if (i>maxmun)
	{
		printf("�˻������ڣ�");
		return;
	}
	do {
		fread(&temp, sizeof(user), 1, fd);
	} while (temp.ID != i);
	if (strcmp(temp.password, pass) != 0)
		printf("�������!");
	else {
		printf("%8s %15s %6s %10s\n", "�˺�", "�û�����", "����", "������");
		printf("---------------------------------------------\n\n");
		printf("NO.%d %15s %6s %.2f\n", temp.ID, temp.name, temp.password, temp.money);
	}

	fclose(fd);
}

Status password_confrimation(char password[]) {
	int x = 5;
	char pass[6];
	printf("�������˻�����:");
	scanf("%s", &pass);
	fflush(stdin);
	do
	{
		x -= 1;
		if (strcmp(pass, password) != 0)
		{
			printf("������󣬻���%d�λ���\n", x);
			scanf("%s", &pass);
			fflush(stdin);
		}
		else return 1;
	} while (x>1);
	printf("�˳�");
	return 0;
}

void save()
{
	int cout();
	printf("%30s\n", "***�û����ҵ��***");
	printf("*************************************\n");
	int i, m, num;
	double money;
	FILE *fd;
	user *temp, use;
	num = cout();
	temp = (user*)malloc(num * sizeof(user));
	char pass[6];
	printf("����洢�˻���");
	scanf("%d", &i);
	if (i>num || i<0)
	{
		printf("���˻������ڣ�\n");
		return;
	}

	//�������� 
	printf("�����˻����룺");
	scanf("%s", &pass);
	fflush(stdin);

	//��¼�˻�  
	if ((fd = fopen("erhuo.txt", "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (m = 0; m<num; m++)
	{
		fread(&temp[m], sizeof(user), 1, fd);
	}
	fclose(fd);

	//��� 
	printf("�������");
	do {
		scanf("%lf", &money);
		if (money<0)
		{
			printf("�������Ч��\n");
		}
	} while (money<0);
	//�����ݴ���ļ��� 
	if ((fd = fopen("erhuo.txt", "wb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (m = 0; m<num; m++)
	{
		if (temp[m].ID == i)
		{
			temp[m].money += money;
			use = temp[m];
		}
		fwrite(&temp[m], sizeof(user), 1, fd);
	}
	fclose(fd);
	free(temp);
	printf("���ɹ���");

	//��¼���� 
	score temp2;
	if ((fd = fopen(file2, "ab")) == NULL)//�Ժ�׷��ʽ���ļ� 
	{
		printf("�ļ������ڣ�");
		exit(1);
	}
	temp2 = score2(use, 1, money);
	fwrite(&temp2, sizeof(score), 1, fd);
	fclose(fd);

}

void get()
{//ȡ�� 
	printf("%30s\n", "***�û�ȡ��ҵ��***");
	printf("*************************************\n");
	int i, m, num, x;
	double money;
	FILE *fd;
	user *temp, use;

	printf("����ȡ���˻�:");
	scanf("%d", &i);
	num = cout();
	if (i>num)
	{
		printf("�˻������ڣ�");
		return;
	}

	//��¼�˻� 
	temp = (user*)malloc(num * sizeof(user));
	if ((fd = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}

	for (m = 0; m<num; m++)
	{
		fread(&temp[m], sizeof(user), 1, fd);
	}
	fclose(fd);

	//cunkuan 
	if ((fd = fopen(file, "wb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (m = 0; m<num; m++)
	{
		if (temp[m].ID == i)
		{
			while (1)//��ѭ�� 
			{
				x = password_confrimation(temp[m].password);//ȷ������ 
				if (x == 0) break;
				printf("����ȡ����:");
				do {
					scanf("%lf", &money);
					if (money<0)
					{
						printf("ȡ������Ч��\n");
					}
					if (money>temp[m].money)
						printf("ȡ���������\n");
				} while (money<0 && money<temp[m].money);
				temp[m].money -= money;
				use = temp[m];
				printf("ȡ��ɹ���");
				break;
			}
		}
		fwrite(&temp[m], sizeof(user), 1, fd);
	}
	fclose(fd);
	free(temp);


	//��¼�ļ� 
	score temp2;
	if ((fd = fopen(file2, "ab")) == NULL)
	{
		printf("�ļ������ڣ�");
		exit(1);
	}

	temp2 = score2(use, 2, money);
	fwrite(&temp2, sizeof(score), 1, fd);
	fclose(fd);

}

void display() //��ʾ�û�����
{
	printf("%30s\n", "***�û�������ʾ**");
	printf("*************************************\n");
	FILE * fp;
	struct user temp;
	if ((fp = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	printf("%5s %14s %14s %10s\n", "�˺�", "�û�����", "����", "������");
	printf("---------------------------------------------\n\n");
	while (fread(&temp, sizeof(struct user), 1, fp))
	{
		if(temp.ID==-1)
		continue;
		printf("NO.%d %20s %10s %.2f\n", temp.ID, temp.name, temp.password, temp.money);
	}
	fclose(fp);
}


void Del()
{//���� 
	int count();
	printf("%30s\n", "***ע���˻�***");
	printf("*************************************\n");
	FILE * fd;
	user *temp, use;
	int i, maxnum, m;
	char f;
	printf("����ע���˻���");
	scanf("%d", &i);
	maxnum = cout();
	if (i>maxnum || i<0)
	{
		printf("���˻������ڣ�");
		return;
	}
	//��¼�˻� 
	temp = (user*)malloc(maxnum * sizeof(user));
	if ((fd = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}

	for (m = 0; m<maxnum; m++)
	{
		fread(&temp[m], sizeof(user), 1, fd);
	}
	fclose(fd);

	//shanchu 
	//�����ݴ���ļ��� 
	if ((fd = fopen(file, "wb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (m = 0; m<maxnum; m++)
	{
		if (temp[m].ID == i)
		{

			if (temp[m].money != 0.00)
			{
				printf("��ȡ�����д�");
				fwrite(&temp[m], sizeof(user), 1, fd);
				continue;
			}
			else      //���Ϊ0 
			{
				int x;
				if ((x = password_confrimation(temp[m].password)) == 0)
					return;
				else
				{
					printf("���ٴ�ȷ���Ƿ�����?(Y or N?)");
					scanf("%c", &f);
					while (f != 'Y' && f != 'y' && f != 'n' && f != 'N')
					{
						printf("���������������");
						scanf("%c", &f);
					}
					if (f == 'Y' || f == 'y')
					{
						use = temp[m];
						temp[m].ID = -1;
						printf("�����ɹ���\n");
						printf("NO.%d %15s %15s %.2f\n", use.ID, use.name, use.password, use.money);
						//break; 

					}

				}
			}
		}
		fwrite(&temp[m], sizeof(user), 1, fd);
	}
	fclose(fd);
	free(temp);

	//��¼ 
	score temp2;
	score2(use, 1, 0);
	if ((fd = fopen(file2, "ab")) == NULL)
	{
		printf("�ļ������ڣ�");
		exit(1);
	}

	temp2 = score2(use, 3, 0);
	fwrite(&temp2, sizeof(score), 1, fd);
	fclose(fd);
}

void Tran_record()
{//���׼�¼ 
	printf("%30s", "***���׼�¼***\n");

	FILE *fd;
	user temp;
	score temp2;
	int i, maxnum, x;
	printf("����Ҫ��ѯ�˻���");
	scanf("%d", &i);


	maxnum = cout();
	if (i>maxnum)
	{
		printf("���˻������ڣ�\n");
		return;
	}

	if ((fd = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	while (fread(&temp, sizeof(struct user), 1, fd))
	{
		if (temp.ID == i)
			break;
	}
	fclose(fd);

	if (temp.ID != i)
	{
		printf("�û��ѱ�ע����");
		return;
	}

	//ȷ������ 
	if ((x = password_confrimation(temp.password)) == 0)
		return;
	//��ʾ��¼ 
	if ((fd = fopen(file2, "rb")) == NULL)
	{
		printf("�ļ������ڣ�");
		exit(1);
	}
	printf("%12s %18s %12s %10s %6s %10s\n", "ʱ��", "�˺�", "�û�����", "ҵ��", "����", "���");
	printf("--------------------------------------------------------------------\n\n");
	while (fread(&temp2, sizeof(score), 1, fd))
	{
		if (temp2.ID == i)
		{
			printf("%2d��%2d��%2d��\t%2d:%2d:%2d", temp2.year, temp2.month, temp2.days, temp2.hour, temp2.mid, temp2.sec);
			switch (temp2.fun)
			{
			case 0:printf("%cNO.%5d %15s %6s %10.2f %10.2f\n", ' ', temp2.ID, temp.name, "����", temp2.wec, temp2.money); break;
			case 1:printf("%cNO.%5d %15s %6s %10.2f %10.2f\n", ' ', temp2.ID, temp.name, "���", temp2.wec, temp2.money); break;
			case 2:printf("%cNO.%5d %15s %6s %10.2f %10.2f\n", ' ', temp2.ID, temp.name, "ȡ��", temp2.wec, temp2.money); break;
			case 3:printf("%cNO.%5d %15s %6s %10.2f %10.2f\n", ' ', temp2.ID, temp.name, "����", temp2.wec, temp2.money); break;
			}
		}
	}
	return;
}

//������

void pass_exc()
{
	FILE *fd;
	char pass[6];
	int n, i, m, maxnum;
	user *temp;
	printf("������Ҫ�޸�������˻���");
	scanf("%d",&n);
	maxnum = cout();
	if (n>maxnum)
	{
		printf("���˻������ڣ�\n");
		return;
	}
	
		temp = (user*)malloc(maxnum * sizeof(user));
	if ((fd = fopen(file, "rb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}

	for (m = 0; m<maxnum; m++)
	{
		fread(&temp[m], sizeof(user), 1, fd);
		
		if (temp[m].ID == n)
		{
			printf("Please enter password:");
			scanf("%s",pass);
			if (strcmp(pass, temp[m].password) != 0)
			{
				printf("�������\n\t�˳�");
				return;
			}
		}
	}
	fclose(fd);
	
	if ((fd = fopen(file, "wb")) == NULL)
	{
		printf("cannot open file!\n");
		exit(1);
	}
	for (m = 0; m<maxnum; m++)
	{
		if (temp[m].ID == n)
		{
			
			printf("���޸����루�˳�ҵ������ N����");
			while (1)
			{scanf("%s",pass);
				fflush(stdin);
				for (i = 0; i<7;)
				{
					if (pass[i] <'0' || pass[i]>'9')
					{

						break;
					}
					else i++;
				}
				if (i != 6 || strlen(temp[m].password) != 6)
				{
					if (i != 6)
						printf("password must number!");
					if (strlen(temp[m].password) != 6)
						printf("password must 6!");
				}
				else break;
			}
			strcpy(temp[m].password, pass);
			printf("�޸ĳɹ���"); 
		}
		fwrite(&temp[m], sizeof(score), 1, fd);
	}
	fclose(fd);
	free(temp);
} 

int main()
{
	int x;
	while (1)
	{
		printf("%40s", "Current savings account management\n");
		printf("---------------------------------------------\n\n");
		print();
		scanf("%d", &x);
		system("cls");
		switch (x)

		{
		case 1:add(); break;
		case 2:Del(); break;
		case 3:save(); break;
		case 4:get(); break;
		case 5:select(); break;
		case 6:display(); break;
		case 7:Tran_record(); break;
		case 8:pass_exc();break;
		case 9:printf("\n\n��ӭ�´ι��٣�\n\n\tף����ҵ�гɣ�");return 0;
		default:
			printf("�Բ�������ѡ��Ĺ��ܲ�����!\n");
		}
		getch();
		system("cls");
	}
}


