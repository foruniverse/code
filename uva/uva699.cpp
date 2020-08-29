#include<cstdio>
#include<cstring>

const int maxn = 100000+10;


int sum[maxn];

void build(int temp)
{
    int test;
    scanf("%d",&test);
    //dang qian quanzhong
    if(test==-1)
        return;
    sum[temp]+=test;
    build(temp-1);
    build(temp+1);
}

bool read()
{
    int n;
    scanf("%d",&n);
    if(n==-1)
        return false;
    memset(sum,0,sizeof(sum));
    sum[maxn>>1]=n;

    build((maxn>>1) -1);
    build((maxn>>1)+1);
    return true;
}

int main()
{
    int count =0;
    while(read())
    {
        printf("Case %d:\n",++count);
        int p=0;
        while(sum[p]==0) p++;
        printf("%d",sum[p++]);
        while(sum[p]!=0) 
            printf(" %d",sum[p++]);
        printf("\n\n\n");
    }
    return 0;
}
