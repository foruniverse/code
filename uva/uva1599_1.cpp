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
        bfs_1();        
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
        for(int i=0;i<side[now].size();i++)
        {
            int no = side[now][i];
            int v= edges[no].y;
            if(!vis[v])
            {
                vis[v]=1;
                que.push(v);
                dis[v]=dis[now]+1;
            }
        }
    }
}

vector<int> ans;
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
            for(int i=0;i<side[now].size();i++)
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



void add_edge(int x,int y,int c)
{
    edges.push_back(edge(x,y,c));
    side[x].push_back(edges.size()-1);
}

