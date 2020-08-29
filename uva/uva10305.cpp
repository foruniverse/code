#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

const int maxn = 100+10;
int point[maxn];
int side[maxn][maxn];
int n,m;
int vis[maxn];
stack<int> s;
bool dfs(int now)
{
    vis[now] = -1;
    for(int i=1;i<=n;i++)
    {
        if(side[now][i])
        {
            if(vis[i]<0 && now !=i)
                return false;
            else if(vis[i] == 0 &&!dfs(i))
            {
                return false;
            }
        }
    }

    vis[now] =1;
    s.push(now);
    return true;
}

int main()
{
    int count =0;
    while(scanf("%d%d",&n,&m)==2 && n )
    {
        int x,y;
        for(int i=1;i<=m;i++)
        {
           scanf("%d%d",&x,&y); 
           side[x][y]=1;
        }
        printf(count++>0?"\n":"");
        bool flag = true;
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
                if(!dfs(i))
                {
                    flag = false;
                    break;
                }
        }
        
        if(flag)
        {
            printf("%d",s.top());
            s.pop();
            while(!s.empty())
            {
                printf(" %d",s.top());
                s.pop();
            }
        }
        memset(vis,0,sizeof(vis));
        memset(side,0,sizeof(side));
    }
}
