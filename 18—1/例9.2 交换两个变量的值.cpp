#include"stdio.h"
  int main()
  {
	void swap(int *,int *);
	int x = 7, y = 11, *px = &x, *py = &y;
	
	printf("x=%d,\ty=%d\n", x, y);
	printf("swapped:\n");
	swap(px, py);
	printf("%d,%d\n",x,y);
	printf("%d,%d\n",*px,*py);	
  }
  
  void swap(int *a, int *b)
  {
  	int temp;
  	
  	temp = *a;
  	*a = *b;
  	*b = temp;
  }
