#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 20
#define EQ(a,b) ((a) == (b))
#define LT(a,b) ((a) <  (b))
#define LQ(a,b) ((a) <= (b))
typedef struct student
{
	int ID;
	char name[Max];
	int score;
	int place;
}*st;

void input( st &s , int x )
{
	int i;
	int id,sc,p;
	char n[Max];
	s = ( st )malloc( x * sizeof( st ) );
	for( i = 0 ; i < x ; i ++ )
	{
		printf( "please int id:" );
		scanf( "%d",&id );
		s[i].ID = id;
		printf( "please int name:" );
		scanf( "%s",n );
		strcpy( s[i].name,n );
		printf( "please int score:" );
		scanf( "%d",&sc );
		s[i].score = sc;
		printf( "please int place:" );
		scanf( "%d",&p );
		s[i].place = p;
	}
}

void Insert( st s , int x )
{//ֱ�Ӳ������� 
	int i,j;
	for( i = 2 ; i <= x ; i ++ )
		if( s[i].ID < s[i-1].ID )
		{
			s[i] = s[i-1];
			for( j = i - 1 ; s[0].ID < s[j].ID ; j -- )
				s[j+1] = s[j];
			s[j+1] = s[0];
		}
}

void maopao( st s,int x )
{//ð������ 
	int i,j;
	st temp;
	for( i = 0 ; i < x ; i ++ )
		for( j = 0 ; j < x - i - 1 ; j ++ )
			if( s[j].ID > s[j+1].ID )
			{
				*temp = s[j];
				s[j] = s[j+1];
				s[j+1] = *temp;
			}
}

void Choose( st s,int x )
{//ѡ������ 
	int i,j,k;
	st temp;
	for( i = 1 ; i < x ; i ++ )
	{
		k = i;
		for( j = i + 1 ; j <= x; j ++ )
			if(s[k].ID > s[j].ID )
				k = j;
		if( i != k )
		{
			*temp = s[i];
			s[i] = s[k];
			s[k] = *temp;
		}
	}
}

void HeapAdjust( st s,int m,int n )
{
	st r;
	int j;
	*r = s[m];
	for( j = 2*m ; j <= n ; j *= 2 )
	{
		if ( j < n && s[j].ID < s[j+1].ID )
			j ++;
		if ( r->ID >= s[j].ID )
			break;
		s[m] = s[j];
		m = n;
	}
	s[m] = *r;
}

void HeapSort( st s,int x )
{//������ 
	int i;
	st temp;
	for( i = x/2 ; i > 0 ; i -- )
		HeapAdjust( s,i,x );
	for( i = x ; i > 1 ; i -- )
	{
		*temp = s[1];
		s[1] = s[i];
		s[i] = *temp;
	}
}

void towroad( st s,st &t,int i,int m,int n )
{//2·���� 
	int j,k;
	j = m + 1;
	k = i;
	while( i <= m && j <= n )
		if( s[i].ID <= s[j].ID )
			t[k++] = s[i++];
		else
			t[k++] = s[j++];
	while( i <= m )
		t[k++] = s[i++];
	while( j <= m )
		t[k++] = s[j++];
}

void Merge(st s,st &t,int i,int m,int n)
{
    int j,k;
	for(j = m+1,k = 1;i<=m&&j<=n;++k)
	{
		if(LQ(s[i].ID,s[j].ID))
		t[k] = s[i++];
		else t[k] = s[j++];
		}
	if(i<=m)
	{
		while(i<=m)
		{
			t[k] = s[i];
			k++,i++;
		}
	}
	else
	{
		while(j<=n)
		{
			t[k] = s[j];
			k++,j++;
		}
	}
}

void MSort( st s,st &t1,int m,int t )
{ 
	int n;
	st t2;
	if ( m == t )
		t1[m] = s[m];
	else
	{
		n = ( m + t ) / 2;
		MSort( s,t2,m,n );
		MSort( s,t2,n+1,t );
		Merge( t2,t1,m,n,t );
	}
}

void MergeSort( st &s,int x )
{
	MSort( s,s,1,x );
}

int partition( st &s ,int low,int high )
{//�������� 
	int temp;
	s[0] = s[low];
	temp = s[low].ID;
	while( low < high )
	{
		while( low < high && s[high].ID >= temp )
			high--;
		if( low < high )
			s[low++] = s[high];
		while( low < high && s[high].ID <= temp )
			low++;
		if( low < high )
			s[high--] = s[low];
	}
	s[low] = s[0];
	return low;
}

void QSort( st &s , int low , int high )
{//���� 
	int t;
	if( low < high )
	{
	   t = partition( s,low,high );
	   QSort( s,low,t-1 );
       QSort( s,t+1,high );
	}
}

void QuickSort( st &s,int x )
{
	QSort( s,1,x );
}

int main()
{
	int num;
	st g;
	printf( "please int a num:\n" );
	scanf( "%d",&num );
	input( g,num );
	return 0;
}
 







