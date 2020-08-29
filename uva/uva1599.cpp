#include<iostream> 
#include<vector>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 100000 +5;
const int INF = 1.0e+9;
int dis[maxn];

struct edge{
    int x,y,c;
    edge(int x,int y,int c):x(x),y(y),c(c){}
};
vector<edge> edges;
vector<int> side[maxn];
int vis[maxn];
int n,m;

void bfs();
void back_bfs();
void bfs_1();
void print_edge();
void bfs_2();
void add_edge(int,int,int);
int main()
{
#ifdef LOCAL
    freopen("input.txt","r",stdin);
#endif
    while(scanf("%d%d",&n,&m) == 2)
    {
        int x,y,c;
        for(int i=0;i<=n;i++) side[i].clear();
        edges.clear();
        // c= 0 not connect
        while(m--)
        {
            scanf("%d%d%d",&x,&y,&c);
            add_edge(x,y,c);
            add_edge(y,x,c);// each edge can be passed in either direction
        }
       // print_edge();
        back_bfs();
        bfs_2();        
        memset(vis,0,sizeof(vis));
        memset(dis,0,sizeof(dis));
    }
    return 0;
}

void back_bfs()
{
    queue<int> que;
    que.push(n);
    dis[n]=0;
    vis[n]=1;
    while(!que.empty())
    {
        int now = que.front(); que.pop();
      //  cout<<"now= "<<now<<endl;
        for(int i=0;i<side[now].size();i++)
        {
            int no = side[now][i];
            int v= edges[no].y;
    //        cout<<"next="<<v<<endl;
            if(!vis[v])
            {
     //           cout<<"suc in"<<endl;
                vis[v]=1;
                que.push(v);
                dis[v]=dis[now]+1;
            }
        }
    }
}

vector<int> ans;
void bfs_2()
{
    vector<int> next;
    vector<int> temp;
    next.push_back(1);
    
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=1;i<=dis[1];i++)
    {
        int best = INF;
       for(auto now:next)
       {
           for(auto now_edge:side[now])
           {
               int color = edges[now_edge].c; 
               if(dis[edges[now_edge].y]== dis[now] -1)
               {
                   if(color <best)
                       best = color;
               }
           }
       }
       ans.push_back(best);
       for(auto now:next)
           for(auto now_edge:side[now])
           {
               int color = edges[now_edge].c;
               int next_point = edges[now_edge].y;
               if(!vis[next_point] && color == best && dis[next_point] == dis[now] -1)
               {
                   temp.push_back(next_point);
                   vis[next_point]=1;
               }

           }
        next = temp;
        temp.clear();
//        cout<<best<<endl;
    }
    printf("%d\n%d",ans.size(),ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
    putchar('\n');
    ans.clear();
}
void bfs_1()
{
    vector<int> next;
    vector<int> temp;
    next.push_back(1);
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=dis[1];i++)
    {
        int best = INF;
        for(int j=0;j<next.size();j++)
        {
            int now = next[j];
            for(int i=0;i<side[next[j]].size();i++)
            {
                int no= side[now][i];
                int v = edges[no].y;
                if(dis[v] == dis[now] - 1)
                {
                    if(edges[no].c < best)
                    {
                        best = edges[no].c;
                        temp.clear();
                        temp.push_back(v);
                        vis[v] = 1;
                    }
                    else if(edges[no].c == best)
                    {
                        if(!vis[v])
                        {
                            temp.push_back(v);
                            vis[v] =1 ;
                        }

                    }
                }
            }
        }
//        for(int i=0;i<temp.size();i++)
//            cout<<temp[i]<<" ";
//        cout<<endl;
        next = temp;
        temp.clear();
//        cout<<best<<endl;
        ans.push_back(best);
    }
    printf("%d\n%d",ans.size(),ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
    putchar('\n');
    ans.clear();
}

void bfs()
{
    queue<int> que;
    ans.clear();
    que.push(1);
    memset(vis,0,sizeof(vis));
    vis[1]=1;
    while(!que.empty())
    {
        int u = que.front();
        que.pop();
        if(u==n)
            break;
        int best = INF;
        vector<int> temp;
        for(int i=0;i<side[u].size();i++)
        {
            int no =side[u][i];
            int v= edges[no].y;
            if(!vis[v] && dis[v]==dis[u]-1)
            {
                if(edges[no].c<best)
                {
                    temp.clear();
                    best=edges[no].c;
                    temp.push_back(v);
                }
                else if(edges[no].c==best)
                    temp.push_back(v);
            }
        }
        ans.push_back(best);
        printf("\n%d\n",temp.size());
        for(int i=0;i<temp.size();i++)
        {
            que.push(temp[i]);
        }

    }

//    printf("%d\n%d",ans.size(),ans[0]);
     printf("%d",ans[0]);
    for(int i=1;i<ans.size();i++)
        printf(" %d",ans[i]);
    putchar('\n');

}


void add_edge(int x,int y,int c)
{
    edges.push_back(edge(x,y,c));
 //   printf("%d %d %d",x,y,c);
    side[x].push_back(edges.size()-1);
  //  printf(" %d :%d",x,edges.size()-1); 
   // printf(" %d",side[x].size());
    //putchar('\n'); 

}
void print_edge()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<side[i].size();j++)
        {
            printf("%d,%d\n",edges[side[i][j]].x,edges[side[i][j]].y);

        }
        putchar('\n');
    }
}
