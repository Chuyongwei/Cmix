//#include<stdio.h>
////公历纪年法中，能被4整除的大多是闰年，
////但能被100整除而不能被400整除的年份不是闰年， 
////能被3200整除的也不是闰年，如1900年是平年，2000年是闰年，3200年不是闰年
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


/*输入
第一行有一个整数n，表示测试数据的数目。其后n行每行有5个整数，整数之间用一个空格隔开。
第一个数表示第一天的月份，第二个数表示第一天的日期，第三个数表示第一天细菌的数目，
第四个数表示要求的那一天的月份，第五个数表示要求的那一天的日期。
已知第一天和要求的一天在同一年并且该年不是闰年，要求的一天一定在第一天之后。
数据保证要求的一天的细菌数目在长整数（long）范围内。
输出
对于每一组测试数据，输出一行，该行包含一个整数，为要求的一天的细菌数。
样例输入
2
1 1 1 1 2
2 28 10 3 2
样例输出
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
描述
在我们现在使用的日历中, 闰年被定义为能被4整除的年份，但是能被100整除而不能被400整除的年是例外，它们不是闰年。
例如：1700, 1800, 1900 和 2100 不是闰年，而 1600, 2000 和 2400是闰年。
 给定从公元2000年1月1日开始逝去的天数，你的任务是给出这一天是哪年哪月哪日星期几。
输入
输入包含若干行，每行包含一个正整数，表示从2000年1月1日开始逝去的天数。
输入最后一行是?1, 不必处理。可以假设结果的年份不会超过9999。
输出
对每个测试样例，输出一行，该行包含对应的日期和星期几。
格式为“YYYY-MM-DD DayOfWeek”, 其中 “DayOfWeek”
 必须是下面中的一个： "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday" 或 "Saturday“。
样例输入
1730 
1740 
1750 
1751 
-1
样例输出
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

//有覆盖掉其他数值的可能性。

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
/*描述
上周末，M.A. Ya教授对古老的玛雅有了一个重大发现。从一个古老的节绳（玛雅人用于记事的工具）中，
教授发现玛雅人使用了一个一年有365天的叫做Haab的历法。这个Haab历法拥有19个月，在开始的18个月，
一个月有20天，月份的名字分别是pop, no, zip, zotz, tzec, xul, yoxkin, mol, chen, yax, zac, ceh, mac, kankin, muan, pax, koyab, cumhu。
这些月份中的日期用0到19表示。Haab历的最后一个月叫做uayet，它只有5天，用0到4表示。
玛雅人认为这个日期最少的月份是不吉利的，在这个月法庭不开庭，人们不从事交易，甚至没有人打扫屋中的地板。 

因为宗教的原因，玛雅人还使用了另一个历法，在这个历法中年被称为Tzolkin(holly年)，一年被分成13个不同的时期，
每个时期有20天，每一天用一个数字和一个单词相组合的形式来表示。使用的数字是1~13，使用的单词共有20个，
它们分别是：imix, ik, akbal, kan, chicchan, cimi, manik, lamat, muluk, ok, chuen, eb, ben, ix, mem, cib, caban, eznab, canac, ahau。
注意：年中的每一天都有着明确唯一的描述，比如，在一年的开始，
日期如下描述： 1 imix, 2 ik, 3 akbal, 4 kan, 5 chicchan, 6 cimi, 7 manik, 8 lamat, 9 muluk, 10 ok, 
11 chuen, 12 eb, 13 ben, 1 ix, 2 mem, 3 cib, 4 caban, 5 eznab, 6 canac, 7 ahau, ，8 imix, 9 ik, 10 akbal ……
也就是说数字和单词各自独立循环使用。 

Haab历和Tzolkin历中的年都用数字0，1，……表示，数字0表示世界的开始。所以第一天被表示成： 
Haab: 0. pop 0 
Tzolkin: 1 imix 0 
请帮助M.A. Ya教授写一个程序可以把Haab历转化成Tzolkin历。 
输入
Haab历中的数据由如下的方式表示： 
日期. 月份 年数 

输入中的第一行表示要转化的Haab历日期的数据量。下面的每一行表示一个日期，年数小于5000。
输出
Tzolkin历中的数据由如下的方式表示： 
天数字 天名称 年数 

第一行表示输出的日期数量。下面的每一行表示一个输入数据中对应的Tzolkin历中的日期。
样例输入
3
10. zac 0
0. pop 0
10. zac 1995
样例输出
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

        "koyab","cumhu","uayet"};// Haab历月份

char month2[20][10] ={"imix","ik","akbal","kan","chicchan","cimi",

    "manik","lamat","muluk", "ok", "chuen",

     "eb","ben","ix","mem","cib","caban","eznab",

    "canac","ahau"};// Tzolkin历};
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
描述
在国外，每月的13号和每周的星期5都是不吉利的。特别是当13号那天恰好是星期5时，更不吉利。已知某年的一月一日是星期w，并且这一年一定不是闰年，求出这一年所有13号那天是星期5的月份，按从小到大的顺序输出月份数字。（w=1..7）
输入
输入有一行，即一月一日星期几（w）。（1 <= w <= 7）
输出
输出有一到多行，每行一个月份，表示该月的13日是星期五。
样例输入
7
样例输出
1
10
提示
1、3、5、7、8、10、12月各有31天
4、6、9、11月各有30天
2月有28天
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










