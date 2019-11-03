#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int num;
	char a[20];
	int score;
}Student;
void Input(Student stu[],int n){
	
	int i;
	for(i=1;i<=n;i++){
        printf("请输入学生的学号，姓名，分数:\n");
	    scanf("%d",&stu[i].num);
		getchar();
		scanf("%s",&stu[i].a);
		scanf("%d",&stu[i].score);

	}
}
void  InsertSort(Student stu[],int n){ 
	//对待排序序列L进行直接插入排序
	int i,j;
    for(i=2; i<=n; i++)
        if (stu[i].score<stu[i-1].score){
		     stu[0]=stu[i];
             stu[i]=stu[i-1];
              for(j = i-2; stu[i].score < stu[j].score; j--)
                  stu[i] = stu[j];          // 记录后移
              stu[j+1] = stu[0];   //记录插入
        }
} // InsertSort
void Maopaosort(Student stu[],int n){
	int i,j;
	Student temp;
	for (j=1; j<=n-1; j++)
        for (i =1; i<=n-j; i++){
            if (stu[i].score >stu[i + 1].score){
               temp = stu[i]; 
               stu[i] = stu[i + 1]; 
              stu[i + 1] = temp;
			}
		}
 }
void Output(Student stu[],int n){
	int i;
	int j=1;
	for(i=n;i>=1;i--){
		printf("%3d %s%3d%3d\n",stu[i].num,stu[i].a,stu[i].score,j++);
	}
}
int  Partition(Student stu[], int low,int high){
	//对顺序表L进行一趟快速排序，返回枢轴记录所在的位置
	int key;
    stu[0] = stu[low];   // 用子表的第一记录作枢轴记录
    key = stu[low].score;
    while(low<high){
         while(low<high && stu[high].score>=key) --high;
         if(low<high)
             stu[low++] = stu[high];    // 将比pivotkey 小的记录移到低端
         while(low<high &&stu[low].score<=key) ++low;
         if(low<high)
             stu[high--] =stu[low];     // 将比pivotkey 大的记录移到高端
    }
    stu[low] = stu[0];
    return low;
}
void  Qsort(Student stu[],int low,int high){
	//对顺序表L的子序列L.r[low..high]作快速排序
	int pivotloc;
    if(low<high){
        pivotloc = Partition(stu, low, high);
        Qsort(stu, low, pivotloc-1);
        Qsort(stu, pivotloc+1, high);
   }
}  // QSort

void QuickSort(Student stu[],int n)
{//对顺序表L作快速排序
     Qsort(stu, 1, n);
} // QuickSort
void SelectSort(Student stu[],int n){
	//对顺序表L进行简单选择排序
	int i,k,j;
	Student temp;
     for ( i=1; i<n; ++i)
      {   k=i;  
            //选择关键字最小的记录
           for (j = i+1;j <= n; ++j)
	       if (stu[k].score >stu[j].score)   k=j;
	//最小记录与第i个记录互换
           if (i!=k){ 
               temp=stu[i];
	           stu[i]=stu[k];
			   stu[k]=temp; 
           }
      }
}
void HeapAdjust(Student stu[], int s, int m){
	//调整H.r[s..m]成一个大顶堆
	Student rc;
	int j;
     rc=stu[s];
     for(j=2*s; j<=m; j*=2 )
     {    if( j<m && stu[j].score < stu[j+1].score)   j++;
           if( rc.score>= stu[j].score)  break; 
           stu[s] = stu[j];    s=j;
     }
     stu[s] = rc;
} 
void HeapSort(Student stu[],int n){ 
	//对顺序表H进行堆排序
  //初始堆建立
	int i;
	Student temp;
  for ( i = n/2;  i > 0;  --i)
        HeapAdjust(stu, i, n);
  //堆的输出与调整
 for ( i = n;  i > 1;  --i)
    {   temp = stu[1];
        stu[1] = stu[i];
        stu[i] = temp;
        HeapAdjust(stu, 1, i-1);
    }
}
void Merge( Student s[], Student t[], int i, int m, int n )
{//将有序的SR[i..m]和SR[m+1..n]归并为有序的TR[i..n]
    int j,k;
   j = m+1;  k = i;
   while( i <= m && j <= n )
      if( s[i].score <= s[j].score)   t[k++] = s[i++];
      else  t[k++] = s[j++];
   while( i <= m)    t[ k++] = s[i++];
   while( j <= n)     t[ k++] = s[j++];
}//Merge 
void MSort( Student stu[], Student t1[], int s, int t)
{//将SR[s..t]归并排序为TR1[s..t]。
	Student t2[20];
	int m;
    if( s == t )   t1[s] = stu[s];
    else 
    {    m = ( s+t )/2;         //将SR[s..t]平分为SR[s..m]和SR[m+1..t]
          MSort( stu, t2, s, m ); //将SR[s..m]归并为有序的TR2[s..m] 
          MSort( stu, t2, m+1, t); //将SR[m+1..t]归并为有序的TR2[m+1..t] 
          Merge( t2,t1,s,m,t); //将TR2[s..m]和TR2[m+1..t]归并到TR1[s..t] 
    }
}

int main()
{
	printf("需要多少人？");
	int n;
	int i;
	scanf("%d",&n);
	Student stu[n+1]; 
	Input(stu[], n);
	for(i=1;i<=n;i++)
	printf("%10d%20s%5d\n",stu[i].a,stu[i].num,stu[i].score);
	int x;
	printf("（1）编程实现插入排序算法；\n");
	printf("（2）编程实现快速排序算法；\n");
	printf("（3）编程实现选择排序算法；\n");
	printf("（4）编程实现归并排序算法。\n");
    scanf("%d",&x);
	switch(x)
	{
		case 1:  InsertSort( stu, n);break;
		case 2:  QuickSort( stu,n);break;
		case 3: SelectSort(stu,n);break;
		case 4: HeapSort( stu, n);break;
	}
	
	for(i=1;i<=n;i++)
	printf("%10d%20s%5d\n",stu[i].a,stu[i].num,stu[i].score);
}

