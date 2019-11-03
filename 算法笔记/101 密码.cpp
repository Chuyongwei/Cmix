#include<bits/stdc++.h>
using namespace std;
char a[31],b[31],c[31],l;

void change(char a[],int i){
    a[i] ^= 1;
    if(i > 0)
        a[i-1] ^= 1;
    if(i < l-1)
        a[i+1] ^= 1;
}
int main(){
    int i,n1 = 0,n2 = 1,f1 = 1,f2 = 1;
    gets(a);
    gets(b);
    l = strlen(a);
    memcpy(c,a,sizeof(a));
    for(i = 0; i <= l-2; i++){
        if(a[i] != b[i]){
            change(a,i+1);
            n1++;
        }
    }
    if(a[l-1] != b[l-1])
        f1 = 0;
    change(c,0);
    for(i = 0; i <= l-2; i++){
        if(c[i] != b[i]){
            change(c,i+1);
            n2++;
        }
    }
    if(c[l-1] != b[l-1])
        f2=0;
    if(f1 == 0 && f2 == 0)
        printf("impossible");
    else
        printf("%d",min(n1,n2));
    return 0;
}
