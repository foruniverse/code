#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

void test(double dir,int depth)
{
    printf("double:: dir:%lf, depth:%d\n",dir,depth);
    printf("int:: dir:%d, depth:%d",(int)dir,depth);
    cout<<endl;
    if(dir>100)
        return ;
    test(dir+1*pow(5,depth),depth+1);
}
void test1(int dir,int depth)
{

    printf("double:: dir:%lf, depth:%d\n",(double)dir,depth);
    printf("int:: dir:%d, depth:%d",(int)dir,depth);
    cout<<endl;
    if(dir>100)
        return ;
    test1(dir+1*pow(5,depth),depth+1);
}
int main()
{
    test(0,0);
    cout<<endl<<endl;
    test1(0,0);
    int tst=pow(5,0)*1 +0;
    cout<<tst<<endl;
     tst=pow(5,1)*1+tst;
     cout<<tst+25<<endl;
     int t =pow(5,2);
     cout<<tst+t<<endl;
    cout<<tst<<endl;
     tst=pow(5,2)*1+tst;
    cout<<tst<<endl;

    cout<<pow(5,2)*1+6<<endl;
    return 0;
}

