#include"function.h"
int fun1(int n)
{
	int i, m=1;
	for(i=n;i>0;i--)
	m*=n;
	return m;
}
