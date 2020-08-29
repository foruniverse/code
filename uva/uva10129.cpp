#include<cstdio>
#include<cstring>
using namespace std;
const int maxn = 1000 +10;
int n,m;
int point[30], side[30][30],in[30],out[30]. vis[30];
bool euler();

void dfs(int);
//dfs后判断是否有节点未被访问，如果有则图不联通
bool check()
{
    for(int i=0;i<=25;i++)
        if(point[i] )
            if(vis[i]==0)
                return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&m);
        char buffer[maxn];
        int b;
        for(int i=1;i<=m;i++)
        {
            scanf("%s",buffer);
            int a=buffer[0]-'a';
            b= buffer[strlen(buffer)-1]-'a';
            point[a]=1;
            point[b] =1;
            side[a][b]=side[b][a] =1; //判断的是基图联通，有向图的基图即无向图
            in[a]++;//统计入度
            out[b]++;//统计出度
        }
        dfs(b);//无向图的联通就随便找个点遍历，
        if((euler() && check())|| m==1 || m==0) 
        {
            printf("Ordering is possible.\n");
        }
        else printf("The door cannot be opened.\n");
        //清除中间变量
        memset(vis,0,sizeof(vis));
        memset(side,0,sizeof(side));
        memset(point,0,sizeof(point));
        memset(in,0,sizeof(in)); 
        memset(out,0,sizeof(out)); 
    } 
    return 0; 
} 
void dfs(int now)
{
    vis[now]=1;
    for(int i=0;i<=25;i++)
        if(side[now][i] && !vis[i]) 
            dfs(i);
}
bool euler() //判断节点度数
{
    int count1=0;
    int count2=0;
    for(int i=0;i<=25;i++)
    {
        if(in[i]-out[i]>1 && out[i] - in[i]>1)
            return false;
        if(in[i]-out[i]==1)
        {
            if(++count1>1) return false;
        }else if(out[i]-in[i]==1)
        {
            if(++count2>1)   return false;
        }
    }
    return true;
}
