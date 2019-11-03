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
        printf("������ѧ����ѧ�ţ�����������:\n");
	    scanf("%d",&stu[i].num);
		getchar();
		scanf("%s",&stu[i].a);
		scanf("%d",&stu[i].score);

	}
}
void  InsertSort(Student stu[],int n){ 
	//�Դ���������L����ֱ�Ӳ�������
	int i,j;
    for(i=2; i<=n; i++)
        if (stu[i].score<stu[i-1].score){
		     stu[0]=stu[i];
             stu[i]=stu[i-1];
              for(j = i-2; stu[i].score < stu[j].score; j--)
                  stu[i] = stu[j];          // ��¼����
              stu[j+1] = stu[0];   //��¼����
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
	//��˳���L����һ�˿������򣬷��������¼���ڵ�λ��
	int key;
    stu[0] = stu[low];   // ���ӱ�ĵ�һ��¼�������¼
    key = stu[low].score;
    while(low<high){
         while(low<high && stu[high].score>=key) --high;
         if(low<high)
             stu[low++] = stu[high];    // ����pivotkey С�ļ�¼�Ƶ��Ͷ�
         while(low<high &&stu[low].score<=key) ++low;
         if(low<high)
             stu[high--] =stu[low];     // ����pivotkey ��ļ�¼�Ƶ��߶�
    }
    stu[low] = stu[0];
    return low;
}
void  Qsort(Student stu[],int low,int high){
	//��˳���L��������L.r[low..high]����������
	int pivotloc;
    if(low<high){
        pivotloc = Partition(stu, low, high);
        Qsort(stu, low, pivotloc-1);
        Qsort(stu, pivotloc+1, high);
   }
}  // QSort

void QuickSort(Student stu[],int n)
{//��˳���L����������
     Qsort(stu, 1, n);
} // QuickSort
void SelectSort(Student stu[],int n){
	//��˳���L���м�ѡ������
	int i,k,j;
	Student temp;
     for ( i=1; i<n; ++i)
      {   k=i;  
            //ѡ��ؼ�����С�ļ�¼
           for (j = i+1;j <= n; ++j)
	       if (stu[k].score >stu[j].score)   k=j;
	//��С��¼���i����¼����
           if (i!=k){ 
               temp=stu[i];
	           stu[i]=stu[k];
			   stu[k]=temp; 
           }
      }
}
void HeapAdjust(Student stu[], int s, int m){
	//����H.r[s..m]��һ���󶥶�
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
	//��˳���H���ж�����
  //��ʼ�ѽ���
	int i;
	Student temp;
  for ( i = n/2;  i > 0;  --i)
        HeapAdjust(stu, i, n);
  //�ѵ���������
 for ( i = n;  i > 1;  --i)
    {   temp = stu[1];
        stu[1] = stu[i];
        stu[i] = temp;
        HeapAdjust(stu, 1, i-1);
    }
}
void Merge( Student s[], Student t[], int i, int m, int n )
{//�������SR[i..m]��SR[m+1..n]�鲢Ϊ�����TR[i..n]
    int j,k;
   j = m+1;  k = i;
   while( i <= m && j <= n )
      if( s[i].score <= s[j].score)   t[k++] = s[i++];
      else  t[k++] = s[j++];
   while( i <= m)    t[ k++] = s[i++];
   while( j <= n)     t[ k++] = s[j++];
}//Merge 
void MSort( Student stu[], Student t1[], int s, int t)
{//��SR[s..t]�鲢����ΪTR1[s..t]��
	Student t2[20];
	int m;
    if( s == t )   t1[s] = stu[s];
    else 
    {    m = ( s+t )/2;         //��SR[s..t]ƽ��ΪSR[s..m]��SR[m+1..t]
          MSort( stu, t2, s, m ); //��SR[s..m]�鲢Ϊ�����TR2[s..m] 
          MSort( stu, t2, m+1, t); //��SR[m+1..t]�鲢Ϊ�����TR2[m+1..t] 
          Merge( t2,t1,s,m,t); //��TR2[s..m]��TR2[m+1..t]�鲢��TR1[s..t] 
    }
}

int main()
{
	printf("��Ҫ�����ˣ�");
	int n;
	int i;
	scanf("%d",&n);
	Student stu[n+1]; 
	Input(stu[], n);
	for(i=1;i<=n;i++)
	printf("%10d%20s%5d\n",stu[i].a,stu[i].num,stu[i].score);
	int x;
	printf("��1�����ʵ�ֲ��������㷨��\n");
	printf("��2�����ʵ�ֿ��������㷨��\n");
	printf("��3�����ʵ��ѡ�������㷨��\n");
	printf("��4�����ʵ�ֹ鲢�����㷨��\n");
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

