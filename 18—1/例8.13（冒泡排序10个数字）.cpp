#include<stdio.h>
  void printarray(int arr[10])                 /*此函数用于输出数组值，数组名arr是形参*/ 
  {
	  int i;
	  for(i=0; i<10; i++)
	     printf("%6d", arr[i]);
	  printf("\n");
  }
  void sort(int a[], int n)                    /*对数组进行冒泡排序，数组名a是形参*/ 
  {
  	int i, j, t;
  	 for(i=1; i<n; i++)
  	     for(j=0; j<n-1; j++)
  	         if(a[j] > a[j])
  	         {t=a[j]; a[j]=a[j+1]; a[j+1] = t;}
  }
  main()
  {
  	int a[]={50, 23, 22, 12, 60, 70, 80, 90, 10, 5};
  	printf("\nThe array beforing sorted sorted is:  \n");
  	
  	printarray(a);                                /*打印排序前的数组， 数组名a作函数参数 */ 
  	sort(a, 10);                                /*调用排序函数，数组名a做函数实参*/ 
  	printf("\nThe array is after sorted:  \n");
  	printarray(a);                                 /*打印排序后的数组，数组名a做实际参数*/ 
  }
