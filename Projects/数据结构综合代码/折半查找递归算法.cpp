#include<stdio.h>
int b_search(int *p, int l,int r, int key);
int main(){
 	int a[7]={5,13,19,21,37,56,64};
 	int i, p, k;
 	for(i=0;i<7;i++)
 		printf("%d\t",a[i]);
 	printf("\n");
 	for(i=0; i<2; i++){
  		printf("input the num of you want to found:");
  		scanf("%d", &k); //输入56或12
  		p=b_search(a, 0, 6, k);
  		if(p>=0)
   			printf("found: %d=a[%d]\n", k, p);
  		else
   			printf("no found: %d\n", k);
	}
 	return 0;
}
//二分查找，找到返回位置，否则返回-1
int b_search(int *p, int l,int r, int key){
 	int f,m;
 	m=(l+r)/2;
 	if(l>r)
  		f=-1;
 	else if(p[m]==key)
  		f=m;
 	else if(p[m]>key)
  		f=b_search(p, l, r-1, key);
 	else
  		f=b_search(p, l+1, r, key);
 	return f;
}
