#include<stdio.h>
  void printarray(int arr[10])                 /*�˺��������������ֵ��������arr���β�*/ 
  {
	  int i;
	  for(i=0; i<10; i++)
	     printf("%6d", arr[i]);
	  printf("\n");
  }
  void sort(int a[], int n)                    /*���������ð������������a���β�*/ 
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
  	
  	printarray(a);                                /*��ӡ����ǰ�����飬 ������a���������� */ 
  	sort(a, 10);                                /*������������������a������ʵ��*/ 
  	printf("\nThe array is after sorted:  \n");
  	printarray(a);                                 /*��ӡ���������飬������a��ʵ�ʲ���*/ 
  }
