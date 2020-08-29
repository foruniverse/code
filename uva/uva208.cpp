#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
const int maxn = 22;
int tar,sum;
int node[maxn],side[maxn][maxn],vis[maxn];

vector<int> ans;
void dfs(int cur)
{
    if(cur == tar) { ++sum;printf("%d",ans[0]); for(int i = 1; i < ans.size(); ++i) printf(" %d",ans[i]); putchar('\n'); }
    for(int i = 1; i < maxn; ++i)
    {
        if(i == cur) continue;
        if(!vis[i] && side[cur][i])
        {
            vis[i] = 1;ans.push_back(i);
            dfs(i);
            vis[i] = 0; ans.pop_back();
        }
    }
}

bool bfs()
{
    memset(vis,0,sizeof(vis));
   queue<int> que;
   que.push(1);
   vis[1] = 1;
   while(!que.empty())
   {
       int cur = que.front(); que.pop();
       if(cur == tar) { return true; } 
       for(int i = 1; i < maxn; ++i)
       {
           if(i == cur) continue;
           if(!vis[i] && side[cur][i])
           {
               vis[i] = 1;
               que.push(i);
           }
       }
   }
   return false;
}

int main(){
    int cont = 0;
    while(scanf("%d",&tar) == 1)
    {
        int a,b;
        memset(side,0,sizeof(side));
        while(scanf("%d%d",&a,&b) == 2 && a && b)
        {
            side[a][b] = 1; side[b][a] = 1;
        }
        printf("CASE %d:\n",++cont);
        if(!bfs()) {printf("There are 0 routes from the firestation to streetcorner %d.\n",tar); continue;  }
        memset(vis,0,sizeof(vis));
        sum = 0;
        ans.clear();
        ans.push_back(1);
        vis[1] = 1;
        dfs(1);
        printf("There are %d routes from the firestation to streetcorner %d.\n",sum,tar);
    }
    return 0;
}
