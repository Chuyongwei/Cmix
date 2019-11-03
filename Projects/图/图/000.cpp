#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define	Max 100

typedef struct Suo
{
	int suo;
	int address;
}S;

typedef struct
{
	S k[Max];
}L;

int ChartSearch(int a[], int n, int high, int num)
{
	int i;
	i = 0;
	while (a[i])
		i++;
	high = i;
	for (i = 0; i < high; i++)
		if (a[i] == num)
		{
			printf("it is sucessful!!!\n");
			return i;
		}
	printf("it is failed!!\n");
	return 0;
}

void Sort(int a[], int n)
{
	int i, j;
	int temp;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i; j++)
			if (a[j] < a[j - 1])
			{
				temp = a[j];
				a[j] = a[j - 1];
				a[j - 1] = temp;
			}
}

void Search_Bin(int a[], int high, int low, int num)
{
	int mid;
	while (high >= low)
	{
		mid = (high + low) / 2;
		if (a[mid] == num)
		{
			printf("it is succeed!!!\n");
			return;
		}
		if (num < a[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	printf("it is failed!!!\n");
	return;
}

void SuoYin(int a[], int n, int s, int num)
{
	L o;
	int i, j, k, g;
	int max, si;
	max = i = k = j = 0;
	si = n / s;
	max = 0;
	for (g = 0; g < s; g++)
	{
		o.k[g].address = i;
		for (; i < si; i++)
			if (max < a[i])
				max = a[i];
		o.k[j++].suo = max;
		si += si;
	}
	for (i = 0; i < s - 1; i++)
		if (num < o.k[i].suo)
			for (j = o.k[i].address; j < o.k[i + 1].address; j++)
				if (num == a[j])
				{
					printf("it is scceed!!!\n");
					return;
				}
	if (num < o.k[i].suo)
		for (j = o.k[i].address; j < n; j++)
			if (num == a[j])
			{
				printf("it is scceed!!!\n");
				return;
			}
	printf("it is failed!!!\n");
}


int main()
{
	int s[Max], n;
	int k[Max] = { 22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53 };
	int i, x, y, z, l;
	int size, nm, m;
	l = 0;
	srand(time(0));
	printf("input the number you need:\n");
	scanf("%d", &n);
	m = n;
	for (i = 0; i < n; i++)
	{
		s[i] = rand() % 100;
		printf("%d\t", s[i]);
	}
	printf("input the num you want to search:\n");
	scanf("%d", &x);
	ChartSearch(s, n, l, x);
	Sort(s, n);
	for (i = 0; i < m; i++)
		printf("%d\t", s[i]);
	printf("\n");
	printf("input the num you want to search:\n");
	scanf("%d", &y);
	Search_Bin(s, m, l, y);
	size = 3;
	nm = 18;
	for (i = 0; i < nm; i++)
		printf("%d ", k[i]);
	printf("\n");
	printf("input the num you want to search:\n");
	scanf("%d", &z);
	SuoYin(k, nm, size, z);
	return 0;
}




