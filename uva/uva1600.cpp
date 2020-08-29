#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int maxn = 25;
int board[maxn][maxn];
int vis[maxn][maxn][maxn];
int dis[maxn][maxn];
int mem[maxn][maxn];
using pos = pair<int,int>;
int m,n,k;

bool inside(int x,int y)
{
    return x>=1&& x<=m && y>=1 && y <=n;
}
void bfs()
{
    queue<pos> que;
    que.push(make_pair(1,1));
    vis[1][1][0]=1;
    while(!que.empty())
    {
        pos u=que.front();
        que.pop();
        int x=u.first,y=u.second;
        if(u.first == m && u.second ==n)
        {
            cout<<dis[x][y]<<endl;
            return ;
        }
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if((i==0||j==0)&& i!=j)
                {
                    int step
                    if(board[x+i][y+j]==1)
                        step=mem[x][y]+1;
                    else step=0;
                    if(!vis[x+i][y+j][step] &&inside(x+i,y+j))
                    { 
                        if( board[x+i][y+j]==1)
                        {
                            int step=mem[x][y];
                            if(step>=k)
                                continue;
                            //if(mem[x+i][y+j]>=++step)
                            //    continue;
                            mem[x+i][y+j]=++step; 
                            vis[x+i][y+j][step]=1;
                            que.push(make_pair(x+i,y+j));
                            dis[x+i][y+j]=dis[x][y]+1;
                            continue;
                        }
                            que.push(make_pair(x+i,y+j));
                            vis[x+i][y+j][0]=1;
                            dis[x+i][y+j]=dis[x][y]+1;
                    }
                }
            }
        }
    }        
    cout<<"-1"<<endl;
}
int main()
{
    int num;
    cin>>num;

    while(num--)
    {
        memset(board,0,sizeof(board));
        memset(vis,0,sizeof(vis));
        memset(mem,0,sizeof(mem));
        memset(dis,0,sizeof(dis));
        int temp;
        cin>>m>>n>>k;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                cin>>temp;
                board[i][j]=temp;
            }
        bfs();
    }
}
