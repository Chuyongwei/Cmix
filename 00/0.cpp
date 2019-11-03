#include<iostream>
using namespace std;

#include<iostream>

#include<cstdio>

using namespace std;

int main()

{

    int t , a[60];

    a[1] = 1 ;

    a[2] = 2;

    a[3] = 3;

    a[4] = 4;

    for(int i = 5 ; i < 60 ; i ++)

    {

        a[i] = a[i-1] + a[i-3];

    }
    int i = 0;
    int *b;
    do{
    	b = new b[i+1];
    	cin >> n;
    	b[i] = a[n];
    	i++;
    }while(n!=0)
    for(int j = 0;j<=i;j++)
    {
    	cout<<b[i]<<endl;
    }
    return 0 ;

}

 

