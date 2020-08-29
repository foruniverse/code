#include<iostream>
#include<cstdio>
using namespace std;

//递归的魅
int w;
bool read_input(int &w)
{
    int w1,d1,w2,d2;
    scanf("%d%d%d%d",&w1,&d1,&w2,&d2);
    bool b1=true;
    bool b2 = true;
    if(!w1)
        b1= read_input(w1);
    if(!w2) 
        b2=read_input(w2);
    w = w1 + w2;
    //计算子天平总重量
    return ( b1 && b2 && (w1 * d1 == w2* d2 ) ) ;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        if(read_input(w))
            printf("YES\n");
        else printf("NO\n");
        if(i!=n)
            printf("\n");
    }
    return 0;
}
