//#include<stdio.h>
////�������귨�У��ܱ�4�����Ĵ�������꣬
////���ܱ�100���������ܱ�400��������ݲ������꣬ 
////�ܱ�3200������Ҳ�������꣬��1900����ƽ�꣬2000�������꣬3200�겻������
/*
int main()
{
	int x;
	scanf("%d",&x);
	if(x%4==0)
	{
		if(x%100!=0)
		printf("Y");
		else{
		 if(x%400==0&&x%3200!=0)
		{
			printf("Y");
		}
		else
		{
			printf("N");
		}
		}
	}else{
		printf("N");
		
	}
} 
*/


/*����
��һ����һ������n����ʾ�������ݵ���Ŀ�����n��ÿ����5������������֮����һ���ո������
��һ������ʾ��һ����·ݣ��ڶ�������ʾ��һ������ڣ�����������ʾ��һ��ϸ������Ŀ��
���ĸ�����ʾҪ�����һ����·ݣ����������ʾҪ�����һ������ڡ�
��֪��һ���Ҫ���һ����ͬһ�겢�Ҹ��겻�����꣬Ҫ���һ��һ���ڵ�һ��֮��
���ݱ�֤Ҫ���һ���ϸ����Ŀ�ڳ�������long����Χ�ڡ�
���
����ÿһ��������ݣ����һ�У����а���һ��������ΪҪ���һ���ϸ������
��������
2
1 1 1 1 2
2 28 10 3 2
�������
2
40
*/
/*
#include<iostream>
using namespace std;
struct num {
	int b[4];
	long m;
	int day;
};
int main()
{
	int mouth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int n;
	cin >> n;
	struct num *a;
	a = new struct num[n];
	for (int i = 0; i<n; i++)
	{
		cin >> a[i].b[0] >> a[i].b[1] >> a[i].m >> a[i].b[2] >> a[i].b[3];
	}
	int sum, i, j;
	for (i = 0; i<n; i++)
	{
		a[i].day = 0;
		if (a[i].b[0] == a[i].b[2])
		{
			a[i].day = a[i].b[3] - a[i].b[1];
		}
		else {

			a[i].day += (mouth[a[i].b[0]-1] - a[i].b[1]);
			for (j = a[i].b[0]; j != a[i].b[2] - 1; j++)
			{
				a[i].day += mouth[j];
			}
			a[i].day += a[i].b[3];
		}
	}
	for (i = 0; i<n; i++)
	{
		for (j = 0; j<a[i].day; j++)
		{
			a[i].m *= 2;
		}
		cout << a[i].m<<endl;
	}

}
*/

/*
����
����������ʹ�õ�������, ���걻����Ϊ�ܱ�4��������ݣ������ܱ�100���������ܱ�400�������������⣬���ǲ������ꡣ
���磺1700, 1800, 1900 �� 2100 �������꣬�� 1600, 2000 �� 2400�����ꡣ
 �����ӹ�Ԫ2000��1��1�տ�ʼ��ȥ����������������Ǹ�����һ�������������������ڼ���
����
������������У�ÿ�а���һ������������ʾ��2000��1��1�տ�ʼ��ȥ��������
�������һ����?1, ���ش������Լ���������ݲ��ᳬ��9999��
���
��ÿ���������������һ�У����а�����Ӧ�����ں����ڼ���
��ʽΪ��YYYY-MM-DD DayOfWeek��, ���� ��DayOfWeek��
 �����������е�һ���� "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" �� "Saturday����
��������
1730 
1740 
1750 
1751 
-1
�������
2004-09-26 Sunday 
2004-10-06 Wednesday 
2004-10-16 Saturday 
2004-10-17 Sunday
*/
/*
#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;


int days;
int get_dayofweek();
int get_year();
int get_month(int leap_year);



int main(){
//bool flag;//false for bike and true for walk;
int year,month,dayofweek;
int leap_year;
char week[7][10]={"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
while((cin>>days)&&days!=-1){
 dayofweek=get_dayofweek();
 year=get_year();
 leap_year=(year%4==0&&year%100!=0||year%400==0);
 month=get_month(leap_year);

 cout<<year<<'-';
 if(month<10){
    cout<<'0';
 }
 cout<<month<<'-';
 if(days<9){
    cout<<'0';
 }
 cout<<++days<<' ';
 cout<<week[dayofweek];
 cout<<endl;
}



return 0;

}
//cout<<fixed<<setprecision(2) << f

//�и��ǵ�������ֵ�Ŀ����ԡ�

int get_dayofweek(){

int dayofweek;
dayofweek=days%7;
return dayofweek;

}

int get_year(){
int i=2000,leap_year;

while(1){
    leap_year=(i%4==0&&i%100!=0||i%400==0);
    if(days>=366&&leap_year==1){
    days-=366;
    i++;
    continue;
}
if(days>=365&&leap_year==0){
    days-=365;
    i++;
    continue;
}else

break;

}

return i;

}



int get_month(int leap_year){
int pmonth[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int rmonth[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int j=0;
while(1){
    if(leap_year==1&&days>=rmonth[j]){
        days=days-rmonth[j];
        j++;
    }else if(leap_year==0&&days>=pmonth[j]){
        days=days-pmonth[j];
        j++;
    }else break;



}

return ++j;
}
*/
/*����
����ĩ��M.A. Ya���ڶԹ��ϵ���������һ���ش��֡���һ�����ϵĽ��������������ڼ��µĹ��ߣ��У�
���ڷ���������ʹ����һ��һ����365��Ľ���Haab�����������Haab����ӵ��19���£��ڿ�ʼ��18���£�
һ������20�죬�·ݵ����ֱַ���pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu��
��Щ�·��е�������0��19��ʾ��Haab�������һ���½���uayet����ֻ��5�죬��0��4��ʾ��
��������Ϊ����������ٵ��·��ǲ������ģ�������·�ͥ����ͥ�����ǲ����½��ף�����û���˴�ɨ���еĵذ塣 

��Ϊ�ڽ̵�ԭ�������˻�ʹ������һ��������������������걻��ΪTzolkin(holly��)��һ�걻�ֳ�13����ͬ��ʱ�ڣ�
ÿ��ʱ����20�죬ÿһ����һ�����ֺ�һ����������ϵ���ʽ����ʾ��ʹ�õ�������1~13��ʹ�õĵ��ʹ���20����
���Ƿֱ��ǣ�imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau��
ע�⣺���е�ÿһ�춼������ȷΨһ�����������磬��һ��Ŀ�ʼ��
�������������� 1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk, 10 ok, 
11 chuen, 12 eb, 13 ben, 1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6 canac, 7 ahau, ��8 imix, 9 ik, 10 akbal ����
Ҳ����˵���ֺ͵��ʸ��Զ���ѭ��ʹ�á� 

Haab����Tzolkin���е��궼������0��1��������ʾ������0��ʾ����Ŀ�ʼ�����Ե�һ�챻��ʾ�ɣ� 
Haab: 0. pop 0 
Tzolkin: 1 imix 0 
�����M.A. Ya����дһ��������԰�Haab��ת����Tzolkin���� 
����
Haab���е����������µķ�ʽ��ʾ�� 
����. �·� ���� 

�����еĵ�һ�б�ʾҪת����Haab�����ڵ��������������ÿһ�б�ʾһ�����ڣ�����С��5000��
���
Tzolkin���е����������µķ�ʽ��ʾ�� 
������ ������ ���� 

��һ�б�ʾ��������������������ÿһ�б�ʾһ�����������ж�Ӧ��Tzolkin���е����ڡ�
��������
3
10. zac 0
0. pop 0
10. zac 1995
�������
3
3 chuen 0
1 imix 0
9 cimi 2801
*/
/*
#include<bits/stdc++.h>
//enum H {pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu};
//enum T_mou {imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau};
struct  Haab{
	int year;
	char mou[10];//1-18,19
	int day;//0-19
};
struct Tzolkin{
	int year;
	int mou;//1-13
	int day;//1-20
};
int main()
{
	using namespace std;
	
	char month1[19][10] ={"pop","no","zip","zotz","tzec","xul",

        "yoxkin","mol", "chen", "yax","zac",

         "ceh","mac","kankin","muan","pax",

        "koyab","cumhu","uayet"};// Haab���·�

char month2[20][10] ={"imix","ik","akbal","kan","chicchan","cimi",

    "manik","lamat","muluk", "ok", "chuen",

     "eb","ben","ix","mem","cib","caban","eznab",

    "canac","ahau"};// Tzolkin��};
    int n;
    cin>>n;
	long day[n];
    struct Haab a[n];
    struct Tzolkin b[n];
    int i,j;
	for(i = 0;i<n;i++)
	{	
		scanf("%d.%s",&a[i].day,&a[i].mou);
		//gets(a[i].mou);
		scanf("%d",&a[i].year);
		day[i] = a[i].year*365;
		for(j = 0;j<19;j++)
		{
			if(strcmp(month1[j],a[i].mou)==0)
			{
				day[i]+=(j*20+a[i].day);
				break;
			}
		} 
	}
	int m;
	for(i = 0;i<n;i++)
	{
		b[i].year = day[i]/260;
		m = day[i]%260;
		if(b[i].mou==13)
		{
			
		}
		b[i].mou = m%20;
		b[i].day = m%13;
	}
	cout<<n<<endl;
	for(i = 0;i<n;i++)
	{
	//	printf("%d %s %d\n",1+dates%13, month2[dates%20],dates/260);
		std::cout<<(b[i].day+1)<<" "<<month2[b[i].mou]<<" "<<b[i].year<<std::endl;
	}
} 
*/

/*
����
�ڹ��⣬ÿ�µ�13�ź�ÿ�ܵ�����5���ǲ������ġ��ر��ǵ�13������ǡ��������5ʱ��������������֪ĳ���һ��һ��������w��������һ��һ���������꣬�����һ������13������������5���·ݣ�����С�����˳������·����֡���w=1..7��
����
������һ�У���һ��һ�����ڼ���w������1 <= w <= 7��
���
�����һ�����У�ÿ��һ���·ݣ���ʾ���µ�13���������塣
��������
7
�������
1
10
��ʾ
1��3��5��7��8��10��12�¸���31��
4��6��9��11�¸���30��
2����28��
*/
#include<bits/stdc++.h>
int main()
{
	using namespace std;
	int data=0;
	cin>>data;
	int mouth[] = { 12,31,28,31,30,31,30,31,31,30,31,30 };
	int i ;
	for(i = 0;i<12;i++)
	{
		data += mouth[i];
		if(data%7==5)
		cout<<i+1<<endl; 
	}
} 










