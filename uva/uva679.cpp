#include<cstdio>
#include<cstring>
// tle 超时
using namespace std;
const int maxn = 20;
int node[1<<maxn];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int d,x;
        scanf("%d%d",&d,&x);
        int k;
        for(int j=1;j<=x;j++)
        {
            for(k=1; k<((1<<d) - (1<<(d-1)));)
            {
                if(node[k]==0)
                {
                    node[k]=1;
                    k=k*2;
                }
                else{
                    node[k]=0;
                    k=k*2+1;
                } 
            }
        }
        printf("%d\n",k);
        memset(node,0,sizeof(node));
    }
    int temp;
    scanf("%d",&temp);
    return 0;
}
