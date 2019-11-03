#include <stdio.h>
int main()
{ 
	float a=100,b=10; 
	float *pointer_1, *pointer_2; 
	pointer_1=&a; 
	pointer_2=&b;  
	printf("a=%f,b=%f\n",a,b); 
	printf("*pointer_1=%f,*pointer_2=%f\n",*pointer_1,*pointer_2); 
    return 0;
}
/*a*/
