#include <stdio.h>
int main ( )
{
     int i, j;
     i = 5;
     j = 6;
     printf("%d,%d \n", i, j);
     printf("%d,%d \n", i++, j--);
     printf("%d,%d \n", i, j);
     printf("%d,%d \n", ++i, --j);
     return 0;
}
