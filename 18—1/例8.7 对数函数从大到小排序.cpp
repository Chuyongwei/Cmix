#include<stdio.h>
  void sort(int arr[],int n)
  { 
	int i,j,k,t ;
	for(i=0; i<n-1; i++)
	{
	  k = i;
	  for(j=i+1;j<n; j++)
	     if(arr[j] < arr[k]) k = j ;
	  t=arr[k]; arr[k]=arr[i]; arr[i]=t;
    }
  }
  main()
  {
  	int a[10], i ;
  	for(i=0; i<10; i++)
  	    scanf("%d",&a[i]) ;
    sort(a, 10);
  	printf("\n the sorted array: \n");
  	for(i=0; i<10; i++)
  	    printf("%d,", a[i]);
  	return 0; 
  }
