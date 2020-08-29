#include<iostream>
#include<cstdio>
using namespace std;

int main(){
    long long  a,b,c,d;
    while(scanf("%lld%lld%lld%lld",&a,&b,&c,&d) == 4)
    {
        if(a == 0 && b == 0) { printf("0\n"); continue; }
        if(a == 0 || b ==0 )
        {
            printf("%lld\n",d);
            continue;
        }
        if( a == b ) {  cout<<min(c,2 * d)<<endl; continue;}
        cout<<min(c + d, 2 * d)<<endl; 
    }
    return 0;
}
// 面向数据做题，针对所有数据分讨论， noip风格
