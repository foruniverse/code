#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{   
   int a[7] = {1,2,3,4,5,6,7}; 
   int cont = 0;
   do{
       
        printf("7\n");
        for(auto x:a) printf("%d ",x);
        putchar('\n');
   }while(next_permutation(a,a+7));
    return 0;
    
}
