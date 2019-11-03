#include <stdio.h>

#define M 50
#define N 50
#define MAXSIZE 20

typedef int ElemType; 

typedef struct{
    int r,c;
    ElemType d;
} Triple;

typedef struct{
	Triple data[MAXSIZE+1];
	int mu;
    int nu;
    int tu;

} TSMatrix;

int A[M][N],B[M][N],C[M][N];
 
void CreateMat(TSMatrix &t,int row,int col){
    int i,j;
    t.mu=row;
	t.nu=col;
	t.tu=0;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            if(A[i][j]!=0){
                t.data[t.tu].r=i;
				t.data[t.tu].c=j;
                t.data[t.tu].d=A[i][j];
				t.tu++;
            }    
        }    
    }    
}

int MatAdd(TSMatrix a,TSMatrix b,TSMatrix &c){
    int i=0,j=0,k=0;
    ElemType v;
    if(a.mu!=b.mu||a.nu!=b.nu)
		return 0;
    c.mu=a.mu;
	c.nu=a.nu;
    while(i<a.tu&&j<b.tu){
        if(a.data[i].r==b.data[j].r){
            if(a.data[i].c<b.data[j].c){
                c.data[k].r=a.data[i].r;
                c.data[k].c=a.data[i].c;
                c.data[k].d=a.data[i].d;
                i++;
				k++;
            } 
            else if(a.data[i].c>b.data[j].c){
                c.data[k].r=b.data[j].r;
                c.data[k].c=b.data[j].c;
                c.data[k].d=b.data[j].d;
                j++;
				k++;
            }      
            else{
                v=a.data[i].d+b.data[j].d;
                if(v!=0){
                    c.data[k].r=a.data[i].r;
                    c.data[k].c=a.data[i].c;
                    c.data[k].d=v;
                    k++;
                }
                i++;
				j++;   
            }    
        }    
        else if(a.data[i].r<b.data[j].r){
            c.data[k].r=a.data[i].r;
            c.data[k].c=a.data[i].c;
            c.data[k].d=a.data[i].d;
            i++;
			k++;
        }     
	else{
            c.data[k].r=b.data[j].r;
            c.data[k].c=b.data[j].c;
            c.data[k].d=b.data[j].d;
            j++;
			k++;
        }   
        c.tu=k;  
    }    
    return 1;
}
void DispMat(TSMatrix t){
    int i;
    if(t.tu<=0)
		return;
    printf("%d\t%d\t%d\n",t.mu,t.mu,t.tu);
    for(i=0;i<t.tu;i++)
        printf("\n%d\t%d\t%d\n",t.data[i].r,t.data[i].c,t.data[i].d);
}     

int main(){
    int row,col;
	int i,j;
	int x,y;
    int count=0;
    TSMatrix a,b,c;
    printf("请输入矩阵行、列数：\n");
    scanf("%d%d",&row,&col);
    printf("请输入矩阵A元素：\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&A[i][j]); 
        }    
    }  
	 
    printf("请输入矩阵B元素：\n"); 
	for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&B[i][j]);
			C[i][j]=A[i][j]+B[i][j]; 
        }    
    } 
    
    CreateMat(a,row,col);
	CreateMat(b,row,col); 
    printf("矩阵A的三元组表示为：\n");
	DispMat(a);
    printf("矩阵B的三元组表示为：\n");
	DispMat(b);
    
    printf("矩阵之和为:\n");
	for(i=0;i<row;i++){
		for(j=0;j<col;j++){
			printf("%d\t",C[i][j]);
			if((++count)%col==0)
				printf("\n");
		}
	}
    if(MatAdd(a,b,c)){
	
		printf("矩阵A、B相加后得到的三元组表示为：\n");
    	DispMat(c);
	}
    
    return 0;    
}
