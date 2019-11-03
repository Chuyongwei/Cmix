#include<stdio.h>
#include"string.h"
main()
{
      char a[128];
      int i, len, z, s, k, q;
      
      z=s=k=q=0;
      gets(a);
      len = strlen(a);
      for(i=0; i<len; i++)
          if((a[i]>='a' && a[i]<='z') || (a[i]='A' && a[i]<='z'))
              z++;
          else
              if((a[i]='0' && a[i]<='9'))
                  s++;
              else
                 if(a[i] = ' ')
                    k++;
                 else
                    q++;
          printf("%5d%5d%5d%5d", z, s, k, q);
          while(1); 
          }
