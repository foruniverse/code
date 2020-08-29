#include<iostream>
#include<cstdio>
using namespace std;

bool check(int x,int y,int z)
{
    return (x + y > z) && (x + z > y) && ( y + z > x ) && x != y && x!=z && y !=z;
}
int main(){
    int n;
    while(scanf("%d",&n) == 1 && n)
    {
        int buffer[n];
        for(int i = 0; i < n; ++i) scanf("%d",&buffer[i]);
        int cont = 0;
        for(int i = 0; i < n -2 ; ++i) 
        {
            for(int j = i + 1; j < n - 1; ++j)
            {
                for(int k = j + 1; k < n; ++k)
                {
                    if(check(buffer[i],buffer[j],buffer[k])) 
                    {
                        ++cont;
                    }
                }
            }
        }
        printf("%d\n",cont);
    } 
    return 0;
}
