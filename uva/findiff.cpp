#include<cstdio>
char buffer[100000+10][1000];
int main()
{
    int which;
    scanf("%d",&which);
    freopen("input.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int m;
        scanf("%d",&m);
        
        for(int i=1;i<=m;i++)
        {
            scanf("%s",buffer[i]);
        }
        if(i==which)
        {
            printf("%d",m);
            putchar('\n');
            for(int i=1;i<=m;i++)
            {
                printf("%s",buffer[i]);
                putchar('\n');
            }
            break;
        }
    }
    return 0;
}
