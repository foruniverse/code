#include<cstdio>

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int d,x;
        scanf("%d%d",&d,&x);
        int k=1;
        for(int j=0;j<d-1;j++)
            if(x%2)// 奇数
            {
                x=(x+1)>>1;
                k*=2;
            }else 
            {
                x=x/2;
                k=k*2+1;
            }
        printf("%d\n",k);
    }
    return 0;
}
